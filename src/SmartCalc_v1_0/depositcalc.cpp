#include "depositcalc.h"

#include <QDate>
#include <QMessageBox>

#include "../s21_calc.h"
#include "ui_depositcalc.h"

DepositCalc::DepositCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::DepositCalc) {
  ui->setupUi(this);
  ui->depositLine->setValidator(new QDoubleValidator(ui->depositLine));
  ui->changeSum->setValidator(new QDoubleValidator(ui->changeSum));
  ui->changeDate->setDate(QDate::currentDate());
  ui->changeDate->setDateRange(
      QDate::currentDate(),
      QDate::currentDate().addMonths(ui->months->value()));
  capitalisation = false;
}

DepositCalc::~DepositCalc() { delete ui; }

void DepositCalc::on_addPayment_clicked() {
  if (ui->changeSum->text().toDouble() <= 0) {
    QMessageBox::critical(this, "error", "incorrect payment sum");
  } else {
    changeRecord add;
    add.date = ui->changeDate->date();
    add.sum = ui->changeSum->text().toDouble();
    bool notHaving = true;
    for (auto &elem : payments) {
      if (add.date == elem.date) {
        elem.sum = elem.sum + add.sum;
        notHaving = false;
      }
    }
    if (notHaving) {
      payments.push_back(add);
    }

    delete ui->tablePayments;
    ui->tablePayments = new QTableWidget(payments.size(), 2, this);
    ui->tablePayments->setGeometry(320, 0, 291, 411);
    ui->tablePayments->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    for (int i = 0; i < payments.size(); i++) {
      ui->tablePayments->setItem(
          i, 0, new QTableWidgetItem(payments[i].date.toString()));
      ui->tablePayments->setItem(
          i, 1, new QTableWidgetItem(QString::number(payments[i].sum, 'f', 2)));
    }
    ui->tablePayments->show();
  }
}

void DepositCalc::on_addAddition_clicked() {
  if (ui->changeSum->text().toDouble() <= 0) {
    QMessageBox::critical(this, "error", "incorrect addition sum");
  } else {
    changeRecord add;
    add.date = ui->changeDate->date();
    add.sum = ui->changeSum->text().toDouble();
    bool notHaving = true;
    for (auto &elem : additions) {
      if (add.date == elem.date) {
        elem.sum = elem.sum + add.sum;
        notHaving = false;
      }
    }
    if (notHaving) {
      additions.push_back(add);
    }

    delete ui->tableAdditions;
    ui->tableAdditions = new QTableWidget(additions.size(), 2, this);
    ui->tableAdditions->setGeometry(610, 0, 291, 411);
    ui->tableAdditions->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    for (int i = 0; i < additions.size(); i++) {
      ui->tableAdditions->setItem(
          i, 0, new QTableWidgetItem(additions[i].date.toString()));
      ui->tableAdditions->setItem(
          i, 1,
          new QTableWidgetItem(QString::number(additions[i].sum, 'f', 2)));
    }
    ui->tableAdditions->show();
  }
}

void DepositCalc::on_calculate_clicked() {
  deposit = ui->depositLine->text().toDouble();
  rate = ui->depositRate->value();
  taxRate = ui->taxRate->value();
  monthsTerm = ui->months->value();
  if (deposit <= 0) {
    QMessageBox::critical(this, "error", "incorrect deposit sum");
  } else if (rate == 0) {
    QMessageBox::critical(this, "error", "incorrect rate");
  } else if (taxRate == 0) {
    QMessageBox::critical(this, "error", "incorrect tax rate");
  } else if (monthsTerm == 0) {
    QMessageBox::critical(this, "error", "incorrect term");
  } else {
    create_report();
    additions.clear();
    payments.clear();
    report.clear();
  }
}

void DepositCalc::on_months_valueChanged(int arg1) {
  ui->changeDate->setDateRange(QDate::currentDate(),
                               QDate::currentDate().addMonths(arg1));
}

void DepositCalc::on_capitalisation_clicked() {
  capitalisation = !capitalisation;
}

void DepositCalc::create_report() {
  QDate now = QDate::currentDate();
  QDate end = now.addMonths(monthsTerm);
  std::sort(payments.begin(), payments.end(),
            [](const changeRecord &a, const changeRecord &b) {
              return a.date < b.date;
            });
  std::sort(additions.begin(), additions.end(),
            [](const changeRecord &a, const changeRecord &b) {
              return a.date < b.date;
            });
  init_percents_vector();
  double percents = 0;
  double remainderDeposit = deposit;
  bool havingRecord;
  double totalPercents = 0;
  double percentsByYear = 0;
  double totalTax = 0;
  for (; now <= end; now = now.addDays(1)) {
    havingRecord = false;
    reportRecord add;
    add.date = now;
    add.percents = 0;
    add.addition = 0;
    add.remainder = remainderDeposit;
    if (percentsDate.size() && now == percentsDate.front()) {
      havingRecord = true;
      if (capitalisation) {
        add.addition = percents;
        remainderDeposit += percents;
        add.remainder += percents;
      }
      add.percents += percents;
      percents = 0;
      percentsDate.pop_front();
    }
    if (additions.size() && now == additions.front().date) {
      havingRecord = true;
      add.addition += additions.front().sum;
      add.remainder += additions.front().sum;
      remainderDeposit += additions.front().sum;
      additions.pop_front();
    }
    if (payments.size() && now == payments.front().date &&
        remainderDeposit - payments.front().sum >= 0) {
      havingRecord = true;
      add.addition -= payments.front().sum;
      add.remainder -= payments.front().sum;
      remainderDeposit -= payments.front().sum;
      payments.pop_front();
    }
    if (havingRecord) {
      report.push_back(add);
    }
    percents += depositProfitForDay(remainderDeposit, rate, now.daysInYear());
    totalPercents +=
        depositProfitForDay(remainderDeposit, rate, now.daysInYear());
    percentsByYear +=
        depositProfitForDay(remainderDeposit, rate, now.daysInYear());
    if (now.dayOfYear() == 1) {
      totalTax += calculateTax(&percentsByYear, taxRate);
    }
  }
  report.front().addition = deposit;
  report.front().percents = 0;
  init_report_table();
  ui->totalPercents->setText(QString::number(totalPercents, 'f', 2));
  ui->totalTax->setText(QString::number(totalTax, 'f', 2));
  ui->totalDeposit->setText(QString::number(remainderDeposit, 'f', 2));
}

void DepositCalc::init_percents_vector() {
  QDate now = QDate::currentDate();
  QDate end = now.addMonths(monthsTerm);
  if (ui->period->currentText() == "Every day") {
    for (; now < end; now = now.addDays(1)) {
      percentsDate.push_back(now);
    }
  } else if (ui->period->currentText() == "Every month") {
    for (; now < end; now = now.addMonths(1)) {
      percentsDate.push_back(now);
    }
  } else if (ui->period->currentText() == "Every year") {
    for (; now < end; now = now.addYears(1)) {
      percentsDate.push_back(now);
    }
  }
  percentsDate.push_back(end);
}

void DepositCalc::init_report_table() {
  delete ui->tableReport;
  ui->tableReport = new QTableWidget(report.size(), 4, this);
  ui->tableReport->setGeometry(320, 410, 581, 291);
  ui->tableReport->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  for (int i = 0; i < report.size(); i++) {
    ui->tableReport->setItem(i, 0,
                             new QTableWidgetItem(report[i].date.toString()));
    ui->tableReport->setItem(
        i, 1,
        new QTableWidgetItem(QString::number(report[i].percents, 'f', 2)));
    ui->tableReport->setItem(
        i, 2,
        new QTableWidgetItem(QString::number(report[i].addition, 'f', 2)));
    ui->tableReport->setItem(
        i, 3,
        new QTableWidgetItem(QString::number(report[i].remainder, 'f', 2)));
  }
  ui->tableReport->show();
}

#include "creditcalc.h"

#include <QDate>
#include <QMessageBox>
#include <QTableWidget>

#include "../s21_calc.h"
#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
  ui->creditSum->setValidator(new QDoubleValidator(ui->creditSum));
  mode = 0;
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_clicked() {
  double creditSum = ui->creditSum->text().toDouble();
  int term = ui->term->value();
  double rate = ui->rate->value();
  if (creditSum <= 0) {
    QMessageBox::critical(this, "error", "incorrect credit sum");
  } else if (term <= 0) {
    QMessageBox::critical(this, "error", "incorrect term");
  } else if (rate <= 0) {
    QMessageBox::critical(this, "error", "incorrect rate");
  } else if (mode == 0) {
    QMessageBox::warning(this, "attention", "chose mode");
  } else if (mode == 2) {
    annuitial_calculate(creditSum, term, rate);
  } else if (mode == 1) {
    differential_calculate(creditSum, term, rate);
  }
}

void CreditCalc::on_differential_clicked() { mode = 1; }

void CreditCalc::on_annuitial_clicked() { mode = 2; }

void CreditCalc::annuitial_calculate(double creditSum, int term, double rate) {
  double monthlyPayment;
  double overpayment;
  double totalPayment;
  annuityCredit(creditSum, term, rate, 2, &monthlyPayment, &overpayment,
                &totalPayment);
  ui->monthlyPayment->setText(QString::number(monthlyPayment, 'f', 2));
  ui->Overpayment->setText(QString::number(overpayment, 'f', 2));
  ui->totalPayments->setText(QString::number(totalPayment, 'f', 2));
}

void CreditCalc::differential_calculate(double creditSum, int term,
                                        double rate) {
  this->setGeometry(this->x(), this->y() + 28, 600, 600);
  QTableWidget *paymentTable = new QTableWidget(term, 3, this);
  paymentTable->setGeometry(300, 0, 300, 600);
  double monthlyPayment;
  double overpayment;
  double totalPayment = creditSum;
  double reminder = creditSum;
  double constPayment = creditSum / term;
  double payment;
  QDate now = QDate::currentDate();
  for (int i = 0; i < term; i++) {
    now = now.addMonths(1);
    payment = differentialPayment(reminder, rate, now.daysInYear(),
                                  now.daysInMonth());
    totalPayment += payment;
    reminder -= constPayment;
    paymentTable->setItem(i, 0, new QTableWidgetItem(now.toString()));
    paymentTable->setItem(
        i, 1, new QTableWidgetItem(QString::number(payment, 'f', 2)));
    paymentTable->setItem(i, 2,
                          new QTableWidgetItem(QString::number(
                              fabs(reminder) > 1e-2 ? reminder : 0, 'f', 2)));
  }
  ui->totalPayments->setText(QString::number(totalPayment, 'f', 2));
  ui->Overpayment->setText(QString::number(totalPayment - creditSum, 'f', 2));
  ui->monthlyPayment->setText(QString::number(totalPayment / term, 'f', 2) +
                              " (average)");
  paymentTable->show();
}

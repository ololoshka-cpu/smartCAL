#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QDate>
#include <QDialog>
#include <QVector>

namespace Ui {
class DepositCalc;
}

typedef struct {
  QDate date;
  double sum;
} changeRecord;

typedef struct {
  QDate date;
  double percents;
  double addition;
  double remainder;
} reportRecord;

class DepositCalc : public QDialog {
  Q_OBJECT

 public:
  explicit DepositCalc(QWidget *parent = nullptr);
  ~DepositCalc();

 private slots:
  void on_addPayment_clicked();
  void on_addAddition_clicked();
  void on_calculate_clicked();
  void on_months_valueChanged(int arg1);
  void on_capitalisation_clicked();

 private:
  Ui::DepositCalc *ui;
  QVector<changeRecord> additions, payments;
  QVector<QDate> percentsDate;
  QVector<reportRecord> report;
  double deposit;
  double rate;
  double taxRate;
  int monthsTerm;
  bool capitalisation;
  void create_report();
  void init_percents_vector();
  void init_report_table();
};

#endif  // DEPOSITCALC_H

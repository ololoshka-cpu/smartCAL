#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QDialog>

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_pushButton_clicked();
  void on_differential_clicked();
  void on_annuitial_clicked();

 private:
  Ui::CreditCalc *ui;
  int mode;
  void annuitial_calculate(double creditSum, int term, double rate);
  void differential_calculate(double creditSum, int term, double rate);
};

#endif  // CREDITCALC_H

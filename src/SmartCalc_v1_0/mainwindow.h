#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  bool eventFilter(QObject *obj, QEvent *event);
 private slots:
  void on_button_1_clicked();
  void on_line_edit_EXPRESSION_textEdited(const QString &arg1);
  void on_line_edit_X_textEdited(const QString &arg1);
  void on_button_2_clicked();
  void on_button_3_clicked();
  void on_button_4_clicked();
  void on_button_5_clicked();
  void on_button_6_clicked();
  void on_button_7_clicked();
  void on_button_8_clicked();
  void on_button_9_clicked();
  void on_button_DOT_clicked();
  void on_button_0_clicked();
  void on_button_LEFT_BRACKET_clicked();
  void on_button_RIGHT_BRACKET_clicked();
  void on_button_PLUS_clicked();
  void on_button_MINUS_clicked();
  void on_button_MUL_clicked();
  void on_button_DIV_clicked();
  void on_button_POW_clicked();
  void on_button_SIN_clicked();
  void on_button_COS_clicked();
  void on_button_TAN_clicked();
  void on_button_ASIN_clicked();
  void on_button_ACOS_clicked();
  void on_button_ATAN_clicked();
  void on_button_LN_clicked();
  void on_button_LOG_clicked();
  void on_button_SQRT_clicked();
  void on_button_GRAPH_clicked();
  void on_button_CREDIT_clicked();
  void on_button_DEPOSIT_clicked();
  void on_button_PI_clicked();
  void on_button_E_clicked();
  void on_button_X_clicked();
  void on_button_CLEAR_ALL_clicked();
  void on_button_BACKSPACE_clicked();
  void on_button_TOTAL_clicked();
  void on_button_MOD_clicked();

 private:
  QString expression;
  QString x_expression;
  QString *current_expression;
  QLineEdit *current_line;
  void insert_symbol(char);
  void insert_func(QString);
  void total();
  bool key_in_set(int);
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H

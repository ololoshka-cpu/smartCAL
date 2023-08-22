#include "mainwindow.h"

#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>

#include "../s21_calc.h"
#include "./ui_mainwindow.h"
#include "creditcalc.h"
#include "depositcalc.h"
#include "graph.h"

static int keys[] = {0x20, 0x30,      0x31,      0x32,      0x33,
                     0x34, 0x35,      0x36,      0x37,      0x38,
                     0x39, 0x1000003, 0x1000005, 0x2B,      0x2D,
                     0x28, 0x29,      0x1000012, 0x1000014, 0x45,
                     0x2A, 0x2F,      0x5E,      16777223,  0x2E};
static int keys_count = 25;

bool MainWindow::eventFilter(QObject *pobj, QEvent *event) {
  bool result = false;
  if (event->type() == QEvent::MouseButtonPress) {
    if (pobj->objectName() == "line_edit_EXPRESSION") {
      current_line = ui->line_edit_EXPRESSION;
      current_expression = &expression;
    } else if (pobj->objectName() == "line_edit_X") {
      current_line = ui->line_edit_X;
      current_expression = &x_expression;
    }
  } else if (event->type() == QEvent::KeyPress) {
    int ke = static_cast<QKeyEvent *>(event)->key();
    result = !key_in_set(ke);
    if (ke == 16777220) {
      total();
    }
  }
  return result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->line_edit_EXPRESSION->installEventFilter(this);
  ui->line_edit_X->installEventFilter(this);
  current_line = ui->line_edit_EXPRESSION;
  expression = ui->line_edit_EXPRESSION->text();
  x_expression = ui->line_edit_X->text();
  current_expression = &expression;
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::key_in_set(int key) {
  bool result = false;
  for (int i = 0; i < keys_count; i++) {
    if (key == keys[i]) {
      result = true;
    }
  }
  return result;
}

void MainWindow::insert_symbol(char a) {
  int pos = current_line->cursorPosition();
  current_expression->insert(pos, a);
  current_line->setText(*current_expression);
  current_line->setCursorPosition(pos + 1);
}

void MainWindow::insert_func(QString func) {
  int pos = current_line->cursorPosition();
  int size;
  if (func == "mod") {
    size = 4;
  } else if (func == "π") {
    size = 2;
  } else {
    size = func.size();
  }
  current_expression->insert(pos, func);
  current_line->setText(*current_expression);
  current_line->setCursorPosition(pos + size - 1);
}

void MainWindow::total() {
  if (ui->line_edit_EXPRESSION->text().length() == 0) {
    QMessageBox::critical(this, "error", "expression line is empty");
  } else if (ui->line_edit_EXPRESSION->text().contains('x')) {
    if (ui->line_edit_X->text().length() == 0) {
      QMessageBox::critical(this, "error", "x is undefined");
    } else {
      char *x_src =
          (char *)calloc(ui->line_edit_X->text().length() + 1, sizeof(char));
      strcpy(x_src, ui->line_edit_X->text().toLocal8Bit());
      char *x_res = calculate_expression(x_src, NULL);
      if (x_res[0] == '-' || isdigit(x_res[0])) {
        char *exp_src = (char *)calloc(
            ui->line_edit_EXPRESSION->text().length() + 1, sizeof(char));
        strcpy(exp_src, ui->line_edit_EXPRESSION->text().toLocal8Bit());
        char *exp_res = calculate_expression(exp_src, x_res);
        QMessageBox::information(this, "answer", exp_res);
        free(exp_src);
        free(exp_res);
      } else {
        QMessageBox::critical(this, "error", "incorrect x");
      }
      free(x_src);
      free(x_res);
    }
  } else {
    char *exp_src = (char *)calloc(
        ui->line_edit_EXPRESSION->text().length() + 1, sizeof(char));
    strcpy(exp_src, ui->line_edit_EXPRESSION->text().toLocal8Bit());
    char *exp_res = calculate_expression(exp_src, NULL);
    QMessageBox::information(this, "answer", exp_res);
    free(exp_src);
    free(exp_res);
  }
}

void MainWindow::on_line_edit_EXPRESSION_textEdited(const QString &arg1) {
  expression = ui->line_edit_EXPRESSION->text();
}

void MainWindow::on_line_edit_X_textEdited(const QString &arg1) {
  x_expression = ui->line_edit_X->text();
}

void MainWindow::on_button_GRAPH_clicked() {
  if (ui->line_edit_EXPRESSION->text().contains('x')) {
    char *exp_src = (char *)calloc(
        ui->line_edit_EXPRESSION->text().length() + 1, sizeof(char));
    strcpy(exp_src, ui->line_edit_EXPRESSION->text().toLocal8Bit());
    char value[] = "1";
    char *exp_res = calculate_expression(exp_src, value);
    if (!strcmp(exp_res, ERROR_BRACKETS) || !strcmp(exp_res, ERROR_OPERATION)) {
      QMessageBox::critical(this, "error", exp_res);
    } else {
      Graph graphWindow;
      graphWindow.setModal(true);
      graphWindow.set_exp(ui->line_edit_EXPRESSION->text());
      graphWindow.exec();
    }
    free(exp_res);
    free(exp_src);
  } else {
    QMessageBox::warning(this, "warninng", "x is undefined");
  }
}

void MainWindow::on_button_CREDIT_clicked() {
  CreditCalc creditWindow;
  creditWindow.setModal(true);
  creditWindow.exec();
}

void MainWindow::on_button_DEPOSIT_clicked() {
  DepositCalc depositWindow;
  depositWindow.setModal(true);
  depositWindow.exec();
}

void MainWindow::on_button_1_clicked() { insert_symbol('1'); }

void MainWindow::on_button_2_clicked() { insert_symbol('2'); }

void MainWindow::on_button_3_clicked() { insert_symbol('3'); }

void MainWindow::on_button_4_clicked() { insert_symbol('4'); }

void MainWindow::on_button_5_clicked() { insert_symbol('5'); }

void MainWindow::on_button_6_clicked() { insert_symbol('6'); }

void MainWindow::on_button_7_clicked() { insert_symbol('7'); }

void MainWindow::on_button_8_clicked() { insert_symbol('8'); }

void MainWindow::on_button_9_clicked() { insert_symbol('9'); }

void MainWindow::on_button_DOT_clicked() { insert_symbol('.'); }

void MainWindow::on_button_0_clicked() { insert_symbol('0'); }

void MainWindow::on_button_LEFT_BRACKET_clicked() { insert_symbol('('); }

void MainWindow::on_button_RIGHT_BRACKET_clicked() { insert_symbol(')'); }

void MainWindow::on_button_PLUS_clicked() { insert_symbol('+'); }

void MainWindow::on_button_MINUS_clicked() { insert_symbol('-'); }

void MainWindow::on_button_MUL_clicked() { insert_symbol('*'); }

void MainWindow::on_button_DIV_clicked() { insert_symbol('/'); }

void MainWindow::on_button_POW_clicked() { insert_symbol('^'); }

void MainWindow::on_button_E_clicked() { insert_symbol('e'); }

void MainWindow::on_button_X_clicked() {
  if (current_line->objectName() == "line_edit_EXPRESSION") insert_symbol('x');
}

void MainWindow::on_button_SIN_clicked() { insert_func("sin()"); }

void MainWindow::on_button_COS_clicked() { insert_func("cos()"); }

void MainWindow::on_button_TAN_clicked() { insert_func("tan()"); }

void MainWindow::on_button_ASIN_clicked() { insert_func("asin()"); }

void MainWindow::on_button_ACOS_clicked() { insert_func("acos()"); }

void MainWindow::on_button_ATAN_clicked() { insert_func("atan()"); }

void MainWindow::on_button_LN_clicked() { insert_func("ln()"); }

void MainWindow::on_button_LOG_clicked() { insert_func("log()"); }

void MainWindow::on_button_SQRT_clicked() { insert_func("sqrt()"); }

void MainWindow::on_button_PI_clicked() { insert_func("π"); }

void MainWindow::on_button_MOD_clicked() { insert_func("mod"); }

void MainWindow::on_button_CLEAR_ALL_clicked() {
  current_expression->clear();
  current_line->clear();
}

void MainWindow::on_button_BACKSPACE_clicked() {
  int pos = current_line->cursorPosition();
  current_expression->remove(pos - 1, 1);
  current_line->setText(*current_expression);
  current_line->setCursorPosition(pos - 1);
}

void MainWindow::on_button_TOTAL_clicked() { total(); }

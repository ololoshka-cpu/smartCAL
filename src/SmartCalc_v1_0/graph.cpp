#include "graph.h"

#include "../s21_calc.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

void Graph::set_exp(QString src) {
  func = (char *)calloc(src.length() + 1, sizeof(char));
  strcpy(func, src.toLocal8Bit());
  exp = src;
  ui->label->setText(exp);
}

Graph::~Graph() {
  delete ui;
  if (func) free(func);
}

void Graph::on_pushButton_clicked() {
  double xFrom = ui->xFrom->value();
  double yFrom = ui->yFrom->value();
  double xTo = ui->xTo->value();
  double yTo = ui->yTo->value();
  if (xTo <= xFrom || yTo <= yFrom) {
    QMessageBox::critical(this, "error", "incorrect intervals");
  } else {
    QVector<double> x, y;
    double step = (xTo - xFrom) / 1000;
    x.push_back(xFrom);
    y.push_back(getY(xFrom));
    for (double from = xFrom + step; from <= xTo; from += step) {
      double currentX = from;
      double currentY = getY(from);
      if (y.back() * currentY < 0) {
        x.push_back(currentX - step / 2);
        y.push_back(qQNaN());
      }
      x.push_back(currentX);
      y.push_back(currentY);
    }
    ui->graph->addGraph();
    ui->graph->graph(0)->addData(x, y);
    ui->graph->xAxis->setLabel("x");
    ui->graph->yAxis->setLabel("y");
    ui->graph->xAxis->setRange(xFrom, xTo);
    ui->graph->yAxis->setRange(yFrom, yTo);
    ui->graph->replot();
  }
}

double Graph::getY(double x) {
  double res = qQNaN();
  QString xString = QString::number(x);
  char *xChar = (char *)calloc(xString.length() + 1, sizeof(char));
  strcpy(xChar, xString.toLocal8Bit());
  char *result = calculate_expression(func, xChar);
  if (result[0] == '-' || isdigit(result[0])) {
    res = QString(result).toDouble();
  }
  return res;
}

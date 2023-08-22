#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

namespace Ui {
class Graph;
}

class Graph : public QDialog {
  Q_OBJECT
 public:
  explicit Graph(QWidget *parent = nullptr);
  explicit Graph(QWidget *parent, QString src);
  void set_exp(QString src);
  ~Graph();
 private slots:
  void on_pushButton_clicked();

 private:
  char *func;
  double getY(double x);
  QString exp;
  Ui::Graph *ui;
};

#endif  // GRAPH_H

/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QCustomPlot *graph;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *yFrom;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *xFrom;
    QLabel *label_3;
    QDoubleSpinBox *xTo;
    QDoubleSpinBox *yTo;
    QPushButton *pushButton;

    void setupUi(QDialog *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->resize(1200, 800);
        Graph->setMinimumSize(QSize(1200, 800));
        Graph->setMaximumSize(QSize(1200, 800));
        graph = new QCustomPlot(Graph);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setGeometry(QRect(0, 0, 1200, 700));
        label = new QLabel(Graph);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 700, 600, 100));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(Graph);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(610, 700, 431, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        yFrom = new QDoubleSpinBox(gridLayoutWidget);
        yFrom->setObjectName(QString::fromUtf8("yFrom"));
        yFrom->setMinimum(-1000000.000000000000000);
        yFrom->setMaximum(1000000.000000000000000);
        yFrom->setSingleStep(0.100000000000000);
        yFrom->setValue(-10.000000000000000);

        gridLayout->addWidget(yFrom, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        xFrom = new QDoubleSpinBox(gridLayoutWidget);
        xFrom->setObjectName(QString::fromUtf8("xFrom"));
        xFrom->setMinimum(-1000000.000000000000000);
        xFrom->setMaximum(1000000.000000000000000);
        xFrom->setSingleStep(0.100000000000000);
        xFrom->setValue(-20.000000000000000);

        gridLayout->addWidget(xFrom, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        xTo = new QDoubleSpinBox(gridLayoutWidget);
        xTo->setObjectName(QString::fromUtf8("xTo"));
        xTo->setMinimum(-1000000.000000000000000);
        xTo->setMaximum(1000000.000000000000000);
        xTo->setSingleStep(0.100000000000000);
        xTo->setValue(20.000000000000000);

        gridLayout->addWidget(xTo, 0, 3, 1, 1);

        yTo = new QDoubleSpinBox(gridLayoutWidget);
        yTo->setObjectName(QString::fromUtf8("yTo"));
        yTo->setMinimum(-1000000.000000000000000);
        yTo->setMaximum(1000000.000000000000000);
        yTo->setSingleStep(0.100000000000000);
        yTo->setValue(10.000000000000000);

        gridLayout->addWidget(yTo, 1, 3, 1, 1);

        pushButton = new QPushButton(Graph);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1050, 710, 141, 81));

        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QDialog *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Graph", "x from", nullptr));
        label_4->setText(QCoreApplication::translate("Graph", "x to", nullptr));
        label_5->setText(QCoreApplication::translate("Graph", "y to", nullptr));
        label_3->setText(QCoreApplication::translate("Graph", "y from", nullptr));
        pushButton->setText(QCoreApplication::translate("Graph", "PLOT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *line_edit_EXPRESSION;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_GRAPH;
    QPushButton *button_CREDIT;
    QPushButton *button_DEPOSIT;
    QPushButton *button_CLEAR_ALL;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_3;
    QPushButton *button_TOTAL;
    QPushButton *button_ATAN;
    QPushButton *button_PLUS;
    QPushButton *button_6;
    QPushButton *button_TAN;
    QPushButton *button_2;
    QPushButton *button_MUL;
    QPushButton *button_LN;
    QPushButton *button_4;
    QPushButton *button_0;
    QPushButton *button_LEFT_BRACKET;
    QPushButton *button_5;
    QPushButton *button_DOT;
    QPushButton *button_MINUS;
    QPushButton *button_ACOS;
    QPushButton *button_BACKSPACE;
    QPushButton *button_RIGHT_BRACKET;
    QPushButton *button_9;
    QPushButton *button_ASIN;
    QPushButton *button_DIV;
    QPushButton *button_7;
    QPushButton *button_COS;
    QPushButton *button_SIN;
    QPushButton *button_8;
    QPushButton *button_1;
    QPushButton *button_POW;
    QPushButton *button_SQRT;
    QPushButton *button_LOG;
    QPushButton *button_MOD;
    QLineEdit *line_edit_X;
    QPushButton *button_X;
    QPushButton *button_PI;
    QPushButton *button_E;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 480);
        MainWindow->setMinimumSize(QSize(400, 480));
        MainWindow->setMaximumSize(QSize(400, 480));
        QPalette palette;
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line_edit_EXPRESSION = new QLineEdit(centralwidget);
        line_edit_EXPRESSION->setObjectName(QString::fromUtf8("line_edit_EXPRESSION"));
        line_edit_EXPRESSION->setGeometry(QRect(10, 10, 321, 61));
        QFont font;
        font.setPointSize(22);
        font.setKerning(true);
        line_edit_EXPRESSION->setFont(font);
        line_edit_EXPRESSION->setMaxLength(255);
        line_edit_EXPRESSION->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 410, 381, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_GRAPH = new QPushButton(horizontalLayoutWidget);
        button_GRAPH->setObjectName(QString::fromUtf8("button_GRAPH"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_GRAPH->sizePolicy().hasHeightForWidth());
        button_GRAPH->setSizePolicy(sizePolicy);
        button_GRAPH->setMaximumSize(QSize(116, 16777215));

        horizontalLayout->addWidget(button_GRAPH);

        button_CREDIT = new QPushButton(horizontalLayoutWidget);
        button_CREDIT->setObjectName(QString::fromUtf8("button_CREDIT"));
        sizePolicy.setHeightForWidth(button_CREDIT->sizePolicy().hasHeightForWidth());
        button_CREDIT->setSizePolicy(sizePolicy);
        button_CREDIT->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(button_CREDIT);

        button_DEPOSIT = new QPushButton(horizontalLayoutWidget);
        button_DEPOSIT->setObjectName(QString::fromUtf8("button_DEPOSIT"));
        sizePolicy.setHeightForWidth(button_DEPOSIT->sizePolicy().hasHeightForWidth());
        button_DEPOSIT->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(button_DEPOSIT);

        button_CLEAR_ALL = new QPushButton(centralwidget);
        button_CLEAR_ALL->setObjectName(QString::fromUtf8("button_CLEAR_ALL"));
        button_CLEAR_ALL->setGeometry(QRect(340, 10, 50, 61));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 120, 381, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_3 = new QPushButton(gridLayoutWidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_3->sizePolicy().hasHeightForWidth());
        button_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_3, 0, 2, 1, 1);

        button_TOTAL = new QPushButton(gridLayoutWidget);
        button_TOTAL->setObjectName(QString::fromUtf8("button_TOTAL"));
        sizePolicy1.setHeightForWidth(button_TOTAL->sizePolicy().hasHeightForWidth());
        button_TOTAL->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_TOTAL, 4, 2, 1, 1);

        button_ATAN = new QPushButton(gridLayoutWidget);
        button_ATAN->setObjectName(QString::fromUtf8("button_ATAN"));
        sizePolicy1.setHeightForWidth(button_ATAN->sizePolicy().hasHeightForWidth());
        button_ATAN->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_ATAN, 2, 5, 1, 1);

        button_PLUS = new QPushButton(gridLayoutWidget);
        button_PLUS->setObjectName(QString::fromUtf8("button_PLUS"));
        sizePolicy1.setHeightForWidth(button_PLUS->sizePolicy().hasHeightForWidth());
        button_PLUS->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_PLUS, 0, 3, 1, 1);

        button_6 = new QPushButton(gridLayoutWidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));
        sizePolicy1.setHeightForWidth(button_6->sizePolicy().hasHeightForWidth());
        button_6->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_6, 1, 2, 1, 1);

        button_TAN = new QPushButton(gridLayoutWidget);
        button_TAN->setObjectName(QString::fromUtf8("button_TAN"));
        sizePolicy1.setHeightForWidth(button_TAN->sizePolicy().hasHeightForWidth());
        button_TAN->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_TAN, 1, 4, 1, 1);

        button_2 = new QPushButton(gridLayoutWidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));
        sizePolicy1.setHeightForWidth(button_2->sizePolicy().hasHeightForWidth());
        button_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_2, 0, 1, 1, 1);

        button_MUL = new QPushButton(gridLayoutWidget);
        button_MUL->setObjectName(QString::fromUtf8("button_MUL"));
        sizePolicy1.setHeightForWidth(button_MUL->sizePolicy().hasHeightForWidth());
        button_MUL->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_MUL, 2, 3, 1, 1);

        button_LN = new QPushButton(gridLayoutWidget);
        button_LN->setObjectName(QString::fromUtf8("button_LN"));
        sizePolicy1.setHeightForWidth(button_LN->sizePolicy().hasHeightForWidth());
        button_LN->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_LN, 3, 5, 1, 1);

        button_4 = new QPushButton(gridLayoutWidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        sizePolicy1.setHeightForWidth(button_4->sizePolicy().hasHeightForWidth());
        button_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_4, 1, 0, 1, 1);

        button_0 = new QPushButton(gridLayoutWidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));
        sizePolicy1.setHeightForWidth(button_0->sizePolicy().hasHeightForWidth());
        button_0->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_0, 3, 1, 1, 1);

        button_LEFT_BRACKET = new QPushButton(gridLayoutWidget);
        button_LEFT_BRACKET->setObjectName(QString::fromUtf8("button_LEFT_BRACKET"));
        sizePolicy1.setHeightForWidth(button_LEFT_BRACKET->sizePolicy().hasHeightForWidth());
        button_LEFT_BRACKET->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_LEFT_BRACKET, 4, 0, 1, 1);

        button_5 = new QPushButton(gridLayoutWidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        sizePolicy1.setHeightForWidth(button_5->sizePolicy().hasHeightForWidth());
        button_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_5, 1, 1, 1, 1);

        button_DOT = new QPushButton(gridLayoutWidget);
        button_DOT->setObjectName(QString::fromUtf8("button_DOT"));
        sizePolicy1.setHeightForWidth(button_DOT->sizePolicy().hasHeightForWidth());
        button_DOT->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_DOT, 3, 0, 1, 1);

        button_MINUS = new QPushButton(gridLayoutWidget);
        button_MINUS->setObjectName(QString::fromUtf8("button_MINUS"));
        sizePolicy1.setHeightForWidth(button_MINUS->sizePolicy().hasHeightForWidth());
        button_MINUS->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_MINUS, 1, 3, 1, 1);

        button_ACOS = new QPushButton(gridLayoutWidget);
        button_ACOS->setObjectName(QString::fromUtf8("button_ACOS"));
        sizePolicy1.setHeightForWidth(button_ACOS->sizePolicy().hasHeightForWidth());
        button_ACOS->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_ACOS, 2, 4, 1, 1);

        button_BACKSPACE = new QPushButton(gridLayoutWidget);
        button_BACKSPACE->setObjectName(QString::fromUtf8("button_BACKSPACE"));
        sizePolicy1.setHeightForWidth(button_BACKSPACE->sizePolicy().hasHeightForWidth());
        button_BACKSPACE->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_BACKSPACE, 3, 2, 1, 1);

        button_RIGHT_BRACKET = new QPushButton(gridLayoutWidget);
        button_RIGHT_BRACKET->setObjectName(QString::fromUtf8("button_RIGHT_BRACKET"));
        sizePolicy1.setHeightForWidth(button_RIGHT_BRACKET->sizePolicy().hasHeightForWidth());
        button_RIGHT_BRACKET->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_RIGHT_BRACKET, 4, 1, 1, 1);

        button_9 = new QPushButton(gridLayoutWidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));
        sizePolicy1.setHeightForWidth(button_9->sizePolicy().hasHeightForWidth());
        button_9->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_9, 2, 2, 1, 1);

        button_ASIN = new QPushButton(gridLayoutWidget);
        button_ASIN->setObjectName(QString::fromUtf8("button_ASIN"));
        sizePolicy1.setHeightForWidth(button_ASIN->sizePolicy().hasHeightForWidth());
        button_ASIN->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_ASIN, 1, 5, 1, 1);

        button_DIV = new QPushButton(gridLayoutWidget);
        button_DIV->setObjectName(QString::fromUtf8("button_DIV"));
        sizePolicy1.setHeightForWidth(button_DIV->sizePolicy().hasHeightForWidth());
        button_DIV->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_DIV, 3, 3, 1, 1);

        button_7 = new QPushButton(gridLayoutWidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));
        sizePolicy1.setHeightForWidth(button_7->sizePolicy().hasHeightForWidth());
        button_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_7, 2, 0, 1, 1);

        button_COS = new QPushButton(gridLayoutWidget);
        button_COS->setObjectName(QString::fromUtf8("button_COS"));
        sizePolicy1.setHeightForWidth(button_COS->sizePolicy().hasHeightForWidth());
        button_COS->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_COS, 0, 5, 1, 1);

        button_SIN = new QPushButton(gridLayoutWidget);
        button_SIN->setObjectName(QString::fromUtf8("button_SIN"));
        sizePolicy1.setHeightForWidth(button_SIN->sizePolicy().hasHeightForWidth());
        button_SIN->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_SIN, 0, 4, 1, 1);

        button_8 = new QPushButton(gridLayoutWidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));
        sizePolicy1.setHeightForWidth(button_8->sizePolicy().hasHeightForWidth());
        button_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_8, 2, 1, 1, 1);

        button_1 = new QPushButton(gridLayoutWidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));
        sizePolicy1.setHeightForWidth(button_1->sizePolicy().hasHeightForWidth());
        button_1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_1, 0, 0, 1, 1);

        button_POW = new QPushButton(gridLayoutWidget);
        button_POW->setObjectName(QString::fromUtf8("button_POW"));
        sizePolicy1.setHeightForWidth(button_POW->sizePolicy().hasHeightForWidth());
        button_POW->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_POW, 4, 3, 1, 1);

        button_SQRT = new QPushButton(gridLayoutWidget);
        button_SQRT->setObjectName(QString::fromUtf8("button_SQRT"));
        sizePolicy1.setHeightForWidth(button_SQRT->sizePolicy().hasHeightForWidth());
        button_SQRT->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_SQRT, 4, 4, 1, 1);

        button_LOG = new QPushButton(gridLayoutWidget);
        button_LOG->setObjectName(QString::fromUtf8("button_LOG"));
        sizePolicy1.setHeightForWidth(button_LOG->sizePolicy().hasHeightForWidth());
        button_LOG->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_LOG, 4, 5, 1, 1);

        button_MOD = new QPushButton(gridLayoutWidget);
        button_MOD->setObjectName(QString::fromUtf8("button_MOD"));
        sizePolicy1.setHeightForWidth(button_MOD->sizePolicy().hasHeightForWidth());
        button_MOD->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(button_MOD, 3, 4, 1, 1);

        line_edit_X = new QLineEdit(centralwidget);
        line_edit_X->setObjectName(QString::fromUtf8("line_edit_X"));
        line_edit_X->setGeometry(QRect(7, 83, 191, 31));
        QFont font1;
        font1.setBold(true);
        line_edit_X->setFont(font1);
        line_edit_X->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        button_X = new QPushButton(centralwidget);
        button_X->setObjectName(QString::fromUtf8("button_X"));
        button_X->setGeometry(QRect(202, 70, 53, 50));
        button_PI = new QPushButton(centralwidget);
        button_PI->setObjectName(QString::fromUtf8("button_PI"));
        button_PI->setGeometry(QRect(266, 70, 59, 50));
        button_E = new QPushButton(centralwidget);
        button_E->setObjectName(QString::fromUtf8("button_E"));
        button_E->setGeometry(QRect(335, 70, 56, 50));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc_v1.0", nullptr));
        line_edit_EXPRESSION->setText(QString());
        line_edit_EXPRESSION->setPlaceholderText(QString());
        button_GRAPH->setText(QCoreApplication::translate("MainWindow", "GRAPH", nullptr));
        button_CREDIT->setText(QCoreApplication::translate("MainWindow", "CreditCalc", nullptr));
        button_DEPOSIT->setText(QCoreApplication::translate("MainWindow", "DepositCalc", nullptr));
        button_CLEAR_ALL->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button_TOTAL->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        button_ATAN->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        button_PLUS->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button_TAN->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button_MUL->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        button_LN->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_LEFT_BRACKET->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button_DOT->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        button_MINUS->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        button_ACOS->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        button_BACKSPACE->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        button_RIGHT_BRACKET->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button_ASIN->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        button_DIV->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button_COS->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        button_SIN->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_POW->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        button_SQRT->setText(QCoreApplication::translate("MainWindow", "\342\210\232 ", nullptr));
        button_LOG->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        button_MOD->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        line_edit_X->setText(QString());
        button_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        button_PI->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
        button_E->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

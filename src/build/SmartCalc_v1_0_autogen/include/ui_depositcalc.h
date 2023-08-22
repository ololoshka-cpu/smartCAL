/********************************************************************************
** Form generated from reading UI file 'depositcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITCALC_H
#define UI_DEPOSITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositCalc
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QDateEdit *changeDate;
    QDoubleSpinBox *taxRate;
    QLabel *label_3;
    QLabel *totalDeposit;
    QPushButton *addAddition;
    QPushButton *calculate;
    QLineEdit *depositLine;
    QLineEdit *changeSum;
    QLabel *label_2;
    QLabel *label_7;
    QRadioButton *capitalisation;
    QPushButton *addPayment;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *totalPercents;
    QLabel *label;
    QComboBox *period;
    QLabel *label_9;
    QLabel *totalTax;
    QDoubleSpinBox *depositRate;
    QSpinBox *months;
    QTableWidget *tablePayments;
    QTableWidget *tableAdditions;
    QTableWidget *tableReport;

    void setupUi(QDialog *DepositCalc)
    {
        if (DepositCalc->objectName().isEmpty())
            DepositCalc->setObjectName(QString::fromUtf8("DepositCalc"));
        DepositCalc->resize(900, 700);
        DepositCalc->setMinimumSize(QSize(900, 700));
        DepositCalc->setMaximumSize(QSize(900, 700));
        gridLayoutWidget = new QWidget(DepositCalc);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 311, 701));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        changeDate = new QDateEdit(gridLayoutWidget);
        changeDate->setObjectName(QString::fromUtf8("changeDate"));

        gridLayout->addWidget(changeDate, 6, 1, 1, 1);

        taxRate = new QDoubleSpinBox(gridLayoutWidget);
        taxRate->setObjectName(QString::fromUtf8("taxRate"));
        taxRate->setMaximum(50.000000000000000);
        taxRate->setSingleStep(0.100000000000000);
        taxRate->setValue(8.500000000000000);

        gridLayout->addWidget(taxRate, 3, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        totalDeposit = new QLabel(gridLayoutWidget);
        totalDeposit->setObjectName(QString::fromUtf8("totalDeposit"));

        gridLayout->addWidget(totalDeposit, 11, 1, 1, 1);

        addAddition = new QPushButton(gridLayoutWidget);
        addAddition->setObjectName(QString::fromUtf8("addAddition"));

        gridLayout->addWidget(addAddition, 7, 1, 1, 1);

        calculate = new QPushButton(gridLayoutWidget);
        calculate->setObjectName(QString::fromUtf8("calculate"));

        gridLayout->addWidget(calculate, 8, 1, 1, 1);

        depositLine = new QLineEdit(gridLayoutWidget);
        depositLine->setObjectName(QString::fromUtf8("depositLine"));

        gridLayout->addWidget(depositLine, 0, 1, 1, 1);

        changeSum = new QLineEdit(gridLayoutWidget);
        changeSum->setObjectName(QString::fromUtf8("changeSum"));

        gridLayout->addWidget(changeSum, 6, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        capitalisation = new QRadioButton(gridLayoutWidget);
        capitalisation->setObjectName(QString::fromUtf8("capitalisation"));

        gridLayout->addWidget(capitalisation, 5, 1, 1, 1);

        addPayment = new QPushButton(gridLayoutWidget);
        addPayment->setObjectName(QString::fromUtf8("addPayment"));

        gridLayout->addWidget(addPayment, 7, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        totalPercents = new QLabel(gridLayoutWidget);
        totalPercents->setObjectName(QString::fromUtf8("totalPercents"));

        gridLayout->addWidget(totalPercents, 9, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        period = new QComboBox(gridLayoutWidget);
        period->addItem(QString());
        period->addItem(QString());
        period->addItem(QString());
        period->setObjectName(QString::fromUtf8("period"));

        gridLayout->addWidget(period, 4, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 11, 0, 1, 1);

        totalTax = new QLabel(gridLayoutWidget);
        totalTax->setObjectName(QString::fromUtf8("totalTax"));

        gridLayout->addWidget(totalTax, 10, 1, 1, 1);

        depositRate = new QDoubleSpinBox(gridLayoutWidget);
        depositRate->setObjectName(QString::fromUtf8("depositRate"));
        depositRate->setMaximum(50.000000000000000);
        depositRate->setSingleStep(0.100000000000000);
        depositRate->setValue(5.000000000000000);

        gridLayout->addWidget(depositRate, 2, 1, 1, 1);

        months = new QSpinBox(gridLayoutWidget);
        months->setObjectName(QString::fromUtf8("months"));
        months->setMinimum(1);
        months->setMaximum(360);
        months->setValue(12);

        gridLayout->addWidget(months, 1, 1, 1, 1);

        tablePayments = new QTableWidget(DepositCalc);
        tablePayments->setObjectName(QString::fromUtf8("tablePayments"));
        tablePayments->setGeometry(QRect(320, 0, 291, 411));
        tableAdditions = new QTableWidget(DepositCalc);
        tableAdditions->setObjectName(QString::fromUtf8("tableAdditions"));
        tableAdditions->setGeometry(QRect(610, 0, 291, 411));
        tableReport = new QTableWidget(DepositCalc);
        tableReport->setObjectName(QString::fromUtf8("tableReport"));
        tableReport->setGeometry(QRect(320, 410, 581, 291));

        retranslateUi(DepositCalc);

        QMetaObject::connectSlotsByName(DepositCalc);
    } // setupUi

    void retranslateUi(QDialog *DepositCalc)
    {
        DepositCalc->setWindowTitle(QCoreApplication::translate("DepositCalc", "Dialog", nullptr));
        label_8->setText(QCoreApplication::translate("DepositCalc", "Total tax", nullptr));
        label_3->setText(QCoreApplication::translate("DepositCalc", "Deposit rate", nullptr));
        totalDeposit->setText(QString());
        addAddition->setText(QCoreApplication::translate("DepositCalc", "Add addition", nullptr));
        calculate->setText(QCoreApplication::translate("DepositCalc", "Calculate deposit", nullptr));
        depositLine->setText(QCoreApplication::translate("DepositCalc", "1000000", nullptr));
        changeSum->setText(QCoreApplication::translate("DepositCalc", "10000", nullptr));
        label_2->setText(QCoreApplication::translate("DepositCalc", "Term, month", nullptr));
        label_7->setText(QCoreApplication::translate("DepositCalc", "Total percents", nullptr));
        capitalisation->setText(QCoreApplication::translate("DepositCalc", "capitalisation", nullptr));
        addPayment->setText(QCoreApplication::translate("DepositCalc", "Add payment", nullptr));
        label_4->setText(QCoreApplication::translate("DepositCalc", "Tax rate", nullptr));
        label_5->setText(QCoreApplication::translate("DepositCalc", "Payments period", nullptr));
        totalPercents->setText(QString());
        label->setText(QCoreApplication::translate("DepositCalc", "Deposit", nullptr));
        period->setItemText(0, QCoreApplication::translate("DepositCalc", "Every day", nullptr));
        period->setItemText(1, QCoreApplication::translate("DepositCalc", "Every month", nullptr));
        period->setItemText(2, QCoreApplication::translate("DepositCalc", "Every year", nullptr));

        label_9->setText(QCoreApplication::translate("DepositCalc", "Total deposit", nullptr));
        totalTax->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DepositCalc: public Ui_DepositCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITCALC_H

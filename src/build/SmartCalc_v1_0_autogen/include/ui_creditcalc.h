/********************************************************************************
** Form generated from reading UI file 'creditcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITCALC_H
#define UI_CREDITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CreditCalc
{
public:
    QLineEdit *creditSum;
    QLabel *label;
    QSpinBox *term;
    QLabel *label_2;
    QDoubleSpinBox *rate;
    QLabel *label_3;
    QRadioButton *differential;
    QRadioButton *annuitial;
    QPushButton *pushButton;
    QLabel *monthlyPayment;
    QLabel *label_5;
    QLabel *Overpayment;
    QLabel *totalPayments;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;

    void setupUi(QDialog *CreditCalc)
    {
        if (CreditCalc->objectName().isEmpty())
            CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
        CreditCalc->resize(300, 600);
        CreditCalc->setMinimumSize(QSize(300, 600));
        CreditCalc->setMaximumSize(QSize(700, 600));
        creditSum = new QLineEdit(CreditCalc);
        creditSum->setObjectName(QString::fromUtf8("creditSum"));
        creditSum->setGeometry(QRect(130, 51, 111, 21));
        label = new QLabel(CreditCalc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(12, 51, 37, 16));
        term = new QSpinBox(CreditCalc);
        term->setObjectName(QString::fromUtf8("term"));
        term->setGeometry(QRect(130, 121, 111, 21));
        term->setMaximum(360);
        term->setValue(12);
        label_2 = new QLabel(CreditCalc);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(12, 121, 91, 16));
        rate = new QDoubleSpinBox(CreditCalc);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setGeometry(QRect(130, 191, 111, 21));
        rate->setMaximum(50.000000000000000);
        rate->setSingleStep(0.100000000000000);
        rate->setValue(12.500000000000000);
        label_3 = new QLabel(CreditCalc);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 191, 27, 16));
        differential = new QRadioButton(CreditCalc);
        differential->setObjectName(QString::fromUtf8("differential"));
        differential->setGeometry(QRect(150, 260, 89, 20));
        annuitial = new QRadioButton(CreditCalc);
        annuitial->setObjectName(QString::fromUtf8("annuitial"));
        annuitial->setGeometry(QRect(10, 260, 83, 20));
        pushButton = new QPushButton(CreditCalc);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 320, 86, 32));
        monthlyPayment = new QLabel(CreditCalc);
        monthlyPayment->setObjectName(QString::fromUtf8("monthlyPayment"));
        monthlyPayment->setGeometry(QRect(130, 401, 121, 16));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monthlyPayment->sizePolicy().hasHeightForWidth());
        monthlyPayment->setSizePolicy(sizePolicy);
        label_5 = new QLabel(CreditCalc);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(12, 401, 104, 16));
        Overpayment = new QLabel(CreditCalc);
        Overpayment->setObjectName(QString::fromUtf8("Overpayment"));
        Overpayment->setGeometry(QRect(130, 466, 244, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Overpayment->sizePolicy().hasHeightForWidth());
        Overpayment->setSizePolicy(sizePolicy1);
        totalPayments = new QLabel(CreditCalc);
        totalPayments->setObjectName(QString::fromUtf8("totalPayments"));
        totalPayments->setGeometry(QRect(130, 531, 244, 16));
        sizePolicy1.setHeightForWidth(totalPayments->sizePolicy().hasHeightForWidth());
        totalPayments->setSizePolicy(sizePolicy1);
        label_8 = new QLabel(CreditCalc);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(12, 466, 81, 16));
        label_9 = new QLabel(CreditCalc);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(12, 531, 91, 16));
        label_11 = new QLabel(CreditCalc);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(388, 466, 16, 16));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        retranslateUi(CreditCalc);

        QMetaObject::connectSlotsByName(CreditCalc);
    } // setupUi

    void retranslateUi(QDialog *CreditCalc)
    {
        CreditCalc->setWindowTitle(QCoreApplication::translate("CreditCalc", "Dialog", nullptr));
        creditSum->setText(QCoreApplication::translate("CreditCalc", "1000000", nullptr));
        label->setText(QCoreApplication::translate("CreditCalc", "Credit", nullptr));
        label_2->setText(QCoreApplication::translate("CreditCalc", "Term, month", nullptr));
        label_3->setText(QCoreApplication::translate("CreditCalc", "Rate", nullptr));
        differential->setText(QCoreApplication::translate("CreditCalc", "differential", nullptr));
        annuitial->setText(QCoreApplication::translate("CreditCalc", "annuititial", nullptr));
        pushButton->setText(QCoreApplication::translate("CreditCalc", "Calculate", nullptr));
        monthlyPayment->setText(QString());
        label_5->setText(QCoreApplication::translate("CreditCalc", "Monthly payment", nullptr));
        Overpayment->setText(QString());
        totalPayments->setText(QString());
        label_8->setText(QCoreApplication::translate("CreditCalc", "Overpayment", nullptr));
        label_9->setText(QCoreApplication::translate("CreditCalc", "Total payments", nullptr));
        label_11->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreditCalc: public Ui_CreditCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITCALC_H

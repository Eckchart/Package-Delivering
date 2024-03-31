/********************************************************************************
** Form generated from reading UI file 'courier_company_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIER_COMPANY_WINDOW_H
#define UI_COURIER_COMPANY_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_courier_company_window
{
public:
    QVBoxLayout *verticalLayout_2;
    QListWidget *packagesListWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *recipientLabel;
    QLineEdit *recipientLineEdit;
    QLabel *streetLabel;
    QLineEdit *streetLineEdit;
    QLabel *streetNrLabel;
    QLineEdit *streetNrLineEdit;
    QLabel *xLocLabel;
    QLineEdit *xLocLineEdit;
    QLabel *yLocLabel;
    QLineEdit *yLocLineEdit;
    QPushButton *addPushButton;

    void setupUi(QWidget *courier_company_window)
    {
        if (courier_company_window->objectName().isEmpty())
            courier_company_window->setObjectName("courier_company_window");
        courier_company_window->resize(594, 455);
        verticalLayout_2 = new QVBoxLayout(courier_company_window);
        verticalLayout_2->setObjectName("verticalLayout_2");
        packagesListWidget = new QListWidget(courier_company_window);
        packagesListWidget->setObjectName("packagesListWidget");

        verticalLayout_2->addWidget(packagesListWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        recipientLabel = new QLabel(courier_company_window);
        recipientLabel->setObjectName("recipientLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, recipientLabel);

        recipientLineEdit = new QLineEdit(courier_company_window);
        recipientLineEdit->setObjectName("recipientLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, recipientLineEdit);

        streetLabel = new QLabel(courier_company_window);
        streetLabel->setObjectName("streetLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, streetLabel);

        streetLineEdit = new QLineEdit(courier_company_window);
        streetLineEdit->setObjectName("streetLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, streetLineEdit);

        streetNrLabel = new QLabel(courier_company_window);
        streetNrLabel->setObjectName("streetNrLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, streetNrLabel);

        streetNrLineEdit = new QLineEdit(courier_company_window);
        streetNrLineEdit->setObjectName("streetNrLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, streetNrLineEdit);

        xLocLabel = new QLabel(courier_company_window);
        xLocLabel->setObjectName("xLocLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, xLocLabel);

        xLocLineEdit = new QLineEdit(courier_company_window);
        xLocLineEdit->setObjectName("xLocLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, xLocLineEdit);

        yLocLabel = new QLabel(courier_company_window);
        yLocLabel->setObjectName("yLocLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, yLocLabel);

        yLocLineEdit = new QLineEdit(courier_company_window);
        yLocLineEdit->setObjectName("yLocLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, yLocLineEdit);


        verticalLayout->addLayout(formLayout);

        addPushButton = new QPushButton(courier_company_window);
        addPushButton->setObjectName("addPushButton");

        verticalLayout->addWidget(addPushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(courier_company_window);

        QMetaObject::connectSlotsByName(courier_company_window);
    } // setupUi

    void retranslateUi(QWidget *courier_company_window)
    {
        courier_company_window->setWindowTitle(QCoreApplication::translate("courier_company_window", "Form", nullptr));
        recipientLabel->setText(QCoreApplication::translate("courier_company_window", "Recipient:", nullptr));
        streetLabel->setText(QCoreApplication::translate("courier_company_window", "Street:", nullptr));
        streetNrLabel->setText(QCoreApplication::translate("courier_company_window", "Street number:", nullptr));
        xLocLabel->setText(QCoreApplication::translate("courier_company_window", "X Location:", nullptr));
        yLocLabel->setText(QCoreApplication::translate("courier_company_window", "Y Location:", nullptr));
        addPushButton->setText(QCoreApplication::translate("courier_company_window", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class courier_company_window: public Ui_courier_company_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIER_COMPANY_WINDOW_H

/********************************************************************************
** Form generated from reading UI file 'courier_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIER_WINDOW_H
#define UI_COURIER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_courier_window
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *packagesListWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *zoneLabel;
    QLineEdit *zoneLineEdit;
    QPushButton *deliverPushButton;
    QComboBox *streetsComboBox;

    void setupUi(QWidget *courier_window)
    {
        if (courier_window->objectName().isEmpty())
            courier_window->setObjectName("courier_window");
        courier_window->resize(535, 356);
        verticalLayout = new QVBoxLayout(courier_window);
        verticalLayout->setObjectName("verticalLayout");
        packagesListWidget = new QListWidget(courier_window);
        packagesListWidget->setObjectName("packagesListWidget");

        verticalLayout->addWidget(packagesListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        zoneLabel = new QLabel(courier_window);
        zoneLabel->setObjectName("zoneLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, zoneLabel);

        zoneLineEdit = new QLineEdit(courier_window);
        zoneLineEdit->setObjectName("zoneLineEdit");
        zoneLineEdit->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, zoneLineEdit);


        horizontalLayout->addLayout(formLayout);

        deliverPushButton = new QPushButton(courier_window);
        deliverPushButton->setObjectName("deliverPushButton");

        horizontalLayout->addWidget(deliverPushButton);

        streetsComboBox = new QComboBox(courier_window);
        streetsComboBox->setObjectName("streetsComboBox");

        horizontalLayout->addWidget(streetsComboBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(courier_window);

        QMetaObject::connectSlotsByName(courier_window);
    } // setupUi

    void retranslateUi(QWidget *courier_window)
    {
        courier_window->setWindowTitle(QCoreApplication::translate("courier_window", "Form", nullptr));
        zoneLabel->setText(QCoreApplication::translate("courier_window", "Zone:", nullptr));
        deliverPushButton->setText(QCoreApplication::translate("courier_window", "Deliver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class courier_window: public Ui_courier_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIER_WINDOW_H

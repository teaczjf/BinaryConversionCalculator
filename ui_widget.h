/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_11;
    QLineEdit *lineEdit_DEC;
    QPushButton *pushButton_DEC;
    QLabel *label_19;
    QLineEdit *lineEdit_HEX4;
    QPushButton *pushButton_HEX4;
    QLabel *label_18;
    QLineEdit *lineEdit_HEX8;
    QPushButton *pushButton_HEX8;
    QLabel *label_16;
    QLineEdit *lineEdit_HEX16;
    QPushButton *pushButton_HEX16;
    QLabel *label_17;
    QLineEdit *lineEdit_HEX32;
    QPushButton *pushButton_HEX32;
    QLabel *label_12;
    QLineEdit *lineEdit_HEX64;
    QPushButton *pushButton_HEX64;
    QLabel *label_13;
    QLineEdit *lineEdit_FLOAT;
    QPushButton *pushButton_FLOAT;
    QLabel *label_14;
    QLineEdit *lineEdit_DOUBLE;
    QPushButton *pushButton_DOUBLE;
    QLabel *label_15;
    QLineEdit *lineEdit_BIN;
    QPushButton *pushButton_BIN;
    QRadioButton *radbtn_int;
    QRadioButton *radbtn_uint;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(825, 321);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 0, 0, 1, 1);

        lineEdit_DEC = new QLineEdit(Widget);
        lineEdit_DEC->setObjectName(QStringLiteral("lineEdit_DEC"));

        gridLayout->addWidget(lineEdit_DEC, 0, 1, 1, 1);

        pushButton_DEC = new QPushButton(Widget);
        pushButton_DEC->setObjectName(QStringLiteral("pushButton_DEC"));

        gridLayout->addWidget(pushButton_DEC, 0, 2, 1, 1);

        label_19 = new QLabel(Widget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 1, 0, 1, 1);

        lineEdit_HEX4 = new QLineEdit(Widget);
        lineEdit_HEX4->setObjectName(QStringLiteral("lineEdit_HEX4"));
        lineEdit_HEX4->setMaxLength(1);

        gridLayout->addWidget(lineEdit_HEX4, 1, 1, 1, 1);

        pushButton_HEX4 = new QPushButton(Widget);
        pushButton_HEX4->setObjectName(QStringLiteral("pushButton_HEX4"));

        gridLayout->addWidget(pushButton_HEX4, 1, 2, 1, 1);

        label_18 = new QLabel(Widget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 2, 0, 1, 1);

        lineEdit_HEX8 = new QLineEdit(Widget);
        lineEdit_HEX8->setObjectName(QStringLiteral("lineEdit_HEX8"));
        lineEdit_HEX8->setMaxLength(2);

        gridLayout->addWidget(lineEdit_HEX8, 2, 1, 1, 1);

        pushButton_HEX8 = new QPushButton(Widget);
        pushButton_HEX8->setObjectName(QStringLiteral("pushButton_HEX8"));

        gridLayout->addWidget(pushButton_HEX8, 2, 2, 1, 1);

        label_16 = new QLabel(Widget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 3, 0, 1, 1);

        lineEdit_HEX16 = new QLineEdit(Widget);
        lineEdit_HEX16->setObjectName(QStringLiteral("lineEdit_HEX16"));
        lineEdit_HEX16->setMaxLength(4);

        gridLayout->addWidget(lineEdit_HEX16, 3, 1, 1, 1);

        pushButton_HEX16 = new QPushButton(Widget);
        pushButton_HEX16->setObjectName(QStringLiteral("pushButton_HEX16"));

        gridLayout->addWidget(pushButton_HEX16, 3, 2, 1, 1);

        label_17 = new QLabel(Widget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 4, 0, 1, 1);

        lineEdit_HEX32 = new QLineEdit(Widget);
        lineEdit_HEX32->setObjectName(QStringLiteral("lineEdit_HEX32"));
        lineEdit_HEX32->setMaxLength(8);

        gridLayout->addWidget(lineEdit_HEX32, 4, 1, 1, 1);

        pushButton_HEX32 = new QPushButton(Widget);
        pushButton_HEX32->setObjectName(QStringLiteral("pushButton_HEX32"));

        gridLayout->addWidget(pushButton_HEX32, 4, 2, 1, 1);

        label_12 = new QLabel(Widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 5, 0, 1, 1);

        lineEdit_HEX64 = new QLineEdit(Widget);
        lineEdit_HEX64->setObjectName(QStringLiteral("lineEdit_HEX64"));
        lineEdit_HEX64->setMaxLength(16);

        gridLayout->addWidget(lineEdit_HEX64, 5, 1, 1, 1);

        pushButton_HEX64 = new QPushButton(Widget);
        pushButton_HEX64->setObjectName(QStringLiteral("pushButton_HEX64"));

        gridLayout->addWidget(pushButton_HEX64, 5, 2, 1, 1);

        label_13 = new QLabel(Widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        lineEdit_FLOAT = new QLineEdit(Widget);
        lineEdit_FLOAT->setObjectName(QStringLiteral("lineEdit_FLOAT"));

        gridLayout->addWidget(lineEdit_FLOAT, 6, 1, 1, 1);

        pushButton_FLOAT = new QPushButton(Widget);
        pushButton_FLOAT->setObjectName(QStringLiteral("pushButton_FLOAT"));

        gridLayout->addWidget(pushButton_FLOAT, 6, 2, 1, 1);

        label_14 = new QLabel(Widget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        lineEdit_DOUBLE = new QLineEdit(Widget);
        lineEdit_DOUBLE->setObjectName(QStringLiteral("lineEdit_DOUBLE"));

        gridLayout->addWidget(lineEdit_DOUBLE, 7, 1, 1, 1);

        pushButton_DOUBLE = new QPushButton(Widget);
        pushButton_DOUBLE->setObjectName(QStringLiteral("pushButton_DOUBLE"));

        gridLayout->addWidget(pushButton_DOUBLE, 7, 2, 1, 1);

        label_15 = new QLabel(Widget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 8, 0, 1, 1);

        lineEdit_BIN = new QLineEdit(Widget);
        lineEdit_BIN->setObjectName(QStringLiteral("lineEdit_BIN"));
        lineEdit_BIN->setMaxLength(64);

        gridLayout->addWidget(lineEdit_BIN, 8, 1, 1, 1);

        pushButton_BIN = new QPushButton(Widget);
        pushButton_BIN->setObjectName(QStringLiteral("pushButton_BIN"));

        gridLayout->addWidget(pushButton_BIN, 8, 2, 1, 1);

        radbtn_int = new QRadioButton(Widget);
        radbtn_int->setObjectName(QStringLiteral("radbtn_int"));

        gridLayout->addWidget(radbtn_int, 9, 0, 1, 1);

        radbtn_uint = new QRadioButton(Widget);
        radbtn_uint->setObjectName(QStringLiteral("radbtn_uint"));

        gridLayout->addWidget(radbtn_uint, 9, 1, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 10, 0, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "DEC:", Q_NULLPTR));
        pushButton_DEC->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_19->setText(QApplication::translate("Widget", "HEX(4b):", Q_NULLPTR));
        pushButton_HEX4->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_18->setText(QApplication::translate("Widget", "HEX(8b):", Q_NULLPTR));
        pushButton_HEX8->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "HEX(16b):", Q_NULLPTR));
        pushButton_HEX16->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_17->setText(QApplication::translate("Widget", "HEX(32b):", Q_NULLPTR));
        pushButton_HEX32->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "HEX(64b):", Q_NULLPTR));
        pushButton_HEX64->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "FLOAT:", Q_NULLPTR));
        pushButton_FLOAT->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "DOUBLE:", Q_NULLPTR));
        pushButton_DOUBLE->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "BIN:", Q_NULLPTR));
        pushButton_BIN->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", Q_NULLPTR));
        radbtn_int->setText(QApplication::translate("Widget", "\346\234\211\347\254\246\345\217\267", Q_NULLPTR));
        radbtn_uint->setText(QApplication::translate("Widget", "\346\227\240\347\254\246\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "FLOAT DOUBLE \345\217\252\346\234\211\346\234\211\347\254\246\345\217\267\345\244\204\347\220\206  BIN\345\217\252\345\275\223\346\227\240\347\254\246\345\217\267\345\244\204\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

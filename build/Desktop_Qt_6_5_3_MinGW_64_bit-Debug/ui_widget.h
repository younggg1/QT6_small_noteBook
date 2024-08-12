/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mytextedit.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widgetButtons;
    QWidget *layoutWidget1;
    QHBoxLayout *hlLayoutButtons;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;
    MyTextEdit *textEdit;
    QWidget *widgetBottom;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelPosition;
    QLabel *labelCode;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 589);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("\350\256\260\344\272\213\346\234\254");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(-10, -10, 811, 601));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetButtons = new QWidget(layoutWidget);
        widgetButtons->setObjectName("widgetButtons");
        widgetButtons->setMinimumSize(QSize(0, 70));
        widgetButtons->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 243, 255);"));
        layoutWidget1 = new QWidget(widgetButtons);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 381, 52));
        hlLayoutButtons = new QHBoxLayout(layoutWidget1);
        hlLayoutButtons->setObjectName("hlLayoutButtons");
        hlLayoutButtons->setContentsMargins(0, 0, 0, 0);
        btnOpen = new QPushButton(layoutWidget1);
        btnOpen->setObjectName("btnOpen");
        btnOpen->setEnabled(true);
        btnOpen->setMinimumSize(QSize(50, 50));
        btnOpen->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/open.png);"));

        hlLayoutButtons->addWidget(btnOpen, 0, Qt::AlignVCenter);

        btnSave = new QPushButton(layoutWidget1);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumSize(QSize(50, 50));
        btnSave->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/save.png);"));

        hlLayoutButtons->addWidget(btnSave, 0, Qt::AlignVCenter);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(50, 50));
        btnClose->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/close.png);"));

        hlLayoutButtons->addWidget(btnClose);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlLayoutButtons->addItem(horizontalSpacer);


        verticalLayout->addWidget(widgetButtons);

        textEdit = new MyTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout->addWidget(textEdit);

        widgetBottom = new QWidget(layoutWidget);
        widgetBottom->setObjectName("widgetBottom");
        widgetBottom->setMinimumSize(QSize(0, 50));
        widgetBottom->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 243, 255);"));
        layoutWidget2 = new QWidget(widgetBottom);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 10, 801, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelPosition = new QLabel(layoutWidget2);
        labelPosition->setObjectName("labelPosition");

        horizontalLayout->addWidget(labelPosition);

        labelCode = new QLabel(layoutWidget2);
        labelCode->setObjectName("labelCode");

        horizontalLayout->addWidget(labelCode);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widgetBottom);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "YZH\350\256\260\344\272\213\346\234\254", nullptr));
        btnOpen->setText(QString());
        btnSave->setText(QString());
        btnClose->setText(QString());
        labelPosition->setText(QCoreApplication::translate("Widget", "\347\254\2541\350\241\214\347\254\2541\345\210\227", nullptr));
        labelCode->setText(QCoreApplication::translate("Widget", "UTF-8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

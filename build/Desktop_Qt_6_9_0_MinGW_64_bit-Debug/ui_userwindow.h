/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QPushButton *ADD_BUTTON;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *EDIT_BUTTON;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *DELETE_BUTTON;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *GET_BUTTON;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QPushButton *RESERVE_BUTTON;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QPushButton *SEARCH_BUTTON;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(480, 359);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 10, 261, 291));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        ADD_BUTTON = new QPushButton(layoutWidget);
        ADD_BUTTON->setObjectName("ADD_BUTTON");

        horizontalLayout_6->addWidget(ADD_BUTTON);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        EDIT_BUTTON = new QPushButton(layoutWidget);
        EDIT_BUTTON->setObjectName("EDIT_BUTTON");

        horizontalLayout_2->addWidget(EDIT_BUTTON);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        DELETE_BUTTON = new QPushButton(layoutWidget);
        DELETE_BUTTON->setObjectName("DELETE_BUTTON");

        horizontalLayout_4->addWidget(DELETE_BUTTON);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        GET_BUTTON = new QPushButton(layoutWidget);
        GET_BUTTON->setObjectName("GET_BUTTON");

        horizontalLayout_3->addWidget(GET_BUTTON);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        RESERVE_BUTTON = new QPushButton(layoutWidget);
        RESERVE_BUTTON->setObjectName("RESERVE_BUTTON");

        horizontalLayout_5->addWidget(RESERVE_BUTTON);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        SEARCH_BUTTON = new QPushButton(layoutWidget);
        SEARCH_BUTTON->setObjectName("SEARCH_BUTTON");

        horizontalLayout_7->addWidget(SEARCH_BUTTON);


        verticalLayout->addLayout(horizontalLayout_7);

        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 480, 18));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName("statusbar");
        UserWindow->setStatusBar(statusbar);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("UserWindow", "ADD BOOK", nullptr));
        ADD_BUTTON->setText(QCoreApplication::translate("UserWindow", "ADD", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "EDIT BOOK", nullptr));
        EDIT_BUTTON->setText(QCoreApplication::translate("UserWindow", "EDIT", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindow", "DELETE BOOK", nullptr));
        DELETE_BUTTON->setText(QCoreApplication::translate("UserWindow", "DELETE", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindow", "GET BOOK", nullptr));
        GET_BUTTON->setText(QCoreApplication::translate("UserWindow", "GET", nullptr));
        label_5->setText(QCoreApplication::translate("UserWindow", "RESERVE BOOK", nullptr));
        RESERVE_BUTTON->setText(QCoreApplication::translate("UserWindow", "RESERVE", nullptr));
        label_7->setText(QCoreApplication::translate("UserWindow", "SEARCH FOR BOOK", nullptr));
        SEARCH_BUTTON->setText(QCoreApplication::translate("UserWindow", "SEARCH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'user_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_WINDOW_H
#define UI_USER_WINDOW_H

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

class Ui_User_Window
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QPushButton *ADD_BUTTON;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *EDIT_BUTTON;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *DELETE_BUTTON;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *GET_BUTTON;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *RESERVE_BUTTON;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QPushButton *SEARCH_BUTTON;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *User_Window)
    {
        if (User_Window->objectName().isEmpty())
            User_Window->setObjectName("User_Window");
        User_Window->resize(480, 359);
        centralwidget = new QWidget(User_Window);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(36, 10, 261, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        ADD_BUTTON = new QPushButton(widget);
        ADD_BUTTON->setObjectName("ADD_BUTTON");

        horizontalLayout_6->addWidget(ADD_BUTTON);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        EDIT_BUTTON = new QPushButton(widget);
        EDIT_BUTTON->setObjectName("EDIT_BUTTON");

        horizontalLayout->addWidget(EDIT_BUTTON);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        DELETE_BUTTON = new QPushButton(widget);
        DELETE_BUTTON->setObjectName("DELETE_BUTTON");

        horizontalLayout_4->addWidget(DELETE_BUTTON);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        GET_BUTTON = new QPushButton(widget);
        GET_BUTTON->setObjectName("GET_BUTTON");

        horizontalLayout_3->addWidget(GET_BUTTON);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        RESERVE_BUTTON = new QPushButton(widget);
        RESERVE_BUTTON->setObjectName("RESERVE_BUTTON");

        horizontalLayout_2->addWidget(RESERVE_BUTTON);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        SEARCH_BUTTON = new QPushButton(widget);
        SEARCH_BUTTON->setObjectName("SEARCH_BUTTON");

        horizontalLayout_5->addWidget(SEARCH_BUTTON);


        verticalLayout->addLayout(horizontalLayout_5);

        User_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(User_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 480, 18));
        User_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(User_Window);
        statusbar->setObjectName("statusbar");
        User_Window->setStatusBar(statusbar);

        retranslateUi(User_Window);

        QMetaObject::connectSlotsByName(User_Window);
    } // setupUi

    void retranslateUi(QMainWindow *User_Window)
    {
        User_Window->setWindowTitle(QCoreApplication::translate("User_Window", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("User_Window", "ADD BOOK", nullptr));
        ADD_BUTTON->setText(QCoreApplication::translate("User_Window", "ADD", nullptr));
        label->setText(QCoreApplication::translate("User_Window", "EDIT BOOK", nullptr));
        EDIT_BUTTON->setText(QCoreApplication::translate("User_Window", "EDIT", nullptr));
        label_4->setText(QCoreApplication::translate("User_Window", "DELETE BOOK", nullptr));
        DELETE_BUTTON->setText(QCoreApplication::translate("User_Window", "DELETE", nullptr));
        label_3->setText(QCoreApplication::translate("User_Window", "GET BOOK", nullptr));
        GET_BUTTON->setText(QCoreApplication::translate("User_Window", "GET", nullptr));
        label_2->setText(QCoreApplication::translate("User_Window", "RESERVE BOOK", nullptr));
        RESERVE_BUTTON->setText(QCoreApplication::translate("User_Window", "RESERVE", nullptr));
        label_5->setText(QCoreApplication::translate("User_Window", "SEARCH FOR BOOK", nullptr));
        SEARCH_BUTTON->setText(QCoreApplication::translate("User_Window", "SEARCH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_Window: public Ui_User_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_WINDOW_H

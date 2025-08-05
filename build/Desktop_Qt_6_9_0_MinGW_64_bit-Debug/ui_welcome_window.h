/********************************************************************************
** Form generated from reading UI file 'welcome_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_WINDOW_H
#define UI_WELCOME_WINDOW_H

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

class Ui_Welcome_Window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainVerticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *buttonLayout;
    QPushButton *Sign_in_button;
    QPushButton *Login_in_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Welcome_Window)
    {
        if (Welcome_Window->objectName().isEmpty())
            Welcome_Window->setObjectName("Welcome_Window");
        Welcome_Window->resize(480, 359);
        centralwidget = new QWidget(Welcome_Window);
        centralwidget->setObjectName("centralwidget");
        mainVerticalLayout = new QVBoxLayout(centralwidget);
        mainVerticalLayout->setObjectName("mainVerticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString::fromUtf8("font: 900 20pt 'Segoe UI'; color: #22223b;"));

        mainVerticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        mainVerticalLayout->addWidget(label_2);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        Sign_in_button = new QPushButton(centralwidget);
        Sign_in_button->setObjectName("Sign_in_button");

        buttonLayout->addWidget(Sign_in_button);

        Login_in_button = new QPushButton(centralwidget);
        Login_in_button->setObjectName("Login_in_button");

        buttonLayout->addWidget(Login_in_button);


        mainVerticalLayout->addLayout(buttonLayout);

        Welcome_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Welcome_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 480, 18));
        Welcome_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Welcome_Window);
        statusbar->setObjectName("statusbar");
        Welcome_Window->setStatusBar(statusbar);

        retranslateUi(Welcome_Window);

        QMetaObject::connectSlotsByName(Welcome_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Welcome_Window)
    {
        Welcome_Window->setWindowTitle(QCoreApplication::translate("Welcome_Window", "Welcome Page", nullptr));
        label->setText(QCoreApplication::translate("Welcome_Window", "WELCOME TO YOUR LIBRARY MANAGEMENT SYSTEM", nullptr));
        label_2->setText(QCoreApplication::translate("Welcome_Window", "please chose : ", nullptr));
        Sign_in_button->setText(QCoreApplication::translate("Welcome_Window", "Sign In", nullptr));
        Login_in_button->setText(QCoreApplication::translate("Welcome_Window", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome_Window: public Ui_Welcome_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_WINDOW_H

/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *GoToSignUpButton;
    QLabel *label_2;
    QPushButton *LogInButton;
    QLabel *label_5;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *FirstNameEdit;
    QLineEdit *LastNameEdit;
    QLineEdit *ID_Edit;
    QLineEdit *PasswordEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->setWindowModality(Qt::WindowModality::NonModal);
        LoginWindow->resize(500, 380);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Fluent Icons")});
        font.setPointSize(12);
        font.setStrikeOut(false);
        font.setKerning(false);
        LoginWindow->setFont(font);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background-color: rgb(255, 255, 255)\n"
";\n"
"}"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(249, -7, 250, 351));
        frame->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgb(139, 94, 60);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 225, 111, 21));
        QFont font1;
        font1.setPointSize(8);
        font1.setItalic(true);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:white;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 80, 181, 91));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Frame 245.png")));
        label_4->setScaledContents(true);
        GoToSignUpButton = new QPushButton(frame);
        GoToSignUpButton->setObjectName("GoToSignUpButton");
        GoToSignUpButton->setGeometry(QRect(50, 250, 161, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setBold(true);
        font2.setItalic(true);
        font2.setKerning(false);
        GoToSignUpButton->setFont(font2);
        GoToSignUpButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #6A442B; /* Brown color */\n"
"    color: white;                 \n"
"    border-radius: 20px;               /* Adjust for pill shape */\n"
"                   /* Vertical padding, width will be set by layout */\n"
"    font-weight: bold;                 /* Bold text */\n"
"    font-size: 16px;                   \n"
"\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 101, 131, 20));
        QFont font3;
        font3.setPointSize(7);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        LogInButton = new QPushButton(centralwidget);
        LogInButton->setObjectName("LogInButton");
        LogInButton->setGeometry(QRect(30, 280, 201, 41));
        LogInButton->setFont(font2);
        LogInButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: rgb(139, 94, 60); /* Brown color */\n"
"    color: white;                 \n"
"    border-radius: 20px;               /* Adjust for pill shape */\n"
"    padding: 10px 0;                   /* Vertical padding, width will be set by layout */\n"
"    font-weight: bold;                 /* Bold text */\n"
"    font-size: 16px;                   \n"
"\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 20, 51, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/SvgjsG2242.png")));
        label_5->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 70, 141, 31));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color : rgb(62, 47, 28);\n"
"}"));
        label->setTextFormat(Qt::TextFormat::PlainText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 132, 191, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FirstNameEdit = new QLineEdit(widget);
        FirstNameEdit->setObjectName("FirstNameEdit");
        FirstNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;  \n"
"color: rgb(62, 47, 28);            /* Add some internal padding */\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #555555; /* A darker grey */\n"
"}"));
        FirstNameEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(FirstNameEdit);

        LastNameEdit = new QLineEdit(widget);
        LastNameEdit->setObjectName("LastNameEdit");
        LastNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        LastNameEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(LastNameEdit);

        ID_Edit = new QLineEdit(widget);
        ID_Edit->setObjectName("ID_Edit");
        ID_Edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        ID_Edit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(ID_Edit);

        PasswordEdit = new QLineEdit(widget);
        PasswordEdit->setObjectName("PasswordEdit");
        PasswordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));

        verticalLayout->addWidget(PasswordEdit);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 18));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "New to our platform?  ", nullptr));
        label_4->setText(QString());
        GoToSignUpButton->setText(QCoreApplication::translate("LoginWindow", "Sign Up", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Please enter your credentials ", nullptr));
        LogInButton->setText(QCoreApplication::translate("LoginWindow", "Log In", nullptr));
        label_5->setText(QString());
        label->setText(QCoreApplication::translate("LoginWindow", "Welcome Back !", nullptr));
        FirstNameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "First Name", nullptr));
        LastNameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Last Name", nullptr));
        ID_Edit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "ID CARD", nullptr));
        PasswordEdit->setText(QString());
        PasswordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

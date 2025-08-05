/********************************************************************************
** Form generated from reading UI file 'signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignInWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *GoToLogInButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *SignInButton;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *FirstNameEdit;
    QLineEdit *LastNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *EmailEdit;
    QLineEdit *UniversityEdit;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *IDedit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDateEdit *DateEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *RFIDEdit;
    QComboBox *TypeComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *PasswordEdit;
    QLineEdit *PasswordConfEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignInWindow)
    {
        if (SignInWindow->objectName().isEmpty())
            SignInWindow->setObjectName("SignInWindow");
        SignInWindow->resize(500, 380);
        centralwidget = new QWidget(SignInWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 250, 361));
        frame->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgb(139, 94, 60);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 220, 121, 21));
        QFont font;
        font.setItalic(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:white;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 90, 171, 81));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Frame 245.png")));
        label_4->setScaledContents(true);
        GoToLogInButton = new QPushButton(frame);
        GoToLogInButton->setObjectName("GoToLogInButton");
        GoToLogInButton->setGeometry(QRect(50, 250, 161, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        font1.setItalic(true);
        font1.setKerning(false);
        GoToLogInButton->setFont(font1);
        GoToLogInButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #6A442B; /* Brown color */\n"
"    color: white;                 \n"
"    border-radius: 20px;               /* Adjust for pill shape */\n"
"                   /* Vertical padding, width will be set by layout */\n"
"    font-weight: bold;                 /* Bold text */\n"
"    font-size: 16px;                   \n"
"\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 10, 111, 41));
        QFont font2;
        font2.setPointSize(22);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color : rgb(62, 47, 28);\n"
"}"));
        label->setTextFormat(Qt::TextFormat::PlainText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 56, 171, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SignInButton = new QPushButton(centralwidget);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(280, 300, 191, 41));
        SignInButton->setFont(font1);
        SignInButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: rgb(139, 94, 60); /* Brown color */\n"
"    color: white;                 \n"
"    border-radius: 20px;               /* Adjust for pill shape */\n"
"                   /* Vertical padding, width will be set by layout */\n"
"    font-weight: bold;                 /* Bold text */\n"
"    font-size: 16px;                   \n"
"\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 17, 41, 31));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/SvgjsG2242.png")));
        label_5->setScaledContents(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(260, 90, 231, 193));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        FirstNameEdit = new QLineEdit(layoutWidget);
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
        FirstNameEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(FirstNameEdit);

        LastNameEdit = new QLineEdit(layoutWidget);
        LastNameEdit->setObjectName("LastNameEdit");
        LastNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        LastNameEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(LastNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        EmailEdit = new QLineEdit(layoutWidget);
        EmailEdit->setObjectName("EmailEdit");
        EmailEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;  \n"
"color: rgb(62, 47, 28);            /* Add some internal padding */\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #555555; /* A darker grey */\n"
"}"));
        EmailEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(EmailEdit);

        UniversityEdit = new QLineEdit(layoutWidget);
        UniversityEdit->setObjectName("UniversityEdit");
        UniversityEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        UniversityEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(UniversityEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        IDedit = new QLineEdit(layoutWidget);
        IDedit->setObjectName("IDedit");
        IDedit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        IDedit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(IDedit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background :rgb(255, 255, 255);\n"
" border-radius: 10px; \n"
"}"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_6);

        DateEdit = new QDateEdit(layoutWidget);
        DateEdit->setObjectName("DateEdit");

        horizontalLayout_6->addWidget(DateEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        RFIDEdit = new QLineEdit(layoutWidget);
        RFIDEdit->setObjectName("RFIDEdit");
        RFIDEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        RFIDEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(RFIDEdit);

        TypeComboBox = new QComboBox(layoutWidget);
        TypeComboBox->addItem(QString());
        TypeComboBox->addItem(QString());
        TypeComboBox->addItem(QString());
        TypeComboBox->addItem(QString());
        TypeComboBox->addItem(QString());
        TypeComboBox->addItem(QString());
        TypeComboBox->setObjectName("TypeComboBox");

        horizontalLayout_3->addWidget(TypeComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        PasswordEdit = new QLineEdit(layoutWidget);
        PasswordEdit->setObjectName("PasswordEdit");
        PasswordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));

        horizontalLayout_7->addWidget(PasswordEdit);

        PasswordConfEdit = new QLineEdit(layoutWidget);
        PasswordConfEdit->setObjectName("PasswordConfEdit");
        PasswordConfEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        PasswordConfEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_7->addWidget(PasswordConfEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        SignInWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignInWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 18));
        SignInWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SignInWindow);
        statusbar->setObjectName("statusbar");
        SignInWindow->setStatusBar(statusbar);

        retranslateUi(SignInWindow);

        QMetaObject::connectSlotsByName(SignInWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignInWindow)
    {
        SignInWindow->setWindowTitle(QCoreApplication::translate("SignInWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("SignInWindow", "Already have Account? ", nullptr));
        label_4->setText(QString());
        GoToLogInButton->setText(QCoreApplication::translate("SignInWindow", "Log In", nullptr));
        label->setText(QCoreApplication::translate("SignInWindow", "Sign Up ", nullptr));
        label_2->setText(QCoreApplication::translate("SignInWindow", "Please provide your information ", nullptr));
        SignInButton->setText(QCoreApplication::translate("SignInWindow", "Sign Up", nullptr));
        label_5->setText(QString());
        FirstNameEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "First Name", nullptr));
        LastNameEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "Last Name", nullptr));
        EmailEdit->setText(QString());
        EmailEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "EMAIL", nullptr));
        UniversityEdit->setText(QString());
        UniversityEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "UNIVERSITY", nullptr));
        IDedit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "ID CARD", nullptr));
        label_6->setText(QCoreApplication::translate("SignInWindow", "Date Of Birth", nullptr));
        RFIDEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "RFID", nullptr));
        TypeComboBox->setItemText(0, QCoreApplication::translate("SignInWindow", "student", nullptr));
        TypeComboBox->setItemText(1, QCoreApplication::translate("SignInWindow", "teacher", nullptr));
        TypeComboBox->setItemText(2, QCoreApplication::translate("SignInWindow", "administrator", nullptr));
        TypeComboBox->setItemText(3, QCoreApplication::translate("SignInWindow", "librarian", nullptr));
        TypeComboBox->setItemText(4, QCoreApplication::translate("SignInWindow", "externel", nullptr));
        TypeComboBox->setItemText(5, QCoreApplication::translate("SignInWindow", "Library Director", nullptr));

        TypeComboBox->setPlaceholderText(QCoreApplication::translate("SignInWindow", "TYPE", nullptr));
        PasswordEdit->setText(QString());
        PasswordEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "Password", nullptr));
        PasswordConfEdit->setText(QString());
        PasswordConfEdit->setPlaceholderText(QCoreApplication::translate("SignInWindow", "Password confirmation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInWindow: public Ui_SignInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
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
    QLineEdit *PasswordEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *RFIDEdit;
    QComboBox *TypeComboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(400, 300);
        layoutWidget = new QWidget(UserDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 20, 291, 221));
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

        PasswordEdit = new QLineEdit(layoutWidget);
        PasswordEdit->setObjectName("PasswordEdit");
        PasswordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));

        verticalLayout->addWidget(PasswordEdit);

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

        pushButton = new QPushButton(UserDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 260, 56, 18));
        pushButton_2 = new QPushButton(UserDialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 260, 56, 18));

        retranslateUi(UserDialog);

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "Dialog", nullptr));
        FirstNameEdit->setPlaceholderText(QCoreApplication::translate("UserDialog", "First Name", nullptr));
        LastNameEdit->setPlaceholderText(QCoreApplication::translate("UserDialog", "Last Name", nullptr));
        EmailEdit->setText(QString());
        EmailEdit->setPlaceholderText(QCoreApplication::translate("UserDialog", "EMAIL", nullptr));
        UniversityEdit->setText(QString());
        UniversityEdit->setPlaceholderText(QCoreApplication::translate("UserDialog", "UNIVERSITY", nullptr));
        IDedit->setPlaceholderText(QCoreApplication::translate("UserDialog", "ID CARD", nullptr));
        label_6->setText(QCoreApplication::translate("UserDialog", "Date Of Birth", nullptr));
        PasswordEdit->setText(QString());
        PasswordEdit->setPlaceholderText(QCoreApplication::translate("UserDialog", "Password", nullptr));
        RFIDEdit->setPlaceholderText(QCoreApplication::translate("UserDialog", "RFID", nullptr));
        TypeComboBox->setItemText(0, QCoreApplication::translate("UserDialog", "student", nullptr));
        TypeComboBox->setItemText(1, QCoreApplication::translate("UserDialog", "teacher", nullptr));
        TypeComboBox->setItemText(2, QCoreApplication::translate("UserDialog", "administrator", nullptr));
        TypeComboBox->setItemText(3, QCoreApplication::translate("UserDialog", "librarian", nullptr));
        TypeComboBox->setItemText(4, QCoreApplication::translate("UserDialog", "externel", nullptr));
        TypeComboBox->setItemText(5, QCoreApplication::translate("UserDialog", "Library Director", nullptr));

        TypeComboBox->setPlaceholderText(QCoreApplication::translate("UserDialog", "TYPE", nullptr));
        pushButton->setText(QCoreApplication::translate("UserDialog", "Submit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserDialog", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'bookdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDIALOG_H
#define UI_BOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *TitleEdit;
    QLineEdit *AuthorEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *HasDigitalEdit;
    QLineEdit *FieldEdit;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *ISBNEdit;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *LibraryCodeEdit;
    QLineEdit *YearEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *BorrowingDaysEdit;
    QLineEdit *RenewalDaysEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *BookDialog)
    {
        if (BookDialog->objectName().isEmpty())
            BookDialog->setObjectName("BookDialog");
        BookDialog->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        BookDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(BookDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 30, 291, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        TitleEdit = new QLineEdit(layoutWidget);
        TitleEdit->setObjectName("TitleEdit");
        TitleEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;  \n"
"color: rgb(62, 47, 28);            /* Add some internal padding */\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #555555; /* A darker grey */\n"
"}"));
        TitleEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(TitleEdit);

        AuthorEdit = new QLineEdit(layoutWidget);
        AuthorEdit->setObjectName("AuthorEdit");
        AuthorEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        AuthorEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(AuthorEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        HasDigitalEdit = new QLineEdit(layoutWidget);
        HasDigitalEdit->setObjectName("HasDigitalEdit");
        HasDigitalEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;  \n"
"color: rgb(62, 47, 28);            /* Add some internal padding */\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #555555; /* A darker grey */\n"
"}"));
        HasDigitalEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(HasDigitalEdit);

        FieldEdit = new QLineEdit(layoutWidget);
        FieldEdit->setObjectName("FieldEdit");
        FieldEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        FieldEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(FieldEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        ISBNEdit = new QLineEdit(layoutWidget);
        ISBNEdit->setObjectName("ISBNEdit");
        ISBNEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        ISBNEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(ISBNEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        LibraryCodeEdit = new QLineEdit(layoutWidget);
        LibraryCodeEdit->setObjectName("LibraryCodeEdit");
        LibraryCodeEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(LibraryCodeEdit);

        YearEdit = new QLineEdit(layoutWidget);
        YearEdit->setObjectName("YearEdit");
        YearEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        YearEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(YearEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BorrowingDaysEdit = new QLineEdit(layoutWidget);
        BorrowingDaysEdit->setObjectName("BorrowingDaysEdit");
        BorrowingDaysEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        BorrowingDaysEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(BorrowingDaysEdit);

        RenewalDaysEdit = new QLineEdit(layoutWidget);
        RenewalDaysEdit->setObjectName("RenewalDaysEdit");
        RenewalDaysEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #CFCFCF; /* A light grey border */\n"
"    border-radius: 10px;       /* Adjust this value for desired roundness */\n"
"    padding: 5px;              /* Add some internal padding */\n"
"}\n"
""));
        RenewalDaysEdit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(RenewalDaysEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(BookDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 270, 56, 18));
        pushButton_2 = new QPushButton(BookDialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 270, 56, 18));
        label = new QLabel(BookDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 37, 31));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/SvgjsG2242.png")));
        label->setScaledContents(true);

        retranslateUi(BookDialog);

        QMetaObject::connectSlotsByName(BookDialog);
    } // setupUi

    void retranslateUi(QDialog *BookDialog)
    {
        BookDialog->setWindowTitle(QCoreApplication::translate("BookDialog", "Dialog", nullptr));
        TitleEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Title", nullptr));
        AuthorEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Author", nullptr));
        HasDigitalEdit->setText(QString());
        HasDigitalEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Has Digital ?", nullptr));
        FieldEdit->setText(QString());
        FieldEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Field", nullptr));
        ISBNEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "ISBN", nullptr));
        LibraryCodeEdit->setText(QString());
        LibraryCodeEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Library Code", nullptr));
        YearEdit->setText(QString());
        YearEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Year Of Publication", nullptr));
        BorrowingDaysEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Borrowing Days Limit", nullptr));
        RenewalDaysEdit->setPlaceholderText(QCoreApplication::translate("BookDialog", "Renewal Days Limit", nullptr));
        pushButton->setText(QCoreApplication::translate("BookDialog", "Submit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("BookDialog", "close", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BookDialog: public Ui_BookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDIALOG_H

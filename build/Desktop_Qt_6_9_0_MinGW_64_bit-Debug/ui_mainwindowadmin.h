/********************************************************************************
** Form generated from reading UI file 'mainwindowadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWADMIN_H
#define UI_MAINWINDOWADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowAdmin
{
public:
    QWidget *centralwidget;
    QFrame *leftSidebar;
    QLabel *logoImageLabel;
    QToolButton *toolButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *dashboardButton;
    QToolButton *dashboardButton_3;
    QToolButton *dashboardButton_2;
    QToolButton *dashboardButton_4;
    QToolButton *dashboardButton_5;
    QStackedWidget *stackedWidget;
    QWidget *Home_page_2;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_2;
    QFrame *CurrentBook_2;
    QLabel *current_book_logo;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *Curren_book_title_lable;
    QFrame *TimerToReturnBook_2;
    QLabel *time_to_return_logo;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *time_to_return_title;
    QFrame *LastNotification_2;
    QLabel *label_12;
    QTextEdit *Notification_text;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *LastNewsButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QWidget *Users_page;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *AddUserButton;
    QPushButton *PenalizeUserButton;
    QPushButton *DeleteUserButton;
    QPushButton *EditUserButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ListOfBannedUsersButton;
    QPushButton *ListOfPenalizedUsersButton;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *SearchUserEdit;
    QComboBox *SearchUserTypeComboBox;
    QTableWidget *UsersTable;
    QLabel *comment_in_users_table;
    QWidget *Books_page_2;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *SearchBookEdit;
    QComboBox *SearchBookTypeComboBox;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *AddBookButton;
    QPushButton *DeleteBookButton;
    QPushButton *EditBookButton;
    QTableWidget *BooksTable;
    QLabel *comment_in_books_table;
    QWidget *History_page_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *ListOfBorrowedBooksButton;
    QPushButton *ListOfUnreturnedBooksButton;
    QTableWidget *BooksTable_2;
    QLabel *comment_in_books_table_2;
    QWidget *About_page_2;
    QLabel *label_33;
    QFrame *frame_8;
    QLabel *label_34;
    QLabel *label_35;
    QFrame *frame_10;
    QLabel *label_37;
    QLabel *label_36;
    QFrame *frame_11;
    QLabel *label_38;
    QLabel *label_3;
    QFrame *frame;
    QLabel *label;
    QToolButton *toolButton_4;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout;
    QToolButton *NotificationButton;
    QToolButton *SettingsButton;
    QLabel *Typelabel;
    QLabel *FullNameLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowAdmin)
    {
        if (MainWindowAdmin->objectName().isEmpty())
            MainWindowAdmin->setObjectName("MainWindowAdmin");
        MainWindowAdmin->resize(500, 380);
        centralwidget = new QWidget(MainWindowAdmin);
        centralwidget->setObjectName("centralwidget");
        leftSidebar = new QFrame(centralwidget);
        leftSidebar->setObjectName("leftSidebar");
        leftSidebar->setGeometry(QRect(0, 0, 71, 381));
        leftSidebar->setStyleSheet(QString::fromUtf8("#leftSidebar {\n"
"    background-color: rgb(139, 94, 60); /* Darker brown */\n"
"    border: none; /* Remove any default border */\n"
"}"));
        leftSidebar->setFrameShape(QFrame::Shape::StyledPanel);
        leftSidebar->setFrameShadow(QFrame::Shadow::Raised);
        logoImageLabel = new QLabel(leftSidebar);
        logoImageLabel->setObjectName("logoImageLabel");
        logoImageLabel->setGeometry(QRect(6, 5, 61, 35));
        logoImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Frame 245.png")));
        logoImageLabel->setScaledContents(true);
        toolButton = new QToolButton(leftSidebar);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(-1, 280, 71, 21));
        QFont font;
        font.setBold(true);
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: transparent; /* No background by default */\n"
"    color: rgba(255, 255, 255, 180); /* Slightly transparent white text */\n"
"    border: none;\n"
"    padding-left:7px;/* Adjust padding for desired size */\n"
" qproperty-iconSize: 13px 13px;\n"
"\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: rgb(90, 60, 40); /* Slightly lighter brown on hover */\n"
"    color: white; /* Solid white text on hover */\n"
"    border-left: 3px solid white; /* Highlight on the left */\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/logout 3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon);
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        layoutWidget = new QWidget(leftSidebar);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 90, 74, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dashboardButton = new QToolButton(layoutWidget);
        dashboardButton->setObjectName("dashboardButton");
        dashboardButton->setFont(font);
        dashboardButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: transparent; /* No background by default */\n"
"    color: rgba(255, 255, 255, 180); /* Slightly transparent white text */\n"
"    border: none;\n"
"padding-left:5px;\n"
"    text-align: center; /* Align text to the left */\n"
" qproperty-iconSize: 12px 12px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color:rgb(255, 255, 255) /* Slightly lighter brown on hover */\n"
"    color: rgb(139, 94, 60);\n"
"    border-left: 3px solid white; /* Highlight on the left */\n"
"}\n"
"#dashboardButton {\n"
"    background-color: rgb(110, 70, 50); /* Distinct background for active */\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-left: 3px solid white; /* Stronger highlight */\n"
"}\n"
"/* Make sure this specific rule comes after or overrides the general QToolButton rule if needed */"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/element-2 2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboardButton->setIcon(icon1);
        dashboardButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        dashboardButton->setAutoRaise(true);

        verticalLayout->addWidget(dashboardButton);

        dashboardButton_3 = new QToolButton(layoutWidget);
        dashboardButton_3->setObjectName("dashboardButton_3");
        dashboardButton_3->setFont(font);
        dashboardButton_3->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: transparent; /* No background by default */\n"
"    color: rgba(255, 255, 255, 180); /* Slightly transparent white text */\n"
"	padding-left:5px;\n"
"    border: none;\n"
"    text-align: center; /* Align text to the left */\n"
" qproperty-iconSize: 12px 12px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color:rgb(255, 255, 255) /* Slightly lighter brown on hover */\n"
"    color: rgb(139, 94, 60);\n"
"    border-left: 3px solid white; /* Highlight on the left */\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/book-1 1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboardButton_3->setIcon(icon2);
        dashboardButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        dashboardButton_3->setAutoRaise(true);

        verticalLayout->addWidget(dashboardButton_3);

        dashboardButton_2 = new QToolButton(layoutWidget);
        dashboardButton_2->setObjectName("dashboardButton_2");
        dashboardButton_2->setFont(font);
        dashboardButton_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: transparent; /* No background by default */\n"
"    color: rgba(255, 255, 255, 180); /* Slightly transparent white text */\n"
"    border: none;\n"
"padding-left:5px;\n"
"    text-align: center; /* Align text to the left */\n"
" qproperty-iconSize: 9px 9px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color:rgb(255, 255, 255) /* Slightly lighter brown on hover */\n"
"    color: rgb(139, 94, 60);\n"
"    border-left: 3px solid white; /* Highlight on the left */\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/Vector.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboardButton_2->setIcon(icon3);
        dashboardButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        dashboardButton_2->setAutoRaise(true);

        verticalLayout->addWidget(dashboardButton_2);

        dashboardButton_4 = new QToolButton(layoutWidget);
        dashboardButton_4->setObjectName("dashboardButton_4");
        dashboardButton_4->setFont(font);
        dashboardButton_4->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: transparent; /* No background by default */\n"
"    color: rgba(255, 255, 255, 180); /* Slightly transparent white text */\n"
"padding-left:5px;\n"
"    border: none;\n"
"    text-align: center; /* Align text to the left */\n"
" qproperty-iconSize: 12px 12px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color:rgb(255, 255, 255) /* Slightly lighter brown on hover */\n"
"    color: rgb(139, 94, 60);\n"
"    border-left: 3px solid white; /* Highlight on the left */\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/people 3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboardButton_4->setIcon(icon4);
        dashboardButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        dashboardButton_4->setAutoRaise(true);

        verticalLayout->addWidget(dashboardButton_4);

        dashboardButton_5 = new QToolButton(layoutWidget);
        dashboardButton_5->setObjectName("dashboardButton_5");
        dashboardButton_5->setFont(font);
        dashboardButton_5->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: transparent; /* No background by default */\n"
"    color: rgba(255, 255, 255, 180); /* Slightly transparent white text */\n"
"    border: none;\n"
"padding-left:7px;\n"
"    text-align: center; /* Align text to the left */\n"
" qproperty-iconSize: 10px 10px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color:rgb(255, 255, 255) /* Slightly lighter brown on hover */\n"
"    color: rgb(139, 94, 60);\n"
"    border-left: 3px solid white; /* Highlight on the left */\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/Vector (1).png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboardButton_5->setIcon(icon5);
        dashboardButton_5->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        dashboardButton_5->setAutoRaise(true);

        verticalLayout->addWidget(dashboardButton_5);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(70, 30, 431, 371));
        Home_page_2 = new QWidget();
        Home_page_2->setObjectName("Home_page_2");
        layoutWidget_6 = new QWidget(Home_page_2);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(20, 20, 391, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        CurrentBook_2 = new QFrame(layoutWidget_6);
        CurrentBook_2->setObjectName("CurrentBook_2");
        CurrentBook_2->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"padding-right:10px;\n"
"}\n"
""));
        CurrentBook_2->setFrameShape(QFrame::Shape::StyledPanel);
        CurrentBook_2->setFrameShadow(QFrame::Shadow::Raised);
        current_book_logo = new QLabel(CurrentBook_2);
        current_book_logo->setObjectName("current_book_logo");
        current_book_logo->setGeometry(QRect(0, 10, 41, 31));
        current_book_logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/icons8-book-100.png")));
        current_book_logo->setScaledContents(true);
        layoutWidget_2 = new QWidget(CurrentBook_2);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(36, 4, 148, 48));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        Curren_book_title_lable = new QLabel(layoutWidget_2);
        Curren_book_title_lable->setObjectName("Curren_book_title_lable");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        Curren_book_title_lable->setFont(font1);

        verticalLayout_4->addWidget(Curren_book_title_lable);


        horizontalLayout_2->addWidget(CurrentBook_2);

        TimerToReturnBook_2 = new QFrame(layoutWidget_6);
        TimerToReturnBook_2->setObjectName("TimerToReturnBook_2");
        TimerToReturnBook_2->setFrameShape(QFrame::Shape::StyledPanel);
        TimerToReturnBook_2->setFrameShadow(QFrame::Shadow::Raised);
        time_to_return_logo = new QLabel(TimerToReturnBook_2);
        time_to_return_logo->setObjectName("time_to_return_logo");
        time_to_return_logo->setGeometry(QRect(10, 10, 33, 33));
        time_to_return_logo->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/icons8-timer-80.png")));
        time_to_return_logo->setScaledContents(true);
        layoutWidget_3 = new QWidget(TimerToReturnBook_2);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(0, 48, 191, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");

        horizontalLayout_4->addLayout(verticalLayout_5);

        time_to_return_title = new QLabel(TimerToReturnBook_2);
        time_to_return_title->setObjectName("time_to_return_title");
        time_to_return_title->setGeometry(QRect(46, 8, 141, 34));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        time_to_return_title->setFont(font2);
        time_to_return_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(TimerToReturnBook_2);

        LastNotification_2 = new QFrame(Home_page_2);
        LastNotification_2->setObjectName("LastNotification_2");
        LastNotification_2->setGeometry(QRect(200, 110, 211, 111));
        LastNotification_2->setStyleSheet(QString::fromUtf8("border-color:rrgb(170, 85, 0);"));
        LastNotification_2->setFrameShape(QFrame::Shape::StyledPanel);
        LastNotification_2->setFrameShadow(QFrame::Shadow::Raised);
        label_12 = new QLabel(LastNotification_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 0, 191, 41));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label_12->setFont(font3);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Notification_text = new QTextEdit(LastNotification_2);
        Notification_text->setObjectName("Notification_text");
        Notification_text->setGeometry(QRect(40, 55, 151, 51));
        Notification_text->setMinimumSize(QSize(151, 0));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Source Code Pro")});
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setItalic(true);
        Notification_text->setFont(font4);
        Notification_text->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit\n"
"{\n"
"background-color:transparent;\n"
"border-color:rgb(106, 68, 43);\n"
"border-radius : 15px;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Notification_text->setReadOnly(true);
        layoutWidget_5 = new QWidget(Home_page_2);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(20, 130, 145, 61));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_8 = new QSpacerItem(28, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        LastNewsButton = new QToolButton(layoutWidget_5);
        LastNewsButton->setObjectName("LastNewsButton");
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        LastNewsButton->setFont(font5);
        LastNewsButton->setStyleSheet(QString::fromUtf8(" QToolButton {\n"
"      background-color: rgb(120, 78, 50);\n"
"      color: white;\n"
"      border: 2px solid #4E342E;\n"
"      border-radius: 6px;\n"
"     \n"
"    }\n"
"    QToolButton:hover {\n"
"      background-color:  rgb(90, 55, 35);\n"
"    }\n"
"  "));
        LastNewsButton->setIcon(icon5);
        LastNewsButton->setIconSize(QSize(25, 25));
        LastNewsButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        LastNewsButton->setAutoRaise(true);

        horizontalLayout_6->addWidget(LastNewsButton);


        verticalLayout_6->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        label_2 = new QLabel(Home_page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 230, 411, 91));
        label_2->setMinimumSize(QSize(360, 0));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("PMingLiU-ExtB")});
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setItalic(false);
        label_2->setFont(font6);
        label_2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        stackedWidget->addWidget(Home_page_2);
        Users_page = new QWidget();
        Users_page->setObjectName("Users_page");
        layoutWidget1 = new QWidget(Users_page);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 20, 411, 77));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        AddUserButton = new QPushButton(layoutWidget1);
        AddUserButton->setObjectName("AddUserButton");
        AddUserButton->setFont(font2);

        horizontalLayout_11->addWidget(AddUserButton);

        PenalizeUserButton = new QPushButton(layoutWidget1);
        PenalizeUserButton->setObjectName("PenalizeUserButton");
        PenalizeUserButton->setFont(font2);

        horizontalLayout_11->addWidget(PenalizeUserButton);

        DeleteUserButton = new QPushButton(layoutWidget1);
        DeleteUserButton->setObjectName("DeleteUserButton");
        DeleteUserButton->setFont(font2);

        horizontalLayout_11->addWidget(DeleteUserButton);

        EditUserButton = new QPushButton(layoutWidget1);
        EditUserButton->setObjectName("EditUserButton");
        EditUserButton->setFont(font2);

        horizontalLayout_11->addWidget(EditUserButton);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ListOfBannedUsersButton = new QPushButton(layoutWidget1);
        ListOfBannedUsersButton->setObjectName("ListOfBannedUsersButton");

        horizontalLayout_3->addWidget(ListOfBannedUsersButton);

        ListOfPenalizedUsersButton = new QPushButton(layoutWidget1);
        ListOfPenalizedUsersButton->setObjectName("ListOfPenalizedUsersButton");

        horizontalLayout_3->addWidget(ListOfPenalizedUsersButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        SearchUserEdit = new QLineEdit(layoutWidget1);
        SearchUserEdit->setObjectName("SearchUserEdit");
        SearchUserEdit->setFont(font2);

        horizontalLayout_10->addWidget(SearchUserEdit);

        SearchUserTypeComboBox = new QComboBox(layoutWidget1);
        SearchUserTypeComboBox->addItem(QString());
        SearchUserTypeComboBox->addItem(QString());
        SearchUserTypeComboBox->addItem(QString());
        SearchUserTypeComboBox->addItem(QString());
        SearchUserTypeComboBox->addItem(QString());
        SearchUserTypeComboBox->setObjectName("SearchUserTypeComboBox");
        QFont font7;
        font7.setPointSize(8);
        font7.setBold(true);
        SearchUserTypeComboBox->setFont(font7);
        SearchUserTypeComboBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_10->addWidget(SearchUserTypeComboBox);


        verticalLayout_3->addLayout(horizontalLayout_10);

        UsersTable = new QTableWidget(Users_page);
        if (UsersTable->rowCount() < 1)
            UsersTable->setRowCount(1);
        UsersTable->setObjectName("UsersTable");
        UsersTable->setGeometry(QRect(10, 120, 411, 211));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UsersTable->sizePolicy().hasHeightForWidth());
        UsersTable->setSizePolicy(sizePolicy);
        QFont font8;
        font8.setPointSize(5);
        font8.setBold(false);
        UsersTable->setFont(font8);
        UsersTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: rgb(139, 94, 60); /* Black background for the table */\n"
"    alternate-background-color: rgb(106, 68, 43); /* Dark grey for alternating rows */\n"
"    color: white; /* White text color for cell content */\n"
"    gridline-color: #555555; /* Darker grey grid lines */\n"
"    border: 1px solid #555555; /* Border around the table */\n"
"    border-radius: 5px; /* Slightly rounded corners for the table */\n"
"    selection-background-color: #8B5E3C; /* Your brown color for selected rows */\n"
"    selection-color: white;\n"
"}\n"
"QTableWidget QHeaderView::section {\n"
"    background-color:rgb(106, 68, 43); /* Black background for headers */\n"
"    color: white; /* White text for headers */\n"
"    border: none;\n"
"    border-bottom: 1px solid #555555; /* Bottom border for header sections */\n"
"   \n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"/* Style for the horizontal header */\n"
"\n"
"/* Style for individual items (cells) */\n"
"QTableWidget::item {\n"
"   /* p"
                        "adding: 5px; /* Padding inside cells */\n"
"}"));
        comment_in_users_table = new QLabel(Users_page);
        comment_in_users_table->setObjectName("comment_in_users_table");
        comment_in_users_table->setGeometry(QRect(10, 120, 411, 211));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Sakkal Majalla")});
        font9.setPointSize(30);
        font9.setBold(true);
        comment_in_users_table->setFont(font9);
        comment_in_users_table->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"background-color: rgb(139, 94, 60);\n"
"}"));
        comment_in_users_table->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(Users_page);
        Books_page_2 = new QWidget();
        Books_page_2->setObjectName("Books_page_2");
        layoutWidget_7 = new QWidget(Books_page_2);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(100, 50, 321, 31));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        SearchBookEdit = new QLineEdit(layoutWidget_7);
        SearchBookEdit->setObjectName("SearchBookEdit");
        SearchBookEdit->setFont(font2);

        horizontalLayout_7->addWidget(SearchBookEdit);

        SearchBookTypeComboBox = new QComboBox(layoutWidget_7);
        SearchBookTypeComboBox->addItem(QString());
        SearchBookTypeComboBox->addItem(QString());
        SearchBookTypeComboBox->addItem(QString());
        SearchBookTypeComboBox->addItem(QString());
        SearchBookTypeComboBox->addItem(QString());
        SearchBookTypeComboBox->addItem(QString());
        SearchBookTypeComboBox->setObjectName("SearchBookTypeComboBox");
        SearchBookTypeComboBox->setFont(font2);
        SearchBookTypeComboBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(SearchBookTypeComboBox);

        layoutWidget_8 = new QWidget(Books_page_2);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(20, 20, 401, 24));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        AddBookButton = new QPushButton(layoutWidget_8);
        AddBookButton->setObjectName("AddBookButton");
        AddBookButton->setFont(font5);

        horizontalLayout_8->addWidget(AddBookButton);

        DeleteBookButton = new QPushButton(layoutWidget_8);
        DeleteBookButton->setObjectName("DeleteBookButton");
        DeleteBookButton->setFont(font5);

        horizontalLayout_8->addWidget(DeleteBookButton);

        EditBookButton = new QPushButton(layoutWidget_8);
        EditBookButton->setObjectName("EditBookButton");
        EditBookButton->setFont(font5);

        horizontalLayout_8->addWidget(EditBookButton);

        BooksTable = new QTableWidget(Books_page_2);
        if (BooksTable->rowCount() < 1)
            BooksTable->setRowCount(1);
        BooksTable->setObjectName("BooksTable");
        BooksTable->setGeometry(QRect(10, 110, 411, 221));
        sizePolicy.setHeightForWidth(BooksTable->sizePolicy().hasHeightForWidth());
        BooksTable->setSizePolicy(sizePolicy);
        BooksTable->setFont(font8);
        BooksTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: rgb(139, 94, 60); /* Black background for the table */\n"
"    alternate-background-color: rgb(106, 68, 43); /* Dark grey for alternating rows */\n"
"    color: white; /* White text color for cell content */\n"
"    gridline-color: #555555; /* Darker grey grid lines */\n"
"    border: 1px solid #555555; /* Border around the table */\n"
"    border-radius: 5px; /* Slightly rounded corners for the table */\n"
"    selection-background-color: #8B5E3C; /* Your brown color for selected rows */\n"
"    selection-color: white;\n"
"}\n"
"QTableWidget QHeaderView::section {\n"
"    background-color:rgb(106, 68, 43); /* Black background for headers */\n"
"    color: white; /* White text for headers */\n"
"    border: none;\n"
"    border-bottom: 1px solid #555555; /* Bottom border for header sections */\n"
"   \n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"/* Style for the horizontal header */\n"
"\n"
"/* Style for individual items (cells) */\n"
"QTableWidget::item {\n"
"   /* p"
                        "adding: 5px; /* Padding inside cells */\n"
"}"));
        comment_in_books_table = new QLabel(Books_page_2);
        comment_in_books_table->setObjectName("comment_in_books_table");
        comment_in_books_table->setGeometry(QRect(10, 110, 411, 221));
        comment_in_books_table->setFont(font9);
        comment_in_books_table->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"background-color: rgb(139, 94, 60);\n"
"}"));
        comment_in_books_table->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(Books_page_2);
        History_page_2 = new QWidget();
        History_page_2->setObjectName("History_page_2");
        layoutWidget2 = new QWidget(History_page_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 20, 408, 51));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        ListOfBorrowedBooksButton = new QPushButton(layoutWidget2);
        ListOfBorrowedBooksButton->setObjectName("ListOfBorrowedBooksButton");

        horizontalLayout_9->addWidget(ListOfBorrowedBooksButton);

        ListOfUnreturnedBooksButton = new QPushButton(layoutWidget2);
        ListOfUnreturnedBooksButton->setObjectName("ListOfUnreturnedBooksButton");

        horizontalLayout_9->addWidget(ListOfUnreturnedBooksButton);


        verticalLayout_2->addLayout(horizontalLayout_9);

        BooksTable_2 = new QTableWidget(History_page_2);
        if (BooksTable_2->rowCount() < 1)
            BooksTable_2->setRowCount(1);
        BooksTable_2->setObjectName("BooksTable_2");
        BooksTable_2->setGeometry(QRect(10, 100, 411, 221));
        sizePolicy.setHeightForWidth(BooksTable_2->sizePolicy().hasHeightForWidth());
        BooksTable_2->setSizePolicy(sizePolicy);
        BooksTable_2->setFont(font8);
        BooksTable_2->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: rgb(139, 94, 60); /* Black background for the table */\n"
"    alternate-background-color: rgb(106, 68, 43); /* Dark grey for alternating rows */\n"
"    color: white; /* White text color for cell content */\n"
"    gridline-color: #555555; /* Darker grey grid lines */\n"
"    border: 1px solid #555555; /* Border around the table */\n"
"    border-radius: 5px; /* Slightly rounded corners for the table */\n"
"    selection-background-color: #8B5E3C; /* Your brown color for selected rows */\n"
"    selection-color: white;\n"
"}\n"
"QTableWidget QHeaderView::section {\n"
"    background-color:rgb(106, 68, 43); /* Black background for headers */\n"
"    color: white; /* White text for headers */\n"
"    border: none;\n"
"    border-bottom: 1px solid #555555; /* Bottom border for header sections */\n"
"   \n"
"    font-weight: bold;\n"
"}\n"
"\n"
"\n"
"/* Style for the horizontal header */\n"
"\n"
"/* Style for individual items (cells) */\n"
"QTableWidget::item {\n"
"   /* p"
                        "adding: 5px; /* Padding inside cells */\n"
"}"));
        comment_in_books_table_2 = new QLabel(History_page_2);
        comment_in_books_table_2->setObjectName("comment_in_books_table_2");
        comment_in_books_table_2->setGeometry(QRect(10, 100, 411, 241));
        comment_in_books_table_2->setFont(font9);
        comment_in_books_table_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"background-color: rgb(139, 94, 60);\n"
"}"));
        comment_in_books_table_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(History_page_2);
        About_page_2 = new QWidget();
        About_page_2->setObjectName("About_page_2");
        label_33 = new QLabel(About_page_2);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(20, 30, 121, 51));
        frame_8 = new QFrame(About_page_2);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(190, 10, 121, 91));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        label_34 = new QLabel(frame_8);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(0, 20, 121, 51));
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_35 = new QLabel(About_page_2);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(10, 120, 131, 51));
        label_35->setFont(font2);
        frame_10 = new QFrame(About_page_2);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(500, 270, 121, 51));
        frame_10->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:rgb(139, 94, 60);\n"
"border-radius:15px;\n"
"}"));
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        label_37 = new QLabel(frame_10);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(10, 1, 91, 20));
        QFont font10;
        font10.setPointSize(6);
        font10.setBold(true);
        label_37->setFont(font10);
        label_37->setStyleSheet(QString::fromUtf8("color:white;"));
        label_36 = new QLabel(About_page_2);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(270, 240, 141, 31));
        QFont font11;
        font11.setPointSize(11);
        font11.setBold(true);
        label_36->setFont(font11);
        label_36->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_11 = new QFrame(About_page_2);
        frame_11->setObjectName("frame_11");
        frame_11->setGeometry(QRect(280, 280, 121, 41));
        frame_11->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:rgb(139, 94, 60);\n"
"border-radius:15px;\n"
"}"));
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        label_38 = new QLabel(frame_11);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(10, 10, 101, 20));
        QFont font12;
        font12.setPointSize(7);
        font12.setBold(true);
        label_38->setFont(font12);
        label_38->setStyleSheet(QString::fromUtf8("color:white;"));
        label_38->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(About_page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 120, 121, 71));
        label_3->setStyleSheet(QString::fromUtf8("border-color:rgb(85, 85, 0)"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(About_page_2);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(70, 0, 431, 31));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 7, 15, 15));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/user 1.png")));
        label->setScaledContents(true);
        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setGeometry(QRect(390, 20, 31, 31));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    qproperty-iconSize: 17px 17px; /* Adjust icon size */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../Downloads/icons8-notification-material-rounded/icons8-notification-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_4->setIcon(icon6);
        toolButton_4->setAutoRaise(true);
        layoutWidget_10 = new QWidget(frame);
        layoutWidget_10->setObjectName("layoutWidget_10");
        layoutWidget_10->setGeometry(QRect(350, 0, 61, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget_10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NotificationButton = new QToolButton(layoutWidget_10);
        NotificationButton->setObjectName("NotificationButton");
        NotificationButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    qproperty-iconSize: 17px 17px; /* Adjust icon size */\n"
"}\n"
""));
        NotificationButton->setIcon(icon6);
        NotificationButton->setAutoRaise(true);

        horizontalLayout->addWidget(NotificationButton);

        SettingsButton = new QToolButton(layoutWidget_10);
        SettingsButton->setObjectName("SettingsButton");
        SettingsButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    qproperty-iconSize: 17px 17px; /* Adjust icon size */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/setting-2 1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SettingsButton->setIcon(icon7);
        SettingsButton->setAutoRaise(true);

        horizontalLayout->addWidget(SettingsButton);

        Typelabel = new QLabel(frame);
        Typelabel->setObjectName("Typelabel");
        Typelabel->setGeometry(QRect(160, 7, 71, 16));
        Typelabel->setMinimumSize(QSize(60, 0));
        Typelabel->setFont(font12);
        Typelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        FullNameLabel = new QLabel(frame);
        FullNameLabel->setObjectName("FullNameLabel");
        FullNameLabel->setGeometry(QRect(37, 7, 91, 16));
        FullNameLabel->setMinimumSize(QSize(60, 0));
        FullNameLabel->setFont(font7);
        FullNameLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindowAdmin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindowAdmin);
        statusbar->setObjectName("statusbar");
        MainWindowAdmin->setStatusBar(statusbar);

        retranslateUi(MainWindowAdmin);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowAdmin)
    {
        MainWindowAdmin->setWindowTitle(QCoreApplication::translate("MainWindowAdmin", "MainWindow", nullptr));
        logoImageLabel->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindowAdmin", "Log out", nullptr));
        dashboardButton->setText(QCoreApplication::translate("MainWindowAdmin", "Home ", nullptr));
        dashboardButton_3->setText(QCoreApplication::translate("MainWindowAdmin", "Books", nullptr));
        dashboardButton_2->setText(QCoreApplication::translate("MainWindowAdmin", "History", nullptr));
        dashboardButton_4->setText(QCoreApplication::translate("MainWindowAdmin", "Users", nullptr));
        dashboardButton_5->setText(QCoreApplication::translate("MainWindowAdmin", "About", nullptr));
        current_book_logo->setText(QString());
        Curren_book_title_lable->setText(QCoreApplication::translate("MainWindowAdmin", "Managing Books", nullptr));
        time_to_return_logo->setText(QString());
        time_to_return_title->setText(QCoreApplication::translate("MainWindowAdmin", "LOOK FOR DUE DATES", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowAdmin", "LAST NOTIFICATION", nullptr));
        Notification_text->setHtml(QCoreApplication::translate("MainWindowAdmin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Source Code Pro'; font-size:11pt; font-weight:700; font-style:italic;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Notification_text->setPlaceholderText(QCoreApplication::translate("MainWindowAdmin", "No Notifications yet", nullptr));
        LastNewsButton->setText(QCoreApplication::translate("MainWindowAdmin", "   Last News", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowAdmin", "\"A librarian lives a thousand\n"
"               stories through others. The one\n"
"                         who hides books lives only one.\"\n"
"", nullptr));
        AddUserButton->setText(QCoreApplication::translate("MainWindowAdmin", "Add User", nullptr));
        PenalizeUserButton->setText(QCoreApplication::translate("MainWindowAdmin", "Penalize User", nullptr));
        DeleteUserButton->setText(QCoreApplication::translate("MainWindowAdmin", "Delete User", nullptr));
        EditUserButton->setText(QCoreApplication::translate("MainWindowAdmin", "Edit User", nullptr));
        ListOfBannedUsersButton->setText(QCoreApplication::translate("MainWindowAdmin", "List Of Banned Users", nullptr));
        ListOfPenalizedUsersButton->setText(QCoreApplication::translate("MainWindowAdmin", "List Of Penalized Users", nullptr));
        SearchUserEdit->setPlaceholderText(QCoreApplication::translate("MainWindowAdmin", "Search For User", nullptr));
        SearchUserTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindowAdmin", "Search Type", nullptr));
        SearchUserTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindowAdmin", "By First Name", nullptr));
        SearchUserTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindowAdmin", "By ID", nullptr));
        SearchUserTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindowAdmin", "By Type", nullptr));
        SearchUserTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindowAdmin", "By University", nullptr));

        SearchUserTypeComboBox->setPlaceholderText(QString());
        comment_in_users_table->setText(QCoreApplication::translate("MainWindowAdmin", "Modify AND Searc Alll \n"
" Things Related To Users", nullptr));
        SearchBookEdit->setPlaceholderText(QCoreApplication::translate("MainWindowAdmin", "Search For Book", nullptr));
        SearchBookTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindowAdmin", "Search Type", nullptr));
        SearchBookTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindowAdmin", "By Name", nullptr));
        SearchBookTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindowAdmin", "By author", nullptr));
        SearchBookTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindowAdmin", "By ISBN", nullptr));
        SearchBookTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindowAdmin", "By Year", nullptr));
        SearchBookTypeComboBox->setItemText(5, QCoreApplication::translate("MainWindowAdmin", "By Type", nullptr));

        SearchBookTypeComboBox->setPlaceholderText(QString());
        AddBookButton->setText(QCoreApplication::translate("MainWindowAdmin", "Add Book", nullptr));
        DeleteBookButton->setText(QCoreApplication::translate("MainWindowAdmin", "Delete Book", nullptr));
        EditBookButton->setText(QCoreApplication::translate("MainWindowAdmin", "Edit Book", nullptr));
        comment_in_books_table->setText(QCoreApplication::translate("MainWindowAdmin", "START SEARCHING ABOUT \n"
"BOOKS", nullptr));
        ListOfBorrowedBooksButton->setText(QCoreApplication::translate("MainWindowAdmin", "List Of Borrowed Books", nullptr));
        ListOfUnreturnedBooksButton->setText(QCoreApplication::translate("MainWindowAdmin", "UnReturned Books", nullptr));
        comment_in_books_table_2->setText(QCoreApplication::translate("MainWindowAdmin", "ALL THINGS Related \n"
"  To Books", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindowAdmin", "Current Location", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindowAdmin", "technological Pole", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindowAdmin", "Library Hours of Operation", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindowAdmin", "libraryensia@ensia.edu.dz", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindowAdmin", "Contact Information", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindowAdmin", "libraryensia@ensia.edu.dz", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowAdmin", "8 AM ---->  4PM\n"
"    SATURDAY \n"
"     TO\n"
"  THURSDAY", nullptr));
        label->setText(QString());
        toolButton_4->setText(QString());
        NotificationButton->setText(QString());
        SettingsButton->setText(QString());
        Typelabel->setText(QCoreApplication::translate("MainWindowAdmin", "User Type", nullptr));
        FullNameLabel->setText(QCoreApplication::translate("MainWindowAdmin", "FULL NAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowAdmin: public Ui_MainWindowAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWADMIN_H

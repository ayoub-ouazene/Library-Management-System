/********************************************************************************
** Form generated from reading UI file 'mainwindowuser.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWUSER_H
#define UI_MAINWINDOWUSER_H

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

class Ui_MainWindowUser
{
public:
    QWidget *centralwidget;
    QFrame *leftSidebar;
    QLabel *logoImageLabel;
    QToolButton *LogOutButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *HomeButton;
    QToolButton *BooksButton;
    QToolButton *HistoryButton;
    QToolButton *AboutButton;
    QFrame *frame;
    QLabel *label;
    QToolButton *toolButton_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QToolButton *NotificationButton;
    QToolButton *SettingsButton;
    QLabel *Typelabel;
    QLabel *FullNameLabel;
    QFrame *mainContentArea;
    QStackedWidget *stackedWidget;
    QWidget *Home_page;
    QFrame *LastNotification_2;
    QLabel *label_12;
    QTextEdit *Notification_text;
    QLabel *label_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *LastNewsButton;
    QSpacerItem *verticalSpacer;
    QFrame *TimerToReturnBook_2;
    QLabel *time_to_return_title;
    QLabel *time_to_return_label;
    QLabel *consttext;
    QPushButton *ReturnButton;
    QFrame *CurrentBook_2;
    QLabel *current_book_logo;
    QPushButton *RenewButton;
    QLabel *Curren_book_title_lable;
    QLabel *current_book_lable;
    QWidget *Books_page;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *SearchEdit;
    QComboBox *SearchTypeComboBok;
    QTableWidget *BooksTable;
    QLabel *comment_in_books_table;
    QWidget *History_page;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *ListOfBorrowedBooksButton;
    QPushButton *ListOfReservedBooksButton;
    QTableWidget *YourBooksTable;
    QLabel *comment_in_books_table_2;
    QWidget *About_page;
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowUser)
    {
        if (MainWindowUser->objectName().isEmpty())
            MainWindowUser->setObjectName("MainWindowUser");
        MainWindowUser->resize(500, 380);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        MainWindowUser->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/Property 1=Variant2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindowUser->setWindowIcon(icon);
        MainWindowUser->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        MainWindowUser->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindowUser);
        centralwidget->setObjectName("centralwidget");
        leftSidebar = new QFrame(centralwidget);
        leftSidebar->setObjectName("leftSidebar");
        leftSidebar->setGeometry(QRect(-1, -1, 71, 381));
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
        LogOutButton = new QToolButton(leftSidebar);
        LogOutButton->setObjectName("LogOutButton");
        LogOutButton->setGeometry(QRect(-1, 280, 71, 21));
        QFont font1;
        font1.setBold(true);
        LogOutButton->setFont(font1);
        LogOutButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Downloads/logout 3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        LogOutButton->setIcon(icon1);
        LogOutButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        LogOutButton->setAutoRaise(true);
        layoutWidget = new QWidget(leftSidebar);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 90, 74, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        HomeButton = new QToolButton(layoutWidget);
        HomeButton->setObjectName("HomeButton");
        HomeButton->setFont(font1);
        HomeButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/element-2 2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HomeButton->setIcon(icon2);
        HomeButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        HomeButton->setAutoRaise(true);

        verticalLayout->addWidget(HomeButton);

        BooksButton = new QToolButton(layoutWidget);
        BooksButton->setObjectName("BooksButton");
        BooksButton->setFont(font1);
        BooksButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/book-1 1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BooksButton->setIcon(icon3);
        BooksButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        BooksButton->setAutoRaise(true);

        verticalLayout->addWidget(BooksButton);

        HistoryButton = new QToolButton(layoutWidget);
        HistoryButton->setObjectName("HistoryButton");
        HistoryButton->setFont(font1);
        HistoryButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/Vector.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        HistoryButton->setIcon(icon4);
        HistoryButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        HistoryButton->setAutoRaise(true);

        verticalLayout->addWidget(HistoryButton);

        AboutButton = new QToolButton(layoutWidget);
        AboutButton->setObjectName("AboutButton");
        AboutButton->setFont(font1);
        AboutButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        AboutButton->setIcon(icon5);
        AboutButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        AboutButton->setAutoRaise(true);

        verticalLayout->addWidget(AboutButton);

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
        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(350, 0, 61, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NotificationButton = new QToolButton(layoutWidget1);
        NotificationButton->setObjectName("NotificationButton");
        NotificationButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    qproperty-iconSize: 17px 17px; /* Adjust icon size */\n"
"}\n"
""));
        NotificationButton->setIcon(icon6);
        NotificationButton->setAutoRaise(true);

        horizontalLayout->addWidget(NotificationButton);

        SettingsButton = new QToolButton(layoutWidget1);
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
        Typelabel->setGeometry(QRect(170, 4, 51, 21));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        Typelabel->setFont(font2);
        Typelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        FullNameLabel = new QLabel(frame);
        FullNameLabel->setObjectName("FullNameLabel");
        FullNameLabel->setGeometry(QRect(30, 4, 111, 21));
        FullNameLabel->setMinimumSize(QSize(60, 0));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        FullNameLabel->setFont(font3);
        FullNameLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        mainContentArea = new QFrame(centralwidget);
        mainContentArea->setObjectName("mainContentArea");
        mainContentArea->setGeometry(QRect(69, 29, 431, 351));
        mainContentArea->setFrameShape(QFrame::Shape::StyledPanel);
        mainContentArea->setFrameShadow(QFrame::Shadow::Raised);
        stackedWidget = new QStackedWidget(mainContentArea);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 431, 331));
        stackedWidget->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        Home_page = new QWidget();
        Home_page->setObjectName("Home_page");
        LastNotification_2 = new QFrame(Home_page);
        LastNotification_2->setObjectName("LastNotification_2");
        LastNotification_2->setGeometry(QRect(210, 120, 211, 111));
        LastNotification_2->setStyleSheet(QString::fromUtf8("border-color:rrgb(170, 85, 0);"));
        LastNotification_2->setFrameShape(QFrame::Shape::StyledPanel);
        LastNotification_2->setFrameShadow(QFrame::Shadow::Raised);
        label_12 = new QLabel(LastNotification_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 0, 201, 41));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        label_12->setFont(font4);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Notification_text = new QTextEdit(LastNotification_2);
        Notification_text->setObjectName("Notification_text");
        Notification_text->setGeometry(QRect(40, 55, 151, 51));
        Notification_text->setMinimumSize(QSize(151, 0));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Source Code Pro")});
        font5.setPointSize(9);
        font5.setBold(true);
        font5.setItalic(true);
        Notification_text->setFont(font5);
        Notification_text->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit\n"
"{\n"
"background-color:transparent;\n"
"border-color:rgb(106, 68, 43);\n"
"border-radius : 15px;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Notification_text->setReadOnly(true);
        label_2 = new QLabel(Home_page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 240, 411, 81));
        label_2->setMinimumSize(QSize(360, 0));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("PMingLiU-ExtB")});
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setItalic(false);
        label_2->setFont(font6);
        label_2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        layoutWidget2 = new QWidget(Home_page);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 138, 145, 71));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_7 = new QSpacerItem(28, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        LastNewsButton = new QToolButton(layoutWidget2);
        LastNewsButton->setObjectName("LastNewsButton");
        LastNewsButton->setFont(font4);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../Downloads/icons8-news-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        LastNewsButton->setIcon(icon8);
        LastNewsButton->setIconSize(QSize(25, 25));
        LastNewsButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        LastNewsButton->setAutoRaise(true);

        horizontalLayout_5->addWidget(LastNewsButton);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        TimerToReturnBook_2 = new QFrame(Home_page);
        TimerToReturnBook_2->setObjectName("TimerToReturnBook_2");
        TimerToReturnBook_2->setGeometry(QRect(228, 21, 192, 89));
        TimerToReturnBook_2->setFrameShape(QFrame::Shape::StyledPanel);
        TimerToReturnBook_2->setFrameShadow(QFrame::Shadow::Raised);
        time_to_return_title = new QLabel(TimerToReturnBook_2);
        time_to_return_title->setObjectName("time_to_return_title");
        time_to_return_title->setGeometry(QRect(6, 11, 161, 31));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(false);
        time_to_return_title->setFont(font7);
        time_to_return_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        time_to_return_label = new QLabel(TimerToReturnBook_2);
        time_to_return_label->setObjectName("time_to_return_label");
        time_to_return_label->setGeometry(QRect(48, 55, 31, 31));
        time_to_return_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        consttext = new QLabel(TimerToReturnBook_2);
        consttext->setObjectName("consttext");
        consttext->setGeometry(QRect(90, 60, 41, 20));
        consttext->setMinimumSize(QSize(20, 0));
        ReturnButton = new QPushButton(TimerToReturnBook_2);
        ReturnButton->setObjectName("ReturnButton");
        ReturnButton->setGeometry(QRect(150, 60, 41, 20));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Segoe Fluent Icons")});
        font8.setPointSize(9);
        font8.setBold(false);
        font8.setItalic(true);
        font8.setKerning(false);
        ReturnButton->setFont(font8);
        ReturnButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #6A442B; /* Brown color */\n"
"    color: white;                 \n"
"    border-radius: 20px;               /* Adjust for pill shape */\n"
"                   /* Vertical padding, width will be set by layout */\n"
"                 \n"
"\n"
"}"));
        CurrentBook_2 = new QFrame(Home_page);
        CurrentBook_2->setObjectName("CurrentBook_2");
        CurrentBook_2->setGeometry(QRect(31, 21, 193, 89));
        CurrentBook_2->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"padding-right:10px;\n"
"}\n"
""));
        CurrentBook_2->setFrameShape(QFrame::Shape::StyledPanel);
        CurrentBook_2->setFrameShadow(QFrame::Shadow::Raised);
        current_book_logo = new QLabel(CurrentBook_2);
        current_book_logo->setObjectName("current_book_logo");
        current_book_logo->setGeometry(QRect(0, 0, 41, 31));
        current_book_logo->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/icons8-book-100.png")));
        current_book_logo->setScaledContents(true);
        RenewButton = new QPushButton(CurrentBook_2);
        RenewButton->setObjectName("RenewButton");
        RenewButton->setGeometry(QRect(140, 70, 50, 18));
        RenewButton->setFont(font8);
        RenewButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #6A442B; /* Brown color */\n"
"    color: white;                 \n"
"    border-radius: 20px;               /* Adjust for pill shape */\n"
"                   /* Vertical padding, width will be set by layout */\n"
"                 \n"
"\n"
"}"));
        Curren_book_title_lable = new QLabel(CurrentBook_2);
        Curren_book_title_lable->setObjectName("Curren_book_title_lable");
        Curren_book_title_lable->setGeometry(QRect(48, 10, 111, 31));
        QFont font9;
        font9.setPointSize(14);
        font9.setBold(true);
        Curren_book_title_lable->setFont(font9);
        current_book_lable = new QLabel(CurrentBook_2);
        current_book_lable->setObjectName("current_book_lable");
        current_book_lable->setGeometry(QRect(40, 40, 91, 41));
        QFont font10;
        font10.setPointSize(12);
        font10.setItalic(true);
        current_book_lable->setFont(font10);
        current_book_lable->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(Home_page);
        Books_page = new QWidget();
        Books_page->setObjectName("Books_page");
        layoutWidget_7 = new QWidget(Books_page);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(20, 22, 408, 51));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        SearchEdit = new QLineEdit(layoutWidget_7);
        SearchEdit->setObjectName("SearchEdit");
        QFont font11;
        font11.setPointSize(10);
        font11.setBold(true);
        SearchEdit->setFont(font11);

        horizontalLayout_7->addWidget(SearchEdit);

        SearchTypeComboBok = new QComboBox(layoutWidget_7);
        SearchTypeComboBok->addItem(QString());
        SearchTypeComboBok->addItem(QString());
        SearchTypeComboBok->addItem(QString());
        SearchTypeComboBok->addItem(QString());
        SearchTypeComboBok->addItem(QString());
        SearchTypeComboBok->addItem(QString());
        SearchTypeComboBok->setObjectName("SearchTypeComboBok");
        SearchTypeComboBok->setFont(font11);
        SearchTypeComboBok->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(SearchTypeComboBok);

        BooksTable = new QTableWidget(Books_page);
        if (BooksTable->rowCount() < 1)
            BooksTable->setRowCount(1);
        BooksTable->setObjectName("BooksTable");
        BooksTable->setGeometry(QRect(10, 90, 411, 251));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BooksTable->sizePolicy().hasHeightForWidth());
        BooksTable->setSizePolicy(sizePolicy);
        QFont font12;
        font12.setPointSize(5);
        font12.setBold(false);
        BooksTable->setFont(font12);
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
        comment_in_books_table = new QLabel(Books_page);
        comment_in_books_table->setObjectName("comment_in_books_table");
        comment_in_books_table->setGeometry(QRect(10, 90, 411, 241));
        QFont font13;
        font13.setFamilies({QString::fromUtf8("Sakkal Majalla")});
        font13.setPointSize(30);
        font13.setBold(true);
        comment_in_books_table->setFont(font13);
        comment_in_books_table->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"background-color: rgb(139, 94, 60);\n"
"}"));
        comment_in_books_table->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(Books_page);
        History_page = new QWidget();
        History_page->setObjectName("History_page");
        layoutWidget_9 = new QWidget(History_page);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(10, 10, 311, 31));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        ListOfBorrowedBooksButton = new QPushButton(layoutWidget_9);
        ListOfBorrowedBooksButton->setObjectName("ListOfBorrowedBooksButton");
        QFont font14;
        font14.setPointSize(9);
        font14.setBold(true);
        ListOfBorrowedBooksButton->setFont(font14);

        horizontalLayout_9->addWidget(ListOfBorrowedBooksButton);

        ListOfReservedBooksButton = new QPushButton(layoutWidget_9);
        ListOfReservedBooksButton->setObjectName("ListOfReservedBooksButton");
        ListOfReservedBooksButton->setFont(font14);

        horizontalLayout_9->addWidget(ListOfReservedBooksButton);

        YourBooksTable = new QTableWidget(History_page);
        if (YourBooksTable->columnCount() < 5)
            YourBooksTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        YourBooksTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        YourBooksTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        YourBooksTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        YourBooksTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        YourBooksTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (YourBooksTable->rowCount() < 1)
            YourBooksTable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        YourBooksTable->setItem(0, 0, __qtablewidgetitem5);
        YourBooksTable->setObjectName("YourBooksTable");
        YourBooksTable->setGeometry(QRect(10, 50, 411, 281));
        sizePolicy.setHeightForWidth(YourBooksTable->sizePolicy().hasHeightForWidth());
        YourBooksTable->setSizePolicy(sizePolicy);
        YourBooksTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: rgb(139, 94, 60); /* Black background for the table */\n"
"    alternate-background-color: rgb(106, 68, 43); /* Dark grey for alternating rows */\n"
"    color: white; /* White text color for cell content */\n"
"    gridline-color: #555555; /* Darker grey grid lines */\n"
"  border: 1px solid #555555;\n"
"   /* Border around the table */\n"
"    border-radius: 5px; /* Slightly rounded corners for the table */\n"
"    selection-background-color: #8B5E3C; /* Your brown color for selected rows */\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Style for the horizontal header */\n"
"QTableWidget QHeaderView::section {\n"
"    background-color:rgb(106, 68, 43); /* Black background for headers */\n"
"    color: white; /* White text for headers */\n"
"    border: none;\n"
"    border-bottom: 1px solid #555555; /* Bottom border for header sections */\n"
"   \n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Style for individual items (cells) */\n"
"QTableWidget::item {\n"
"   /* p"
                        "adding: 5px; /* Padding inside cells */\n"
"}"));
        comment_in_books_table_2 = new QLabel(History_page);
        comment_in_books_table_2->setObjectName("comment_in_books_table_2");
        comment_in_books_table_2->setGeometry(QRect(10, 50, 411, 281));
        comment_in_books_table_2->setFont(font13);
        comment_in_books_table_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"background-color: rgb(139, 94, 60);\n"
"}"));
        comment_in_books_table_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(History_page);
        About_page = new QWidget();
        About_page->setObjectName("About_page");
        label_33 = new QLabel(About_page);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(20, 30, 121, 51));
        frame_8 = new QFrame(About_page);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(190, 10, 121, 91));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        label_34 = new QLabel(frame_8);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(0, 20, 121, 51));
        label_34->setFont(font14);
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_35 = new QLabel(About_page);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(20, 120, 141, 51));
        label_35->setFont(font11);
        frame_10 = new QFrame(About_page);
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
        QFont font15;
        font15.setPointSize(6);
        font15.setBold(true);
        label_37->setFont(font15);
        label_37->setStyleSheet(QString::fromUtf8("color:white;"));
        label_36 = new QLabel(About_page);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(290, 230, 131, 31));
        label_36->setFont(font11);
        label_36->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_11 = new QFrame(About_page);
        frame_11->setObjectName("frame_11");
        frame_11->setGeometry(QRect(300, 270, 111, 41));
        frame_11->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:rgb(139, 94, 60);\n"
"border-radius:15px;\n"
"}"));
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        label_38 = new QLabel(frame_11);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(8, 10, 101, 20));
        label_38->setFont(font3);
        label_38->setStyleSheet(QString::fromUtf8("color:white;"));
        label_3 = new QLabel(About_page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 120, 121, 81));
        QFont font16;
        font16.setPointSize(10);
        font16.setBold(false);
        label_3->setFont(font16);
        label_3->setStyleSheet(QString::fromUtf8("border-color:rgb(85, 85, 0)"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(About_page);
        MainWindowUser->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindowUser);
        statusbar->setObjectName("statusbar");
        MainWindowUser->setStatusBar(statusbar);

        retranslateUi(MainWindowUser);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowUser);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowUser)
    {
        MainWindowUser->setWindowTitle(QCoreApplication::translate("MainWindowUser", "MainWindowUser", nullptr));
        logoImageLabel->setText(QString());
        LogOutButton->setText(QCoreApplication::translate("MainWindowUser", "Log out", nullptr));
        HomeButton->setText(QCoreApplication::translate("MainWindowUser", "Home ", nullptr));
        BooksButton->setText(QCoreApplication::translate("MainWindowUser", "Books", nullptr));
        HistoryButton->setText(QCoreApplication::translate("MainWindowUser", "History", nullptr));
        AboutButton->setText(QCoreApplication::translate("MainWindowUser", "About", nullptr));
        label->setText(QString());
        toolButton_4->setText(QString());
        NotificationButton->setText(QString());
        SettingsButton->setText(QString());
        Typelabel->setText(QCoreApplication::translate("MainWindowUser", "User Type", nullptr));
        FullNameLabel->setText(QCoreApplication::translate("MainWindowUser", "FULL NAME", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowUser", "LAST NOTIFICATION", nullptr));
        Notification_text->setHtml(QCoreApplication::translate("MainWindowUser", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Source Code Pro'; font-size:9pt; font-weight:700; font-style:italic;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p></body></html>", nullptr));
        Notification_text->setPlaceholderText(QCoreApplication::translate("MainWindowUser", "No Notifications yet", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowUser", "\"A reader lives a thousand\n"
"               lives before he dies The man \n"
"                        who never reads lives only one.\"\n"
"", nullptr));
        LastNewsButton->setText(QCoreApplication::translate("MainWindowUser", "   Last News", nullptr));
        time_to_return_title->setText(QCoreApplication::translate("MainWindowUser", "Time To Return Book", nullptr));
        time_to_return_label->setText(QCoreApplication::translate("MainWindowUser", "7", nullptr));
        consttext->setText(QCoreApplication::translate("MainWindowUser", "days", nullptr));
        ReturnButton->setText(QCoreApplication::translate("MainWindowUser", "Return", nullptr));
        current_book_logo->setText(QString());
        RenewButton->setText(QCoreApplication::translate("MainWindowUser", "Renew", nullptr));
        Curren_book_title_lable->setText(QCoreApplication::translate("MainWindowUser", "Current Book", nullptr));
        current_book_lable->setText(QCoreApplication::translate("MainWindowUser", "Book Name", nullptr));
        SearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindowUser", "Search For Book", nullptr));
        SearchTypeComboBok->setItemText(0, QCoreApplication::translate("MainWindowUser", "Search Type", nullptr));
        SearchTypeComboBok->setItemText(1, QCoreApplication::translate("MainWindowUser", "By Title", nullptr));
        SearchTypeComboBok->setItemText(2, QCoreApplication::translate("MainWindowUser", "By Author", nullptr));
        SearchTypeComboBok->setItemText(3, QCoreApplication::translate("MainWindowUser", "By ISBN", nullptr));
        SearchTypeComboBok->setItemText(4, QCoreApplication::translate("MainWindowUser", "By Year", nullptr));
        SearchTypeComboBok->setItemText(5, QCoreApplication::translate("MainWindowUser", "By Type", nullptr));

        SearchTypeComboBok->setPlaceholderText(QString());
        comment_in_books_table->setText(QCoreApplication::translate("MainWindowUser", "START SEARCHING ABOUT \n"
"BOOKS", nullptr));
        ListOfBorrowedBooksButton->setText(QCoreApplication::translate("MainWindowUser", "List Of Borrowed Books", nullptr));
        ListOfReservedBooksButton->setText(QCoreApplication::translate("MainWindowUser", "List Of Reserved Books", nullptr));
        QTableWidgetItem *___qtablewidgetitem = YourBooksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindowUser", "ISBN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = YourBooksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindowUser", "TITLE", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = YourBooksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindowUser", "AUTHOR", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = YourBooksTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindowUser", "DATE ", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = YourBooksTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindowUser", "AVAILABLE", nullptr));

        const bool __sortingEnabled = YourBooksTable->isSortingEnabled();
        YourBooksTable->setSortingEnabled(false);
        YourBooksTable->setSortingEnabled(__sortingEnabled);

        comment_in_books_table_2->setText(QCoreApplication::translate("MainWindowUser", "GET INFORMATION ABOUT\n"
" YOUR BOOKS", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindowUser", "Current Location", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindowUser", "School Location \n"
"in the map", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindowUser", "Library Hours of Operation", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindowUser", "libraryensia@ensia.edu.dz", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindowUser", "Contact Information", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindowUser", "libraryensia@ensia.edu.dz", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowUser", "8 AM ---->  4PM\n"
"    SATURDAY \n"
"     TO\n"
"  THURSDAY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowUser: public Ui_MainWindowUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWUSER_H

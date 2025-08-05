
#include "mainwindowuser.h"
#include "ui_mainwindowuser.h"
#include <QMessageBox>
#include <QDate>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QFrame>
#include <QFont>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QSize>
#include <QApplication>
#include "loginwindow.h"
#include "databasemanageruser.h"
#include "databasemanagerbook.h"

// Forward declaration for FixType function
QString FixType(User* user);



MainWindowUser::MainWindowUser(User* user,DatabaseManagerUser* dbuser,DatabaseManagerBook* dbbook,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowUser),user(user),dbbook(dbbook),dbuser(dbuser)
{
    ui->setupUi(this);

    connect(ui->SearchEdit, &QLineEdit::textChanged, this, &MainWindowUser::searchBooks);
    connect(ui->SearchTypeComboBok, &QComboBox::currentTextChanged, this, &MainWindowUser::searchBooks);

    ui->stackedWidget->setCurrentWidget(ui->Home_page);
    ui->FullNameLabel->setText(user->getFirstName() + " " + user->getLastName());
    ui->Typelabel->setText(FixType(user).toUpper());


    QList<Book*>books = dbbook->getCurrentBooksForUser(user);


    if(books.empty())
    {
        ui->current_book_lable->hide();
        ui->Curren_book_title_lable->setText("Get A New Book For Reading");
        ui->RenewButton->setText("Borrow");



        ui->time_to_return_title->hide();
        ui->time_to_return_label->hide();
        ui->ReturnButton->hide();
    }
    else
    {
        QStringList bookTitles;
        for (QList<Book*>::const_iterator it = books.constBegin(); it != books.constEnd(); ++it)
        {
            bookTitles << (*it)->getTitle();
        }

        ui->current_book_lable->setText(bookTitles.join("\n"));

        QDate due_date =dbbook->getDueDate(books[0]->getISBN(),user->getIDCard());
        QDate current_date = QDate::currentDate();
        int days = due_date.daysTo(current_date);

        ui->time_to_return_label->setText(QString::number(days));
        if (days < 0)
        {
            ui->time_to_return_label->setStyleSheet("color: red;");
        }
        else
        {
            ui->time_to_return_label->setStyleSheet("color: green;");
        }


        if(QDate::currentDate() > due_date.addDays(2))
        {
            ui->Notification_text->setText("DEAR USER, Please return the book as the due date has expired "
                                           + QString::number(days) + " days ago.\n"
                                             "You will be penalized if you don't return it!");

        }


    }

}



MainWindowUser::~MainWindowUser()
{
    delete ui;
}




void MainWindowUser::handleBorrow(int row,QList<Book*>books,User* user)
{
    if (row >= 0 && row < books.size()) {
        Book* book = books.at(row);

        if( dbbook->BorrowBook(book,user) == "")
        {

            QMessageBox::information(this, "Borrow", "Borrowing book: " + book->getTitle());

        }
        else
        {
            QMessageBox::information(this, "Failed to Borrow", dbbook->BorrowBook(book,user));
        }


    }
}

void MainWindowUser::handleReserve(int row,QList<Book*>books,User* user)
{
    if (row >= 0 && row < books.size()) {
        Book* book = books.at(row);

        if(dbbook->reserveBook(book,user))
        {
            QMessageBox::information(this, "Reserve", "Reserving book: " + book->getTitle());
        }

        else
        {
            QMessageBox::information(this, "Failed to Reserve", "You can't reserve this book");
        }

    }
}


void MainWindowUser::on_LogOutButton_clicked()
{
    this->close();
    LoginWindow* window = new LoginWindow();
    window->show();

}


void MainWindowUser::searchBooks()
{
    QList<Book*> books;
    QString searchText = ui->SearchEdit->text().trimmed();
    QString searchType = ui->SearchTypeComboBok->currentText().trimmed();

    if (searchText.isEmpty()) {
        ui->BooksTable->clearContents();
        ui->BooksTable->setRowCount(0);
        ui->comment_in_books_table->hide();
        return;
    }

    // Case-insensitive search type comparison
    QString searchTypeLower = searchType.toLower();
    if (searchTypeLower == "by title") {
        books = dbbook->searchBookByTitle(searchText);
    } else if (searchTypeLower == "by author") {
        books = dbbook->searchBookByAuthor(searchText);
    } else if (searchTypeLower == "by isbn") {
        books = dbbook->searchBookByISBN(searchText);
    } else if (searchTypeLower == "by type") {
        books = dbbook->searchBookByField(searchText);
    } else if (searchTypeLower == "by year") {
        books = dbbook->searchBookByYear(searchText.toInt());
    } else {
        return;
    }

    ui->BooksTable->clearContents();
    ui->BooksTable->setRowCount(0);

    if (books.isEmpty()) {
        ui->comment_in_books_table->setText("No available result for this search");
        ui->comment_in_books_table->show();
        return;
    }

    ui->comment_in_books_table->hide();
    ui->BooksTable->setColumnCount(9);
    ui->BooksTable->setRowCount(books.size());
    QStringList headerLabels = {"Title", "Author", "Year", "ISBN", "Field", "Available", "Count", "Borrow", "Reserve"};
    ui->BooksTable->setHorizontalHeaderLabels(headerLabels);
    for (int i = 0; i < books.size(); ++i)
    {
        ui->BooksTable->setItem(i, 0, new QTableWidgetItem(books[i]->getTitle()));
        ui->BooksTable->setItem(i, 1, new QTableWidgetItem(books[i]->getAuthor()));
        ui->BooksTable->setItem(i, 2, new QTableWidgetItem(QString::number(books[i]->getPublicationYear())));
        ui->BooksTable->setItem(i, 3, new QTableWidgetItem(books[i]->getISBN()));
        ui->BooksTable->setItem(i, 4, new QTableWidgetItem(books[i]->getField()));
        ui->BooksTable->setItem(i, 5, new QTableWidgetItem(dbbook->IsBookAvailable(books[i]) ? "Yes" : "No"));
        ui->BooksTable->setItem(i, 6, new QTableWidgetItem(QString::number(dbbook->getBookCount(books[i]))));

        QPushButton* BorrowButton = new QPushButton("Borrow");
        connect(BorrowButton, &QPushButton::clicked, this, [=]() {
            handleBorrow(i, books, user);
        });
        ui->BooksTable->setCellWidget(i, 7, BorrowButton);

        QPushButton* ReserveButton = new QPushButton("Reserve");
        connect(ReserveButton, &QPushButton::clicked, this, [=]() {
            handleReserve(i, books, user);
        });
        ui->BooksTable->setCellWidget(i, 8, ReserveButton);
    }

    ui->BooksTable->resizeColumnsToContents();
    ui->BooksTable->resizeRowsToContents();
    ui->BooksTable->viewport()->update();
    ui->BooksTable->update();
}



void MainWindowUser::on_RenewButton_clicked()
{
    if(ui->RenewButton->text() == "Renew")
 {
    QList<Book*> books;

    books = dbbook->getCurrentBooksForUser(user);

    QList<QString> valid_books ;

    for(int i = 0; i < books.size(); ++i)
    {
        Book* book = books.at(i);
        if(dbbook->renewBook(book, user))
        {
            valid_books.append(book->getTitle());
        }
    }

    if(!valid_books.empty())
    {
        QString successMsg = "Successfully renewed the following book(s):\n " + valid_books.join("\n• ");
        QMessageBox::information(this,"Succefull operation" ,successMsg);
        return ;
    }
    else
    {
        QMessageBox::critical(this,"Failed Operation","Failed to renew the book / books");
    }
  }



else
{
     ui->stackedWidget->setCurrentWidget(ui->Books_page);
 }

}



void MainWindowUser::on_LastNewsButton_clicked()
{
    // Create a top-level window with a title bar and close button
    QWidget* news = new QWidget(nullptr, Qt::Window);
    news->setWindowTitle("📰 Latest News");
    news->resize(500, 350);

    // Main layout
    QVBoxLayout* layout = new QVBoxLayout(news);
    layout->setContentsMargins(15, 15, 15, 15);
    layout->setSpacing(10);

    // Header label
    QLabel* header = new QLabel("📢 Welcome to the News Reader!");
    QFont headerFont("Segoe UI", 14, QFont::Bold);
    header->setFont(headerFont);
    layout->addWidget(header);

    // Divider line
    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    // Text area
    QTextEdit* text = new QTextEdit();
    text->setReadOnly(true);
    text->setText("- 🗞️ News 1: The library now has 100+ new books.\n"
                  "- 🔧 News 2: Maintenance will occur this weekend.\n"
                  "- 🚀 News 3: A new digital system is coming soon!");
    QFont textFont("Segoe UI", 10);
    text->setFont(textFont);
    layout->addWidget(text);

    // Set the layout and show the window
    news->setLayout(layout);
    news->show();
}







void MainWindowUser :: handleRenew(int row,QList<Book*>books,User* user)
{
    if (row >= 0 && row < books.size()) {
        Book* book = books.at(row);

        if(dbbook->renewBook(book,user))
        {
            QMessageBox::information(this, "Renew", "Renewing book: " + book->getTitle());
        }

        else
        {
            QMessageBox::information(this, "Failed to Renew", "You can't renew this book");
        }

    }
}



void MainWindowUser :: handleReturn(int row,QList<Book*>books,User* user)
{
    if (row >= 0 && row < books.size()) {
        Book* book = books.at(row);

        if(dbbook->returnBook(book,user))
        {
            QMessageBox::information(this, "Return", "Returning book: " + book->getTitle());
        }

        else
        {
            QMessageBox::information(this, "Failed to Return", "You can't return this book");
        }

    }
}


void MainWindowUser :: handleClaim(int row,QList<Book*>books,User* user)
{
    if (row >= 0 && row < books.size()) {
        Book* book = books.at(row);

        if(dbbook->claimBook(book,user))
        {
            QMessageBox::information(this, "Claim", "Claiming book: " + book->getTitle());
        }

        else
        {
            QMessageBox::information(this, "Failed to Claim", "You can't claim this book");
        }

    }
}



void MainWindowUser::on_ReturnButton_clicked()
{
    QList<Book*> books;

    books = dbbook->getCurrentBooksForUser(user);
    if(books.empty())
    {
        QMessageBox::critical(this,"Operation Failed","There is no book to return ");
        return;
    }

    QList<QString> returned_books;

    for(Book* book : books)
    {
        QDate due_date = dbbook->getDueDate(book->getISBN(),user->getIDCard());
        if(QDate::currentDate() >= due_date)
        {
            if(dbbook->returnBook(book,user))
            {
                returned_books.append(book->getTitle());
            }

        }
    }

    if(returned_books.empty())
    {
        QMessageBox::warning(this,"Failed to Return","No books were returned because none are due yet.");
        return;
    }
    else
    {
        QString successMsg = "Successfully returned the following book(s):\n• " + returned_books.join("\n• ");
        QMessageBox::information(this, "Successful Operation", successMsg);
        return;
    }


}


void MainWindowUser::on_BooksButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Books_page);  
}




void MainWindowUser::on_HomeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Home_page);
}


void MainWindowUser::on_HistoryButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->History_page);
}


void MainWindowUser::on_AboutButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->About_page);
}


void MainWindowUser::on_ListOfBorrowedBooksButton_clicked()
{
    // Ensure the table is visible and properly configured
    ui->YourBooksTable->setVisible(true);
    ui->YourBooksTable->show();
    ui->comment_in_books_table_2->hide();

    // Clear any existing content and reset the table
    ui->YourBooksTable->clearContents();
    ui->YourBooksTable->clear();
    ui->YourBooksTable->setRowCount(0);
    ui->YourBooksTable->setColumnCount(0);

    QList<Book*> books = dbbook->getCurrentBooksForUser(user);

    qDebug() << "Borrowed books button clicked. Found" << books.size() << "borrowed books for user.";

    if(books.empty())
    {
        ui->comment_in_books_table_2->show();
        ui->comment_in_books_table_2->setText("No Borrowed Text Now !,Try to Borrow now ");
        qDebug() << "No borrowed books found for user.";
        return ;
    }

    // Set up the table structure properly
    ui->YourBooksTable->setColumnCount(7);
    ui->YourBooksTable->setRowCount(books.size());

    // Set headers BEFORE adding data
    QStringList headerLabels = {"Title", "Author", "Year", "ISBN", "Field", "Renew","Return"};
    ui->YourBooksTable->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with data
    for (int i=0 ; i<books.size() ; i++)
    {
        // Create items and set them immediately
        ui->YourBooksTable->setItem(i, 0, new QTableWidgetItem(books[i]->getTitle()));
        ui->YourBooksTable->setItem(i, 1, new QTableWidgetItem(books[i]->getAuthor()));
        ui->YourBooksTable->setItem(i, 2, new QTableWidgetItem(QString::number(books[i]->getPublicationYear())));
        ui->YourBooksTable->setItem(i, 3, new QTableWidgetItem(books[i]->getISBN()));
        ui->YourBooksTable->setItem(i, 4, new QTableWidgetItem(books[i]->getField()));

        QPushButton* RenewButton = new QPushButton("Renew");
        connect(RenewButton, &QPushButton::clicked, this, [=]() {
            handleRenew(i, books, user);
        });
        ui->YourBooksTable->setCellWidget(i, 5, RenewButton);

        QPushButton* ReturnButton = new QPushButton("Return");
        connect(ReturnButton, &QPushButton::clicked, this, [=]() {
            handleReturn(i, books, user);
        });
        ui->YourBooksTable->setCellWidget(i, 6, ReturnButton);
    }

    // Force the table to update and repaint
    ui->YourBooksTable->resizeColumnsToContents();
    ui->YourBooksTable->resizeRowsToContents();
    ui->YourBooksTable->viewport()->update();
    ui->YourBooksTable->update();
}



void MainWindowUser::on_ListOfReservedBooksButton_clicked()
{
    // Ensure the table is visible and properly configured
    ui->YourBooksTable->setVisible(true);
    ui->YourBooksTable->show();
    ui->comment_in_books_table_2->hide();

    // Clear any existing content and reset the table
    ui->YourBooksTable->clearContents();
    ui->YourBooksTable->clear();
    ui->YourBooksTable->setRowCount(0);
    ui->YourBooksTable->setColumnCount(0);

    QList<Book*> books = dbbook->getCurrentReservationsForUser(user);

    qDebug() << "Reserved books button clicked. Found" << books.size() << "reserved books for user.";

    if(books.empty())
    {
        ui->comment_in_books_table_2->show();
        ui->comment_in_books_table_2->setText("No Reservations Now !,Try to Reserve now ");
        qDebug() << "No reserved books found for user.";
        return ;
    }

    // Set up the table structure properly
    ui->YourBooksTable->setColumnCount(6);
    ui->YourBooksTable->setRowCount(books.size());

    // Set headers BEFORE adding data
    QStringList headerLabels = {"Title", "Author", "Year", "ISBN", "Field", "Claim"};
    ui->YourBooksTable->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with data
    for (int i=0 ; i<books.size() ; i++)
    {
        // Create items and set them immediately
        ui->YourBooksTable->setItem(i, 0, new QTableWidgetItem(books[i]->getTitle()));
        ui->YourBooksTable->setItem(i, 1, new QTableWidgetItem(books[i]->getAuthor()));
        ui->YourBooksTable->setItem(i, 2, new QTableWidgetItem(books[i]->getPublicationYear()));
        ui->YourBooksTable->setItem(i, 3, new QTableWidgetItem(books[i]->getISBN()));
        ui->YourBooksTable->setItem(i, 4, new QTableWidgetItem(books[i]->getField()));

        QPushButton* ClaimButton = new QPushButton("Claim");
        connect(ClaimButton, &QPushButton::clicked, this, [=]() {
            handleClaim(i, books, user);
        });
        ui->YourBooksTable->setCellWidget(i, 5, ClaimButton);
    }

    // Force the table to update and repaint
    ui->YourBooksTable->resizeColumnsToContents();
    ui->YourBooksTable->resizeRowsToContents();
    ui->YourBooksTable->viewport()->update();
    ui->YourBooksTable->update();
}


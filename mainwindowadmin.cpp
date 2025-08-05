#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"
#include "userdialog.h"
#include "bookdialog.h"
#include <QMessageBox>
#include "databasemanageruser.h"


MainWindowAdmin::MainWindowAdmin(User* user ,DatabaseManagerUser* dbuser,DatabaseManagerBook* dbbook,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowAdmin)   ,user(user), dbbook(dbbook),dbuser(dbuser)
{
    ui->setupUi(this);


    ui->stackedWidget->setCurrentWidget(ui->Home_page_2);
    ui->FullNameLabel->setText(user->getFirstName() + " " + user->getLastName());
    ui->Typelabel->setText(FixType(user).toUpper());

    connect(ui->SearchUserEdit, &QLineEdit::textChanged, this, &MainWindowAdmin::searchUsers);
    connect(ui->SearchBookEdit, &QLineEdit::textChanged, this, &MainWindowAdmin::searchBooks);
    connect(ui->SearchUserTypeComboBox, &QComboBox::currentTextChanged, this, &MainWindowAdmin::searchUsers);
    connect(ui->SearchBookTypeComboBox, &QComboBox::currentTextChanged, this, &MainWindowAdmin::searchBooks);


}



MainWindowAdmin::~MainWindowAdmin()
{
    delete ui;
}





void MainWindowAdmin::searchUsers()
{
    QList<User*> users;

    QString searchText = ui->SearchUserEdit->text().trimmed();
    QString searchType = ui->SearchUserTypeComboBox->currentText().trimmed();

    if (searchText.isEmpty()) {
        ui->UsersTable->clearContents();
        ui->UsersTable->setRowCount(0);
        ui->comment_in_users_table->hide();
        return;
    }

    // Case-insensitive search type comparison
    QString searchTypeLower = searchType.toLower();
    if (searchTypeLower == "by first name") {
        users = dbuser->searchUserByFirstName(searchText);
    } else if (searchTypeLower == "by id") {
        users = dbuser->searchUserByID(searchText.toLongLong());
    } else if (searchTypeLower == "by type") {
        users = dbuser->searchUserByType(searchText);
    } else if (searchTypeLower == "by university") {
        users = dbuser->searchUserByUniversity(searchText);
    } else {
        qDebug() << "Invalid user search type: " << searchType;
    }

    ui->UsersTable->clearContents();
    ui->UsersTable->setRowCount(0);

    if (users.isEmpty()) {
        ui->comment_in_users_table->setText("No Available Users For this search");
        ui->comment_in_users_table->show();
        return;
    }

    ui->comment_in_users_table->hide();
    ui->UsersTable->setColumnCount(5);
    ui->UsersTable->setRowCount(users.size());
    QStringList headerLabels = {"FirstName", "LastName", "ID CARD", "UNIVERSITY", "TYPE"};
    ui->UsersTable->setHorizontalHeaderLabels(headerLabels);
    for (int i = 0; i < users.size(); ++i) {
        ui->UsersTable->setItem(i, 0, new QTableWidgetItem(users[i]->getFirstName()));
        ui->UsersTable->setItem(i, 1, new QTableWidgetItem(users[i]->getLastName()));
        ui->UsersTable->setItem(i, 2, new QTableWidgetItem(QString::number(users[i]->getIDCard())));
        ui->UsersTable->setItem(i, 3, new QTableWidgetItem(users[i]->getUniversity()));
        ui->UsersTable->setItem(i, 4, new QTableWidgetItem(FixType(users[i])));
    }
    ui->UsersTable->resizeColumnsToContents();
    ui->UsersTable->resizeRowsToContents();
    ui->UsersTable->viewport()->update();
    ui->UsersTable->update();
}


void MainWindowAdmin::searchBooks()
{
    QList<Book*> books;

    QString searchText = ui->SearchBookEdit->text().trimmed();
    QString searchType = ui->SearchBookTypeComboBox->currentText().trimmed();

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
        QMessageBox::warning(this, "Search failed", "Invalid book search type.");
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
    ui->BooksTable->setColumnCount(7);
    ui->BooksTable->setRowCount(books.size());
    QStringList headerLabels = {"Title", "Author", "Year", "ISBN", "Field", "Available", "Count"};
    ui->BooksTable->setHorizontalHeaderLabels(headerLabels);
    for (int i = 0; i < books.size(); ++i) {
        ui->BooksTable->setItem(i, 0, new QTableWidgetItem(books[i]->getTitle()));
        ui->BooksTable->setItem(i, 1, new QTableWidgetItem(books[i]->getAuthor()));
        ui->BooksTable->setItem(i, 2, new QTableWidgetItem(QString::number(books[i]->getPublicationYear())));
        ui->BooksTable->setItem(i, 3, new QTableWidgetItem(books[i]->getISBN()));
        ui->BooksTable->setItem(i, 4, new QTableWidgetItem(books[i]->getField()));
        ui->BooksTable->setItem(i, 5, new QTableWidgetItem(dbbook->IsBookAvailable(books[i]) ? "Yes" : "No"));
        ui->BooksTable->setItem(i, 6, new QTableWidgetItem(QString::number(dbbook->getBookCount(books[i]))));
    }
    ui->BooksTable->resizeColumnsToContents();
    ui->BooksTable->resizeRowsToContents();
    ui->BooksTable->viewport()->update();
    ui->BooksTable->update();
}


void MainWindowAdmin::on_AddUserButton_clicked()
{

    UserDialog* page = new UserDialog("ADD");
    page->show();
}



void MainWindowAdmin::on_PenalizeUserButton_clicked()
{
    UserDialog* page  = new UserDialog("PENALIZE");
    page->show();
}


void MainWindowAdmin::on_DeleteUserButton_clicked()
{
     UserDialog* page = new UserDialog("DELETE");
     page->show();
}





void MainWindowAdmin::on_EditUserButton_clicked()
{
    UserDialog* page = new UserDialog("EDIT");
    page->show();
}




void MainWindowAdmin::on_ListOfBannedUsersButton_clicked()
{
    QList<User*> users = dbuser->listblockedUsers();

    // Clear and reset the table properly
    ui->UsersTable->clearContents();
    ui->UsersTable->clear();
    ui->UsersTable->setRowCount(0);
    ui->UsersTable->setColumnCount(0);

    if(users.empty())
    {
        ui->comment_in_users_table->setText("No Banned Users !");
        ui->comment_in_users_table->show();
        return ;
    }

    ui->comment_in_users_table->hide();

    // Set up the table structure properly
    ui->UsersTable->setColumnCount(5);
    ui->UsersTable->setRowCount(users.size());

    // Set headers BEFORE adding data
     QStringList headerLabels = {"FirstName", "LastName", "ID CARD", "UNIVERSITY", "TYPE"};
    ui->UsersTable->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with data
    for (int i=0 ; i<users.size() ; i++)
    {
        ui->UsersTable->setItem(i,0,new QTableWidgetItem(users[i]->getFirstName()));
        ui->UsersTable->setItem(i,1,new QTableWidgetItem(users[i]->getLastName()));
        ui->UsersTable->setItem(i,2,new QTableWidgetItem(users[i]->getIDCard()));
        ui->UsersTable->setItem(i,3,new QTableWidgetItem(users[i]->getUniversity()));
        ui->UsersTable->setItem(i,4,new QTableWidgetItem(FixType(users[i])));
    }

    // Force the table to update and repaint
    ui->UsersTable->resizeColumnsToContents();
    ui->UsersTable->resizeRowsToContents();
    ui->UsersTable->viewport()->update();
    ui->UsersTable->update();
    ui->UsersTable->show();
}







void MainWindowAdmin::on_ListOfPenalizedUsersButton_clicked()
{
    QList<User*> users = dbuser->listpenalizeUsers();

    // Clear and reset the table properly
    ui->UsersTable->clearContents();
    ui->UsersTable->clear();
    ui->UsersTable->setRowCount(0);
    ui->UsersTable->setColumnCount(0);

    if(users.empty())
    {
        ui->comment_in_users_table->setText("No Penalized Users !");
        ui->comment_in_users_table->show();
        return ;
    }

    ui->comment_in_users_table->hide();

    // Set up the table structure properly
    ui->UsersTable->setColumnCount(5);
    ui->UsersTable->setRowCount(users.size());

    // Set headers BEFORE adding data
    QStringList headerLabels = {"FirstName", "LastName", "ID CARD", "UNIVERSITY", "TYPE"};
    ui->UsersTable->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with data
    for (int i=0 ; i<users.size() ; i++)
    {
        ui->UsersTable->setItem(i,0,new QTableWidgetItem(users[i]->getFirstName()));
        ui->UsersTable->setItem(i,1,new QTableWidgetItem(users[i]->getLastName()));
        ui->UsersTable->setItem(i,2,new QTableWidgetItem(users[i]->getIDCard()));
        ui->UsersTable->setItem(i,3,new QTableWidgetItem(users[i]->getUniversity()));
        ui->UsersTable->setItem(i,4,new QTableWidgetItem(FixType(users[i])));
    }

    // Force the table to update and repaint
    ui->UsersTable->resizeColumnsToContents();
    ui->UsersTable->resizeRowsToContents();
    ui->UsersTable->viewport()->update();
    ui->UsersTable->update();
    ui->UsersTable->show();
}


void MainWindowAdmin::on_AddBookButton_clicked()
{
    BookDialog* page = new BookDialog("ADD");
    page->show();
}


void MainWindowAdmin::on_DeleteBookButton_clicked()
{
    BookDialog* page = new BookDialog("DELETE");
    page->show();
}



void MainWindowAdmin::on_EditBookButton_clicked()
{
    BookDialog* page = new BookDialog("EDIT");
    page->show();
}





void MainWindowAdmin::on_ListOfBorrowedBooksButton_clicked()
{
    QList<Book*> books = dbbook->getBorrowedBooks();

    // Clear and reset the table properly
    ui->BooksTable_2->clearContents();
    ui->BooksTable_2->clear();
    ui->BooksTable_2->setRowCount(0);
    ui->BooksTable_2->setColumnCount(0);

    if(books.empty())
    {
        ui->comment_in_books_table_2->setText("No Borrowed books for now");
        ui->comment_in_books_table_2->show();
        return;
    }

    ui->comment_in_books_table_2->hide();

    // Set up the table structure properly
    ui->BooksTable_2->setColumnCount(6);
    ui->BooksTable_2->setRowCount(books.size());

    // Set headers BEFORE adding data
    QStringList headerLabels = {"Title", "Author", "Year", "ISBN", "Field", "Available"};
    ui->BooksTable_2->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with data
    for (int i=0 ; i<books.size() ; i++)
    {
        ui->BooksTable_2->setItem(i,0,new QTableWidgetItem(books[i]->getTitle()));
        ui->BooksTable_2->setItem(i,1,new QTableWidgetItem(books[i]->getAuthor()));
        ui->BooksTable_2->setItem(i,2,new QTableWidgetItem(books[i]->getPublicationYear()));
        ui->BooksTable_2->setItem(i,3,new QTableWidgetItem(books[i]->getISBN()));
        ui->BooksTable_2->setItem(i,4,new QTableWidgetItem(books[i]->getField()));
        bool available = dbbook->IsBookAvailable(books[i]);
        ui->BooksTable_2->setItem(i, 5, new QTableWidgetItem(available ? "Yes" : "No"));
    }

    // Force the table to update and repaint
    ui->BooksTable_2->resizeColumnsToContents();
    ui->BooksTable_2->resizeRowsToContents();
    ui->BooksTable_2->viewport()->update();
    ui->BooksTable_2->update();
}






void MainWindowAdmin::on_dashboardButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Home_page_2);
}




void MainWindowAdmin::on_dashboardButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Books_page_2);
}



void MainWindowAdmin::on_dashboardButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->History_page_2);
}


void MainWindowAdmin::on_dashboardButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Users_page);
}


void MainWindowAdmin::on_dashboardButton_5_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->About_page_2);
}


void MainWindowAdmin::on_ListOfUnreturnedBooksButton_clicked()
{
    QList<Book*> books = dbbook->getUnreturnedBooks();

    // Clear and reset the table properly
    ui->BooksTable_2->clearContents();
    ui->BooksTable_2->clear();
    ui->BooksTable_2->setRowCount(0);
    ui->BooksTable_2->setColumnCount(0);

    if(books.empty())
    {
        ui->comment_in_books_table_2->setText("No unreturned books for now");
        ui->comment_in_books_table_2->show();
        return;
    }

    ui->comment_in_books_table_2->hide();

    // Set up the table structure properly
    ui->BooksTable_2->setColumnCount(6);
    ui->BooksTable_2->setRowCount(books.size());

    // Set headers BEFORE adding data
    QStringList headerLabels = {"Title", "Author", "Year", "ISBN", "Field", "Available"};
    ui->BooksTable_2->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with data
    for (int i=0 ; i<books.size() ; i++)
    {
        ui->BooksTable_2->setItem(i,0,new QTableWidgetItem(books[i]->getTitle()));
        ui->BooksTable_2->setItem(i,1,new QTableWidgetItem(books[i]->getAuthor()));
        ui->BooksTable_2->setItem(i,2,new QTableWidgetItem(books[i]->getPublicationYear()));
        ui->BooksTable_2->setItem(i,3,new QTableWidgetItem(books[i]->getISBN()));
        ui->BooksTable_2->setItem(i,4,new QTableWidgetItem(books[i]->getField()));
        bool available = dbbook->IsBookAvailable(books[i]);
        ui->BooksTable_2->setItem(i, 5, new QTableWidgetItem(available ? "Yes" : "No"));
    }

    // Force the table to update and repaint
    ui->BooksTable_2->resizeColumnsToContents();
    ui->BooksTable_2->resizeRowsToContents();
    ui->BooksTable_2->viewport()->update();
    ui->BooksTable_2->update();
}


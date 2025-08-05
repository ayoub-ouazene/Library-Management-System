#include "bookdialog.h"
#include "ui_bookdialog.h"
#include "databasemanagerbook.h"
#include "databasemanageruser.h"
#include <QMessageBox>


BookDialog::BookDialog(QString type, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookDialog),type(type)
{
    ui->setupUi(this);
}

BookDialog::~BookDialog()
{
    delete ui;
}

void BookDialog::on_pushButton_clicked()
{

    QString title = ui->TitleEdit->text();
    QString author = ui->AuthorEdit->text();
    int publicationYear = ui->YearEdit->text().toInt();
    QString field = ui->FieldEdit->text();
    bool digitalVersion = ui->HasDigitalEdit->text().toInt();
    QString ISBN = ui->ISBNEdit->text();
    QString libraryCode = ui->LibraryCodeEdit->text();
    int borrowingDaysLimit = ui->BorrowingDaysEdit->text().toInt();
    int renewalLimit = ui->RenewalDaysEdit->text().toInt();


    if(!valid_name(title) || !valid_name(author) || !valid_name(field) || !valid_name(ISBN) || !valid_name(libraryCode))
    {
        QMessageBox::critical(this, "Failed","PLease enter all the informations");
        return;
    }

    DatabaseManagerBook dbbook;

    Book* book = new Book(title,author,publicationYear,field,digitalVersion,ISBN,libraryCode,borrowingDaysLimit,renewalLimit);

    if(type =="ADD" )
    {
        if(dbbook.addBook(book))
        {
            QMessageBox::information(this,"Succefull Registration","Bookr added Succefully");
            this->hide();
        }
        else
        {
            QMessageBox::warning(this,"Failed","Failed To Add book");
            qDebug() << "Error: Failed to add user to database. Check DatabaseManager logs.";
        }
    }
    else if(type == "EDIT")
    {
        if(dbbook.editBook(book))
        {
            QMessageBox::information(this,"Succefull Registration","Bookr added Succefully");
            this->hide();
        }
        else
        {
            QMessageBox::warning(this,"Failed","Failed To Add book");
            qDebug() << "Error: Failed to add user to database. Check DatabaseManager logs.";
        }
    }
    else if (type == "DELETE")
    {
        if(dbbook.deleteBook(book))
        {
            QMessageBox::information(this,"Succefull Registration","Bookr added Succefully");
            this->hide();
        }
        else
        {
            QMessageBox::warning(this,"Failed","Failed To Add book");
        }
    }
    else
    {
        qDebug()<<"invalid type ...";
        return ;
    }

    delete book;
}


void BookDialog::on_pushButton_2_clicked()
{
    this->hide();
}


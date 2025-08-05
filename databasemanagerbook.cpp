#include "databasemanagerbook.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QRegularExpression>
#include <QStringList>
#include "databasemanageruser.h"

DatabaseManagerBook :: DatabaseManagerBook(QObject* parent ):DatabaseManager(parent)
{
    if (!m_db.isOpen()) {
        qDebug() << "Database not open in DatabaseManagerBook constructor";
        return;
    }

}

DatabaseManagerBook::~DatabaseManagerBook() {}

bool DatabaseManagerBook :: addBook(Book* book)const
{
    if(!book)
    {
        qDebug()<<"Pointer to Book doesn't exist (null ptr) ";
        return 0;
    }

    QSqlQuery query;

    if(searchBook(book))
    {
        query.prepare("SELECT NUMBER_OF_COPIES , NUMBER_OF_AVAILABLE_BOOKS FROM books WHERE ISBN = ?");
        query.addBindValue(book->getISBN());
        int number1 = 1 ;
        int number2 = 1 ;
        if(query.exec())
        {
            if(query.next())
            {
                number1 = query.value(0).toInt();
                number2 = query.value(1).toInt();
            }
        }
        else
        {
            qDebug()<<"Failed to find the book !";
            return 0;
        }



        query.prepare("UPDATE books SET NUMBER_OF_COPIES = ? , NUMBER_OF_AVAILABLE_BOOKS = ?  WHERE ISBN = ?");
        query.addBindValue(number1+1);
        query.addBindValue(number2+1);
        query.addBindValue(book->getISBN());

        if(query.exec())
        {
            qDebug()<<"adding book succefully | increasing number of books by 1 ";
            return 1;
        }
        return 0;

    }
    else
    {
       query.prepare("INSERT INTO books VALUES (:isbn,:title,:author,:library_code ,:field,:number_of_copies ,:year , :digital_version , :borrowing_limit ,:renewal_limit , :number_of_available_books)"
                      );
        query.bindValue(":isbn",book->getISBN());
       query.bindValue(":title" , book->getTitle());
        query.bindValue(":author",book->getAuthor());
       query.bindValue(":library_code",book->getLibraryCode());
        query.bindValue(":field",book->getField());
       query.bindValue(":number_of_copies",1);
        query.bindValue(":year",book->getPublicationYear());
       query.bindValue(":digital_version",book->hasDigitalVersion());
        query.bindValue(":borrowing_limit",book->getBorrowingDaysLimit());
       query.bindValue(":renewal_limit",book->getRenewalLimit());
        query.bindValue(":number_of_available_books",0);

       if(query.exec())
        {
            qDebug()<<"adding book succefully to the data base ";
           return 1;
       }
       return 0;
    }
}

bool DatabaseManagerBook :: searchBook(Book* book)const
{
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM books WHERE ISBN = :isbn ");
    query.bindValue(":isbn",book->getISBN());
      int number=0;
    if(query.exec())
    {
        if(query.next())
        {

            number = query.value(0).toInt();
        }
    }

    if(number != 1)
    {
        qDebug()<<"Book not Found ! ";
        return 0;
    }

    return 1;

}


bool DatabaseManagerBook :: deleteBook(Book* book)const
{
    if(!book)
    {
        qDebug()<<"the Pointer is null ! ";
        return 0;
    }

    QSqlQuery query;
    if(!searchBook(book))
    {
        qDebug()<<"the Book doesn't exists in the db ! ";
        return 0;
    }

    query.prepare("DELETE FROM books WHERE ISBN = :isbn");
    query.bindValue(":isbn",book->getISBN());

    if(query.exec())
    {
        qDebug()<<"The book was deleted succefully ! ";
        return 1;
    }

    return 0;

}

bool DatabaseManagerBook :: editBook(Book* book)const
{

    if(!book)
    {
        qDebug()<<"the Pointer is null ! ";
        return 0;
    }

    QSqlQuery query;
    if(!searchBook(book))
    {
        qDebug()<<"the Book doesn't exists in the db ! ";
        return 0;
    }

    query.prepare("UPDATE books SET  TITLE = ? , AUTHOR = ?, LIBRARY_CODE = ? , FIELD_OF_BOOK = ? , PUBLICATION_YEAR = ?, DIGITAL_VERSION = ?, BORROWING_DAYS_LIMIT = ?, RENEWAL_LIMIT = ? WHERE ISBN = :isbn ");
    query.addBindValue(book->getTitle());
    query.addBindValue(book->getAuthor());
    query.addBindValue(book->getLibraryCode());
    query.addBindValue(book->getField());
    query.addBindValue(book->getPublicationYear());
    query.addBindValue(book->hasDigitalVersion());
    query.addBindValue(book->getBorrowingDaysLimit());
    query.addBindValue(book->getRenewalLimit());
    query.bindValue(":isbn",book->getISBN());

    if(query.exec())
    {
        qDebug()<<"updating book info succefully ! ";
        return 1;
    }

    return 0 ;

}

int DatabaseManagerBook :: getBookCount(Book* book)const
{

    if(!book)
    {
        qDebug()<<"the Pointer is null ! ";
        return 0;
    }

    QSqlQuery query;
    if(!searchBook(book))
    {
        qDebug()<<"the Book doesn't exists in the db ! ";
        return 0;
    }


    query.prepare("SELECT NUMBER_OF_COPIES FROM books WHERE ISBN = :isbn");

    query.bindValue(":isbn",book->getISBN());

    if(query.exec())
    {
        if(query.next())
        {
            return query.value(0).toInt();
        }
    }
    qDebug()<<"failed to get data ! "<<query.lastError().text();
    return 0;

}

  int DatabaseManagerBook :: getBookCount(QString ISBN)const
{


      QSqlQuery query;
      if(!searchBook(ISBN))
      {
          qDebug()<<"the Book doesn't exists in the db ! ";
          return 0;
      }


      query.prepare("SELECT NUMBER_OF_COPIES FROM books WHERE ISBN = :isbn");

      query.bindValue(":isbn",ISBN);

      if(query.exec())
      {
          if(query.next())
          {
              return query.value(0).toInt();
          }
      }
      qDebug()<<"failed to get data ! "<<query.lastError().text();
      return 0;
}


 void DatabaseManagerBook :: updateBookCount(Book* book ,int count)
{
     if(!book)
     {
         qDebug()<<"the Pointer is null ! ";
         return;
     }

     QSqlQuery query;
     if(!searchBook(book))
     {
         qDebug()<<"the Book doesn't exists in the db ! ";
         return;
     }
     query.prepare("SELECT  NUMBER_OF_COPIES , NUMBER_OF_AVAILABLE_BOOKS FROM books  WHERE ISBN = ? ");
     query.addBindValue(book->getISBN());

     int number_available = 0;
     int number_copies = 0;
     if(query.exec())
     {
         if(query.next())
         {
             number_copies =  query.value(0).toInt();
             number_available = query.value(1).toInt();
         }
     }

     int def ;
     def = number_copies - number_available;
     if(count < number_copies && count < def )
     {
         qDebug()<<"can't set this number ! ";
         return;
     }
     query.prepare("UPDATE books SET NUMBER_OF_COPIES = ? , NUMBER_OF_AVAILABLE_BOOKS = ?  WHERE ISBN = :isbn ");
     query.addBindValue(count);
     query.addBindValue(count - def);
     query.bindValue(":isbn",book->getISBN());

     if(!query.exec())
     {
         qDebug()<<"Failed to update the count of books"<<query.lastError().text();
         return;
     }
     qDebug()<<"Succefully updated ! ";

}


void DatabaseManagerBook :: updateBookCount(QString ISBN ,int count)
{


    QSqlQuery query;
    if(!searchBook(ISBN))
    {
        qDebug()<<"the Book doesn't exists in the db ! ";
        return;
    }
    query.prepare("SELECT  NUMBER_OF_COPIES , NUMBER_OF_AVAILABLE_BOOKS FROM books  WHERE ISBN = ? ");
    query.addBindValue(ISBN);

    int number_available = 0;
    int number_copies = 0;
    if(query.exec())
    {
        if(query.next())
        {
            number_copies =  query.value(0).toInt();
            number_available = query.value(1).toInt();
        }
    }

    int def ;
    def = number_copies - number_available;
    if(count < number_copies && count < def )
    {
        qDebug()<<"can't set this number ! ";
        return;
    }
    query.prepare("UPDATE books SET NUMBER_OF_COPIES = ? , NUMBER_OF_AVAILABLE_BOOKS = ?  WHERE ISBN = :isbn ");
    query.addBindValue(count);
    query.addBindValue(count - def);
    query.bindValue(":isbn",ISBN);

    if(!query.exec())
    {
        qDebug()<<"Failed to update the count of books"<<query.lastError().text();
        return;
    }
    qDebug()<<"Succefully updated ! ";
}


 bool DatabaseManagerBook :: searchBook(const QString& isbn) const
{
     QSqlQuery query;

     query.prepare("SELECT COUNT(*) FROM books WHERE ISBN = :isbn ");
     query.bindValue(":isbn",isbn);
     int number=0;
     if(query.exec())
     {
         if(query.next())
         {

             number = query.value(0).toInt();
         }
     }

     if(number != 1)
     {
         qDebug()<<"Book not Found ! ";
         return 0;
     }

     return 1;
}

 QList<Book*> DatabaseManagerBook :: searchBookByISBN(const QString& isbn) const
{
     QSqlQuery query;
    QList<Book*> list;

     if(!searchBook(isbn))
    {
        qDebug()<<"the Book does not exist ! ";
         return list;
     }

     query.prepare("SELECT * FROM books WHERE ISBN = :isbn ");
     query.bindValue(":isbn",isbn);

     if(query.exec())
     {
         if(query.next())
         {
             QString title = query.value("TITLE").toString();
             QString author = query.value("AUTHOR").toString();
             int publicationYear = query.value("PUBLICATION_YEAR").toInt();
             QString field = query.value("FIELD_OF_BOOK").toString();
             bool digitalVersion = query.value("DIGITAL_VERSION").toInt();
             QString libraryCode = query.value("LIBRARY_CODE").toString();
             int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
             int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

             Book* book = new Book(title,author,publicationYear,field,digitalVersion,isbn,libraryCode,borrowingDaysLimit,renewalLimit);

             list.append(book);
         }
     }
     else
     {
         qDebug()<<"cannot find the book ! ";
     }

     return list ;

}

 QList<Book*> DatabaseManagerBook :: searchBookByTitle(const QString& title) const
{
     QSqlQuery query;
     QList<Book*> list;


     query.prepare("SELECT * FROM books WHERE TITLE = :title ");
     query.bindValue(":title",title);

     if(query.exec())
     {
         while(query.next())
         {
             QString author = query.value("AUTHOR").toString();
             int publicationYear = query.value("PUBLICATION_YEAR").toInt();
             QString field = query.value("FIELD_OF_BOOK").toString();
             bool digitalVersion = query.value("DIGITAL_VERSION").toInt();
             QString ISBN = query.value("ISBN").toString();
             QString libraryCode = query.value("LIBRARY_CODE").toString();
             int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
             int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

             Book* book = new Book(title,author,publicationYear,field,digitalVersion,ISBN,libraryCode,borrowingDaysLimit,renewalLimit);

             list.append(book);
         }

         if(list.empty())
         {
             qDebug()<<"no such book with this title : "<<title; ;
         }
     }
     else
     {
         qDebug()<<"Failed to find books ! "<<query.lastError().text();
     }

     return list ;

}


 QList<Book*> DatabaseManagerBook :: searchBookByAuthor(const QString& author) const
{
     QSqlQuery query;
     QList<Book*> list;


     query.prepare("SELECT * FROM books WHERE AUTHOR = :author ");
     query.bindValue(":author",author);

     if(query.exec())
     {
         while(query.next())
         {
             QString title = query.value("TITLE").toString();
             int publicationYear = query.value("PUBLICATION_YEAR").toInt();
             QString field = query.value("FIELD_OF_BOOK").toString();
             bool digitalVersion = query.value("DIGITAL_VERSION").toInt();
             QString ISBN = query.value("ISBN").toString();
             QString libraryCode = query.value("LIBRARY_CODE").toString();
             int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
             int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

             Book* book = new Book(title,author,publicationYear,field,digitalVersion,ISBN,libraryCode,borrowingDaysLimit,renewalLimit);

             list.append(book);
         }

         if(list.empty())
         {
             qDebug()<<"no such book with this author : "<<author; ;
         }
     }
     else
     {
         qDebug()<<"Failed to find books ! "<<query.lastError().text();
     }

     return list ;

}

    QList<Book*> DatabaseManagerBook :: searchBookByField(const QString& field) const
{
        QSqlQuery query;
        QList<Book*> list;


        query.prepare("SELECT * FROM books WHERE FIELD_OF_BOOK = :field ");
        query.bindValue(":field",field);

        if(query.exec())
        {
            while(query.next())
            {
                QString title = query.value("TITLE").toString();
                QString author = query.value("AUTHOR").toString();
                int publicationYear = query.value("PUBLICATION_YEAR").toInt();
                bool digitalVersion = query.value("DIGITAL_VERSION").toInt();
                QString ISBN = query.value("ISBN").toString();
                QString libraryCode = query.value("LIBRARY_CODE").toString();
                int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
                int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

                Book* book = new Book(title,author,publicationYear,field,digitalVersion,ISBN,libraryCode,borrowingDaysLimit,renewalLimit);

                list.append(book);
            }

            if(list.empty())
            {
                qDebug()<<"no such book in this field : "<<field;
            }
        }
        else
        {
            qDebug()<<"Failed to find books ! "<<query.lastError().text();
        }

        return list ;
}

QList<Book*> DatabaseManagerBook :: searchBookByYear(const int& year ) const
{
    QSqlQuery query;
    QList<Book*> list;


    query.prepare("SELECT * FROM books WHERE PUBLICATION_YEAR = :year ");
    query.bindValue(":year",year);

    if(query.exec())
    {
        while(query.next())
        {
            QString title = query.value("TITLE").toString();
            QString author = query.value("AUTHOR").toString();
            QString field = query.value("FIELD_OF_BOOK").toString();
            bool digitalVersion = query.value("DIGITAL_VERSION").toInt();
            QString ISBN = query.value("ISBN").toString();
            QString libraryCode = query.value("LIBRARY_CODE").toString();
            int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
            int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

            Book* book = new Book(title,author,year,field,digitalVersion,ISBN,libraryCode,borrowingDaysLimit,renewalLimit);

            list.append(book);
        }

        if(list.empty())
        {
            qDebug()<<"no such book in this year : "<<year;
        }
    }
    else
    {
        qDebug()<<"Failed to find books ! "<<query.lastError().text();
    }

    return list ;
}


QList<Book*> DatabaseManagerBook :: getAllBooks() const
{
    QSqlQuery query;
    QList<Book*> list;

    query.prepare("SELECT * FROM books ");

    if(query.exec())
    {
        while(query.next())
        {
            QString title = query.value("TITLE").toString();
            QString author = query.value("AUTHOR").toString();
             int year = query.value("PUBLICATION_YEAR").toInt();
            QString field = query.value("FIELD_OF_BOOK").toString();
            bool digitalVersion = query.value("DIGITAL_VERSION").toInt();
            QString ISBN = query.value("ISBN").toString();
            QString libraryCode = query.value("LIBRARY_CODE").toString();
            int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
            int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

            Book* book = new Book(title,author,year,field,digitalVersion,ISBN,libraryCode,borrowingDaysLimit,renewalLimit);

            list.append(book);
        }
        if(list.empty())
        {
            qDebug()<<"no such book in the data base  ! ";
        }
    }

    else
    {
        qDebug()<<"Failed to find books ! "<<query.lastError().text();
    }

    return list ;
}


bool DatabaseManagerBook :: reserveBook(Book* book, User* user)const
{
    if(!book || !user)
    {
        qDebug()<<"null Pointer ! ";
        return 0;
    }

    if(!searchBook(book))
    {
        qDebug()<<"Book does not exists ! ";
        return 0;
    }

    DatabaseManagerUser db;
    if(!db.searchUser(user))
    {
        qDebug()<< "User does not exists ! ";
        return 0;
    }

    if(IsBookAvailable(book))
    {
        qDebug()<<"The Book is already available you can not reserve it ! ";
        return 0;
    }

    QSqlQuery query ;

    query.prepare("SELECT * FROM bookcopies WHERE ISBN = :isbn  ORDER BY DUE_DATE ASC LIMIT 1 ");
    query.bindValue(":isbn",book->getISBN());

    int copy = 0;
    if(query.exec())
    {
        if(query.next())
        {
            copy= query.value(0).toInt();
        }
        else
        {
            qDebug()<<"Failed in execution ...";
            return 0;
        }
    }
    else
    {
        qDebug()<<"Failed in execution ...";
        return 0;
    }

    if(copy == 0)
    {
        qDebug()<<"No currently borrowed copies of this book found to place a reservation";
        return 0;
    }

    query.prepare("SELECT QUEUE_POSITION FROM reservations WHERE COPY_ID = :copy AND ISBN = :isbn ORDER BY QUEUE_POSITION DESC LIMIT 1");
    query.bindValue(":copy",copy);
    query.bindValue(":isbn",book->getISBN());

    int last_pos =0;

    if(query.exec())
    {
        if(query.next())
        {
            last_pos= query.value(0).toInt();
        }
        else
        {
            qDebug()<<"Failed in execution ...";
            return 0;
        }
    }
    else
    {
        qDebug()<<"Failed in execution ...";
        return 0;
    }



    query.prepare("SELECT DUE_DATE FROM bookcopies WHERE ISBN = :isbn AND COPY_ID = :copy ");
    query.bindValue(":isbn",book->getISBN());
    query.bindValue(":copy",copy);
    QString date = "" ;

    if(query.exec())
    {
        if(query.next())
        {
            date = query.value(0).toString();
        }
        else
        {
            qDebug()<<"Failed in execution ...";
            return 0;
        }
    }
    else
    {
        qDebug()<<"Failed in execution ...";
        return 0;
    }

    if(date  == "")
    {
        qDebug()<<"There is no available copy ...";
        return 0;
    }

    QDate myDate = QDate::fromString(date, Qt::ISODate);

    query.prepare("INSERT INTO reservations (ISBN, COPY_ID, ID_CARD, RESERVATION_DATE, QUEUE_POSITION, EXPIRATION_DATE) VALUES ( ?,?,?,?,?,?)");
    query.addBindValue(book->getISBN());
    query.addBindValue(copy);
    query.addBindValue(user->getIDCard());
    query.addBindValue(QDate::currentDate().toString(Qt::ISODate));
    query.addBindValue(last_pos+1);
    query.addBindValue(myDate.addDays(1));

    if(query.exec())
    {
        qDebug()<<"Reservation went succefully ... ";
        query.prepare("UPDATE bookcopies SET DUE_DATE = ? WHERE ISBN = :isbn AND COPY_ID = :copy ");
        query.addBindValue(myDate.addDays(book->getBorrowingDaysLimit() +1 ));
        query.bindValue(":isbn",book->getISBN());
        query.bindValue(":copy",copy);

        if(query.exec())
        {
            qDebug()<<"All reservation's steps went well !";
            return 1;
        }
        else
        {
            qDebug()<<"Failed to update bookcopies ";
            return 0;
        }

    }

    qDebug()<<"Failed in execution ...";
    return 0;



}



QString DatabaseManagerBook :: BorrowBook(Book* book,User* user) const
{
    if(!book || !user)
    {
        qDebug()<<"null Pointer ! ";
        return "Failed to get book";
    }

    if(!searchBook(book))
    {
        qDebug()<<"Book does not exists ! ";
        return "Book does not exists !";
    }
    DatabaseManagerUser db;
    if(!db.searchUser(user))
    {
        return "User does not exists ! ";
    }

    if(!IsBookAvailable(book))
    {
         return "No available Book to get ";
    }

    QSqlQuery query ;
    query.prepare("SELECT * FROM bookcopies WHERE ISBN = :isbn AND IS_AVAILABLE = 1 LIMIT 1");
    query.bindValue(":isbn",book->getISBN());

    int copy = 0;
    if(query.exec())
    {
        if(query.next())
        {
            copy = query.value(0).toInt();
        }
        else
        {
            return "Failed to execute the query" ;
        }
    }
    else
    {
        return "Failed to execute the query" ;
    }


    query.prepare("SELECT BORROWING_DAYS_LIMIT , NUMBER_OF_AVAILABLE_BOOKS FROM books WHERE ISBN = :isbn ");
    query.bindValue(":isbn",book->getISBN());
    int days = 0;
    int number_available=0;
    if(query.exec())
    {
        if(query.next())
        {
            days = query.value(0).toInt();
            number_available=query.value(1).toInt();
        }
        else
        {
            return "Failed to execute the query" ;
        }

    }
    else
    {
        return "Failed to execute the query" ;
    }


    query.prepare("UPDATE bookcopies SET CURRENT_BORROWER_ID = :id , DUE_DATE = :date , IS_AVAILABLE = 0 WHERE COPY_ID = :copy ");
    query.bindValue(":id",user->getIDCard());
    query.bindValue(":date",QDate::currentDate().addDays(days).toString(Qt::ISODate));
    query.bindValue(":copy",copy);

    if(query.exec())
    {
        query.prepare("INSERT INTO transformations ( ISBN , COPY_ID , OPERATION_DATE , OPERATION_TYPE , ID_CARD , EMAIL , DUE_DATE , RETURNED ) VALUES (?,?,?,?,?,?,?,?)");

        query.addBindValue(book->getISBN());
        query.addBindValue(copy);
        query.addBindValue(QDate::currentDate().toString(Qt::ISODate));
        query.addBindValue("BORROW");
        query.addBindValue(user->getIDCard());
        query.addBindValue(user->getEmail());
        query.addBindValue(QDate::currentDate().addDays(days).toString(Qt::ISODate));
        query.addBindValue(0);

        if(query.exec())
        {
            query.prepare("UPDATE books SET NUMBER_OF_AVAILABLE_BOOKS = ? WHERE ISBN = :isbn ");
            query.addBindValue(number_available-1);
            query.bindValue(":isbn",book->getISBN());

            if(query.exec())
            {
                  qDebug()<<"Borrowing operation was completed succefully ! ";
            }
            return "";
        }
        else
        {
            qDebug()<<"Failed to borrow the book from bookcopies table  ";
            return "Failed to execute the query" ;
        }



    }
    else
    {
        qDebug()<<"Failed to borrow the book from bookcopies table  ";
        return "Failed to execute the query" ;
    }



}



bool DatabaseManagerBook :: IsBookAvailable(Book* book)const
{
    if(!book)
    {
        qDebug()<<"null Pointer ! ";
        return 0 ;
    }

    QSqlQuery query ;

    query.prepare("SELECT COUNT(*) FROM bookcopies WHERE ISBN = :isbn  AND IS_AVAILABLE = 1 ");
    query.bindValue(":isbn",book->getISBN());

    if(query.exec())
    {
        if(query.next())
        {
            if(query.value(0).toInt() > 0)
            {
                qDebug()<<"There is an available copy ";
                return 1 ;
            }
            else
            {
                  qDebug()<<"There is not an available copy ";
                return 0 ;
            }
        }

    }

    qDebug()<<"Failed to execute query ! ";
    return 0;


}



 bool DatabaseManagerBook :: renewBook(Book* book, User* user)const
{

    if(!book || !user)
    {
        qDebug()<<"Null ptr !";
         return 0;
    }

     DatabaseManagerUser dbuser;
     if(!searchBook(book) || ! dbuser.searchUser(user))
     {
         qDebug()<<"Book or user is not valid ... ";
         return 0;
     }

     QSqlDatabase db = QSqlDatabase::database();
     db.transaction();

     QSqlQuery query ;
     query.prepare("SELECT * FROM transformations WHERE ISBN = :isbn AND ID_CARD = :id AND OPERATION_TYPE = :operation ORDER BY OPERATION_DATE DESC");
     query.bindValue(":isbn",book->getISBN());
     query.bindValue(":id",user->getIDCard());
     query.bindValue(":operation","BORROW");
     int copy=0;
     QString date="";
     if(query.exec())
     {
         if(query.next())
         {
             date = query.value("DUE_DATE").toString();
             copy= query.value("COPY_ID").toInt();
         }
         else
         {
             db.rollback();
             qDebug()<<"There is no user that borrow this book ";
             return 0 ;
         }
     }
     else
     {
        db.rollback();
         qDebug()<<"Failed to execute query , no borrower already ";
         return 0 ;
     }
     if(copy == 0 || date =="")
     {
          db.rollback();
         qDebug()<<"There is no user that borrow this book ";
         return 0 ;
     }

     QDate myDate = QDate::fromString(date, Qt::ISODate);

     if(myDate != QDate::currentDate())
     {
          db.rollback();
         qDebug()<<"You can't renew if it is not the due date  ";
         return 0 ;
     }

     query.prepare("SELECT COUNT(*) FROM reservations WHERE ISBN = :isbn AND COPY_ID = :copy");
     query.bindValue(":isbn",book->getISBN());
     query.bindValue(":copy",copy);

     if(query.exec())
     {
         if(query.next())
         {
             if(query.value(0).toInt() > 0)
             {
                  db.rollback();
                 qDebug()<<"There is already reservations for this copy , you cannot renew it ";
                 return 0 ;
             }
             else
             {
                 qDebug()<<"You can renew the Book succefully for "<<book->getRenewalLimit()<<" days ";

                 query.prepare("UPDATE transformations SET RETURNED = 1 WHERE ISBN = :isbn AND COPY_ID = :copy AND ID_CARD = :id ");
                 query.bindValue(":isbn",book->getISBN());
                 query.bindValue(":copy",copy);
                 query.bindValue(":id",user->getIDCard());
                 if(!query.exec())
                 {
                      db.rollback();
                     qDebug()<<"Failed to execute query ";
                     return 0;
                 }

                query.prepare("INSERT INTO transformations ( ISBN , COPY_ID , OPERATION_DATE , OPERATION_TYPE , ID_CARD , EMAIL , DUE_DATE , RETURNED ) VALUES (?,?,?,?,?,?,?,?)");

                 query.addBindValue(book->getISBN());
                 query.addBindValue(copy);
                 query.addBindValue(QDate::currentDate().toString(Qt::ISODate));
                 query.addBindValue("RENEW");
                 query.addBindValue(user->getIDCard());
                 query.addBindValue(user->getEmail());
                 query.addBindValue(QDate::currentDate().addDays(book->getRenewalLimit()).toString(Qt::ISODate));
                 query.addBindValue(0);

                 if(!query.exec())
                 {
                      db.rollback();
                     qDebug()<<"Failed to execute query ";
                     return 0;
                 }

                 qDebug()<<"Transformation added succefully";

                 query.prepare("UPDATE bookcopies SET DUE_DATE = :date WHERE COPY_ID = :copy AND ISBN = :isbn ");
                 query.bindValue(":date",QDate::currentDate().addDays(book->getRenewalLimit()).toString(Qt::ISODate));
                 query.bindValue(":copy",copy);
                 query.bindValue(":isbn",book->getISBN());

                 if(!query.exec())
                 {
                      db.rollback();
                     qDebug()<<"Failed to execute query ";
                     return 0;
                 }
                 db.commit();
                 return 1 ;
             }
         }

     }

      db.rollback();
     qDebug()<<"Failed to execute query ";
     return 0;

}



bool DatabaseManagerBook :: returnBook(Book* book , User* user)const
{
    if(!book || !user)
    {
        qDebug()<<"Null ptr !";
        return 0;
    }

    DatabaseManagerUser dbuser;
    if(!searchBook(book) || ! dbuser.searchUser(user))
    {
        qDebug()<<"Book or user is not valid ... ";
        return 0;
    }

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.transaction()) {
        qDebug() << "Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query ;
    query.prepare("SELECT * FROM transformations WHERE ISBN = :isbn AND ID_CARD = :id  ORDER BY OPERATION_DATE DESC LIMIT 1");
    query.bindValue(":isbn",book->getISBN());
    query.bindValue(":id",user->getIDCard());
    int copy=0;
    int returned=0;
    if(query.exec())
    {
        if(query.next())
        {
            returned = query.value("RETURNED").toInt();
            copy= query.value("COPY_ID").toInt();
        }
        else
        {
            db.rollback();
            qDebug()<<"There is no user that borrow this book ";
            return 0 ;
        }
    }
    else
    {
        db.rollback();
        qDebug()<<"Failed to execute query , no borrower already ";
        return 0 ;
    }
    if(copy == 0 )
    {
        db.rollback();
        qDebug()<<"There is no user that borrow this book ";
        return 0 ;
    }

    if(returned == 1)
    {
        db.rollback();
        qDebug()<<"The Copy is already returned";
        return 0 ;
    }

    query.prepare("UPDATE transformations SET RETURNED = 1 WHERE ISBN = :isbn AND ID_CARD = :id AND COPY_ID = :copy ");
    query.bindValue(":isbn",book->getISBN());
    query.bindValue(":id",user->getIDCard());
    query.bindValue(":copy",copy);

    if(!query.exec())
    {
        db.rollback();
        qDebug()<<"Failed to execute query"<<query.lastError().text();
        return 0 ;
    }

    query.prepare("SELECT COUNT(*) FROM reservations WHERE ISBN = :isbn AND COPY_ID = :copy");
    query.bindValue(":isbn",book->getISBN());
    query.bindValue(":copy",copy);
    if(!query.exec())
    {
        db.rollback();
        qDebug()<<"Failed to execute query"<<query.lastError().text();
        return 0 ;
    }

    if(query.next())
    {
        if(query.value(0).toInt() == 0)
        {
            query.prepare("UPDATE bookcopies SET IS_AVAILABLE = 1 , CURRENT_BORROWER_ID = :id , DUE_DATE = :date  WHERE ISBN = :isbn AND COPY_ID = :copy");
            query.bindValue(":isbn",book->getISBN());
            query.bindValue(":copy",copy);
            query.bindValue(":id",QVariant());
            query.bindValue(":date",QVariant());

            if(!query.exec())
            {
                db.rollback();
                qDebug()<<"Failed to execute query"<<query.lastError().text();
                return 0 ;
            }

        }

            db.commit();
        qDebug()<<"Returned succefully ! ";
        return 1;
    }
    else
    {
        db.rollback();
        qDebug()<<"Failed to execute query"<<query.lastError().text();
        return 0 ;
    }

}



bool DatabaseManagerBook :: claimBook(Book* book,User* user)const
{

    if(!book || !user)
    {
        qDebug()<<"Null ptr !";
        return 0;
    }

    DatabaseManagerUser dbuser;
    if(!searchBook(book) || ! dbuser.searchUser(user))
    {
        qDebug()<<"Book or user is not valid ... ";
        return 0;
    }


    QSqlQuery query;
    query.prepare("SELECT * FROM reservations WHERE ISBN = :isbn AND ID = :id ");
    query.bindValue(":isbn",book->getISBN());
    query.bindValue(":id",user->getIDCard());

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query , no reserved book already ";
        return 0 ;
    }

    if(query.next())
    {
        if( query.value("EXPIRATION_DATE").toDate() == QDate::currentDate() )
        {
            QSqlQuery query2;
            query2.prepare("INSERT INTO transformations (ISBN, COPY_ID, OPERATION_DATE, OPERATION_TYPE, ID_CARD, EMAIL, DUE_DATE, RETURNED) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
            query2.addBindValue(book->getISBN());
            query2.addBindValue(query.value("COPY_ID").toInt());
            query2.addBindValue(QDate::currentDate().toString(Qt::ISODate));
            query2.addBindValue("BORROW");
            query2.addBindValue(user->getIDCard());
            query2.addBindValue(user->getEmail());
            query2.addBindValue(QDate::currentDate().addDays(book->getBorrowingDaysLimit()));
            query2.addBindValue(0);


            if(!query2.exec())
            {
                qDebug()<<"Failed to execute query , no reserved book already ";
                return 0 ;
            }


                QSqlQuery query3;
                query3.prepare("UPDATE bookcopies SET CURRENT_BORROWER_ID = :id  WHERE ISBN = :isbn AND COPY_ID = :copy ");
                query3.bindValue(":id",user->getIDCard());
                query3.bindValue(":isbn",book->getISBN());
                query3.bindValue(":copy" , query.value("COPY_ID").toInt());

                if(!query3.exec())
                {
                    qDebug()<<"Failed to execute query , no reserved book already ";
                    return 0 ;
                }
                    QSqlQuery query4;
                    query4.prepare("DELETE FROM reservations WHERE RESERVATION_ID = ? ");
                    query4.addBindValue(query.value("RESERVATION_ID").toInt());
                    if(query4.exec() )
                    {
                        return 1;
                    }
                    else
                    {
                        qDebug()<<"Failed to execute query , no reserved book already ";
                        return 0 ;
                    }


        }


    }


    return 0;

}




 QList<User*>  DatabaseManagerBook :: getBookBorrower(Book* book)const
{
     QList<User*>list;
     if(!book)
    {
        qDebug()<<"Null ptr !";
         return list;
     }

     if(!searchBook(book))
     {
         qDebug()<<"The Book is not available";
         return list;
     }


     QSqlQuery query;

     query.prepare("SELECT ID_CARD FROM transformations WHERE ISBN = :isbn AND RETURNED = 0");
     query.bindValue(":isbn",book->getISBN());

     if(!query.exec())
     {
         qDebug()<<"Failed to execute query";
         return list ;
     }

     long long id =0 ;

     while(query.next())
     {
         id = query.value(0).toLongLong();

         QSqlQuery query2;
         query2.prepare("SELECT * FROM users WHERE ID_CARD = :id ");
         query2.bindValue(":id",id);

         if(!query2.exec())
         {
             qDebug()<<"Failed to execute query";
             return list ;
         }

         QString First_name = query2.value("FIRST_NAME").toString();
         QString Last_name = query2.value("LAST_NAME").toString();
         QString email =  query2.value("EMAIL").toString();
         QString password = query2.value("PASSWORD").toString();
         QString date_of_birth = query2.value("DATE_OF_BIRTH").toString();
         QString University  = query2.value("UNIVERSITY").toString() ;
         QString PenaltyReason = query2.value("PENALTY_REASON").toString();
         int PenaltyDays = query2.value("PENALTY_DAYS").toInt();
         int RFID = query2.value("RFID").toInt();

         User* user = new User( First_name , Last_name ,  email ,password , date_of_birth , University , PenaltyReason , PenaltyDays ,  RFID ,id);

         list.append(user);


     }


     if(list.empty())
     {
         qDebug()<<"There is no Current Borrower for the book ...";
         return list ;
     }



     return list;

}




 QList<User*> DatabaseManagerBook :: getBookHistory( Book* book)const
{
     QList<User*>list;
     if(!book)
     {
         qDebug()<<"Null ptr !";
         return list;
     }

     if(!searchBook(book))
     {
         qDebug()<<"The Book is not available";
         return list;
     }


     QSqlQuery query;

     query.prepare("SELECT DISTINCT ID_CARD FROM transformations WHERE ISBN = :isbn ");
     query.bindValue(":isbn",book->getISBN());

     if(!query.exec())
     {
         qDebug()<<"Failed to execute query";
         return list ;
     }

     long long id =0 ;

     while(query.next())
     {
         id = query.value(0).toLongLong();

         QSqlQuery query2;
         query2.prepare("SELECT * FROM users WHERE ID_CARD = :id ");
         query2.bindValue(":id",id);

         if(!query2.exec())
         {
             qDebug()<<"Failed to execute query";
             return list ;
         }

         QString First_name = query2.value("FIRST_NAME").toString();
         QString Last_name = query2.value("LAST_NAME").toString();
         QString email =  query2.value("EMAIL").toString();
         QString password = query2.value("PASSWORD").toString();
         QString date_of_birth = query2.value("DATE_OF_BIRTH").toString();
         QString University  = query2.value("UNIVERSITY").toString() ;
         QString PenaltyReason = query2.value("PENALTY_REASON").toString();
         int PenaltyDays = query2.value("PENALTY_DAYS").toInt();
         int RFID = query2.value("RFID").toInt();

         User* user = new User( First_name , Last_name ,  email ,password , date_of_birth , University , PenaltyReason , PenaltyDays ,  RFID ,id);

         list.append(user);


     }


     if(list.empty())
     {
         qDebug()<<"There is no Current Borrower for the book ...";
         return list ;
     }



     return list;


}



QList<Book*> DatabaseManagerBook :: getCurrentBooksForUser(User* user)const
{
    QList<Book*> list;
    if(!user)
    {
        qDebug()<<"null ptr !";
        return list;
    }

    DatabaseManagerUser db;
    if(! db.searchUser(user))
    {
        qDebug()<<"user not found !";
        return list;
    }


    QSqlQuery query;

    query.prepare("SELECT * FROM bookcopies WHERE CURRENT_BORROWER_ID = :id");
    query.bindValue(":id",user->getIDCard());

    if(!query.exec())
    {
        qDebug()<<"Failed to execute ! ";
        return list;
    }


    while(query.next())
    {
        QString ISBN = query.value("ISBN").toString();
        Book* book;
        book = searchBookByISBN(ISBN).first();
        list.append(book);
    }

    if(list.empty())
    {
        qDebug()<<"Empty list , no book";
        return list;
    }

    qDebug()<<"Return Succefully ";
    return list;



}




QList<Book*> DatabaseManagerBook ::  getCurrentReservationsForUser(User* user)const
{
    QList<Book*> list;
    if(!user)
    {
        qDebug()<<"null ptr !";
        return list;
    }

    DatabaseManagerUser db;
    if(! db.searchUser(user))
    {
        qDebug()<<"user not found !";
        return list;
    }


    QSqlQuery query;

    query.prepare("SELECT * FROM reservations WHERE CURRENT_BORROWER_ID = :id");
    query.bindValue(":id",user->getIDCard());

    if(!query.exec())
    {
        qDebug()<<"Failed to execute ! ";
        return list;
    }


    while(query.next())
    {
        QString ISBN = query.value("ISBN").toString();
        Book* book;
        book = searchBookByISBN(ISBN).first();
        list.append(book);
    }

    if(list.empty())
    {
        qDebug()<<"Empty list , no book";
        return list;
    }

    qDebug()<<"Return Succefully ";
    return list;

}


 QList<Book*>  DatabaseManagerBook :: getBorrowedBooks()const
{
     QSqlQuery query;
    QList<Book*>  list;
    query.prepare("SELECT DISTINCT ISBN FROM bookcopies WHERE IS_AVAILABLE = 0 AND DUE_DATE > :date ");
     query.bindValue(":date",QDate::currentDate());

    if(!query.exec())
     {
         qDebug()<<"Failed to execute ! ";
        return    list;
    }

    while(query.next())
    {
        QString isbn = query.value("ISBN").toString();


        QList<Book*> bks= searchBookByISBN(isbn);

        Book* book =bks[0];


        if(book)
        {
            list.append(book);
        }
        else
        {
            qDebug()<<"invalid book !";
        }
    }


    return list;
}



 QList<Book*> DatabaseManagerBook :: getUnreturnedBooks()const
{
     QSqlQuery query;
     QList<Book*>  list;
     query.prepare("SELECT DISTINCT ISBN FROM bookcopies WHERE IS_AVAILABLE = 0 AND DUE_DATE < :date ");
     query.bindValue(":date",QDate::currentDate());

     if(!query.exec())
     {
         qDebug()<<"Failed to execute ! ";
         return    list;
     }

     while(query.next())
     {
         QString isbn = query.value("ISBN").toString();


         QList<Book*> bks= searchBookByISBN(isbn);

         Book* book =bks[0];


         if(book)
         {
             list.append(book);
         }
         else
         {
             qDebug()<<"invalid book !";
         }
     }


     return list;

}






QDate DatabaseManagerBook:: getDueDate(const QString&  ISBN ,const long long& id )const
{
    if(!searchBook(ISBN))
    {
        qDebug()<<" Book not available ";
        return QDate();
    }
    DatabaseManagerUser db;

    if(!db.searchUser(id))
    {
        qDebug()<<"User not available ";
        return QDate();
    }

    QSqlQuery query;
    query.prepare("SELECT DUE_DATE FROM transformations  WHERE   ISBN = :isbn  AND ID_CARD = :id AND RETURNED = 0");
    query.bindValue(":isbn",ISBN);
    query.bindValue(":id",id);

    if(!query.exec())
    {

        qDebug()<<"Failed to execute !  ";
        return QDate();
    }

    if(query.next())
    {
        qDebug()<<"return due date succefully  ";
        return query.value(0).toDate();
    }
    else
    {
        qDebug()<<"Failed to return ";
        return QDate();
    }




 }


bool validateName(const QString& name) {
    return !name.trimmed().isEmpty();
}

bool validateYear(int year) {
    const int currentYear = QDate::currentDate().year();
    return year >= 1900 && year <= currentYear;
}


bool  validateField(const QString& field) {
    static const QSet<QString> validFields = {
        "LIBRARY & INFORMATION SCIENCE",
        "SOCIAL SCIENCES",
        "LANGUAGE",
        "MANUFACTURE FOR SPECIFIC USES",
        "PHYSICS",
        "MANAGEMENT & BUSINESS",
        "CHEMISTRY",
        "PHILOSOPHY & PSYCHOLOGY",
        "SCIENCE (GENERAL)",
        "MEDICAL SCIENCES, MEDICINE",
        "HISTORY & GEOGRAPHY",
        "BIOLOGY",
        "AGRICULTURE",
        "MANUFACTURING",
        "CHEMICAL ENGINEERING & RELATED TECHNOLOGIES",
        "LITERATURE",
        "GENERAL KNOWLEDGE"
    };
    return validFields.contains(field.toUpper());
}

bool  validateLimit(int limit) {
    return limit > 0 && limit <= 365;
}

bool  validateDigitalVersion(int has_digital) {
    return has_digital == 0 || has_digital == 1;
}





bool DatabaseManagerBook::addArticle(Article* article) const {
    if (!article) {
        qDebug() << "addArticle Error: Null article pointer!";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "addArticle Error: Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO articles_researchpapers (TYPE, TITLE, AUTHOR, PUBLICATION_YEAR, FIELD, DIGITAL_VERSION, BORROWING_DAYS_LIMIT, RENEWAL_LIMIT) "
                  "VALUES (:type, :title, :author, :year, :field, :hasDigital, :borrowingLimit, :renewalLimit)");

    query.bindValue(":type", "Article");
    query.bindValue(":title", article->getTitle());
    query.bindValue(":author", article->getAuthor());
    query.bindValue(":year", article->getPublicationYear());
    query.bindValue(":field", article->getField());
    query.bindValue(":hasDigital", article->hasDigitalVersion());
    query.bindValue(":borrowingLimit", article->getBorrowingDaysLimit());
    query.bindValue(":renewalLimit", article->getRenewalLimit());

    if (!query.exec()) {
        qDebug() << "addArticle Error: Failed to execute query:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (!db.commit()) {
        qDebug() << "addArticle Error: Failed to commit transaction:" << db.lastError().text();
        return false;
    }

    qDebug() << "Article added successfully: " << article->getTitle();
    return true;
}

bool DatabaseManagerBook::searchArticle(Article* article) const {
    if (!article) {
        qDebug() << "searchArticle Error: Null article pointer!";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM articles_researchpapers WHERE TITLE = :title AND AUTHOR = :author AND PUBLICATION_YEAR = :year AND TYPE = 'Article'");
    query.bindValue(":title", article->getTitle());
    query.bindValue(":author", article->getAuthor());
    query.bindValue(":year", article->getPublicationYear());

    if (!query.exec()) {
        qDebug() << "searchArticle Error: Failed to execute query:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        qDebug() << "Article found: " << article->getTitle();
        // If you intended to populate the passed 'article' object with data from the DB,
        // you would do it here using query.value(...) setters on 'article'.
        return true;
    } else {
        qDebug() << "Article not found: " << article->getTitle();
        return false;
    }
}

bool DatabaseManagerBook::deleteArticle(Article* article) const {
    if (!article) {
        qDebug() << "deleteArticle Error: Null article pointer!";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "deleteArticle Error: Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM articles_researchpapers WHERE TITLE = :title AND AUTHOR = :author AND PUBLICATION_YEAR = :year AND TYPE = 'Article'");
    query.bindValue(":title", article->getTitle());
    query.bindValue(":author", article->getAuthor());
    query.bindValue(":year", article->getPublicationYear());

    if (!query.exec()) {
        qDebug() << "deleteArticle Error: Failed to execute query:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (query.numRowsAffected() > 0) {
        if (!db.commit()) {
            qDebug() << "deleteArticle Error: Failed to commit transaction:" << db.lastError().text();
            return false;
        }
        qDebug() << "Article deleted successfully: " << article->getTitle();
        return true;
    } else {
        qDebug() << "deleteArticle Warning: No article found to delete with title " << article->getTitle() << " or no rows affected.";
        db.rollback();
        return false;
    }
}

bool DatabaseManagerBook::editArticle(Article* article) const {
    if (!article) {
        qDebug() << "editArticle Error: Null article pointer!";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "editArticle Error: Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE articles_researchpapers SET "
                  "TITLE = :new_title, AUTHOR = :new_author, PUBLICATION_YEAR = :new_year, "
                  "FIELD = :new_field, DIGITAL_VERSION = :new_hasDigital, "
                  "BORROWING_DAYS_LIMIT = :new_borrowingLimit, RENEWAL_LIMIT = :new_renewalLimit "
                  "WHERE TITLE = :old_title AND AUTHOR = :old_author AND PUBLICATION_YEAR = :old_year AND TYPE = 'Article'");

    query.bindValue(":new_title", article->getTitle());
    query.bindValue(":new_author", article->getAuthor());
    query.bindValue(":new_year", article->getPublicationYear());
    query.bindValue(":new_field", article->getField());
    query.bindValue(":new_hasDigital", article->hasDigitalVersion());
    query.bindValue(":new_borrowingLimit", article->getBorrowingDaysLimit());
    query.bindValue(":new_renewalLimit", article->getRenewalLimit());

    query.bindValue(":old_title", article->getTitle());
    query.bindValue(":old_author", article->getAuthor());
    query.bindValue(":old_year", article->getPublicationYear());

    if (!query.exec()) {
        qDebug() << "editArticle Error: Failed to execute update query:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (query.numRowsAffected() > 0) {
        if (!db.commit()) {
            qDebug() << "editArticle Error: Failed to commit transaction:" << db.lastError().text();
            return false;
        }
        qDebug() << "Article edited successfully: " << article->getTitle();
        return true;
    } else {
        qDebug() << "editArticle Warning: No article found or updated: " << article->getTitle();
        db.rollback();
        return false;
    }
}

QList<Article*> DatabaseManagerBook::getAllArticles() const {
    QList<Article*> list;
    QSqlQuery query("SELECT * FROM articles_researchpapers WHERE TYPE = 'Article'");

    if (!query.exec()) {
        qDebug() << "getAllArticles Error: Failed to execute query:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        // Inlined creation of Article object
        QString title = query.value("TITLE").toString();
        QString author = query.value("AUTHOR").toString();
        int year = query.value("PUBLICATION_YEAR").toInt();
        QString field = query.value("FIELD").toString();
        bool hasDigital = query.value("DIGITAL_VERSION").toBool();
        int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
        int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

        Article* article = new Article(title, author, year, field, hasDigital,
                                       borrowingDaysLimit, renewalLimit);
        list.append(article);
    }

    qDebug() << "Retrieved " << list.size() << " articles.";
    return list;
}

// --- Research paper-related methods ---

bool DatabaseManagerBook::addResearchPaper(ResearchPaper* paper) const {
    if (!paper) {
        qDebug() << "addResearchPaper Error: Null research paper pointer!";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "addResearchPaper Error: Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO articles_researchpapers (TYPE, TITLE, AUTHOR, PUBLICATION_YEAR, FIELD, DIGITAL_VERSION, BORROWING_DAYS_LIMIT, RENEWAL_LIMIT) "
                  "VALUES (:type, :title, :author, :year, :field, :hasDigital, :borrowingLimit, :renewalLimit)");

    query.bindValue(":type", "ResearchPaper");
    query.bindValue(":title", paper->getTitle());
    query.bindValue(":author", paper->getAuthor());
    query.bindValue(":year", paper->getPublicationYear());
    query.bindValue(":field", paper->getField());
    query.bindValue(":hasDigital", paper->hasDigitalVersion());
    query.bindValue(":borrowingLimit", paper->getBorrowingDaysLimit());
    query.bindValue(":renewalLimit", paper->getRenewalLimit());

    if (!query.exec()) {
        qDebug() << "addResearchPaper Error: Failed to execute query:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (!db.commit()) {
        qDebug() << "addResearchPaper Error: Failed to commit transaction:" << db.lastError().text();
        return false;
    }

    qDebug() << "Research Paper added successfully: " << paper->getTitle();
    return true;
}

bool DatabaseManagerBook::searchResearchPaper(ResearchPaper* paper) const {
    if (!paper) {
        qDebug() << "searchResearchPaper Error: Null research paper pointer!";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM articles_researchpapers WHERE TITLE = :title AND AUTHOR = :author AND PUBLICATION_YEAR = :year AND TYPE = 'ResearchPaper'");
    query.bindValue(":title", paper->getTitle());
    query.bindValue(":author", paper->getAuthor());
    query.bindValue(":year", paper->getPublicationYear());

    if (!query.exec()) {
        qDebug() << "searchResearchPaper Error: Failed to execute query:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        qDebug() << "Research Paper found: " << paper->getTitle();
        // If you intended to populate the passed 'paper' object with data from the DB,
        // you would do it here using query.value(...) setters on 'paper'.
        return true;
    } else {
        qDebug() << "Research Paper not found: " << paper->getTitle();
        return false;
    }
}

bool DatabaseManagerBook::deleteResearchPaper(ResearchPaper* paper) const {
    if (!paper) {
        qDebug() << "deleteResearchPaper Error: Null research paper pointer!";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "deleteResearchPaper Error: Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM articles_researchpapers WHERE TITLE = :title AND AUTHOR = :author AND PUBLICATION_YEAR = :year AND TYPE = 'ResearchPaper'");
    query.bindValue(":title", paper->getTitle());
    query.bindValue(":author", paper->getAuthor());
    query.bindValue(":year", paper->getPublicationYear());

    if (!query.exec()) {
        qDebug() << "deleteResearchPaper Error: Failed to execute query:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (query.numRowsAffected() > 0) {
        if (!db.commit()) {
            qDebug() << "deleteResearchPaper Error: Failed to commit transaction:" << db.lastError().text();
            return false;
        }
        qDebug() << "Research Paper deleted successfully: " << paper->getTitle();
        return true;
    } else {
        qDebug() << "deleteResearchPaper Warning: No research paper found to delete with title " << paper->getTitle() << " or no rows affected.";
        db.rollback();
        return false;
    }
}

bool DatabaseManagerBook::editResearchPaper(ResearchPaper* paper) const {
    if (!paper) {
        qDebug() << "editResearchPaper Error: Null research paper pointer!";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "editResearchPaper Error: Failed to start transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE articles_researchpapers SET "
                  "TITLE = :new_title, AUTHOR = :new_author, PUBLICATION_YEAR = :new_year, "
                  "FIELD = :new_field, DIGITAL_VERSION = :new_hasDigital, "
                  "BORROWING_DAYS_LIMIT = :new_borrowingLimit, RENEWAL_LIMIT = :new_renewalLimit "
                  "WHERE TITLE = :old_title AND AUTHOR = :old_author AND PUBLICATION_YEAR = :old_year AND TYPE = 'ResearchPaper'");

    query.bindValue(":new_title", paper->getTitle());
    query.bindValue(":new_author", paper->getAuthor());
    query.bindValue(":new_year", paper->getPublicationYear());
    query.bindValue(":new_field", paper->getField());
    query.bindValue(":new_hasDigital", paper->hasDigitalVersion());
    query.bindValue(":new_borrowingLimit", paper->getBorrowingDaysLimit());
    query.bindValue(":new_renewalLimit", paper->getRenewalLimit());

    query.bindValue(":old_title", paper->getTitle());
    query.bindValue(":old_author", paper->getAuthor());
    query.bindValue(":old_year", paper->getPublicationYear());

    if (!query.exec()) {
        qDebug() << "editResearchPaper Error: Failed to execute update query:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (query.numRowsAffected() > 0) {
        if (!db.commit()) {
            qDebug() << "editResearchPaper Error: Failed to commit transaction:" << db.lastError().text();
            return false;
        }
        qDebug() << "Research Paper edited successfully: " << paper->getTitle();
        return true;
    } else {
        qDebug() << "editResearchPaper Warning: No research paper found or updated: " << paper->getTitle();
        db.rollback();
        return false;
    }
}

QList<ResearchPaper*> DatabaseManagerBook::getAllResearchPapers() const {
    QList<ResearchPaper*> list;
    QSqlQuery query("SELECT * FROM articles_researchpapers WHERE TYPE = 'ResearchPaper'");

    if (!query.exec()) {
        qDebug() << "getAllResearchPapers Error: Failed to execute query:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        // Inlined creation of ResearchPaper object
        QString title = query.value("TITLE").toString();
        QString author = query.value("AUTHOR").toString();
        int year = query.value("PUBLICATION_YEAR").toInt();
        QString field = query.value("FIELD").toString();
        bool hasDigital = query.value("DIGITAL_VERSION").toBool();
        int borrowingDaysLimit = query.value("BORROWING_DAYS_LIMIT").toInt();
        int renewalLimit = query.value("RENEWAL_LIMIT").toInt();

        ResearchPaper* paper = new ResearchPaper(title, author, year, field, hasDigital,
                                                 borrowingDaysLimit, renewalLimit);
        list.append(paper);
    }

    qDebug() << "Retrieved " << list.size() << " research papers.";
    return list;
}

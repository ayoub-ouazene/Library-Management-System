#ifndef DATABASEMANAGERBOOK_H
#define DATABASEMANAGERBOOK_H

#include "databasemanager.h"

#include "book.h"
#include "article.h"
#include "researchpaper.h"
#include "content.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "user.h"

class DatabaseManagerBook : public DatabaseManager
{
    Q_OBJECT
public:
    explicit DatabaseManagerBook(QObject* parent = nullptr);
    ~DatabaseManagerBook()override;

    // Book-related methods
    bool addBook(Book* book) const;
    bool searchBook(Book* book) const;
    bool deleteBook(Book* book) const;
    bool editBook(Book* book) const;

    int getBookCount(QString ISBN)const;
    int getBookCount(Book* book)const;

    void updateBookCount(QString ISBN ,int count);
    void updateBookCount(Book* book ,int count);

    bool searchBook(const QString& isbn) const;
    QList<Book*> searchBookByISBN(const QString& isbn) const;
    QList<Book*> searchBookByTitle(const QString& title) const;
    QList<Book*> searchBookByAuthor(const QString& author) const;
    QList<Book*> searchBookByField(const QString& field) const;
    QList<Book*> searchBookByYear(const int& year) const;

    QList<Book*> getAllBooks() const;

    bool reserveBook(Book* book, User* user)const ;
    QString BorrowBook(Book* book,User* user) const;
    bool IsBookAvailable(Book* book)const;
    bool renewBook(Book* book, User* user)const ;
    bool returnBook(Book* book, User* user) const;
    bool claimBook(Book* book,User* user)const;

    QList<User*> getBookBorrower( Book* book)const ;
    QList<User*> getBookHistory( Book* book)const ;

    QList<Book*> getCurrentBooksForUser(User* user)const;
    QList<Book*> getCurrentReservationsForUser(User* user)const ;

    QList<Book*> getBorrowedBooks()const;
    QList<Book*> getUnreturnedBooks()const;



    QDate getDueDate(const QString&  ISBN ,const long long& id )const;

    // Article-related methods
    bool addArticle(Article* article) const;
    bool searchArticle(Article* article) const;
    bool deleteArticle(Article* article) const;
    bool editArticle(Article* article) const;
    QList<Article*> getAllArticles() const;

    // Research paper-related methods
    bool addResearchPaper(ResearchPaper* paper) const;
    bool searchResearchPaper(ResearchPaper* paper) const;
    bool deleteResearchPaper(ResearchPaper* paper) const;
    bool editResearchPaper(ResearchPaper* paper) const;
    QList<ResearchPaper*> getAllResearchPapers() const;




};


bool validateName(const QString& name);
bool validateYear(int year);
bool  validateField(const QString& field);
bool  validateLimit(int limit);
bool  validateDigitalVersion(int has_digital);

#endif // DATABASEMANAGERBOOK_H 

#ifndef BOOK_H
#define BOOK_H

#include "content.h"

class Book : public Content {
private:
    QString ISBN;
    QString libraryCode;
    int borrowingDaysLimit;
    int renewalLimit;

public:
    // Constructor
    Book(const QString& title="", const QString& author="", int year=0, const QString& field="", bool hasDigital=0,
         const QString& isbn="", const QString& libraryCode="", int borrowingDaysLimit=15, int renewalLimit=10);

    // Destructor
    ~Book();


    QString reservationTimeline() const override;

    // Specific getters/setters
    QString getISBN() const;
    QString getLibraryCode() const;
    int getBorrowingDaysLimit() const;
    int getRenewalLimit() const;

    void setISBN(const QString& isbn);
    void setLibraryCode(const QString& code);
    void setBorrowingDaysLimit(int days);
    void setRenewalLimit(int limit);


};

#endif // BOOK_H

#include "book.h"


Book::Book(const QString& title, const QString& author, int year, const QString& field, bool hasDigital,
           const QString& isbn, const QString& libraryCode, int borrowingDaysLimit, int renewalLimit)
    : Content(title, author, year, field, hasDigital),
    ISBN(isbn), libraryCode(libraryCode), borrowingDaysLimit(borrowingDaysLimit), renewalLimit(renewalLimit)
{

}

Book::~Book() {
}



QString Book::reservationTimeline() const {
    return QString("You can borrow this book for %1 days. Renewable up to %2 times.")
    .arg(borrowingDaysLimit).arg(renewalLimit);
}

QString Book::getISBN() const { return ISBN; }
QString Book::getLibraryCode() const { return libraryCode; }
int Book::getBorrowingDaysLimit() const { return borrowingDaysLimit; }
int Book::getRenewalLimit() const { return renewalLimit; }

void Book::setISBN(const QString& isbn) { ISBN = isbn; }
void Book::setLibraryCode(const QString& code) { libraryCode = code; }
void Book::setBorrowingDaysLimit(int days) { borrowingDaysLimit = days; }
void Book::setRenewalLimit(int limit) { renewalLimit = limit; }




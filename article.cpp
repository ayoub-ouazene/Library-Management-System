#include "article.h"

Article::Article(const QString& title, const QString& author, int year, const QString& field, bool hasDigital,
                 int borrowingDaysLimit, int renewalLimit)
    : Content(title, author, year, field, hasDigital),
    borrowingDaysLimit(borrowingDaysLimit), renewalLimit(renewalLimit)
{}

Article::~Article() {}



QString Article::reservationTimeline() const {
    return QString("You can borrow this article for %1 days. Renewable up to %2 times.")
    .arg(borrowingDaysLimit).arg(renewalLimit);
}

int Article::getBorrowingDaysLimit() const {
    return borrowingDaysLimit;
}

int Article::getRenewalLimit() const {
    return renewalLimit;
}

void Article::setBorrowingDaysLimit(int days) {
    borrowingDaysLimit = days;
}

void Article::setRenewalLimit(int limit) {
    renewalLimit = limit;
}

#include "researchpaper.h"

ResearchPaper::ResearchPaper(const QString& title, const QString& author, int year, const QString& field, bool hasDigital,
                             int borrowingDaysLimit, int renewalLimit)
    : Content(title, author, year, field, hasDigital),
    borrowingDaysLimit(borrowingDaysLimit), renewalLimit(renewalLimit)
{}

ResearchPaper::~ResearchPaper() {}



QString ResearchPaper::reservationTimeline() const {
    return QString("You can borrow this research paper for %1 days. Renewable up to %2 times.")
    .arg(borrowingDaysLimit).arg(renewalLimit);
}

int ResearchPaper::getBorrowingDaysLimit() const {
    return borrowingDaysLimit;
}

int ResearchPaper::getRenewalLimit() const {
    return renewalLimit;
}

void ResearchPaper::setBorrowingDaysLimit(int days) {
    borrowingDaysLimit = days;
}

void ResearchPaper::setRenewalLimit(int limit) {
    renewalLimit = limit;
}

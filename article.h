#ifndef ARTICLE_H
#define ARTICLE_H

#include "content.h"

class Article : public Content {
private:
    int borrowingDaysLimit;
    int renewalLimit;

public:
    // Constructor
    Article(const QString& title, const QString& author, int year, const QString& field, bool hasDigital,
            int borrowingDaysLimit, int renewalLimit);

    // Destructor
    ~Article();


    QString reservationTimeline() const override;

    // Getters
    int getBorrowingDaysLimit() const;
    int getRenewalLimit() const;

    // Setters
    void setBorrowingDaysLimit(int days);
    void setRenewalLimit(int limit);
};

#endif // ARTICLE_H


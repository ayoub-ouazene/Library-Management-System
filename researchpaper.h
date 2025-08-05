#ifndef RESEARCHPAPER_H
#define RESEARCHPAPER_H

#include "content.h"

class ResearchPaper : public Content {
private:
    int borrowingDaysLimit;
    int renewalLimit;

public:
    // Constructor
    ResearchPaper(const QString& title, const QString& author, int year, const QString& field, bool hasDigital,
                  int borrowingDaysLimit, int renewalLimit);

    // Destructor
    ~ResearchPaper();



    QString reservationTimeline() const override;

    // Getters
    int getBorrowingDaysLimit() const;
    int getRenewalLimit() const;

    // Setters
    void setBorrowingDaysLimit(int days);
    void setRenewalLimit(int limit);
};

#endif // RESEARCHPAPER_H


#ifndef CONTENT_H
#define CONTENT_H

#include <QString>
#include <QSqlQuery>

class Content {
private:
    QString title;
    QString author;
    int publicationYear;
    QString field;
    bool digitalVersion;

public:
    // Constructor
    Content(const QString& title, const QString& author, int year, const QString& field, bool hasDigital);

    // Virtual destructor
    virtual ~Content() = default;

    // Getters
    QString getTitle() const;
    QString getAuthor() const;
    int getPublicationYear() const;
    QString getField() const;
    bool hasDigitalVersion() const;

    // Setters
    void setTitle(const QString& t);
    void setAuthor(const QString& a);
    void setPublicationYear(int y);
    void setField(const QString& f);
    void setDigitalVersion(bool hasDigital);


    virtual QString reservationTimeline() const = 0;
};

#endif // CONTENT_H

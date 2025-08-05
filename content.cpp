#include "content.h"

// Constructor
Content::Content(const QString& title, const QString& author, int year, const QString& field, bool hasDigital)
    : title(title), author(author), publicationYear(year), field(field), digitalVersion(hasDigital) {}

// Getters
QString Content::getTitle() const { return title; }
QString Content::getAuthor() const { return author; }
int Content::getPublicationYear() const { return publicationYear; }
QString Content::getField() const { return field; }
bool Content::hasDigitalVersion() const { return digitalVersion; }

// Setters
void Content::setTitle(const QString& t) { title = t; }
void Content::setAuthor(const QString& a) { author = a; }
void Content::setPublicationYear(int y) { publicationYear = y; }
void Content::setField(const QString& f) { field = f; }
void Content::setDigitalVersion(bool hasDigital) { digitalVersion = hasDigital; }


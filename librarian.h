#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "user.h"

class Librarian : public User
{
public:
    Librarian(const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",int=0,int=0,long long=0);

    static int getTotalNumberOfLibrarians();
    static QList<Librarian> getAllLibrarians();
};

#endif // LIBRARIAN_H

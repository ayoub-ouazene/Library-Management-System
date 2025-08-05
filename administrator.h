#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"

class Administrator : public User
{
public:
    Administrator(const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",int=0,int=0,long long=0);

    static int getTotalNumberOfAdministrators();
    static QList<Administrator> getAllAdministrators();
};

#endif // ADMINISTARTOR_H

#ifndef EXTERNEL_H
#define EXTERNEL_H

#include "user.h"

class Externel : public User
{
public:
public:

    Externel(const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",int=0,int=0,long long=0);

    static int getTotalNumberOfExternels();
    static QList<Externel> getAllExternes();
};

#endif // EXTERNEL_H

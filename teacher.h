#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"

class Teacher : public User
{
public:
public:

    Teacher(const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",int=0,int=0,long long=0);

    static int getTotalNumberOfTeachers();
    static QList<Teacher> getAllTeachers();
};

#endif // TEACHER_H

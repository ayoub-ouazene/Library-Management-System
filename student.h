#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"

class Student : public User
{

public:

    Student(const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",int=0,int=0,long long=0);

    static int getTotalNumberOfStudents();
    static QList<Student> getAllStudents();
};

#endif // STUDENT_H

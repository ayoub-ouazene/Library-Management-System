#include "student.h"
#include "databasemanageruser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase> // Needed for checking if database is open

// Student constructor (remains exactly as you provided, mirroring User's constructor)
Student::Student(const QString& a,const QString& b,const QString& c,const QString& d,const QString& e,const QString& f,const QString& g,int x,int y,long long z)
    :User(a,b,c,d,e,f,g,x,y,z){} // Passes 10 arguments to User base constructor

int Student::getTotalNumberOfStudents()
{
    QSqlQuery query;

    if (query.exec("SELECT COUNT(*) FROM users WHERE USER_TYPE = 'student'")) {
        if (query.next()) {
            return query.value(0).toInt();
        }
    } else {
        qDebug() << "Error executing count query:" << query.lastError().text();
    }

    return 0;
}

QList<Student> Student::getAllStudents() {
    QList<Student> userList;
    DatabaseManagerUser db;
    QSqlQuery query;

    if (query.exec("SELECT FirstName, LastName, ID_CARD, RFID, UNIVERSITY, EMAIL, "
                   "DateOfBirth, USER_TYPE, PASSWORD, CREATION_DATE, STATUS, IS_BLOCKED, IS_PENALIZED "
                   "FROM users WHERE USER_TYPE = 'student' ")) {
        while (query.next()) {
            QString firstName     = query.value("FirstName").toString();
            QString lastName      = query.value("LastName").toString();
            long long idCard      = query.value("ID_CARD").toLongLong();
            int rfid              = query.value("RFID").toInt();
            QString university    = query.value("UNIVERSITY").toString();
            QString email         = query.value("EMAIL").toString();
            QString dateOfBirth   = query.value("DateOfBirth").toString();
            QString password_db      = query.value("PASSWORD").toString();

            Student u(firstName, lastName, email, password_db, dateOfBirth, university,
                      "", 0, rfid, idCard);
            userList.append(u);
        }
    } else {
        qDebug() << "Error executing SELECT query:" << query.lastError().text();
    }

    return userList;
}

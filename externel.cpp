#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "externel.h"
#include "databasemanageruser.h"

Externel::Externel(const QString& a,const QString& b,const QString& c,const QString& d,const QString& e,const QString& f,const QString& g,int x,int y,long long z)
    :User(a,b,c,d,e,f,g,x,y,z){}

int Externel::getTotalNumberOfExternels()
{
    QSqlQuery query;

    if (query.exec("SELECT COUNT(*) FROM users WHERE USER_TYPE = 'externel'")) {
        if (query.next()) {
            return query.value(0).toInt();
        }
    } else {
        qDebug() << "Error executing externels's count query:" << query.lastError().text();
    }

    return 0;
}



QList<Externel> Externel::getAllExternes() {
    QList<Externel> userList;
    DatabaseManagerUser db;
    QSqlQuery query;

    // Update column names based on your database schema
    if (query.exec("SELECT first_name, last_name, email, password, date_of_birth, university, "
                   " rfid, id_card FROM users WHERE USER_TYPE = 'externel' ")) {
        while (query.next()) {
            QString firstName     = query.value(0).toString();
            QString lastName      = query.value(1).toString();
            QString email         = query.value(2).toString();
            QString password      = query.value(3).toString();
            QString dateOfBirth   = query.value(4).toString();
            QString university    = query.value(5).toString();
            int rfid              = query.value(6).toInt();
            int idCard            = query.value(7).toLongLong();

            Externel u(firstName, lastName, email, password, dateOfBirth, university,
                      "", 0, rfid, idCard);
            userList.append(u);
        }
    } else {
        qDebug() << "Error executing getAllExternes , SELECT query:" << query.lastError().text();
    }

    return userList;
}


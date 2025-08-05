#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "administrator.h"
#include "databasemanageruser.h"


Administrator::Administrator(const QString& a,const QString& b,const QString& c,const QString& d,const QString& e,const QString& f,const QString& g,int x,int y,long long z)
    :User(a,b,c,d,e,f,g,x,y,z){}

int Administrator::getTotalNumberOfAdministrators()
{
    QSqlQuery query ;

    if(query.exec("SELECT COUNT(*) FROM users WHERE USER_TYPE = 'administrator'"))
    {
        if(query.next())
        {
            return query.value(0).toInt();
        }
    }
    else
    {
        qDebug()<<"Failed to execute the command "<<query.lastError().text();
    }
        return 0;

}



QList<Administrator> Administrator::getAllAdministrators() {
    QList<Administrator> adminlist;
    QSqlQuery query;
    if(Administrator::getTotalNumberOfAdministrators()==0)
    {
        qDebug()<<"There is no Administrator ! ";
        return adminlist;
    }

    if(query.exec("SELECT FirstName, LastName, EMAIL, PASSWORD, DateOfBirth, UNIVERSITY, "
                   " RFID, ID_CARD FROM users WHERE USER_TYPE = 'administrator'"))
    {
        while(query.next())
        {
            QString firstname = query.value(0).toString();
            QString lastname = query.value(1).toString();
            QString email         = query.value(2).toString();
            QString password      = query.value(3).toString();
            QString dateOfBirth   = query.value(4).toString();
            QString university    = query.value(5).toString();
            int rfid              = query.value(6).toInt();
            long long idCard       = query.value(7).toLongLong();

            Administrator admin(firstname,lastname,email,password,dateOfBirth,university,"",0,rfid,idCard);

            adminlist.append(admin);
        }
    }
    else
    {
        qDebug()<<"Error happen when entering users"<<query.lastError().text();
    }

    return adminlist;
}


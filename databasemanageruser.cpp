#include "databasemanageruser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QRegularExpression>
#include <QCryptographicHash>

DatabaseManagerUser::DatabaseManagerUser(QObject* parent) : DatabaseManager(parent) {}
DatabaseManagerUser::~DatabaseManagerUser() {}

bool DatabaseManagerUser:: searchUser(User* user) const
{
    if(!user)
    {
        qDebug()<<"Null ptr ! ";
        return 0 ;
    }

    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM users WHERE ID_CARD = :id ");
    query.bindValue(":id", user->getIDCard());

    if(!query.exec())
    {
        qDebug()<<"Failed to Execute Command !";
        return 0;
    }
    if(query.next())
    {
        if(query.value(0).toInt() == 1)
        {
            qDebug()<<"User Founded ...";
            return 1;
        }
        else
        {
             qDebug()<<"User Not Found ...";
            return 0;
        }
    }
    return 0;
}



 bool DatabaseManagerUser :: searchUser(long long id)const
{


     QSqlQuery query;

     query.prepare("SELECT COUNT(*) FROM users WHERE ID_CARD = :id ");
     query.bindValue(":id", id);

     if(!query.exec())
     {
         qDebug()<<"Failed to Execute Command !";
         return 0;
     }
     if(query.next())
     {
         if(query.value(0).toInt() == 1)
         {
             qDebug()<<"User Founded ...";
             return 1;
         }
         else
         {
             qDebug()<<"User Not Found ...";
             return 0;
         }
     }
     return 0;
}



bool DatabaseManagerUser :: addUser(User* user) const
{
    if(!user)
    {
        qDebug()<<"Null ptr ! ";
        return 0 ;
    }
    if(searchUser(user))
    {
        qDebug()<<"User Already exists you cannot add it ! ";
        return 0 ;
    }

    QSqlQuery query;

    query.prepare("INSERT INTO users (FIRST_NAME, LAST_NAME, ID_CARD, RFID, UNIVERSITY, EMAIL, DATE_OF_BIRTH, USER_TYPE, PASSWORD, CREATION_DATE, IS_BLOCKED, IS_PENALIZED, PENALTY_REASON, PENALTY_DAYS,  END_PENALIZATION) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?)");
    query.addBindValue(user->getFirstName());
    query.addBindValue(user->getLastName());
    query.addBindValue(user->getIDCard());
    query.addBindValue(user->getRFID());
    query.addBindValue(user->getUniversity());
    query.addBindValue(user->getEmail());
    query.addBindValue(user->getDateOfBirth());
    if(dynamic_cast<Administrator*>(user))
    {
        query.addBindValue("administrator");
    }
    else if(dynamic_cast<Externel*>(user))
    {
        query.addBindValue("externel");
    }
    else if(dynamic_cast<Librarian*>(user))
    {
        query.addBindValue("librarian");
    }
    else if(dynamic_cast<Library_Director*>(user))
    {
        query.addBindValue("library_director");
    }
    else if(dynamic_cast<Student*>(user))
    {
        query.addBindValue("student");
    }
    else if(dynamic_cast<Teacher*>(user))
    {
        query.addBindValue("teacher");
    }
    else
    {
        qDebug()<<"Wrong Type !";
        return 0;
    }


    query.addBindValue(user->getPassword());
    query.addBindValue(QDate::currentDate().toString(Qt::ISODate));
    query.addBindValue(0);
    query.addBindValue(0);
    query.addBindValue("");
    query.addBindValue(0);
    query.addBindValue("");


    if(!query.exec())
    {
        qDebug()<<"Failed to execute !";
        return 0;
    }

    qDebug()<<"User added succefully ! ";
    return 1 ;


}


bool DatabaseManagerUser:: addUser(User*user , QString error)const
{
    if(!user)
    {
        error="Null ptr ! ";
        return 0 ;
    }
    if(searchUser(user))
    {
       error="User Already exists you cannot add it ! ";
        return 0 ;
    }

    QSqlQuery query;

    query.prepare("INSERT INTO users (FIRST_NAME, LAST_NAME, ID_CARD, RFID, UNIVERSITY, EMAIL, DATE_OF_BIRTH, USER_TYPE, PASSWORD, CREATION_DATE, IS_BLOCKED, IS_PENALIZED, PENALTY_REASON, PENALTY_DAYS,  END_PENALIZATION) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?)");
    query.addBindValue(user->getFirstName());
    query.addBindValue(user->getLastName());
    query.addBindValue(user->getIDCard());
    query.addBindValue(user->getRFID());
    query.addBindValue(user->getUniversity());
    query.addBindValue(user->getEmail());
    query.addBindValue(user->getDateOfBirth());
    if(dynamic_cast<Administrator*>(user))
    {
        query.addBindValue("administrator");
    }
    else if(dynamic_cast<Externel*>(user))
    {
        query.addBindValue("externel");
    }
    else if(dynamic_cast<Librarian*>(user))
    {
        query.addBindValue("librarian");
    }
    else if(dynamic_cast<Library_Director*>(user))
    {
        query.addBindValue("library_director");
    }
    else if(dynamic_cast<Student*>(user))
    {
        query.addBindValue("student");
    }
    else if(dynamic_cast<Teacher*>(user))
    {
        query.addBindValue("teacher");
    }
    else
    {
       error="Wrong Type !";
        return 0;
    }


    query.addBindValue(user->getPassword());
    query.addBindValue(QDate::currentDate().toString(Qt::ISODate));
    query.addBindValue(0);
    query.addBindValue(0);
    query.addBindValue("");
    query.addBindValue(0);
    query.addBindValue("");


    if(!query.exec())
    {
        error="Failed to execute !";
        return 0;
    }

    error="User added succefully ! ";
    return 1 ;

}


 bool DatabaseManagerUser :: deleteUser(User* user) const
{
     if(!user)
     {
         qDebug()<<"Null ptr ! ";
         return 0 ;
     }
     if(!searchUser(user))
     {
         qDebug()<<"User not exists you cannot delete it  ";
         return 0 ;
     }

     QSqlQuery  query;

     query.prepare("DELETE FROM users WHERE ID_CARD = :id");
     query.bindValue(":id",user->getIDCard());

     if(!query.exec())
     {
         qDebug()<<"Failed to execute user ";
         return 0;
     }

     qDebug()<<"Delete user succefully ...";
     return 1;
}


bool DatabaseManagerUser :: editUser(User* user) const
{

    if(!user)
    {
        qDebug()<<"Null ptr ! ";
        return 0 ;
    }
    if(!searchUser(user))
    {
        qDebug()<<"User not exists you cannot delete it  ";
        return 0 ;
    }

    QSqlQuery  query;

    query.prepare("UPDATE users SET FIRST_NAME = ?, LAST_NAME = ?, RFID = ?, UNIVERSITY = ?, EMAIL = ?, DATE_OF_BIRTH = ?, PASSWORD = ?,  PENALTY_REASON = ? WHERE ID_CARD = ? ");

    query.addBindValue(user->getFirstName());
    query.addBindValue(user->getLastName());
    query.addBindValue(user->getRFID());
    query.addBindValue(user->getUniversity());
    query.addBindValue(user->getEmail());
    query.addBindValue(user->getDateOfBirth());
    query.addBindValue(user->getPassword());
    query.addBindValue(user->getPenaltyReason());
    query.addBindValue(user->getIDCard());

    if(user->getPenaltyDays() >0)
    {
        if(!penalizeUser(user,user->getPenaltyDays()))
        {
            return 0;
        }

    }

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query";
        return 0;
    }



     qDebug()<<"Edit succefully";
    return 1;
}



bool DatabaseManagerUser :: banUser(User* user) const
{
    if(!user)
    {
        qDebug()<<"Null ptr ! ";
        return 0 ;
    }
    if(!searchUser(user))
    {
        qDebug()<<"User not exists you cannot delete it  ";
        return 0 ;
    }

    QSqlQuery  query;

    query.prepare("UPDATE users SET IS_BLOCKED = 1 WHERE ID_CARD = :id AND USER_TYPE != 'library_director'");
    query.bindValue(":id",user->getIDCard());

    if(!query.exec())
    {
        qDebug()<<"Failed to execute ...";
        return 0;
    }

    qDebug()<<"Ban succefully ..";
    return 1;

}


 bool DatabaseManagerUser :: penalizeUser(User* user,const int & days,QString reason) const
{
     if(!user)
     {
         qDebug()<<"Null ptr ! ";
         return 0 ;
     }
     if(!searchUser(user))
     {
         qDebug()<<"User not exists you cannot delete it  ";
         return 0 ;
     }

     QSqlQuery  query;
     query.prepare("SELECT  END_PENALIZATION FROM users WHERE ID_CARD = :id ");
     query.bindValue(":id",user->getIDCard());

     if(!query.exec())
     {
         qDebug()<<"Failed to execute ...";
         return 0;
     }

     QString date;
     if(query.next())
     {
         date = query.value(0).toString();
     }

    QDate myDate = QDate::fromString(date, Qt::ISODate);


    query.prepare("UPDATE users SET IS_PENALIZED = 1 , PENALTY_DAYS = :days , PENALTY_REASON = :reason, END_PENALIZATION = :date  WHERE ID_CARD = :id ");

     query.bindValue(":days",days);
    query.bindValue(":reason",reason);
     query.bindValue(":date",( myDate < QDate::currentDate() || myDate.isNull() ) ? QDate::currentDate().addDays(days).toString(Qt::ISODate):myDate.addDays(days).toString(Qt::ISODate));
     query.bindValue(":id",user->getIDCard());


     if(!query.exec())
     {
         qDebug()<<"Failed to execute ...";
         return 0;
     }

     qDebug()<<"Update succefully ...";
     return 1;

}


User*  DatabaseManagerUser :: validateUser(const QString& FirstName , const QString& LastName , const long long& id ,  const QString&password) const
{


    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE ID_CARD = :id");
    query.bindValue(":id",id);

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query ...";
        return nullptr;
    }

    if(query.next())
    {
        QString first_name = query.value("FIRST_NAME").toString();
        QString last_name = query.value("LAST_NAME").toString();
        QString pswd = query.value("PASSWORD").toString();

        if(FirstName != first_name  || LastName != last_name || pswd != password )
        {
            qDebug()<<"wrong Information , please try again ";
            return nullptr;
        }

        QString email = query.value("EMAIL").toString();
        QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
        QString University = query.value("UNIVERSITY").toString();
        QString PenaltyReason = query.value("PENALTY_REASON").toString();
        int PenaltyDays = query.value("PENALTY_DAYS").toInt();
        int RFID = query.value("RFID").toInt() ;
        QString type = query.value("USER_TYPE").toString();

        User* user ;

        QString typeLower = type.toLower();
        if (typeLower == "administrator") {
            user = new Administrator( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );
        } else if (typeLower == "externel") {
            user = new Externel( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );
        } else if (typeLower == "librarian") {
            user = new Librarian( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );
        } else if (typeLower == "library_director") {
            user = new Library_Director( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );
        } else if (typeLower == "student") {
            user = new Student( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );
        } else if (typeLower == "teacher") {
            user = new Teacher( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );
        }
        else
        {
            qDebug() << "validateUser Error: Unknown USER_TYPE encountered:" << type;
            return nullptr;
        }



        qDebug()<<"Validation of user succefully ...";
        return user;

    }

    qDebug()<<"Failed to find user !";
    return nullptr;

}



QList<User*> DatabaseManagerUser :: searchUserByFirstName(QString firstname)
{
    QSqlQuery query;
    QList<User*> list;


    query.prepare("SELECT * FROM users WHERE FIRST_NAME = :firstname ");
    query.bindValue(":firstname",firstname.toUpper());

    if(query.exec())
    {
        while(query.next())
        {
            QString First_name = firstname ;
            QString Last_name = query.value("LAST_NAME").toString();
            QString email = query.value("EMAIL").toString();
            QString password = query.value("PASSWORD").toString();
            QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
            QString University = query.value("UNIVERSITY").toString();
            QString PenaltyReason = query.value("PENALTY_REASON").toString();
            int PenaltyDays = query.value("PENALTY_DAYS").toInt();
            int RFID = query.value("RFID").toInt();
            long long ID_CARD = query.value("ID_CARD").toLongLong();

            QString type = query.value("USER_TYPE").toString();

            User* user;
            if(type == "student")
            {
               user = new Student(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "teacher")
            {
                user = new Teacher(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "externel")
            {
               user = new Externel(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "administrator")
            {
                 user = new Administrator(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "librarian")
            {
                 user = new Librarian(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "library_director")
            {
                  user = new Library_Director(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else
            {
                qDebug()<<"type not found ...";
                return list;
            }

            list.append(user);

        }
        if(list.empty())
        {
            qDebug()<<"no such user with this first name " ;
        }

    }
    else
    {
        qDebug()<<"cannot find the user ! ";
    }

    return list ;
}





QList<User*> DatabaseManagerUser :: searchUserByID(long long id )
{

    QSqlQuery query;
    QList<User*> list;


    query.prepare("SELECT * FROM users WHERE ID_CARD = :id ");
    query.bindValue(":id",id);

    if(query.exec())
    {
        while(query.next())
        {
            QString First_name = query.value("FIRST_NAME").toString() ;
            QString Last_name = query.value("LAST_NAME").toString();
            QString email = query.value("EMAIL").toString();
            QString password = query.value("PASSWORD").toString();
            QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
            QString University = query.value("UNIVERSITY").toString();
            QString PenaltyReason = query.value("PENALTY_REASON").toString();
            int PenaltyDays = query.value("PENALTY_DAYS").toInt();
            int RFID = query.value("RFID").toInt();
            long long ID_CARD = query.value("ID_CARD").toLongLong();

            QString type = query.value("USER_TYPE").toString();

            User* user;
            if(type == "student")
            {
                user = new Student(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "teacher")
            {
                user = new Teacher(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "externel")
            {
                user = new Externel(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "administrator")
            {
                user = new Administrator(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "librarian")
            {
                user = new Librarian(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "library_director")
            {
                user = new Library_Director(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else
            {
                qDebug()<<"type not found ...";
                return list;
            }

            list.append(user);

        }
        if(list.empty())
        {
            qDebug()<<"no such user with this first name " ;
        }

    }
    else
    {
        qDebug()<<"cannot find the user ! ";
    }

    return list ;
}




QList<User*> DatabaseManagerUser :: searchUserByType(QString type)
{

    QSqlQuery query;
    QList<User*> list;


    query.prepare("SELECT * FROM users WHERE USER_TYPE = :type ");
    query.bindValue(":type",type.toLower() );

    if(query.exec())
    {
        while(query.next())
        {
            QString First_name = query.value("FIRST_NAME").toString() ;
            QString Last_name = query.value("LAST_NAME").toString();
            QString email = query.value("EMAIL").toString();
            QString password = query.value("PASSWORD").toString();
            QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
            QString University = query.value("UNIVERSITY").toString();
            QString PenaltyReason = query.value("PENALTY_REASON").toString();
            int PenaltyDays = query.value("PENALTY_DAYS").toInt();
            int RFID = query.value("RFID").toInt();
            long long ID_CARD = query.value("ID_CARD").toLongLong();

            User* user;
            if(type.toLower() == "student")
            {
                user = new Student(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type.toLower() == "teacher")
            {
                user = new Teacher(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type.toLower() == "externel")
            {
                user = new Externel(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type.toLower() == "administrator")
            {
                user = new Administrator(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type.toLower() == "librarian")
            {
                user = new Librarian(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type.toLower() == "library_director")
            {
                user = new Library_Director(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else
            {
                qDebug()<<"type not found ...";
                return list;
            }

            list.append(user);

        }
        if(list.empty())
        {
            qDebug()<<"no such user with this first name " ;
        }

    }
    else
    {
        qDebug()<<"cannot find the user ! ";
    }

    return list ;
}



QList<User*> DatabaseManagerUser::searchUserByUniversity(QString univ)
{

    QSqlQuery query;
    QList<User*> list;


    query.prepare("SELECT * FROM users WHERE UNIVERSITY = :university ");
    query.bindValue(":university",univ);

    if(query.exec())
    {
        while(query.next())
        {
            QString First_name = query.value("FIRST_NAME").toString();
            QString Last_name = query.value("LAST_NAME").toString();
            QString email = query.value("EMAIL").toString();
            QString password = query.value("PASSWORD").toString();
            QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
            QString University = query.value("UNIVERSITY").toString();
            QString PenaltyReason = query.value("PENALTY_REASON").toString();
            int PenaltyDays = query.value("PENALTY_DAYS").toInt();
            int RFID = query.value("RFID").toInt();
            long long ID_CARD = query.value("ID_CARD").toLongLong();

            QString type = query.value("USER_TYPE").toString();

            User* user;
            if(type == "student")
            {
                user = new Student(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "teacher")
            {
                user = new Teacher(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "externel")
            {
                user = new Externel(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "administrator")
            {
                user = new Administrator(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "librarian")
            {
                user = new Librarian(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else if(type == "library_director")
            {
                user = new Library_Director(First_name,Last_name,email,password,date_of_birth,University,PenaltyReason,PenaltyDays,RFID,ID_CARD);
            }
            else
            {
                qDebug()<<"type not found ...";
                return list;
            }

            list.append(user);

        }
        if(list.empty())
        {
            qDebug()<<"no such user with this first name " ;
        }

    }
    else
    {
        qDebug()<<"cannot find the user ! ";
    }

    return list ;
}



 QList<User*> DatabaseManagerUser :: listpenalizeUsers()const
{
     QList<User*> list ;

    QSqlQuery query ;
     query.prepare("SELECT * FROM users WHERE IS_PENALIZED = 1");

    if(!query.exec())
     {
         qDebug()<<"Failed to execute query !";
         return list;
    }

    while(query.next())
    {
        QString first_name = query.value("FIRST_NAME").toString();
        QString last_name = query.value("LAST_NAME").toString();
        QString pswd = query.value("PASSWORD").toString();
        QString email = query.value("EMAIL").toString();
        QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
        QString University = query.value("UNIVERSITY").toString();
        QString PenaltyReason = query.value("PENALTY_REASON").toString();
        int PenaltyDays = query.value("PENALTY_DAYS").toInt();
        int RFID = query.value("RFID").toInt() ;
        long long id = query.value("ID_CARD").toLongLong();

        User* user = new User( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );

        list.append(user);

    }

    if(list.empty())
    {
        qDebug()<<"There is not Penalized users";
    }

    return list;
}


QList<User*> DatabaseManagerUser :: listunpenalizeUsers()const
{
    QList<User*> list ;

    QSqlQuery query ;
    query.prepare("SELECT * FROM users WHERE IS_PENALIZED = 0 ");

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query !";
        return list;
    }

    while(query.next())
    {
        QString first_name = query.value("FIRST_NAME").toString();
        QString last_name = query.value("LAST_NAME").toString();
        QString pswd = query.value("PASSWORD").toString();
        QString email = query.value("EMAIL").toString();
        QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
        QString University = query.value("UNIVERSITY").toString();
        QString PenaltyReason = query.value("PENALTY_REASON").toString();
        int PenaltyDays = query.value("PENALTY_DAYS").toInt();
        int RFID = query.value("RFID").toInt() ;
        long long id = query.value("ID_CARD").toLongLong();

        User* user = new User( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );

        list.append(user);

    }

    if(list.empty())
    {
        qDebug()<<"There is not unPenalized users";
    }

    return list;
}

QList<User*> DatabaseManagerUser :: listblockedUsers()const
{
    QList<User*> list ;

    QSqlQuery query ;
    query.prepare("SELECT * FROM users WHERE IS_BLOCKED = 1 ");

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query !";
        return list;
    }

    while(query.next())
    {
        QString first_name = query.value("FIRST_NAME").toString();
        QString last_name = query.value("LAST_NAME").toString();
        QString pswd = query.value("PASSWORD").toString();
        QString email = query.value("EMAIL").toString();
        QString date_of_birth = query.value("DATE_OF_BIRTH").toString();
        QString University = query.value("UNIVERSITY").toString();
        QString PenaltyReason = query.value("PENALTY_REASON").toString();
        int PenaltyDays = query.value("PENALTY_DAYS").toInt();
        int RFID = query.value("RFID").toInt() ;
        long long id = query.value("ID_CARD").toLongLong();

        User* user = new User( first_name ,last_name , email ,  pswd ,  date_of_birth , University , PenaltyReason , PenaltyDays , RFID,id );

        list.append(user);

    }

    if(list.empty())
    {
        qDebug()<<"There is not blocked users";
    }

    return list;
}



QList<User*> DatabaseManagerUser :: GeneralSearching(QString first_name, QString last_name, int id_card, int rfid, QString university, QString email, QString date_of_birth, QString user_type, QString creation_date)const
{
    QString queryString = "SELECT * FROM users";
    QStringList conditions;
    QMap<QString, QVariant> bindValues;

    QList<User*> list;

    if (!first_name.isEmpty()) {
        conditions << "FIRST_NAME LIKE :first_name";
        bindValues[":first_name"] = "%" + first_name + "%";
    }
    if (!last_name.isEmpty()) {
        conditions << "LAST_NAME LIKE :last_name";
        bindValues[":last_name"] = "%" + last_name + "%";
    }
    if (id_card != 0) { // Assuming 0 is the default/invalid ID
        conditions << "ID_CARD = :id_card";
        bindValues[":id_card"] = id_card;
    }
    if (rfid != 0) { // Assuming 0 is the default/invalid RFID
        conditions << "RFID = :rfid";
        bindValues[":rfid"] = rfid;
    }
    if (!university.isEmpty()) {
        conditions << "UNIVERSITY LIKE :university";
        bindValues[":university"] = "%" + university + "%";
    }
    if (!email.isEmpty()) {
        conditions << "EMAIL LIKE :email";
        bindValues[":email"] = "%" + email + "%";
    }
    if (!date_of_birth.isEmpty()) {
        conditions << "DATE_OF_BIRTH = :date_of_birth";
        bindValues[":date_of_birth"] = date_of_birth;
    }
    if (!user_type.isEmpty()) {
        conditions << "USER_TYPE = :user_type";
        bindValues[":user_type"] = user_type;
    }
    if (!creation_date.isEmpty()) {
        conditions << "CREATION_DATE = :creation_date";
        bindValues[":creation_date"] = creation_date;
    }


    if (!conditions.isEmpty()) {
        queryString += " WHERE " + conditions.join(" AND ");
    }

    QSqlQuery query;
    query.prepare(queryString);

    // Bind values to the query
    for (auto it = bindValues.constBegin(); it != bindValues.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (!query.exec()) {
        qDebug() << "GeneralSearching Error: Failed to execute query:" << query.lastError().text();
        return list;
    }


    while(query.next())
    {
        QString firstname = query.value("FIRST_NAME").toString();
        QString lastname = query.value("LAST_NAME").toString();
        QString pswd = query.value("PASSWORD").toString();
        QString mail = query.value("EMAIL").toString();
        QString dateofbirth = query.value("DATE_OF_BIRTH").toString();
        QString University = query.value("UNIVERSITY").toString();
        QString PenaltyReason = query.value("PENALTY_REASON").toString();
        int PenaltyDays = query.value("PENALTY_DAYS").toInt();
        int RFID = query.value("RFID").toInt() ;
        long long id = query.value("ID_CARD").toLongLong();

        User* user = new User( firstname ,lastname , mail ,  pswd ,  dateofbirth , University , PenaltyReason , PenaltyDays , RFID,id );

        list.append(user);

    }

    if(list.empty())
    {
        qDebug()<<"There is not blocked users";
    }

    return list;

}


bool valid_name(const QString& name) {
    if(name == ""){ return false; }
    return true;
}

bool valid_id(const long long& id) {
    if (id <= 0 || QString::number(id).length()!=12) {
        return false;
    }
    return true;
}

bool valid_RFID(const int& rfid) {
    if (rfid <= 0 || QString::number(rfid).length()!=7) {
        return false;
    }
    return true;
}

bool isValidEmail(const QString &email) {
    static const QRegularExpression regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex.match(email).hasMatch();
}

QString hashPassword(const QString &password) {
    QByteArray passwordBytes = password.toUtf8();
    QByteArray hashBytes = QCryptographicHash::hash(
        passwordBytes,
        QCryptographicHash::Sha256
        );
    return QString(hashBytes.toHex());
}



#include <QDate>
#include <QString>
#include <QRegularExpression>
#include <QDebug> // For debugging, if needed

// It's good practice to include QCryptographicHash if hashPassword is in the same file/context
// #include <QCryptographicHash> // Only include if hashPassword is defined here.

bool isValidDate(const QString &dob, int minAge, int maxAge) {
    // Define a list of common date formats to try for parsing
    const QStringList dateFormats = {
        "yyyy-MM-dd",
        "dd-MM-yyyy",
        "dd/MM/yyyy",
        "d-M-yyyy",
        "d/M/yyyy",
        "d/MM/yyyy",
        "dd/M/yyyy"

    };

    QDate date;
    bool formatFound = false;

    for (const QString &format : dateFormats) {
        date = QDate::fromString(dob, format);
        if (date.isValid()) {
            formatFound = true;
            break;
        }
    }

    if (!formatFound) {
        qDebug() << "isValidDate Error: Date string '" << dob << "' does not match any accepted format.";
        return false;
    }

    // 1. Check if the parsed date is in the future
    if (date > QDate::currentDate()) {
        qDebug() << "isValidDate Error: Date of birth '" << dob << "' is in the future.";
        return false;
    }

    // 2. Calculate the age based on the parsed date
    int age = QDate::currentDate().year() - date.year();
    // Adjust age if the birthday hasn't occurred yet this year
    if (QDate::currentDate().month() < date.month() ||
        (QDate::currentDate().month() == date.month() &&
         QDate::currentDate().day() < date.day())) {
        age--;
    }

    // 3. Check if the calculated age falls within the specified minimum and maximum age range
    if (age < minAge || age > maxAge) {
        qDebug() << "isValidDate Error: Age (" << age << ") for date '" << dob
                 << "' is not within the allowed range (" << minAge << "-" << maxAge << ").";
        return false;
    }

    // If all validation checks pass, the date is considered valid
    return true;
}


QString FixType(User *user) {
    if(dynamic_cast<Student*>(user)){ return "student"; }
    if(dynamic_cast<Teacher*>(user)){ return "teacher"; }
    if(dynamic_cast<Externel*>(user)){ return "externel"; }
    if(dynamic_cast<Library_Director*>(user)){ return "library_director"; }
    if(dynamic_cast<Librarian*>(user)){ return "librarian"; }
    if(dynamic_cast<Administrator*>(user)){ return "administrator"; }
    return "";
}




#include "runtimefunctions.h"
#include <QDebug>
#include <QDate>

RunTimeFunctions :: RunTimeFunctions(DatabaseManagerBook* dbbook, DatabaseManagerUser* dbuser)
    :dbuser(dbuser),dbbook(dbbook)
{
}


void RunTimeFunctions :: penalizeUsers()
{
    QSqlQuery query;
    query.prepare("SELECT ID_CARD,DUE_DATE FROM transformations WHERE RETURNED = 0 AND DUE_DATE < :date ");
    query.bindValue(":date",QDate::currentDate());

    if(! query.exec())
    {
        qDebug()<<"Failed to execute query !";
        return;
    }

    while(query.next())
    {
        QSqlQuery query2;
        query2.prepare("UPDATE users SET IS_PENALIZED = 1 , PENALTY_REASON = :reason , PENALTY_DAYS = :days ,END_PENALIZATION = :date WHERE ID_CARD = :id ");
        query2.bindValue(":reason","DELAY  IN RETURNING THE BOOK");

        QDate date = query.value(1).toDate();
        int days =  date.daysTo(QDate::currentDate());

        query2.bindValue(":days",days*2);
        query2.bindValue(":date" , QDate::currentDate().addDays(days*2).toString(Qt::ISODate));
        query2.bindValue(":id",query.value(0).toLongLong());

        if(!query2.exec())
        {
            qDebug()<<"Failed to run query 2 ! for user  with id : "<<query.value(0).toString();

        }

    }

    qDebug()<<"penalize users succefully completed ...";
    return;
}


void RunTimeFunctions :: unpenalizeUsers()
{
    QSqlQuery query;
    query.prepare("UPDATE users SET IS_PENALIZED = 0 , PENALTY_REASON = ?, PENALTY_DAYS = ? , END_PENALIZATION = ? WHERE END_PENALIZATION <= ? ");
    query.addBindValue(0);
    query.addBindValue("");
    query.addBindValue(0);
    query.addBindValue("");
    query.addBindValue(QDate::currentDate());

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query !";
        return ;
    }

    qDebug()<<"Unpenalized users succefully !";
}


void RunTimeFunctions :: BlockUsers()
{

}


void RunTimeFunctions :: deleteUsers()
{
    QSqlQuery   query;

    query.prepare("DELETE FROM users WHERE CREATION_DATE = :date AND USER_TYPE = :student");
    query.bindValue(":date",QDate::currentDate().addDays(-365));
    query.bindValue(":student","student");

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query !";
        return ;
    }

     qDebug()<<"Delete users succefully !";
}


void RunTimeFunctions :: UpdateReservations()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM transformations WHERE RETURNED = 0 AND  DUE_DATE < :date");
    query.bindValue(":date",QDate::currentDate());

    if(!query.exec())
    {
        qDebug()<<"Failed to execute query 1!";
        return ;
    }

    while(query.next())
    {
        int def = query.value("DUE_DATE").toDate().daysTo(QDate::currentDate());

        QSqlQuery query2;

        query2.prepare("SELECT DUE_DATE FROM bookcopies WHERE ISBN = :isbn AND COPY_ID = :copy");
        query2.bindValue(":isbn",query.value("ISBN").toString());
        query2.bindValue(":copy",query.value("COPY_ID").toInt());
        if(!query2.exec())
        {
            qDebug()<<"Failed to execute query 2 !";
            return ;
        }
        QDate due_date_general ;
        if(query2.next())
        {
            due_date_general = query2.value(0).toDate();
        }

        query2.prepare("UPDATE bookcopies SET DUE_DATE = :date WHERE ISBN = :isbn AND COPY_ID = :copy ");
        query2.bindValue(":date",due_date_general.addDays(def));
        query2.bindValue(":isbn",query.value("ISBN").toString());
        query2.bindValue(":copy",query.value("COPY_ID").toInt());
        if(!query2.exec())
        {
            qDebug()<<"Failed to execute query 2 !";
            return ;
        }


        query2.prepare("SELECT * from reservations WHERE ISBN = :isbn AND COPY_ID = :copy");
        query2.bindValue(":isbn",query.value("ISBN").toString());
        query2.bindValue(":copy",query.value("COPY_ID").toInt());

        if(!query2.exec())
        {
            qDebug()<<"Failed to execute query 2 !";
            return ;
        }

        while(query2.next())
        {
            QSqlQuery query3;

            query3.prepare("SELECT EXPIRATION_DATE FROM reservations  WHERE ID_CARD = :id");
            query3.bindValue(":id",query2.value("ID_CARD").toLongLong());
            if(!query3.exec())
            {
                qDebug()<<"Failed to execute query 3!";
                return ;
            }
            QDate expiration;
            if(query3.next())
            {
                expiration = query3.value(0).toDate();
            }

            query3.prepare("UPDATE reservations SET EXPIRATION_DATE = :date WHERE ID_CARD = :id");
            query3.bindValue(":date",expiration.addDays(def));
            query3.bindValue(":id",query2.value("ID_CARD").toLongLong());

            if(!query3.exec())
            {
                 qDebug()<<"Failed to execute query 3 for some user ";
            }

        }


        qDebug()<<"Mission Completed Succefully ... ";



    }
}

void RunTimeFunctions::RemoveReservations()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM reservations WHERE EXPIRATION_DATE <= :date");
    query.bindValue(":date", QDate::currentDate());

    if (!query.exec()) {
        qDebug() << "Failed to execute main select query!";
        return;
    }

    while (query.next())
    {
        int reservationId = query.value("RESERVATION_ID").toInt();
        int copyId = query.value("COPY_ID").toInt();
        QString isbn = query.value("ISBN").toString();
        int queuePos = query.value("QUEUE_POSITION").toInt();

        QSqlQuery updateQueueQuery;
        updateQueueQuery.prepare(R"(
            UPDATE reservations
            SET QUEUE_POSITION = QUEUE_POSITION - 1
            WHERE COPY_ID = :copy AND ISBN = :isbn AND QUEUE_POSITION > :pos
        )");
        updateQueueQuery.bindValue(":copy", copyId);
        updateQueueQuery.bindValue(":isbn", isbn);
        updateQueueQuery.bindValue(":pos", queuePos);

        if (!updateQueueQuery.exec()) {
            qDebug() << "Failed to update queue positions!";
        }


        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM reservations WHERE RESERVATION_ID = :id");
        deleteQuery.bindValue(":id", reservationId);

        if (!deleteQuery.exec()) {
            qDebug() << "Failed to delete expired reservation!";
        }
    }

    qDebug() << "Reservation cleanup completed successfully.";
}

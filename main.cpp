#include "loginwindow.h"

#include <QApplication>

#include "runtimefunctions.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/LKTech/Desktop/OOP-Library/data.db");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully.";
    }


    RunTimeFunctions runtime;
    runtime.penalizeUsers();
    runtime.unpenalizeUsers();
    runtime.BlockUsers();
    runtime.deleteUsers();
    runtime.UpdateReservations();
    runtime.RemoveReservations();




    // Create shared database manager instances
    DatabaseManagerUser* dbuser = new DatabaseManagerUser();
    DatabaseManagerBook* dbbook = new DatabaseManagerBook();

    LoginWindow w(dbuser, dbbook);
    w.show();

    return a.exec();
}

#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDir>
#include <QStandardPaths>

DatabaseManager::DatabaseManager(QObject* parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "C:/Users/LKTech/Desktop/OOP-Library/data.db";
    m_db.setDatabaseName(dbPath);
    
    if (!m_db.open()) {
        qDebug() << "Error: Failed to open database:" << m_db.lastError().text();
    } else {
        QSqlQuery query ;
        if (!query.exec("PRAGMA foreign_keys = ON"))
        {
            qDebug() << "Error: Failed to enable foreign keys:" << query.lastError().text();
        }
        qDebug() << "Database opened successfully in constructor at" << dbPath;
            qDebug() << "Foreign keys enabled.";
    }
}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << "Database closed successfully in destructor";
    }
}

bool DatabaseManager::isOpen() const
{
    return m_db.isOpen();
}

QSqlDatabase& DatabaseManager::getDatabase()
{
    return m_db;
}

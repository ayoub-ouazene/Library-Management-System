#include "user.h"
#include "databasemanageruser.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>

using namespace std;

User::User(const QString& firstName , const QString& lastName , const QString& email , const QString& password , const QString& dateOfBirth , const QString& university ,const QString& penaltyReason , int penaltyDays , int rfid , long long idCard )
    : PenaltyReason(penaltyReason), PenaltyDays(penaltyDays)
{

    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setPassword(password);
    setDateOfBirth(dateOfBirth);
    setUniversity(university);
    setRFID(rfid);
    setIDCard(idCard);
}

// All setters
void User::setFirstName(const QString& fname) {
    First_name = fname;
}

void User::setLastName(const QString& lname) {
    Last_name = lname;
}

void User::setEmail(const QString& mail) {
    email = mail;
}

void User::setPassword(const QString& passwd) {
    password = passwd;
}

void User::setDateOfBirth(const QString& dob) {
    date_of_birth = dob;
}

void User::setUniversity(const QString& unv) {
    University = unv;
}

void User::setRFID(int rfid) {
    RFID = rfid;
}

void User::setIDCard(long long id) {
    ID_CARD = id;
}

// All getters
QString User::getFirstName() const {
    return First_name;
}

QString User::getLastName() const {
    return Last_name;
}

QString User::getEmail() const {
    return email;
}

QString User::getPassword() const {
    return password;
}

QString User::getDateOfBirth() const {
    return date_of_birth;
}

QString User::getUniversity() const {
    return University;
}

QString User::getPenaltyReason() const {
    return PenaltyReason;
}

int User::getPenaltyDays() const {
    return PenaltyDays;
}

int User::getRFID() const {
    return RFID;
}
long long User::getIDCard() const {
    return ID_CARD;
}

// isbanned() and isPenalized()
bool User::isbanned()const {
    return 0;
}
bool User::isPenalized() const {
    return PenaltyDays > 0 ;
}


int User::getTotalNumber()
{
    DatabaseManagerUser db;
    QSqlQuery query;
    if (query.exec("SELECT COUNT(*) FROM users")) {
        if (query.next()) {
            return query.value(0).toInt();
        }
    } else {
        qDebug() << "Error executing count query:" << query.lastError().text();
    }
    return 0;
}


QList<User> User::getAllUsers() {
    QList<User> userList;
    DatabaseManagerUser db;
    QSqlQuery query;
    if (query.exec("SELECT FirstName, LastName, ID_CARD, RFID, UNIVERSITY, EMAIL, "
                   "DateOfBirth, USER_TYPE, PASSWORD, CREATION_DATE, STATUS, IS_BLOCKED, IS_PENALIZED FROM users")) {
        while (query.next()) {
            QString firstName     = query.value("FirstName").toString();
            QString lastName      = query.value("LastName").toString();
            long long idCard      = query.value("ID_CARD").toLongLong();
            int rfid              = query.value("RFID").toInt();
            QString university    = query.value("UNIVERSITY").toString();
            QString email         = query.value("EMAIL").toString();
            QString dateOfBirth   = query.value("DateOfBirth").toString();
            QString password_db      = query.value("PASSWORD").toString();
            User u(firstName, lastName, email, password_db, dateOfBirth, university,
                   "", 0, rfid, idCard);
            userList.append(u);
        }
    } else {
        qDebug() << "Error executing SELECT query:" << query.lastError().text();
    }
    return userList;
}

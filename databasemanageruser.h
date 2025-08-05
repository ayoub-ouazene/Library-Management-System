#ifndef DATABASEMANAGERUSER_H
#define DATABASEMANAGERUSER_H

#include "databasemanager.h"
#include "user.h"
#include "student.h"
#include "teacher.h"
#include "externel.h"
#include "library_director.h"
#include "librarian.h"
#include "administrator.h"

class DatabaseManagerUser : public DatabaseManager
{
    Q_OBJECT
public:
    explicit DatabaseManagerUser(QObject* parent = nullptr);
    ~DatabaseManagerUser();

    bool searchUser(User* user) const;
    bool searchUser(long long id)const;

    QList<User*> searchUserByFirstName(QString firstname);
    QList<User*> searchUserByID(long long id );
    QList<User*> searchUserByType(QString type);
    QList<User*>searchUserByUniversity(QString univ);

    bool addUser(User* user) const;
    bool addUser(User*user , QString error)const;
    bool deleteUser(User* user) const;
    bool editUser(User* user) const;

    bool banUser(User* user) const;
    bool penalizeUser(User* user,const int & days,QString reason = "") const;

    User* validateUser(const QString& FirstName , const QString& LastName , const long long& id ,  const QString& password) const;
    QList<User*> listpenalizeUsers()const;
    QList<User*>  listunpenalizeUsers()const;
    QList<User*>  listblockedUsers()const;


    QList<User*> GeneralSearching(QString first_name="", QString last_name="", int id_card=0, int rfid=0, QString university="", QString email="", QString date_of_birth="", QString user_type="", QString creation_date="")const;


};

    bool valid_name(const QString& name);
     bool valid_id(const long long& id);
    bool valid_RFID(const int& rfid);
     bool isValidEmail(const QString &email);
     QString hashPassword(const QString &password);
     bool isValidDate(const QString &dob, int minAge = 5, int maxAge = 120);
     QString FixType(User *user);



#endif // DATABASEMANAGERUSER_H 

#ifndef USER_H
#define USER_H
#include <QString>
using namespace std;


class User
{


private:

    QString First_name;
    QString Last_name;
    QString email;
    QString password ;
    QString date_of_birth;
    QString University;
    QString PenaltyReason;
    int PenaltyDays;
    int RFID;
    long long ID_CARD;


public:
    User(const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",const QString& ="",int=0,int=0,long long=0);
    virtual ~User()=default;

      // Setters
     void setFirstName(const QString& fname);
     void setLastName(const QString& lname);
     void setEmail(const QString& mail);
     void setPassword(const QString& passwd);
     void setDateOfBirth(const QString& dob);
     void setUniversity(const QString& unv);
     void setRFID(int rfid);
    void setIDCard(long long id);

    // Getters
    QString getFirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    QString getPassword() const;
    QString getDateOfBirth() const;
    QString getUniversity() const;
    QString getPenaltyReason()const;
    int getPenaltyDays()const;
    int getRFID() const;
    long long getIDCard()const ;
    virtual bool isbanned()const;
    virtual bool isPenalized()const;




    //Static

    static int getTotalNumber();
    static QList<User> getAllUsers();



};

#endif // USER_H

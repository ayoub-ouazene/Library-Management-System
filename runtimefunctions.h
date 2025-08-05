#ifndef RUNTIMEFUNCTIONS_H
#define RUNTIMEFUNCTIONS_H


#include "databasemanagerbook.h"
#include "databasemanageruser.h"

class RunTimeFunctions
{
public:
    RunTimeFunctions(DatabaseManagerBook* dbbook=nullptr, DatabaseManagerUser* dbuser=nullptr);
    ~RunTimeFunctions()=default;

    void penalizeUsers();
    void unpenalizeUsers();
    void BlockUsers();
    void deleteUsers();

    void UpdateReservations();
    //calculate the differnece between current date and the due date in transformations table
    //until the copy is returned
    //add the difference number in the same time to expiration date of reservations of these copy automatically
    //add the number also to the general due date of the copy in bookcopies table
    //compare new expiration date of users with due  date of other copies
    //change the copy of the user

    void RemoveReservations();
    //remove the exipired reservations
    //update the number in Queue

private :

    DatabaseManagerUser dbuser;
    DatabaseManagerBook dbbook;

};

#endif // RUNTIMEFUNCTIONS_H

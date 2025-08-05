#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QMainWindow>
#include "user.h"
#include "databasemanageruser.h"
#include "databasemanagerbook.h"


namespace Ui {
class MainWindowAdmin;
}

class MainWindowAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowAdmin(User* user,DatabaseManagerUser* dbuser,DatabaseManagerBook* dbbook,QWidget *parent = nullptr);
    ~MainWindowAdmin();
    void searchUsers();
    void searchBooks();

private slots:
    void on_AddUserButton_clicked();

    void on_PenalizeUserButton_clicked();

    void on_DeleteUserButton_clicked();

    void on_EditUserButton_clicked();

    void on_ListOfBannedUsersButton_clicked();

    void on_ListOfPenalizedUsersButton_clicked();

    void on_AddBookButton_clicked();

    void on_DeleteBookButton_clicked();

    void on_EditBookButton_clicked();

    void on_ListOfBorrowedBooksButton_clicked();

    void on_dashboardButton_clicked();

    void on_dashboardButton_3_clicked();

    void on_dashboardButton_2_clicked();

    void on_dashboardButton_4_clicked();

    void on_dashboardButton_5_clicked();

    void on_ListOfUnreturnedBooksButton_clicked();

private:
    Ui::MainWindowAdmin *ui;
    User* user;
    DatabaseManagerBook* dbbook;
    DatabaseManagerUser* dbuser;
};

#endif // MAINWINDOWADMIN_H

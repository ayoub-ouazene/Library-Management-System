#ifndef MAINWINDOWUSER_H
#define MAINWINDOWUSER_H

#include <QMainWindow>
#include "user.h"
#include "databasemanagerbook.h"
#include "databasemanageruser.h"

namespace Ui {
class MainWindowUser;
}

class MainWindowUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUser(User* user,DatabaseManagerUser* dbuser,DatabaseManagerBook* dbbook,QWidget *parent = nullptr);
    ~MainWindowUser();
    void searchBooks();
    void searchUsers();

private slots:
    void on_LogOutButton_clicked();

    void on_RenewButton_clicked();

    void on_LastNewsButton_clicked();



    void on_ReturnButton_clicked();

    void handleBorrow(int row, QList<Book*> books,User* user);

    void handleReserve(int row , QList<Book*> books,User* user);

    void handleRenew(int row, QList<Book*> books,User* user);

    void handleReturn(int row, QList<Book*> books,User* user);

    void handleClaim(int row, QList<Book*> books,User* user);

    void on_BooksButton_clicked();

    void on_HomeButton_clicked();

    void on_HistoryButton_clicked();

    void on_AboutButton_clicked();

    void on_ListOfBorrowedBooksButton_clicked();

    void on_ListOfReservedBooksButton_clicked();

private:
    Ui::MainWindowUser *ui;
    User* user ;
    DatabaseManagerBook* dbbook;
    DatabaseManagerUser* dbuser;

};

#endif // MAINWINDOWUSER_H

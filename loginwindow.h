#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "databasemanagerbook.h"
#include "databasemanageruser.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow( DatabaseManagerUser* dbuser=nullptr,DatabaseManagerBook* dbbook=nullptr, QWidget *parent = nullptr  );
    ~LoginWindow();

private slots:
    void on_GoToSignUpButton_clicked();

    void on_LogInButton_clicked();

private:
    Ui::LoginWindow *ui;
    DatabaseManagerUser* dbuser;
    DatabaseManagerBook* dbbook;
};

#endif // LOGINWINDOW_H

#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QMainWindow>
#include "databasemanagerbook.h"
#include "databasemanageruser.h"

namespace Ui {
class SignInWindow;
}

class SignInWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignInWindow(DatabaseManagerUser* dbuser=nullptr,DatabaseManagerBook* dbbook=nullptr,QWidget *parent = nullptr);
    ~SignInWindow();

private slots:
    void on_SignInButton_clicked();

    void on_GoToLogInButton_clicked();

private:
    Ui::SignInWindow *ui;
    DatabaseManagerUser* dbuser;
    DatabaseManagerBook* dbbook;
};

#endif // SIGNINWINDOW_H

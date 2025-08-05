#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "signinwindow.h"
#include "databasemanageruser.h"
#include "runtimefunctions.h"
#include <QMessageBox>
#include "mainwindowadmin.h"
#include "mainwindowuser.h"

LoginWindow::LoginWindow(DatabaseManagerUser* dbuser , DatabaseManagerBook* dbbook,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow),dbuser(dbuser),dbbook(dbbook)
{
    ui->setupUi(this);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_GoToSignUpButton_clicked()
{
    SignInWindow* window = new SignInWindow();
    this->hide();
    window->show();
}


void LoginWindow::on_LogInButton_clicked()
{
    QString firstname , lastname,password;
    long long id;

    firstname = ui->FirstNameEdit->text();
    lastname = ui->LastNameEdit->text();
    id = ui->ID_Edit->text().toLongLong();
    password = ui->PasswordEdit->text();



    if(!valid_name(firstname) || !valid_name(lastname))
    {
        QMessageBox::warning(this,"Failed to Log in","Invalid Name");
        return ;
    }
    if(!valid_name(password))
    {
        QMessageBox::warning(this,"Failed to Log in","Invalid password");
        return ;
    }
    if(!valid_id(id))
    {
        QMessageBox::warning(this,"Failed to Log in","Invalid id");
        return ;
    }

    User* user =nullptr ;
    user= dbuser->validateUser(firstname,lastname,id,hashPassword(password));


    if(!user)
    {
        QMessageBox::warning(this,"Failed to Log in","Wrong Information \nUser Not Found !");
        return ;
    }

    QMessageBox::information(this,"Succefull","Log in succefully");

    if(FixType(user) == "librarian" || FixType(user) == "library_director")
    {
        MainWindowAdmin* main =new MainWindowAdmin(user,dbuser,dbbook);
        this->hide();
        main->show();
    }
    else
    {
        MainWindowUser* main = new MainWindowUser(user,dbuser,dbbook,this);
        this->hide();
        main->show();
    }


}


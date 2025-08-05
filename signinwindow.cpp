#include "signinwindow.h"
#include "ui_signinwindow.h"
#include "user.h"

#include <QMessageBox>
#include "mainwindowadmin.h"
#include "mainwindowuser.h"
#include "loginwindow.h"
#include "databasemanageruser.h"

SignInWindow::SignInWindow(DatabaseManagerUser* dbuser , DatabaseManagerBook* dbbook,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignInWindow)
{
    ui->setupUi(this);
}

SignInWindow::~SignInWindow()
{
    delete ui;
}

void SignInWindow::on_SignInButton_clicked()
{
    QString firstname = ui->FirstNameEdit->text().toUpper();
    QString lastname= ui->LastNameEdit->text().toUpper();
    QString email= ui->EmailEdit->text();
    QString univ = ui->UniversityEdit->text();

    long long id = ui->IDedit->text().toLongLong();
    QString date = ui->DateEdit->text();

    int rfid = ui->RFIDEdit->text().toInt();
    QString type = ui->TypeComboBox->currentText();
    QString password = ui->PasswordEdit->text();
     QString passwordconf = ui->PasswordConfEdit->text();


     if(password !=passwordconf || !valid_name(password))
     {
         QMessageBox::warning(this,"Failed to regiter","Password Misssmatch and invalid");
         ui->PasswordConfEdit->setFocus();
         return;
     }


     if(!valid_name(firstname)|| !valid_name(lastname) )
     {
         QMessageBox::warning(this,"Failed to regiter","Invalid Name");
         return;
     }

     if(!valid_RFID(rfid))
     {
         QMessageBox::warning(this,"Failed to regiter","Invalid RFID");
         return;
     }

     if(!isValidEmail(email))
     {
         QMessageBox::warning(this,"Failed to regiter","Invalid Email");
         return;
     }

     if(!valid_id(id))
     {
         QMessageBox::warning(this,"Failed to regiter","Invalid ID");
         return;
     }
     if(!isValidDate(date))
     {
         QMessageBox::warning(this,"Failed to regiter","Invalid Date ");
         return;
     }

     User* user ;
      password= hashPassword(password);


     if(type == "student")
     {
           user = new  Student(firstname,lastname,email,password,date,univ,"",0,rfid,id);
     }
     else if(type == "teacher")
         {
             user = new  Teacher(firstname,lastname,email,password,date,univ,"",0,rfid,id);
         }

     else  if(type == "externel")
         {
             user = new  Externel(firstname,lastname,email,password,date,univ,"",0,rfid,id);
         }
    else if (type== "administrator")
         {
             user = new  Administrator(firstname,lastname,email,password,date,univ,"",0,rfid,id);
         }
         else if (type == "librarian")
         {
              user = new  Librarian(firstname,lastname,email,password,date,univ,"",0,rfid,id);
         }

         else if (type == "library_director" )
         {
             user = new  Library_Director(firstname,lastname,email,password,date,univ,"",0,rfid,id);
         }
         else
         {
             QMessageBox::warning(this,"Failed to regiter","Invalid Inavalid Type Of user !");
             return;
         }


         QString error;
         if(dbuser->addUser(user,error))
         {
             QMessageBox::information(this,"Succefull Registration","User added Succefully");
             this->hide();

             if(type == "library_director" || type == "librarian")
             {
                 MainWindowAdmin* main =new MainWindowAdmin(user,dbuser,dbbook);
                 main->show();
             }
             else
             {
                 MainWindowUser* main = new  MainWindowUser(user,dbuser,dbbook,this);
                 main->show();

             }
         }
         else
         {
             QMessageBox::warning(this,"Failed To Add User",error);
             qDebug() << "Error: Failed to add user to database. Check DatabaseManager logs.";
         }

         delete user;
}


void SignInWindow::on_GoToLogInButton_clicked()
{
    this->hide();
    LoginWindow* window = new LoginWindow(dbuser, dbbook);
    window->show();
}


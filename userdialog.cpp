#include "userdialog.h"
#include "ui_userdialog.h"


#include "databasemanageruser.h"
#include "QMessageBox"

UserDialog::UserDialog(QString Type,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserDialog),Type(Type)
{
    ui->setupUi(this);

}


UserDialog::~UserDialog()
{
    delete ui;
}



void UserDialog::on_pushButton_clicked()
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
    DatabaseManagerUser database;

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

    if(Type == "ADD" )
    {
        if(database.addUser(user,error))
        {
            QMessageBox::information(this,"Succefull Registration","User added Succefully");
            this->hide();

        }
        else
        {
            QMessageBox::warning(this,"Failed To Add User",error);
            qDebug() << "Error: Failed to add user to database. Check DatabaseManager logs.";
        }
    }

    else if (Type == "DELETE")
    {
        if(database.deleteUser(user))
        {
            QMessageBox::information(this,"Succefull Registration","User added Succefully");
            this->hide();

        }
        else
        {
            QMessageBox::warning(this,"FAILED","Failed To delete User");
            qDebug() << "Error: Failed to delete user to database. Check DatabaseManager logs.";
        }
    }

    else if (Type == "EDIT")
    {
        if(database.editUser(user))
        {
            QMessageBox::information(this,"Succefull Registration","User added Succefully");
            this->hide();

        }
        else
        {
            QMessageBox::warning(this,"FAILED","Failed To delete User");
            qDebug() << "Error: Failed to delete user to database. Check DatabaseManager logs.";
        }
    }


    else if (Type == "PENALIZE")
    {
        if(database.penalizeUser(user,15,"FROM THE DIRECTOR"))
        {
            QMessageBox::information(this,"Succefull Penalization","User added Succefully");
            this->hide();

        }
        else
        {
            QMessageBox::warning(this,"FAILED","Failed To delete User");
            qDebug() << "Error: Failed to delete user to database. Check DatabaseManager logs.";
        }
    }

    delete user;
}



void UserDialog::on_pushButton_2_clicked()
{
    this->hide();
}


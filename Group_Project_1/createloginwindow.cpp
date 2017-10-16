#include "createloginwindow.h"
#include "ui_createloginwindow.h"
#include "windowholder.h"
#include <database.h>
#include <QString>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
/*! \fn CreateLoginWindow::CreateLoginWindow
 * \param parent */
CreateLoginWindow::CreateLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateLoginWindow)
{
    ui->setupUi(this);
}

/*! \fn CreateLoginWindow::~CreateLoginWindow */
CreateLoginWindow::~CreateLoginWindow()
{
    delete ui;
}

/*! \fn CreateLoginWindow::on_pushButton_clicked */
void CreateLoginWindow::on_pushButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->CreateWindowHide();
    WH->LoginWindowShow();
    Database *DB = Database::getInstance();
}
/*! \fn CreateLoginWindow::on_Enter_clicked */
void CreateLoginWindow::on_Enter_clicked()
{
    QSqlQuery query;
    /* \ToDo Add error checking */
    if(!validateCreateLogin()){
        query.prepare("INSERT INTO Account (firstName, lastName, email, address, states, username, userPassword)"
                      "VALUES (:tempFirst, :tempLast, :tempEmail, :tempAddress, :tempState, :tempUser, :tempPass)");

        query.bindValue(":tempFirst", ui->firstName->text());
        query.bindValue(":tempLast", ui->lastName->text());
        query.bindValue(":tempEmail", ui->email->text());
        query.bindValue(":tempAddress", ui->address->text());
        query.bindValue(":tempState", ui->state->text());
        query.bindValue(":tempUser", ui->username->text());
        query.bindValue(":tempPass", ui->password->text());

        if(!query.exec()){
            qDebug() << "\nLogin Query Failed to execute!\n";
            qDebug() << query.lastError();
        }
        else{
            qDebug() << "\nQuery successfully executed!\n";
        }
        ui->password->clear();
        ui->username->clear();
        ui->firstName->clear();
        ui->lastName->clear();
        ui->email->clear();
        ui->address->clear();
        ui->state->clear();

        windowHolder *w = windowHolder::getInstance();
        w->CreateWindowHide();
        w->LoginWindowShow();
    }
    else{
        QMessageBox::critical(this, "ERROR", "Please fill in all infromation before entering!");
    }
}

 bool CreateLoginWindow::validateCreateLogin(){
     return (ui->firstName->text() == "" || ui->lastName->text() == "" || ui->email->text() == "" ||
             ui->address->text() == "" || ui->state->text() == "" ||
             ui->username->text() == "" || ui->password->text() == "");
 }

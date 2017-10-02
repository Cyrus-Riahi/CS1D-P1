#include "createloginwindow.h"
#include "ui_createloginwindow.h"
#include "windowholder.h"
#include <database.h>

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
    query.prepare("INSERT INTO Account (firstName, lastName, email, address, states, cardNum, CVV, expMonth, expYear, username, password)"
                  "VALUES (:tempFirst, :tempLast, :tempEmail, :tempAddress, :tempState, :tempCard, :tempCVV, :tempMonth, :tempYear, :tempUser, :tempPass)");
    query.bindValue(":tempFirst", ui->firstName->text());
    query.bindValue(":tempLast", ui->lastName->text());
    query.bindValue(":tempEmail", ui->email->text());
    query.bindValue(":tempAddress", ui->address->text());
    query.bindValue(":tempState", ui->state->text());
    query.bindValue(":tempCard", ui->cardNum->text());
    query.bindValue(":tempCVV", ui->CVV->text().toInt());
    query.bindValue(":tempMonth", ui->month->currentText().toInt());
    query.bindValue(":tempYear", ui->year->currentText().toInt());
    query.bindValue(":tempUser", ui->username->text());
    query.bindValue(":tempPass", ui->password->text());

    if(!query.exec()){
        qDebug() << "\nLogin Query Failed to execute!\n";
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
    ui->cardNum->clear();
    ui->CVV->clear();
    ui->month->clear();
    ui->year->clear();
}

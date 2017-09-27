#include "QString"
#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"
#include "windowholder.h"
#include <QMessageBox>

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    this->setWindowTitle("Login Window");
    ui->setupUi(this);
    this->user = false;

}

loginWindow::~loginWindow()
{
    delete ui;
}

QString loginWindow::getUsername()
{
    return ui->usernameLineEdit->displayText();
}

QString loginWindow::getPassword()
{
    return ui->passwordLineEdit->displayText();
}


void loginWindow::on_loginButton_clicked()
{
    if(ui->usernameLineEdit->text() == "user")
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
    }
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
    }
    else
    {
        QMessageBox::critical(this, "ERROR", "Incorrect login information!");
    }
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

bool loginWindow::isAdmin()
{
    return this->user;
}

bool loginWindow::isUser()
{
    return this->user;
}


void loginWindow::on_pushButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->LoginWindowHide();
    WH->CreateWindowShow();
}

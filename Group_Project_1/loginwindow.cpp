#include "QString"
#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"
#include "windowholder.h"
#include <QMessageBox>

/*! \fn loginWindow::loginWindow
 * \param parent */
loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

/*! \fn loginWindow::~loginWindow */
loginWindow::~loginWindow()
{
    delete ui;
}

/*! \fn loginWindow::on_loginButton_clicked */
void loginWindow::on_loginButton_clicked()
{
    /*! \brief user login requirements*/
    if(ui->usernameLineEdit->text() == "user")
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
    }
    /*! \brief admin login requierments*/
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
    }
    /*! \brief Incorrect login information*/
    else
    {
        QMessageBox::critical(this, "ERROR", "Incorrect login information!");
    }
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

/*! \fn loginWindow::on_passwordLineEdit_returnPressed */
void loginWindow::on_passwordLineEdit_returnPressed()
{
    /*! \brief user login requirements*/
    if(ui->usernameLineEdit->text() == "user")
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
    }
    /*! \brief admin login requierments*/
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
    }
    /*! \brief Incorrect login information*/
    else
    {
        QMessageBox::critical(this, "ERROR", "Incorrect login information!");
    }
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

/*! \fn loginWindow::on_usernameLineEdit_returnPressed */
void loginWindow::on_usernameLineEdit_returnPressed()
{
    /*! \brief user login requirements*/
    if(ui->usernameLineEdit->text() == "user")
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
    }
    /*! \brief admin login requierments*/
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
    }
    /*! \brief Incorrect login information*/
    else
    {
        QMessageBox::critical(this, "ERROR", "Incorrect login information!");
    }
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

/*! \fn loginWindow::on_createLoginButton_clicked */
void loginWindow::on_createLoginButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->LoginWindowHide();
    WH->CreateWindowShow();
}

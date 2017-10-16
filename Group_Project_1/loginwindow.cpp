#include "QString"
#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"
#include "windowholder.h"
#include <QMessageBox>


/*! \fn loginWindow::loginWindow
 * \param parent */
QString loginWindow::getUserNameLineEdit()
{
    return ui->usernameLineEdit->text();
}

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
    QVector<Account*> accounts;
    accounts = loadAccounts();
    bool userLogin = validateUserLogin(accounts,
                                       ui->usernameLineEdit->text(),
                                       ui->passwordLineEdit->text());
    /*! \brief user login requirements*/
    if(userLogin)
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
        WH->setMainUsername();
    }
    /*! \brief admin login requierments*/
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
        WH->setMainUsername();
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

    QVector<Account*> accounts;
    accounts = loadAccounts();
    bool userLogin = validateUserLogin(accounts,
                     ui->usernameLineEdit->text(),
                     ui->passwordLineEdit->text());
    /*! \brief user login requirements*/
    if(userLogin)
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
        WH->setMainUsername();
    }
    /*! \brief admin login requierments*/
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
        WH->setMainUsername();
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
    QVector<Account*> accounts;
    accounts = loadAccounts();
    bool userLogin = validateUserLogin(accounts,
                                       ui->usernameLineEdit->text(),
                                       ui->passwordLineEdit->text());
    if(userLogin)
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->MainWindowShow();
        WH->setMainUsername();
    }
    /*! \brief admin login requierments*/
    else if(ui->usernameLineEdit->text() == "admin" &&
            ui->passwordLineEdit->text() == "password" )
    {
        windowHolder* WH = windowHolder::getInstance();
        WH->LoginWindowHide();
        WH->AdminWindowShow();
        WH->setMainUsername();
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

QVector<Account*> loginWindow::loadAccounts(){
    QVector<Account*> accounts;
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");
    if (query.exec("SELECT * FROM Account"))
    {
        while(query.next())
        {
            accounts.push_back(new Account(query.value(0).toString(),
                                           query.value(1).toString(),
                                           query.value(2).toString(),
                                           query.value(3).toString(),
                                           query.value(4).toString(),
                                           query.value(5).toString(),
                                           query.value(6).toString()));
        }
    }
    return accounts;
}

bool loginWindow::validateUserLogin(QVector<Account*> accounts,
                                    QString username,
                                    QString password){
    bool found = false;
    int count = 0;
    while(count < accounts.size()){
        if(accounts[count]->getUsername() == username &&
           accounts[count]->getPassword() == password){
            found = true;
        }
        count++;
    }
    return found;
}

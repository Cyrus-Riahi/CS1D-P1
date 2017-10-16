#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "mainwindow.h"
#include "account.h"
#include <QSqlQuery>
#include <QVariant>
#include <QVector>
#include <QMainWindow>

/*! \namespace UI
*/
namespace Ui {
class loginWindow;
}

/*! * \class loginWindow*/
class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! * \fn loginWindow*/
    /*! * \param parent*/
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

    /*!
     * fn getUserNameLineEdit
     * \return
     */
    QString getUserNameLineEdit();


private slots:
    /*! * \fn on_loginButton_clicked*/
    void on_loginButton_clicked();

    /*! * \fn on_passwordLineEdit_returnPressed*/
    void on_passwordLineEdit_returnPressed();

    /*! * \fn on_usernameLineEdit_returnPressed*/
    void on_usernameLineEdit_returnPressed();

    /*! * \fn on_createLoginButton_clicked*/
    void on_createLoginButton_clicked();

    /*!
     * \fn loadAccounts
     * \return
     */
    QVector<Account*> loadAccounts();

    /*!
     * \fn validateUserLogin
     * \param accounts
     * \param username
     * \param password
     * \return
     */
    bool validateUserLogin(QVector<Account*> accounts, QString username, QString password);

private:
    /*! * \var ui*/
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "mainwindow.h"
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


private slots:
    /*! * \fn on_loginButton_clicked*/
    void on_loginButton_clicked();

    /*! * \fn on_passwordLineEdit_returnPressed*/
    void on_passwordLineEdit_returnPressed();

    /*! * \fn on_usernameLineEdit_returnPressed*/
    void on_usernameLineEdit_returnPressed();

    /*! * \fn on_createLoginButton_clicked*/
    void on_createLoginButton_clicked();

private:
    /*! * \var ui*/
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H

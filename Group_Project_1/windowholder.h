#include "loginwindow.h"
#include "adminwindow.h"
#include "createloginwindow.h"
#include "keywindow.h"
#ifndef WINDOWHOLDER_H
#define WINDOWHOLDER_H

/*! \class windowHolder*/
class windowHolder
{
public:
    /*! \fn getInstance
     * \return*/
    static windowHolder* getInstance();

    /*! \fn MainWindowHide*/
    void MainWindowHide()
    {
        main.hide();
    }

    /*! \fn MainWindowShow*/
    void MainWindowShow()
    {
        main.show();
    }

    /*! \fn LoginWindowHide*/
    void LoginWindowHide()
    {
        login.hide();
    }

    /*! \fn LoginWindowShow*/
    void LoginWindowShow()
    {
        login.show();
    }

    /*! \fn AdminWindowHide*/
    void AdminWindowHide()
    {
        admin.hide();
    }

    /*! \fn AdminWindowShow*/
    void AdminWindowShow()
    {
        admin.hideGroupBoxes();
        admin.show();
    }

    /*! \fn CreateWindowHide*/
    void CreateWindowHide()
    {
        create.hide();
    }

    /*! \fn CreateWindowShow*/
    void CreateWindowShow()
    {
        create.show();
    }

    void keyWindowHide()
    {
        key.hide();
    }

    void keyWindowShow()
    {
        key.show();
    }

    void showFAT()
    {
        main.showFullertonAndTexas();
    }

private:
    windowHolder();                 /*! \var constructor of our singleton*/
    static windowHolder* instance;  /*! \var static instance of the singleton*/
    MainWindow main;                /*! \var mainwindow*/
    loginWindow login;              /*! \var login window*/
    adminWindow admin;              /*! \var admin window*/
    CreateLoginWindow create;       /*! \var create a login window*/
    keyWindow key;                  /*! \var key window*/
};

#endif // WINDOWHOLDER_H

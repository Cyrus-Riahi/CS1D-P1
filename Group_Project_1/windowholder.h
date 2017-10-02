#include "loginwindow.h"
#include "adminwindow.h"
#include "createloginwindow.h"
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

private:
    windowHolder();                 /*! \var constructor of our singleton*/
    static windowHolder* instance;  /*! \var static instance of the singleton*/
    MainWindow main;                /*! \var mainwindow*/
    loginWindow login;              /*! \var login window*/
    adminWindow admin;              /*! \var admin window*/
    CreateLoginWindow create;       /*! \var create a login window*/
};

#endif // WINDOWHOLDER_H

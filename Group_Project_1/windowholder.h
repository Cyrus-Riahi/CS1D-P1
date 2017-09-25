#include "loginwindow.h"
#include "adminwindow.h"
#ifndef WINDOWHOLDER_H
#define WINDOWHOLDER_H


class windowHolder
{
public:
    static windowHolder* getInstance();

    void MainWindowHide()
    {
        main.hide();
    }
    void MainWindowShow()
    {
        main.show();
    }
    void LoginWindowHide()
    {
        login.hide();
    }
    void LoginWindowShow()
    {
        login.show();
    }
    void AdminWindowHide()
    {
        admin.hide();
    }
    void AdminWindowShow()
    {
        admin.show();
    }



private:
    windowHolder();
    static windowHolder* instance;
    MainWindow main;
    loginWindow login;
    adminWindow admin;
};

#endif // WINDOWHOLDER_H

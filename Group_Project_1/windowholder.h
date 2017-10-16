#include "loginwindow.h"
#include "adminwindow.h"
#include "createloginwindow.h"
#include "keywindow.h"
#include "shoppingcart.h"
#ifndef WINDOWHOLDER_H
#define WINDOWHOLDER_H

#include <QDebug>



/*! \class windowHolder*/
class windowHolder
{
public:
    /*! \fn getInstance */
    static windowHolder* getInstance();

    /*! \fn MainWindowHide*/
    void MainWindowHide()
    {
        main.hide();
    }

    /*! \fn MainWindowShow*/
    void MainWindowShow()
    {
        main.checkSchoolsForButtons();
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

    /*! \fn keyWindowHide*/
    void keyWindowHide()
    {
        key.hide();
    }

    /*! \fn keyWindowShow*/
    void keyWindowShow()
    {
        key.show();
    }

    /*! \fn shoppingWindowHide*/
    void shoppingWindowHide()
    {
        shop.hide();
    }

    /*! \fn shoppingWindowShow*/
    void shoppingWindowShow()
    {
        shop.show();
    }

    /*!
     * \fn setShopButton
     * \param school
     */
    void setShopButton(QString school)
    {
        shop.setButtonSchool(school);
    }

    /*! \fn showShopNextSchoolButton*/
    void showShopNextSchoolButton()
    {
        shop.showNextSchoolButton();
    }

    /*! \fn hideShopNextSchoolButton*/
    void hideShopNextSchoolButton()
    {
        shop.hideNextSchoolButton();
    }

    /*! \fn mainUpdateUI*/
    void mainUpdateUI()
    {
        main.updateUserUI();
    }

    /*! \fn mainIncIndex*/
    void mainIncIndex()
    {
        main.incAutoTripIndex();
    }

    /*! \fn updateShopWindow*/
    void updateShopWindow()
    {
        shop.update();
    }


private:
    windowHolder();                 /*! \var constructor of our singleton*/
    static windowHolder* instance;  /*! \var static instance of the singleton*/
    MainWindow main;                /*! \var mainwindow*/
    loginWindow login;              /*! \var login window*/
    adminWindow admin;              /*! \var admin window*/
    CreateLoginWindow create;       /*! \var create a login window*/
    keyWindow key;                  /*! \var key window*/
    shoppingcart shop;              /*! \var key window*/
};

#endif // WINDOWHOLDER_H

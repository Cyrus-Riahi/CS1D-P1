#include "loginwindow.h"
#include "adminwindow.h"
#include "createloginwindow.h"
#include "keywindow.h"
#include "shoppingcart.h"
#include "checkoutwindow.h"
#ifndef WINDOWHOLDER_H
#define WINDOWHOLDER_H

#include <QDebug>

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

    void keyWindowHide()
    {
        key.hide();
    }

    void keyWindowShow()
    {
        key.show();
    }

    void shoppingWindowHide()
    {
        shop.hide();
    }

    void shoppingWindowShow()
    {
        shop.show();
    }

    void setShopButton(QString school)
    {
        shop.setButtonSchool(school);
    }

    void showShopNextSchoolButton()
    {
        shop.showNextSchoolButton();
    }

    void hideShopNextSchoolButton()
    {
        shop.hideNextSchoolButton();
    }

    void mainUpdateUI()
    {
        main.updateUserUI();
    }

    void mainIncIndex()
    {
        main.incAutoTripIndex();
    }

    void updateShopWindow()
    {
        shop.update();
    }

    void checkoutWindowHide()
    {
        checkout.hide();
    }

    void checkoutWindowShow()
    {
        checkout.show();
        checkout.setUserameLabel();
    }
    QString getUserName(){
        return login.getUserNameLineEdit();
    }

    void setMainUsername()
    {
        main.setCurrentAccount(this->getUserName());
    }

    QString getUsername()
    {
        return main.getCurrentAccount();
    }

    void clearShoppingCart()
    {
        shop.clearShoppingCart();
        shop.setShoppingCartTable();
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
    CheckoutWindow checkout;        /*! \var checkout window for buying souvenirs*/
};

#endif // WINDOWHOLDER_H

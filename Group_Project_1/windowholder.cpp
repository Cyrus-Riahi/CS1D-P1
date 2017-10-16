#include "windowholder.h"

/*! \brief windowHolder::instance */
windowHolder* windowHolder::instance = nullptr;

/*! \fn windowHolder::getInstance
 * \return */
windowHolder *windowHolder::getInstance()
{
    if(instance == nullptr)     /*! \brief if the instance is still a nullptr*/
    {
        instance = new windowHolder;/*! \brief create a new instance*/
    }
    return instance; /*! \brief if the instance exists, it'll return a copy of the isntance*/
}

/*! \fn windowHolder::windowHolder */
windowHolder::windowHolder()
{
    main.setWindowTitle("Route Tracker");
    main.setFixedSize(main.width(), main.height());
    main.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    login.setWindowTitle("Route Tracker");
    login.setFixedSize(login.width(), login.height());
    login.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    admin.setWindowTitle("Route Tracker(Admin)");
    admin.setFixedSize(admin.width(), admin.height());
    admin.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    create.setWindowTitle("Create a Login");
    create.setFixedSize(create.width(), create.height());
    create.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    key.setWindowTitle("Key");
    key.setFixedSize(key.width(), key.height());
    key.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    shop.setWindowTitle("Shop \'Til You Drop");
    shop.setFixedSize(shop.width(), shop.height());
    shop.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    checkout.setWindowTitle("Checkout");
    checkout.setFixedSize(checkout.width(), checkout.height());
    checkout.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

}

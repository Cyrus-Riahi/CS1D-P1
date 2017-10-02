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
    login.setWindowTitle("Route Tracker");
    admin.setWindowTitle("Route Tracker(Admin)");
    create.setWindowTitle("Create a Login");
    key.setWindowTitle("Key");
}

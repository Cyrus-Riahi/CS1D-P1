#include "windowholder.h"

windowHolder* windowHolder::instance = nullptr;

windowHolder *windowHolder::getInstance()
{
    if(instance == nullptr)     //if the instance is still a nullptr
    {
        instance = new windowHolder;// create a new instance
    }
    return instance; // if the instance exists, it'll return a copy of the isntance
}

windowHolder::windowHolder()
{
    main.setWindowTitle("Route Tracker");
    login.setWindowTitle("Route Tracker");
    admin.setWindowTitle("Route Tracker(Admin)");
    create.setWindowTitle("Create a Login");
}

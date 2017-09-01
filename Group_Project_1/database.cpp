#include "database.h"
#include <QFileInfo>
#include <QDebug>

// This ensures that our database is a singleton.
// We only need one copy of the database
Database* Database::instance = nullptr;

//This is our private constructor
Database::Database() : QSqlDatabase(addDatabase("MySQL"))
{
    this->setDatabaseName("");// add that path to the Database inside quotes
    QFileInfo existingDatabaseInfo("");// add that path to the Database inside quotes

    if(existingDatabaseInfo.exists()){
        qDebug() << "Database file is open.\n";
        this->open();
        QSqlQuery query;
        query.prepare("PRAGMA foreign_keys = ON");
        query.exec();
    }else{
        qDebug() << "Database file is not open.\n";
    }
}

// This returns the instance as a singleton pattern
Database* Database::getInstance(){
    if(instance == nullptr)     //if the instance is still a nullptr
    {
        instance = new Database;// create a new instance
    }
    return instace; // if the instance exists, it'll return a copy of the isntance
                    // Or if the new instance has been made, it will return that
}

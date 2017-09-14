#include "database.h"
#include <QFileInfo>

// This ensures that our database is a singleton.
// We only need one copy of the database
Database* Database::instance = nullptr;

//This is our private constructor
Database::Database() : QSqlDatabase(addDatabase("QSQLITE"))
{
    this->setDatabaseName("./Database/SchoolTrips.db");// add the path to the Database inside quotes
    QFileInfo existingDatabaseInfo("./Database/SchoolTrips.db");// add th path to the Database inside quotes

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
    return instance; // if the instance exists, it'll return a copy of the isntance
    // Or if the new instance has been made, it will return that
}

// This function returns the name of the school thats closest and
// and the distance to it. It also does check to see if the school has already
// been visited to.
college* Database::getClosestSchool(QString schoolName,
                                    QVector<college *> collegesToVisit)
{
    int smallestDistance = collegesToVisit[81]->distance;
    bool found = false;

    for(int i = 0 ; i < collegesToVisit.size(); i++)
    {
        if(schoolName == collegesToVisit[i]->endingCollege)
        {
            collegesToVisit[i]->visited = true;
        }
        if(schoolName == collegesToVisit[i]->startingCollege &&
           schoolName != collegesToVisit[i]->endingCollege &&
           collegesToVisit[i]->distance < smallestDistance &&
           collegesToVisit[i]->visited == false)
        {
            smallestDistance = collegesToVisit[i]->distance;
        }
    }

    int index = 0;
    while(!found && index < collegesToVisit.size())
    {
        if(smallestDistance == collegesToVisit[index]->distance &&
           schoolName == collegesToVisit[index]->startingCollege)
        {
           found = true;
        }
        else
        {
            index++;
        }
    }
    collegesToVisit[index]->visited = true;
    return collegesToVisit[index];
}

//QSqlQueryModel* Database::souvenirModel(Qstring schoolName){
//    QSqlQueryModel* model = new QSqlQueryModel;

//}

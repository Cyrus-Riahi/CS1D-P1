#ifndef DATABASE_H
#define DATABASE_H
#include "collegestovisit.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPair>
#include <QDebug>
#include <QSqlQueryModel>


// Our database is a singleton because we dont want accidental copies
class Database: public QSqlDatabase
{
public:
    static Database* getInstance();
    void addToDatabase();
    college* getClosestSchool(QString schoolName,
                          QVector<college*> collegesToVisit);

//    QSqlQueryModel* souvenirModel(Qstring schoolName);


private:
    Database();         // private constructor so it cannot be accessed publicly
    static Database* instance;
};

#endif // DATABSE_H

#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>

// Our database is a singleton because we dont want accidental copies
class Database: public QSqlDatabase
{
public:
    static Database* getInstance();
    void addToDatabase();

private:
    Database();         // private constructor so it cannot be accessed publicly
    static Database* instance;
};

#endif // DATABSE_H

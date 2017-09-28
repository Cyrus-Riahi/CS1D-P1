#ifndef DATABASE_H
#define DATABASE_H
#include "collegestovisit.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPair>
#include <QDebug>
#include <QSqlQueryModel>
#include <math.h>


/*! \class Database
 *  Our database is a singleton because we dont want accidental copies
 */
class Database: public QSqlDatabase
{
public:
    /*! * \fn getInstance*/
    /*! * \return*/
    static Database* getInstance();

    /*! * \fn addToDatabase*/
    void addToDatabase();

    /*! * \fn getClosestSchool*/
    /*! * \param schoolName*/
    /*! * \param collegesToVisit*/
    /*! * \return*/
    college* getClosestSchool(QString schoolName,
                          QVector<college*> collegesToVisit);

    /*! * \fn getNumSchools*/
    /*! * \return*/
    int getNumSchools();

private:
    /*!  \fn Database*/
    /*!  private constructor so it cannot be accessed publicly
    */
    Database();
    /*! * \var instance*/
    /*!  static variable of our singleton instance
     */
    static Database* instance;
};

#endif // DATABSE_H

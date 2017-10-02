#include <QString>

#ifndef SOUVENIR_H
#define SOUVENIR_H

/*! \class souvenir*/
class souvenir
{
public:
    /*! \fn souvenir
     * \param schoolName
     * \param souvenirName
     * \param price*/
    souvenir(QString schoolName, QString souvenirName, QString price)
    {
        this->school = schoolName;
        this->souvenirName = souvenirName;
        this->price = price;
    }

    QString school;             /*! \var QString to represnt the souvenir's school*/
    QString souvenirName;       /*! \var QString name of the souvenir*/
    QString price;              /*! \var QString of the price of the souvenir*/
};
#endif // SOUVENIR_H

#include <QString>

#ifndef SOUVENIR_H
#define SOUVENIR_H

class souvenir
{
public:
    souvenir(QString schoolName, QString souvenirName, QString price)
    {
        this->school = schoolName;
        this->souvenirName = souvenirName;
        this->price = price;
    }


    // VARIABLE DECLARATION         need getters and setters and made private
    QString school;
    QString souvenirName;
    QString price;
};



#endif // SOUVENIR_H

#include "account.h"
Account::Account(QString firstName,
                 QString lastName,
                 QString email,
                 QString address,
                 QString state,
                 QString cardNum,
                 QString CVV,
                 QString month,
                 QString year,
                 QString username,
                 QString password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->address = address;
    this->state = state;
    this->cardNum = cardNum;
    this->CVV = CVV;
    this->month = month;
    this->year = year;
    this->username = username;
    this->password = password;
}
QString Account::getUsername(){
    return username;
}

QString Account::getPassword(){
    return password;
}


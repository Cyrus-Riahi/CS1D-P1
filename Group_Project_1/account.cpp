#include "account.h"
Account::Account(QString firstName,
                 QString lastName,
                 QString email,
                 QString address,
                 QString state,
                 QString username,
                 QString password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->address = address;
    this->state = state;
    this->username = username;
    this->password = password;
}
QString Account::getUsername(){
    return username;
}

QString Account::getPassword(){
    return password;
}
void Account::setLastLogin(Account *lastLogin){
//    this->lastLogin = lastLogin;
}

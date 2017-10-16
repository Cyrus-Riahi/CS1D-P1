#include "account.h"

/*!
 * \fn Account::Account
 * \param firstName
 * \param lastName
 * \param email
 * \param address
 * \param state
 * \param username
 * \param password
 */
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

/*!
 * \fn Account::getUsername
 * \return
 */
QString Account::getUsername(){
    return username;
}

/*!
 * \fn Account::getPassword
 * \return
 */
QString Account::getPassword(){
    return password;
}
/*!
 * \fn Account::setLastLogin
 * \param lastLogin
 */
void Account::setLastLogin(Account *lastLogin){
//    this->lastLogin = lastLogin;
}

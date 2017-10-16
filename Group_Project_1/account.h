#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include <QVector>
class Account
{
public:
    /*!
     * \fn Account
     * \param firstName
     * \param lastName
     * \param email
     * \param address
     * \param state
     * \param username
     * \param password
     */
    Account(QString firstName,
            QString lastName,
            QString email,
            QString address,
            QString state,
            QString username,
            QString password);

            void setLastLogin(Account* lastLogin);
            QString getUsername();
            QString getPassword();

private:
    QString firstName;              /*! \var firstName*/
    QString lastName;               /*! \var lastName*/
    QString email;                  /*! \var email*/
    QString address;                /*! \var address*/
    QString state;                  /*! \var state*/
    QString cardNum;                /*! \var cardNum*/
    QString username;               /*! \var username*/
    QString password;               /*! \var password*/
};

#endif // ACCOUNT_H

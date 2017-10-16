#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include <QVector>
class Account
{
public:
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
    QString firstName;
    QString lastName;
    QString email;
    QString address;
    QString state;
    QString cardNum;
    QString username;
    QString password;
};

#endif // ACCOUNT_H

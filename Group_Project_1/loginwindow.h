#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

    QString getUsername();
    QString getPassword();
    bool isAdmin();
    bool isUser();

private slots:
    void on_loginButton_clicked();

    void on_passwordLineEdit_returnPressed();

    void on_usernameLineEdit_returnPressed();

    void on_createLoginButton_clicked();

private:
    Ui::loginWindow *ui;
    MainWindow m;
    bool user;
};

#endif // LOGINWINDOW_H

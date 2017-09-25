#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "windowholder.h"

adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::on_backToLoginButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->AdminWindowHide();
    WH->LoginWindowShow();
}

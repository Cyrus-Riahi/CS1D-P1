#include "createloginwindow.h"
#include "ui_createloginwindow.h"
#include "windowholder.h"

CreateLoginWindow::CreateLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateLoginWindow)
{
    ui->setupUi(this);
}

CreateLoginWindow::~CreateLoginWindow()
{
    delete ui;
}

void CreateLoginWindow::on_pushButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->CreateWindowHide();
    WH->LoginWindowShow();
}

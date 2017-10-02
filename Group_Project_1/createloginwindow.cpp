#include "createloginwindow.h"
#include "ui_createloginwindow.h"
#include "windowholder.h"

/*! \fn CreateLoginWindow::CreateLoginWindow
 * \param parent */
CreateLoginWindow::CreateLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateLoginWindow)
{
    ui->setupUi(this);
}

/*! \fn CreateLoginWindow::~CreateLoginWindow */
CreateLoginWindow::~CreateLoginWindow()
{
    delete ui;
}

/*! \fn CreateLoginWindow::on_pushButton_clicked */
void CreateLoginWindow::on_pushButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->CreateWindowHide();
    WH->LoginWindowShow();
}

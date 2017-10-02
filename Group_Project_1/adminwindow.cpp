#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "windowholder.h"
/*! \fn adminWindow::adminWindow
 * \param parent*/
adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
}

/*! \fn adminWindow::~adminWindow */
adminWindow::~adminWindow()
{
    delete ui;
}

/*! \fn adminWindow::on_backToLoginButton_clicked*/
void adminWindow::on_backToLoginButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->AdminWindowHide();
    WH->LoginWindowShow();
}

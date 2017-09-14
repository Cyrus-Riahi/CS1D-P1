#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Database::getInstance();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CB_School_Souvenirs_currentIndexChanged(const QString &arg1)
{

}

#include "shoppingcart.h"
#include "ui_shoppingcart.h"

shoppingcart::shoppingcart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shoppingcart)
{
    ui->setupUi(this);
}

shoppingcart::~shoppingcart()
{
    delete ui;
}

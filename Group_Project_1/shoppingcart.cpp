#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "windowholder.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

shoppingcart::shoppingcart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shoppingcart)
{
    ui->setupUi(this);


    ui->toTheNextButton->hide();
}

shoppingcart::~shoppingcart()
{
    delete ui;
}

void shoppingcart::setButtonSchool(QString school)
{
    ui->currentSchoolLineEdit->setText(school);

    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT Traditional_Souvenirs, Cost FROM College_Souvenirs WHERE College = ? ORDER BY Traditional_Souvenirs ASC");
    query.addBindValue(school);

    query.exec();

    model->setQuery(query);

    ui->souvenirTableView->setModel(model);
    ui->souvenirTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->souvenirTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->souvenirTableView->verticalHeader()->setVisible(false);
    ui->souvenirTableView->show();
//    QItemSelectionModel *select = ui->souvenirTableView->selectionModel();

//    select->hasSelection(); //check if has selection
//    select->selectedRows(); // return selected row(s)

}

void shoppingcart::showNextSchoolButton()
{
    ui->toTheNextButton->show();
}

void shoppingcart::hideNextSchoolButton()
{
    ui->toTheNextButton->hide();
}

void shoppingcart::on_addToCartPushButton_clicked()
{
    QItemSelectionModel *select = ui->souvenirTableView->selectionModel();

//    select->
//        select->hasSelection(); //check if has selection

}

void shoppingcart::on_toTheNextButton_clicked()
{
    windowHolder *WH = windowHolder::getInstance();
    WH->mainUpdateUI();
}

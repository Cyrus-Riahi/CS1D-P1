#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "windowholder.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QHeaderView>
#include <QStandardItemModel>

shoppingcart::shoppingcart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shoppingcart)
{
    ui->setupUi(this);


    ui->toTheNextButton->hide();

    QStringList labels;
    labels << "School" << "Souvenir" << "Price" << "Quantity";

    ui->shoppingCartTableWidget->setHorizontalHeaderLabels(labels);
    ui->shoppingCartTableWidget->horizontalHeader()->show();
    ui->shoppingCartTableWidget->verticalHeader()->hide();
    ui->shoppingCartTableWidget->setShowGrid(false);
    ui->shoppingCartTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->shoppingCartTableWidget->setSortingEnabled(false);
    ui->shoppingCartTableWidget->setRowCount(ui->shoppingCartTableWidget->rowCount() + 1);

    ui->quantitySpinBox->setMinimum(1);


    ui->quantityLineEdit->setText("Number of souvenirs to buy: ");
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
    QModelIndexList selection = ui->souvenirTableView->selectionModel()->selectedIndexes();

    qDebug() << selection.count();
    qDebug() << selection.at(0).data().toString();
    int rowCount = ui->shoppingCartTableWidget->rowCount();


    if(selection.count() == 1)
    {
        QString indexItem = selection.at(0).data().toString();

        QSqlQuery query;


        qDebug() << rowCount;

        ui->shoppingCartTableWidget->insertRow(rowCount);
        ui->shoppingCartTableWidget->setRowCount(rowCount + 1);

        if(indexItem.at(0) == "$")
        {
            query.prepare("SELECT Traditional_Souvenirs FROM College_Souvenirs WHERE Cost = :Cost AND College = :College");
            query.bindValue(0, indexItem);
            query.bindValue(1, ui->currentSchoolLineEdit->text());

            query.exec();

            query.next();

            ui->shoppingCartTableWidget->setItem(rowCount - 1, 1,
                                                 new QTableWidgetItem(query.value(0).toString()));  // Souvenir
            ui->shoppingCartTableWidget->setItem(rowCount - 1, 2,
                                                 new QTableWidgetItem(indexItem));

        }
        else
        {
            query.prepare("SELECT Traditional_Souvenirs FROM College_Souvenirs WHERE Traditional_Souvenirs = :Souvenir AND College = :College");
            query.bindValue(1, ui->currentSchoolLineEdit->text());
            query.bindValue(0, indexItem);

            query.exec();

            query.next();

            ui->shoppingCartTableWidget->setItem(rowCount - 1, 1,
                                                 new QTableWidgetItem(indexItem));
            ui->shoppingCartTableWidget->setItem(rowCount - 1, 2,
                                                 new QTableWidgetItem(query.value(0).toString()));// Souvenir

        }

        ui->shoppingCartTableWidget->setItem(rowCount - 1, 0,
                                             new QTableWidgetItem(ui->currentSchoolLineEdit->text()));
        ui->shoppingCartTableWidget->setItem(rowCount - 1, 3,
                                             new QTableWidgetItem(ui->quantitySpinBox->text()));


    }
}

void shoppingcart::on_toTheNextButton_clicked()
{
    windowHolder *WH = windowHolder::getInstance();
    WH->mainUpdateUI();
}

void shoppingcart::on_deleteFromCartPushButton_clicked()
{

}

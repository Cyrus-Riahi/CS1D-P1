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

void shoppingcart::clearShoppingCart()
{
    ui->shoppingCartTableWidget->clear();
    for(int i = 0; i < ui->shoppingCartTableWidget->rowCount(); i++)
        ui->shoppingCartTableWidget->removeRow(i);
    ui->shoppingCartTableWidget->removeRow(0);
}

void shoppingcart::on_addToCartPushButton_clicked()
{
    QModelIndexList selection = ui->souvenirTableView->selectionModel()->selectedIndexes();

    int rowCount = ui->shoppingCartTableWidget->rowCount();

    QString tempTotal;
    double totalCost = 0;
    double tempCost = 0;
    if(ui->totalCostLineEdit->text() != "")
    {
        QString temp = ui->totalCostLineEdit->text();
        temp.remove("$");
        totalCost += temp.toDouble();
    }

    if(selection.count() == 1)
    {
        QString indexItem = selection.at(0).data().toString();

        QSqlQuery query;

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

            indexItem.remove("$");
            tempCost = ui->quantitySpinBox->text().toDouble() * indexItem.toDouble();
            totalCost += tempCost;
            tempTotal = QString::number(totalCost);
            if(tempTotal.at(tempTotal.size() - 3) != ".")
            {
                tempTotal.push_back("0");
            }

            ui->totalCostLineEdit->setText("$" + tempTotal);
            qDebug() << totalCost;
        }
        else
        {
            query.prepare("SELECT Cost FROM College_Souvenirs WHERE Traditional_Souvenirs = :Souvenir AND College = :College");
            query.bindValue(1, ui->currentSchoolLineEdit->text());
            query.bindValue(0, indexItem);

            query.exec();

            query.next();

            ui->shoppingCartTableWidget->setItem(rowCount - 1, 1,
                                                 new QTableWidgetItem(indexItem));
            ui->shoppingCartTableWidget->setItem(rowCount - 1, 2,
                                                 new QTableWidgetItem(query.value(0).toString()));// Souvenir

            QString temp = query.value(0).toString();
            temp.remove("$");
            tempCost = ui->quantitySpinBox->text().toDouble() * temp.toDouble();
            totalCost += tempCost;
            tempTotal = QString::number(totalCost);
            if(tempTotal.at(tempTotal.size() - 3) != ".")
            {
                tempTotal.push_back("0");
            }

            ui->totalCostLineEdit->setText("$" + tempTotal);
            qDebug() << totalCost;

        }

        ui->shoppingCartTableWidget->setItem(rowCount - 1, 0,
                                             new QTableWidgetItem(ui->currentSchoolLineEdit->text()));
        ui->shoppingCartTableWidget->setItem(rowCount - 1, 3,
                                             new QTableWidgetItem(ui->quantitySpinBox->text()));



    }
    ui->souvenirTableView->selectionModel()->clear();
}

void shoppingcart::on_toTheNextButton_clicked()
{
    windowHolder *WH = windowHolder::getInstance();
    WH->mainUpdateUI();
}

void shoppingcart::on_deleteFromCartPushButton_clicked()
{
    QModelIndexList selection = ui->shoppingCartTableWidget->selectionModel()->selectedIndexes();
    bool found = false;
    int index = 0;
    double math = 0;
    QString tempTotal = ui->totalCostLineEdit->text();
    QString priceToDelete;

    if(ui->shoppingCartTableWidget->rowCount() > 1 &&
       selection.count() == 1)
    {
        while(!found && index < ui->shoppingCartTableWidget->rowCount())
        {
            qDebug() << QString::number(index);
            for(int j = 0; j < 4; ++j)
            {
                qDebug() << j;
                if(selection.at(0).data().toString() == ui->shoppingCartTableWidget->item(index, j)->text())
                {
                    found = true;
                    qDebug() << "Found";
                    qDebug() << ui->shoppingCartTableWidget->item(index, 0)->text();
                }
            }
            if(!found)
            {
                ++index;
                qDebug() << "Not found";
            }
        }
        priceToDelete = ui->shoppingCartTableWidget->item(index, 2)->text();
        ui->shoppingCartTableWidget->removeRow(index);
    }
    priceToDelete.remove("$");
    tempTotal.remove("$");

    math = tempTotal.toDouble();
    math -= priceToDelete.toDouble();
    tempTotal = QString::number(math);
    if(tempTotal.at(tempTotal.size() - 3) != ".")
    {
        tempTotal.push_back("0");
    }

    ui->totalCostLineEdit->setText("$" + tempTotal);
    ui->shoppingCartTableWidget->selectionModel()->clear();
}

void shoppingcart::on_checkoutButton_clicked()
{
    windowHolder* wh = windowHolder::getInstance();
    wh->checkoutWindowShow();
}

void shoppingcart::setShoppingCartTable()
{
    QStringList labels;
    labels << "School" << "Souvenir" << "Price" << "Quantity";

    ui->shoppingCartTableWidget->setHorizontalHeaderLabels(labels);
    ui->shoppingCartTableWidget->horizontalHeader()->show();
    ui->shoppingCartTableWidget->verticalHeader()->hide();
    ui->shoppingCartTableWidget->setShowGrid(false);
    ui->shoppingCartTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->shoppingCartTableWidget->setSortingEnabled(false);
    ui->shoppingCartTableWidget->setRowCount(ui->shoppingCartTableWidget->rowCount() + 1);

}

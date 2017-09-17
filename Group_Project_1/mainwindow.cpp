#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->tableWidget2 = new QTableWidget(0, 2);
    QStringList labels;
    labels << tr("Destination") << tr("Distance");
    ui->tableWidget2->setHorizontalHeaderLabels(labels);
    ui->tableWidget2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->tableWidget2->verticalHeader()->hide();
    ui->tableWidget2->setShowGrid(false);


    Database *DB = Database::getInstance();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CB_School_Souvenirs_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_CB_Distance_Tracker_currentTextChanged(const QString &arg1)
{
    QVector<college*> collegesList;
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");

    if (query.exec("SELECT * FROM College_Campus_Distances"))
    {
        while(query.next())
        {
            collegesList.push_back(new college(query.value(0).toString(), query.value(1).toString(), false, query.value(2).toInt()));
        }
    }




    if(ui->CB_Distance_Tracker->currentText()!="Select A School")
    {
        qDebug() << collegesList.size();

        int numSchools = ceil(sqrt(collegesList.size()));

        int currentSchoolIndex = -1;
       // int row = ui->tableWidget2->rowCount();

    // Watch this for out of bounds
        for(int i = 0; i < collegesList.size(); i+=(numSchools-1))
        {
            if(ui->CB_Distance_Tracker->currentText() == collegesList[i]->startingCollege)
            {
                currentSchoolIndex = i;
                break;
            }
        }

        if(currentSchoolIndex < 0)
        {
            qDebug() << "NOT FOUND?? Shouldn't be a thing";
        }
        else
        {
            ui->tableWidget2->setRowCount(0);
            for(int i = 0; i < (numSchools-1); i++)
            {
                ui->tableWidget2->insertRow(i);
                ui->tableWidget2->setItem(i, 0, new QTableWidgetItem(collegesList[currentSchoolIndex + i]->endingCollege));
                ui->tableWidget2->setItem(i, 1, new QTableWidgetItem(QString::number(collegesList[currentSchoolIndex + i]->distance)));
            }
        }


    }

}

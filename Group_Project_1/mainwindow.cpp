#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowholder.h"
#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>

/*! \fn MainWindow::MainWindow
 * \param parent */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*! \brief labels
     * This sets up the Distance table in the user window*/
    QStringList labels;
    labels << "Destination" << "Distance (miles)";
    ui->tableWidget2->setHorizontalHeaderLabels(labels);
    ui->tableWidget2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->tableWidget2->verticalHeader()->hide();
    ui->tableWidget2->setShowGrid(false);
    ui->tableWidget2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget2->setSortingEnabled(false);

    /*! \brief labels2
     * This sets up the souvenir table in the user window*/
    QStringList labels2;
    labels2 << "School" << "Souvenir" << "Price";
    ui->souvenirTable->setHorizontalHeaderLabels(labels2);
    ui->souvenirTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->souvenirTable->verticalHeader()->hide();
    ui->souvenirTable->setShowGrid(false);
    ui->souvenirTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    /*! \brief DB
     * This populates the drop down boxes for each user window*/
    Database *DB = Database::getInstance();
    this->populate_CD_Distance_Tracker_Combo_Box();
    this->populate_CD_School_Souvenirs_Combo_Box();

    ui->tabWidget->setCurrentIndex(0);
}

/*! \fn MainWindow::~MainWindow */
MainWindow::~MainWindow()
{
    delete ui;
}

/*! \fn MainWindow::on_CB_School_Souvenirs_currentIndexChanged
 * \param arg1 */
void MainWindow::on_CB_School_Souvenirs_currentIndexChanged(const QString &arg1)
{
    QVector<souvenir*> souvenirsList;
    QSqlQuery query;
    query.prepare("SELECT * FROM College_Souvenirs WHERE College_Souvenirs.College = :tempSchool");
    query.bindValue(0, ui->CB_School_Souvenirs->currentText());

    if (query.exec())
    {
        while(query.next())
        {
            souvenirsList.push_back(new souvenir(query.value(0).toString(), query.value(1).toString(), query.value(2).toString()));
        }
    }


    if(ui->CB_School_Souvenirs->currentText()!= "Select A School")
    {
        ui->souvenirTable->setRowCount(0);
        for(int i = 0; i < souvenirsList.size(); i++)
        {
            ui->souvenirTable->insertRow(i);
            ui->souvenirTable->setItem(i, 0, new QTableWidgetItem(souvenirsList[i]->school));
            ui->souvenirTable->setItem(i, 1, new QTableWidgetItem(souvenirsList[i]->souvenirName));
            ui->souvenirTable->setItem(i, 2, new QTableWidgetItem(souvenirsList[i]->price));
        }
    }
}

// This function populates the drop down box for School Souvenirs
/*! \fn MainWindow::populate_CD_School_Souvenirs_Combo_Box
 * This function populates the drop down box for School Souvenirs */
void MainWindow::populate_CD_School_Souvenirs_Combo_Box()
{
    QVector<souvenir*> souvenirsList;
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");

    if (query.exec("SELECT * FROM College_Souvenirs"))
    {
        while(query.next())
        {
            souvenirsList.push_back(new souvenir(query.value(0).toString(), query.value(1).toString(), query.value(2).toString()));
        }
    }

    QVector<QString> dropDownVector;
    dropDownVector.push_back("Select A School");
    bool found = false;
    for(int i = 0; i < souvenirsList.size(); i++)
    {
        for(int j = 0; j < dropDownVector.size(); j++)
        {
            if(souvenirsList[i]->school == dropDownVector[j])
            {
                found = true;
            }
        }
        if(!found)
        {
            dropDownVector.push_back(souvenirsList[i]->school);
        }
        found = false;
    }


    for(int i = 0; i < dropDownVector.size(); i++)
    {
        ui->CB_School_Souvenirs->addItem(dropDownVector[i]);
    }

}


/*! \fn MainWindow::populate_CD_Distance_Tracker_Combo_Box
 * This function populates the drop down box for Distance Tracker
 */
void MainWindow::populate_CD_Distance_Tracker_Combo_Box()
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
    QVector<QString> dropDownVector;
    dropDownVector.push_back("Select A School");
    bool found = false;
    for(int i = 0; i < collegesList.size(); i++)
    {
        for(int j = 0; j < dropDownVector.size(); j++)
        {
            if(collegesList[i]->startingCollege == dropDownVector[j])
            {
                found = true;
            }
        }
        if(!found)
        {
            dropDownVector.push_back(collegesList[i]->startingCollege);
        }
        found = false;
    }


    for(int i = 0; i < dropDownVector.size(); i++)
    {
        ui->CB_Distance_Tracker->addItem(dropDownVector[i]);
    }

}

/*! \fn MainWindow::on_CB_Distance_Tracker_currentTextChanged
 * \param arg1 */
void MainWindow::on_CB_Distance_Tracker_currentTextChanged(const QString &arg1)
{
    QVector<college*> collegesList;
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");

    if(ui->CB_Distance_Tracker->currentText()!="Select A School")
    {
        QString schoolName = ui->CB_Distance_Tracker->currentText();
        query.prepare("SELECT EndingCollege, Distance FROM College_Campus_Distances WHERE StartingCollege = :schoolName ORDER BY Distance ASC");
        query.bindValue(0, schoolName);
        if (query.exec())
        {
            while(query.next())
            {
                collegesList.push_back(new college(schoolName, query.value(0).toString(), false, query.value(1).toInt()));
            }
        }


        int numSchools = collegesList.size();/*ceil(sqrt(collegesList.size()));*/

        ui->tableWidget2->setRowCount(0);
        for(int i = 0; i < (numSchools); i++)
        {
            ui->tableWidget2->insertRow(i);
            ui->tableWidget2->setItem(i, 0, new QTableWidgetItem(collegesList[i]->endingCollege));
            ui->tableWidget2->setItem(i, 1, new QTableWidgetItem(QString::number(collegesList[i]->distance)));
        }


    }

}

/*! \fn MainWindow::on_backToLoginButton_clicked */
void MainWindow::on_backToLoginButton_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->MainWindowHide();
    WH->LoginWindowShow();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowholder.h"
#include <QDebug>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include "Database.h"

/*! \fn MainWindow::MainWindow
 * \param parent */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    this->manualTrip.clear();
    this->totalMiles = 0;
    ui->numOfSchoolsToVisitLabel->hide();
    ui->numOfSchoolsWheel->hide();

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

    this->setMouseTracking(true);

    ui->Us_pixelmap->setPixmap((QPixmap("..\\Images\\map")));
    ui->Us_pixelmap->setScaledContents(true);
    ui->Us_pixelmap->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


    ui->helpTextBrowser->setText("Welcome to the route tracker program! To use this program:\n"
                                 "1) First figure out if you want to do a manual trip between schools\n"
                                 "\tOR if you want to do an automatic trip using our formula.\n"
                                 "2) If you are unsure about what school each button represents, click the \"Key\" button.\n"
                                 "3) If you chose to do a manual trip(Auto-route-tracking is not clicked), start off by\n"
                                 "\tchoosing your first school. A window will pop up, this window allows you to buy a \n"
                                 "\tsouvenir from that school. Once done, close that window and choose your next school!\n"
                                 "\tOnce you have visited all of your schools, click the checkout button on your final \n"
                                 "\tdestination to checkout and finish!\n"
                                 "4) If you chose to do an auto trip, the button you click represents the starting school.\n"
                                 "\tTo go to more than 1 school, increase the spin box. Once you have the desired settings,\n"
                                 "\tclick the school you would like to start at. After clicking this school, the shopping\n"
                                 "\twindow will apear, to go to the next school in your trip, hit the \"Next School\" Button.\n"
                                 "\tOnce you have visited all of your schools, click the checkout button on your final \n"
                                 "\tdestination to checkout and finish!\n");

    this->autoTripIndex = 0;
}

/*! \fn MainWindow::~MainWindow */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \fn MainWindow::getNumOfSchool
 * \return
 */
int MainWindow::getNumOfSchool()
{
    QVector<QString> collegeNames;
    QSqlQuery query;

    query.prepare("SELECT distinct StartingCollege FROM College_Campus_Distances");

    query.exec();

    while(query.next())
    {
        collegeNames.push_back(query.value(0).toString());
    }

    return collegeNames.size();
}

void MainWindow::showFullertonAndTexas()
{
    ui->FullertonButton->show();
    ui->TexasButton->show();
}

/*!
 * \fn MainWindow::hideAllButtons
 */
void MainWindow::hideAllButtons()
{
    ui->FullertonButton->hide();
    ui->ASUButton->hide();
    ui->MITButton->hide();
    ui->NorthwesternButton->hide();
    ui->OSUButton->hide();
    ui->UCLAButton->hide();
    ui->UCIButton->hide();
    ui->UniversityOfWisconsinButton->hide();
    ui->UniversityOfPacificButton->hide();
    ui->UniversityOfOregonButton->hide();
    ui->UniversityOfMichiganButton->hide();
    ui->TexasButton->hide();
    ui->SaddlebackButton->hide();
}

/*!
 * \fn MainWindow::checkSchoolsForButtons
 */
void MainWindow::checkSchoolsForButtons()
{
    this->hideAllButtons();
    QSqlQuery query;
    QVector<QString> schooooools;

    query.prepare("SELECT distinct StartingCollege from College_Campus_Distances");

    query.exec();

    while(query.next())
    {
        schooooools.push_back(query.value(0).toString());
    }
    for(int i = 0; i < schooooools.size(); ++i)
    {
        if(schooooools[i] == "Arizona State University")
            ui->ASUButton->show();
        if(schooooools[i] == "Massachusetts Institute of Technology (MIT)")
            ui->MITButton->show();
        if(schooooools[i] == "Northwestern")
            ui->NorthwesternButton->show();
        if(schooooools[i] == "Ohio State University")
            ui->OSUButton->show();
        if(schooooools[i] == "Saddleback College")
            ui->SaddlebackButton->show();
        if(schooooools[i] == "University of Michigan")
            ui->UniversityOfMichiganButton->show();
        if(schooooools[i] == "University of California, Irvine (UCI)")
            ui->UCIButton->show();
        if(schooooools[i] == "University of California, Los Angeles (UCLA)")
            ui->UCLAButton->show();
        if(schooooools[i] == "University of Oregon")
            ui->UniversityOfOregonButton->show();
        if(schooooools[i] == "University of the Pacific")
            ui->UniversityOfPacificButton->show();
        if(schooooools[i] == "University of Wisconsin")
            ui->UniversityOfWisconsinButton->show();
        if(schooooools[i] == "California State University, Fullerton")
            ui->FullertonButton->show();
        if(schooooools[i] == "University of Texas")
            ui->TexasButton->show();
    }
    ui->numOfSchoolsWheel->setMaximum(schooooools.size());
    ui->numOfSchoolsWheel->clear();
    ui->numOfSchoolsWheel->setValue(0);
    ui->TotalMilesLabel->clear();
    ui->automaticRouteTrackingCheckBox->setChecked(false);
    ui->numOfSchoolsToVisitLabel->hide();
    ui->numOfSchoolsWheel->hide();
    ui->testBrowser->clear();
}

/*!
 * \fn MainWindow::updateUserUI
 */
void MainWindow::updateUserUI()
{
    windowHolder *WH = windowHolder::getInstance();

    if(this->autoTripIndex < this->autoTrip.size())
    {
        ui->testBrowser->append("From " + this->autoTrip[this->autoTripIndex-1]->startingCollege +
                " to " + this->autoTrip[this->autoTripIndex-1]->endingCollege
                + QString::number(this->autoTrip[this->autoTripIndex-1]->distance) + " miles\n");
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->updateShopWindow();
        WH->shoppingWindowShow();


        this->incAutoTripIndex();
    }
    else if(this->autoTripIndex == this->autoTrip.size())
    {
        ui->testBrowser->append("From " + this->autoTrip[this->autoTripIndex-1]->startingCollege +
                " to " + this->autoTrip[this->autoTripIndex-1]->endingCollege
                + QString::number(this->autoTrip[this->autoTripIndex-1]->distance) + " miles\n");
        WH->setShopButton(this->autoTrip[this->autoTripIndex-1]->endingCollege);
        WH->updateShopWindow();
        WH->shoppingWindowShow();
        this->incAutoTripIndex();
    }
    else
    {
        WH->shoppingWindowHide();
        QMessageBox::information(this, "DONE!", "Visited all the schools!");

    }
}

/*!
 * \fn MainWindow::incAutoTripIndex
 */
void MainWindow::incAutoTripIndex()
{
    this->autoTripIndex++;
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
    ui->CB_School_Souvenirs->clear();
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
    ui->CB_Distance_Tracker->clear();
    QVector<college*> collegesList;
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");

    if (query.exec("SELECT * FROM College_Campus_Distances"))
    {
        while(query.next())
        {
            collegesList.push_back(new college(query.value(0).toString(), query.value(1).toString(), false, query.value(2).toDouble()));
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
                collegesList.push_back(new college(schoolName, query.value(0).toString(), false, query.value(1).toDouble()));
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

void MainWindow::loadCollegesToVisit()
{
    if(!colleges.isEmpty())
    {
        colleges.clear();
    }
    Database *DB = Database::getInstance();
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");


    if (query.exec("SELECT * FROM College_Campus_Distances"))
    {
        while(query.next())
        {
            this->colleges.push_back(new college(query.value(0).toString(), query.value(1).toString(), false, query.value(2).toDouble()));
        }
    }
}

/*!
 * \fn MainWindow::on_SaddlebackButton_clicked
 */
void MainWindow::on_SaddlebackButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 1)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: Saddleback College\n");
        this->loadCollegesToVisit();
        routeTracker("Saddleback College", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: Saddleback College\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("Saddleback College");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to Saddleback College is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("Saddleback College", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "Saddleback College";

        }
        else if(this->currentSchool == "Saddleback College")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: Saddleback College\n");
            this->currentSchool = "Saddleback College";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_UCIButton_clicked
 */
void MainWindow::on_UCIButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 1)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of California, Irvine (UCI)\n");
        this->loadCollegesToVisit();
        routeTracker("University of California, Irvine (UCI)", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of California, Irvine (UCI)\n");
        this->incAutoTripIndex();

    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of California, Irvine (UCI)");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();


            ui->testBrowser->append("From " + this->currentSchool + " to University of California, Irvine (UCI) is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of California, Irvine (UCI)", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of California, Irvine (UCI)";

        }
        else if(this->currentSchool == "University of California, Irvine (UCI)")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of California, Irvine (UCI)\n");
            this->currentSchool = "University of California, Irvine (UCI)";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_UCLAButton_clicked
 */
void MainWindow::on_UCLAButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 1)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of California, Los Angeles (UCLA)\n");
        this->loadCollegesToVisit();
        routeTracker("University of California, Los Angeles (UCLA)", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of California, Los Angeles (UCLA)\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of California, Los Angeles (UCLA)");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to University of California, Los Angeles (UCLA) is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of California, Los Angeles (UCLA)", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of California, Los Angeles (UCLA)";

        }
        else if(this->currentSchool == "University of California, Los Angeles (UCLA)")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of California, Los Angeles (UCLA)\n");
            this->currentSchool = "University of California, Los Angeles (UCLA)";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*! \fn routeTracker
 * \param schoolName
 * \param numOfSchoolsVisiting
 * \param totalMiles
 * \param collegesToVisit */
void MainWindow::routeTracker(QString schoolName,           // Name of school that gets passed in
                              int numOfSchoolsVisiting,     // Total number of schools visiting
                              double &totalMiles,              // Total mileage of the trip
                              QVector<college*> collegesToVisit){// Vector of schools we are visiting
    /*! \brief Our database*/
    Database *DB = Database::getInstance();

    /*! \brief Closest school in comparison to schoolName*/
    college* closestSchool = DB->getClosestSchool(schoolName, collegesToVisit);

    QString closestSchoolName = closestSchool->endingCollege;

    /*! Base Case*/
    if(numOfSchoolsVisiting == 0)
    {
        return; /*! \brief This will leave the program if out number of schools to visit is 0
                    and not return anything since the function is void*/
    } else
    {
        totalMiles += closestSchool->distance;

        qDebug() << "About to push back";
        this->autoTrip.push_back(closestSchool);
        //        ui->testBrowser->append("From " + closestSchool->startingCollege + " to " +
        //                                closestSchool->endingCollege + " is " + QString::number(closestSchool->distance) + " miles\n");

        /*! \brief Calls the function again*/
        routeTracker(closestSchoolName, --numOfSchoolsVisiting, totalMiles, collegesToVisit);
    }
}

/*!
 * \fn MainWindow::on_UniversityOfPacificButton_clicked
 */
void MainWindow::on_UniversityOfPacificButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of the Pacific\n");
        this->loadCollegesToVisit();
        routeTracker("University of the Pacific", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of the Pacific\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of the Pacific");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to University of the Pacific is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of the Pacific", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of the Pacific";

        }
        else if(this->currentSchool == "University of the Pacific")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of the Pacific\n");
            this->currentSchool = "University of the Pacific";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_UniversityOfOregonButton_clicked
 */
void MainWindow::on_UniversityOfOregonButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of Oregon\n");
        this->loadCollegesToVisit();
        routeTracker("University of Oregon", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of Oregon\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of Oregon");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to University of Oregon is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of Oregon", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of Oregon";

        }
        else if(this->currentSchool == "University of Oregon")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of Oregon\n");
            this->currentSchool = "University of Oregon";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_ASUButton_clicked
 */
void MainWindow::on_ASUButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: Arizona State University\n");
        this->loadCollegesToVisit();
        routeTracker("Arizona State University", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: Arizona State University\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("Arizona State University");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to Arizona State University is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("Arizona State University", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "Arizona State University";

        }
        else if(this->currentSchool == "Arizona State University")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: Arizona State University\n");
            this->currentSchool = "Arizona State University";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_UniversityOfWisconsinButton_clicked
 */
void MainWindow::on_UniversityOfWisconsinButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of Wisconsin\n");
        this->loadCollegesToVisit();
        routeTracker("University of Wisconsin", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of Wisconsin\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of Wisconsin");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to University of Wisconsin is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of Wisconsin", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of Wisconsin";

        }
        else if(this->currentSchool == "University of Wisconsin")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of Wisconsin\n");
            this->currentSchool = "University of Wisconsin";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_NorthwesternButton_clicked
 */
void MainWindow::on_NorthwesternButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: Northwestern\n");
        this->loadCollegesToVisit();
        routeTracker("Northwestern", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: Northwestern\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("Northwestern");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to Northwestern is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("Northwestern", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "Northwestern";

        }
        else if(this->currentSchool == "Northwestern")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: Northwestern\n");
            this->currentSchool = "Northwestern";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_UniversityOfMichiganButton_clicked
 */
void MainWindow::on_UniversityOfMichiganButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of Michigan\n");
        this->loadCollegesToVisit();
        routeTracker("University of Michigan", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of Michigan\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of Michigan");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to University of Michigan is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of Michigan", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of Michigan";

        }
        else if(this->currentSchool == "University of Michigan")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of Michigan\n");
            this->currentSchool = "University of Michigan";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_MITButton_clicked
 */
void MainWindow::on_MITButton_clicked()
{
    this->autoTripIndex = 0;
    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        this->autoTrip.clear();

        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: Massachusetts Institute of Technology (MIT)\n");
        this->loadCollegesToVisit();
        routeTracker("Massachusetts Institute of Technology (MIT)", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: Massachusetts Institute of Technology (MIT)\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("Massachusetts Institute of Technology (MIT)");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to Massachusetts Institute of Technology (MIT) is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("Massachusetts Institute of Technology (MIT)", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "Massachusetts Institute of Technology (MIT)";

        }
        else if(this->currentSchool == "Massachusetts Institute of Technology (MIT)")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: Massachusetts Institute of Technology (MIT)\n");
            this->currentSchool = "Massachusetts Institute of Technology (MIT)";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_OSUButton_clicked
 */
void MainWindow::on_OSUButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: Ohio State University\n");
        this->loadCollegesToVisit();
        routeTracker("Ohio State University", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: Ohio State University\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("Ohio State University");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to Ohio State University is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("Ohio State University", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "Ohio State University";

        }
        else if(this->currentSchool == "Ohio State University")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: Ohio State University\n");
            this->currentSchool = "Ohio State University";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_keyButton_clicked
 */
void MainWindow::on_keyButton_clicked()
{
    windowHolder *WH = windowHolder::getInstance();
    WH->keyWindowShow();
}

/*!
 * \fn MainWindow::on_FullertonButton_clicked
 */
void MainWindow::on_FullertonButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: California State University, Fullerton");
        this->loadCollegesToVisit();
        routeTracker("California State University, Fullerton", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: California State University, Fullerton\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("California State University, Fullerton");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to California State University, Fullerton is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("California State University, Fullerton", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "California State University, Fullerton";

        }
        else if(this->currentSchool == "California State University, Fullerton")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: California State University, Fullerton\n");
            this->currentSchool = "California State University, Fullerton";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_TexasButton_clicked
 */
void MainWindow::on_TexasButton_clicked()
{
    this->autoTripIndex = 0;
    this->autoTrip.clear();

    if(ui->automaticRouteTrackingCheckBox->isChecked() &&
            ui->numOfSchoolsWheel->text().toInt() > 0)
    {
        double totalMiles = 0;
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();

        ui->testBrowser->setText("Starting School: University of Texas");
        this->loadCollegesToVisit();
        routeTracker("University of Texas", ui->numOfSchoolsWheel->text().toInt() - 1, totalMiles, colleges);
        QTextCursor cursor = ui->testBrowser->textCursor();
        cursor.setPosition(0);
        ui->testBrowser->setTextCursor(cursor);
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(totalMiles));

        windowHolder *WH = windowHolder::getInstance();
        WH->setShopButton(this->autoTrip[this->autoTripIndex]->startingCollege);
        WH->shoppingWindowShow();
        if(ui->numOfSchoolsWheel->text() > 1)
            ui->testBrowser->setText("Starting School: " + this->autoTrip[this->autoTripIndex]->startingCollege + "\n");
        else
            ui->testBrowser->setText("Starting School: University of Texas\n");
        this->incAutoTripIndex();
    }
    else if(!ui->automaticRouteTrackingCheckBox->isChecked())
    {
        if(!this->currentSchool.isEmpty())
        {
            QSqlQuery query;
            query.prepare("Select Distance from College_Campus_Distances where StartingCollege = ? AND EndingCollege = ?");
            query.addBindValue("University of Texas");
            query.addBindValue(this->currentSchool);

            query.exec();
            query.next();

            ui->testBrowser->append("From " + this->currentSchool + " to University of Texas is "
                                    + QString::number(query.value(0).toDouble()) + " miles\n");

            this->totalMiles += query.value(0).toDouble();

            ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));

            college* temp = new college("University of Texas", currentSchool,false, query.value(0).toDouble());
            this->manualTrip.push_back(temp);
            this->currentSchool = "University of Texas";
        }
        else if(this->currentSchool == "University of Texas")
        {
            QMessageBox::critical(this, "ERROR", "Cannot visit the same school!");
        }
        else
        {
            ui->testBrowser->setText("Starting School: University of Texas\n");
            this->currentSchool = "University of Texas";
            this->totalMiles = 0;
        }
        windowHolder *WH  = windowHolder::getInstance();

        WH->setShopButton(this->currentSchool);
        WH->shoppingWindowShow();
    }
}

/*!
 * \fn MainWindow::on_automaticRouteTrackingCheckBox_clicked
 * \param checked
 */
void MainWindow::on_automaticRouteTrackingCheckBox_clicked(bool checked)
{
    windowHolder *WH = windowHolder::getInstance();
    if(checked)
    {
        ui->numOfSchoolsToVisitLabel->show();
        ui->numOfSchoolsWheel->setValue(0);
        ui->numOfSchoolsWheel->show();
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();
        ui->removePrevDesButton->hide();
        this->manualTrip.clear();
        this->currentSchool.clear();
        this->autoTrip.clear();

        WH->showShopNextSchoolButton();
    }
    else
    {
        ui->numOfSchoolsToVisitLabel->hide();
        ui->numOfSchoolsWheel->hide();
        ui->testBrowser->clear();
        ui->TotalMilesLabel->clear();
        ui->removePrevDesButton->show();

        WH->hideShopNextSchoolButton();
    }
}

/*!
 * \fn MainWindow::on_removePrevDesButton_clicked
 */
void MainWindow::on_removePrevDesButton_clicked()
{
    if(this->manualTrip.size() != 0)
    {
        ui->testBrowser->setText("Starting School: " + manualTrip[0]->endingCollege + "\n");
        this->currentSchool = manualTrip[manualTrip.size() - 1]->endingCollege;


        for(int i = 0; i < this->manualTrip.size() - 1; ++i)
        {
            ui->testBrowser->append("From " + this->manualTrip[i]->endingCollege + " to " + this->manualTrip[i]->startingCollege + " is "
                                    + QString::number(this->manualTrip[i]->distance) + " miles\n");
        }
        this->totalMiles -= manualTrip[manualTrip.size() - 1]->distance;
        ui->TotalMilesLabel->setText("Total Miles: " + QString::number(this->totalMiles));
        this->manualTrip.pop_back();

    }
    else
    {
        ui->testBrowser->clear();
        this->manualTrip.clear();
        this->currentSchool.clear();
    }
}

/*!
 * \fn MainWindow::getCurrentAccount
 * \return
 */
QString MainWindow::getCurrentAccount() const
{
    return currentAccount;
}

/*!
 * \fn MainWindow::setCurrentAccount
 * \param value
 */
void MainWindow::setCurrentAccount(const QString &value)
{
    currentAccount = value;
}

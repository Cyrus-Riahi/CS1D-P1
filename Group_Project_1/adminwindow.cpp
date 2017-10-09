#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "windowholder.h"
#include <QSqlQueryModel>
#include <QMessageBox>
/*! \fn adminWindow::adminWindow
 * \param parent*/
adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);


    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT * FROM College_Souvenirs ORDER BY College ASC");

    query.exec();

    model->setQuery(query);

    ui->SouvenirListTableView->setModel(model);
    ui->SouvenirListTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SouvenirListTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SouvenirListTableView->show();

    QSqlQueryModel* otherModel = new QSqlQueryModel;
    QSqlQuery otherQuery;

    otherQuery.clear();
    otherQuery.prepare("SELECT * FROM College_Campus_Distances ORDER BY StartingCollege ASC");
    otherQuery.exec();

    otherModel->setQuery(otherQuery);

    ui->collegeTableView->setModel(otherModel);
    ui->collegeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->collegeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->collegeTableView->show();


    ui->rightGroupBoxDelete->hide();
    ui->leftGroupBoxAdd->hide();
    ui->bottomGroupBoxModify->hide();


    ui->priceLineEdit->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::white);
    palette->setColor(QPalette::Text,Qt::black);
    ui->priceLineEdit->setPalette(*palette);

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

/*!
 * \fn adminWindow::on_backToLoginButton_2_clicked
 */
void adminWindow::on_backToLoginButton_2_clicked()
{
    windowHolder* WH = windowHolder::getInstance();
    WH->AdminWindowHide();
    WH->LoginWindowShow();
}

/*!
 * \fn adminWindow::on_addSouvenirButton_clicked
 */
void adminWindow::on_addSouvenirButton_clicked()
{
    this->populateAddSouvenirCB();
    ui->leftGroupBoxAdd->show();
    ui->rightGroupBoxDelete->hide();
    ui->bottomGroupBoxModify->hide();
}

/*!
 * \fn adminWindow::hideGroupBoxes
 */
void adminWindow::hideGroupBoxes()
{
    ui->leftGroupBoxAdd->hide();
    ui->rightGroupBoxDelete->hide();
    ui->bottomGroupBoxModify->hide();
    ui->rightDeleteCollegeGroupBox->hide();
    ui->bottomAddFromFileGroupBox->hide();
}

/*!
 * \fn adminWindow::populateAddSouvenirCB
 */
void adminWindow::populateAddSouvenirCB()
{
    ui->addSouvenirSchoolNameComboBox->clear();
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
        ui->addSouvenirSchoolNameComboBox->addItem(dropDownVector[i]);
    }

}

/*!
 * \fn adminWindow::populateSchoolNameDeleteDB
 */
void adminWindow::populateSchoolNameDeleteDB()
{
    ui->schoolNameDeleteComboBox->clear();
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
        ui->schoolNameDeleteComboBox->addItem(dropDownVector[i]);
    }

}

/*!
 * \fn adminWindow::populateSchoolNameModifyCB
 */
void adminWindow::populateSchoolNameModifyCB()
{
    ui->modifySchoolNameComboBox->clear();
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
        ui->modifySchoolNameComboBox->addItem(dropDownVector[i]);
    }
}

/*!
 * \fn adminWindow::on_deleteSouvenirButton_clicked
 */
void adminWindow::on_deleteSouvenirButton_clicked()
{
    this->populateSchoolNameDeleteDB();
    ui->leftGroupBoxAdd->hide();
    ui->rightGroupBoxDelete->show();
    ui->bottomGroupBoxModify->hide();
}

/*!
 * \fn adminWindow::on_modifySouvenirButton_clicked
 */
void adminWindow::on_modifySouvenirButton_clicked()
{
    this->populateSchoolNameModifyCB();
    ui->leftGroupBoxAdd->hide();
    ui->rightGroupBoxDelete->hide();
    ui->bottomGroupBoxModify->show();
}

/*!
 * \fn adminWindow::on_schoolNameDeleteComboBox_currentTextChanged
 * \param arg1
 */
void adminWindow::on_schoolNameDeleteComboBox_currentTextChanged(const QString &arg1)
{
    ui->schoolSouvenirComboBox->clear();
    if(ui->schoolNameDeleteComboBox->currentText() != "Select A School")
    {
        QSqlQuery query;
        QVector<souvenir*> souvenirList;

        query.prepare("SELECT Traditional_Souvenirs FROM College_Souvenirs WHERE College = :school");
        query.bindValue(0, arg1);

        query.exec();

        ui->schoolSouvenirComboBox->addItem("Select A Souvenir");
        while(query.next())
        {
            ui->schoolSouvenirComboBox->addItem(query.value(0).toString());
        }
    }
}

/*!
 * \fn adminWindow::on_schoolSouvenirComboBox_currentIndexChanged
 * \param arg1
 */
void adminWindow::on_schoolSouvenirComboBox_currentIndexChanged(const QString &arg1)
{
    ui->priceLineEdit->clear();
    if(ui->schoolSouvenirComboBox->currentText() != "Select A Souvenir")
    {
        QSqlQuery query;

        query.prepare("SELECT Cost FROM College_Souvenirs WHERE College = :College AND Traditional_Souvenirs = :Traditional_Souvenirs");
        query.bindValue(0, ui->schoolNameDeleteComboBox->currentText());
        query.bindValue(1, arg1);

        query.exec();
        query.next();

        ui->priceLineEdit->setText(query.value(0).toString());
    }

}

/*!
 * \fn adminWindow::on_cancelAddButton_clicked
 */
void adminWindow::on_cancelAddButton_clicked()
{
    ui->leftGroupBoxAdd->hide();
    ui->souvenirNameLineEdit->clear();
    ui->souvenirPriceLineEdit->clear();
}

/*!
 * \fn adminWindow::on_cancelDeleteButton_clicked
 */
void adminWindow::on_cancelDeleteButton_clicked()
{
    ui->rightGroupBoxDelete->hide();
    ui->priceLineEdit->clear();
}

/*!
 * \fn adminWindow::on_cancelModifyButton_clicked
 */
void adminWindow::on_cancelModifyButton_clicked()
{
    ui->bottomGroupBoxModify->hide();
    ui->modifyPriceLineEdit->clear();
}

/*!
 * \fn adminWindow::on_modifySchoolNameComboBox_currentIndexChanged
 * \param arg1
 */
void adminWindow::on_modifySchoolNameComboBox_currentIndexChanged(const QString &arg1)
{
    ui->modifySouvenirComboBox->clear();
    if(ui->modifySchoolNameComboBox->currentText() != "Select A School")
    {
        QSqlQuery query;
        QVector<souvenir*> souvenirList;

        query.prepare("SELECT Traditional_Souvenirs FROM College_Souvenirs WHERE College = :school");
        query.bindValue(0, arg1);

        query.exec();

        ui->modifySouvenirComboBox->addItem("Select A Souvenir");
        while(query.next())
        {
            ui->modifySouvenirComboBox->addItem(query.value(0).toString());
        }
    }

}

/*!
 * \fn adminWindow::on_modifySouvenirComboBox_currentIndexChanged
 * \param arg1
 */
void adminWindow::on_modifySouvenirComboBox_currentIndexChanged(const QString &arg1)
{
    ui->modifyPriceLineEdit->clear();
    if(ui->schoolSouvenirComboBox->currentText() != "Select A Souvenir")
    {
        QSqlQuery query;

        query.prepare("SELECT Cost FROM College_Souvenirs WHERE College = :College AND Traditional_Souvenirs = :Traditional_Souvenirs");
        query.bindValue(0, ui->modifySchoolNameComboBox->currentText());
        query.bindValue(1, arg1);

        query.exec();
        query.next();

        ui->modifyPriceLineEdit->setText(query.value(0).toString());
    }

}

/*!
 * \fn adminWindow::on_addToDatabaseButton_clicked
 */
void adminWindow::on_addToDatabaseButton_clicked()
{
    if(ui->addSouvenirSchoolNameComboBox->currentText() != "Select A School" &&
            ui->souvenirNameLineEdit->text() != ""       &&
            ui->souvenirPriceLineEdit->text() != "")
    {
        QString tempCollege = ui->addSouvenirSchoolNameComboBox->currentText();
        QString tempSouvenirName = ui->souvenirNameLineEdit->text();
        QString tempSouvenirPrice = "$" + ui->souvenirPriceLineEdit->text();

        QSqlQuery query;
        query.prepare("INSERT INTO College_Souvenirs (College, Traditional_Souvenirs, Cost)"
                      "VALUES (:tempCollege, :tempSouvenirName, :tempSouvenirPrice)");
        query.bindValue(":tempCollege", tempCollege);
        query.bindValue(":tempSouvenirName", tempSouvenirName);
        query.bindValue(":tempSouvenirPrice", tempSouvenirPrice);

        if(!query.exec())
        {
            qDebug() << "YOU GOT CANCER!";
        }



        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery otherQuery;

        otherQuery.prepare("SELECT * FROM College_Souvenirs ORDER BY College ASC");

        otherQuery.exec();

        model->setQuery(otherQuery);

        ui->SouvenirListTableView->setModel(model);
        ui->SouvenirListTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->SouvenirListTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->SouvenirListTableView->show();
        ui->leftGroupBoxAdd->hide();
    }
    else
    {
        QMessageBox::critical(this, "ERROR", "Missing required information.");
    }
}

/*!
 * \fn adminWindow::on_deleteFromDatabaseButton_clicked
 */
void adminWindow::on_deleteFromDatabaseButton_clicked()
{
    if(ui->schoolNameDeleteComboBox->currentText() != "Select A School" &&
            ui->schoolSouvenirComboBox->currentText() != "Select A Souvenir")
    {
        QSqlQuery query;

        query.prepare("DELETE FROM College_Souvenirs WHERE College = ? AND Traditional_Souvenirs = ?");
        query.addBindValue(ui->schoolNameDeleteComboBox->currentText());
        query.addBindValue(ui->schoolSouvenirComboBox->currentText());

        if(!query.exec())
        {
            qDebug() << "WE ALL GET CANCER!";
        }
        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery otherQuery;

        otherQuery.prepare("SELECT * FROM College_Souvenirs ORDER BY College ASC");

        otherQuery.exec();

        model->setQuery(otherQuery);

        ui->SouvenirListTableView->setModel(model);
        ui->SouvenirListTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->SouvenirListTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->SouvenirListTableView->show();
        ui->rightGroupBoxDelete->hide();

    }
    else
    {
        QMessageBox::critical(this, "ERROR", "Missing required information.");
    }
}

/*!
 * \fn adminWindow::on_modifyButton_clicked
 */
void adminWindow::on_modifyButton_clicked()
{
    if(ui->modifySchoolNameComboBox->currentText() != "Select A School" &&
            ui->modifySouvenirComboBox->currentText() != "Select A Souvenir")
    {
        QSqlQuery query;

        query.prepare("DELETE FROM College_Souvenirs WHERE College = ? AND Traditional_Souvenirs = ?");
        query.addBindValue(ui->modifySchoolNameComboBox->currentText());
        query.addBindValue(ui->modifySouvenirComboBox->currentText());


        if(!query.exec())
        {
            qDebug() << "WE ALL GET CANCER!";
        }

        QSqlQuery Query;

        Query.prepare("INSERT INTO College_Souvenirs (College, Traditional_Souvenirs, Cost)"
                      "VALUES (:tempCollege, :tempSouvenirName, :tempSouvenirPrice)");
        Query.bindValue(":tempCollege", ui->modifySchoolNameComboBox->currentText());
        Query.bindValue(":tempSouvenirName", ui->modifySouvenirComboBox->currentText());
        Query.bindValue(":tempSouvenirPrice", ui->modifyPriceLineEdit->text());

        Query.exec();

        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery otherQuery;

        otherQuery.prepare("SELECT * FROM College_Souvenirs ORDER BY College ASC");

        otherQuery.exec();

        model->setQuery(otherQuery);

        ui->SouvenirListTableView->setModel(model);
        ui->SouvenirListTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->SouvenirListTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->SouvenirListTableView->show();
        ui->bottomGroupBoxModify->hide();

    }
    else
    {
        QMessageBox::critical(this, "ERROR", "Missing required information.");
    }
}

/*!
 * \fn adminWindow::on_deleteCollegeButton_clicked
 */
void adminWindow::on_deleteCollegeButton_clicked()
{
    this->populateDeleteCollegeCB();
    ui->rightDeleteCollegeGroupBox->show();
    ui->bottomAddFromFileGroupBox->hide();
}

/*!
 * \fn adminWindow::on_AddFromFileButton_clicked
 */
void adminWindow::on_AddFromFileButton_clicked()
{
    ui->bottomAddFromFileGroupBox->show();
    ui->rightDeleteCollegeGroupBox->hide();
}

/*!
 * \fn adminWindow::on_deleteCollegeCancelButton_clicked
 */
void adminWindow::on_deleteCollegeCancelButton_clicked()
{
    ui->rightDeleteCollegeGroupBox->hide();
}

/*!
 * \fn adminWindow::on_addFromFileCancelButton_clicked
 */
void adminWindow::on_addFromFileCancelButton_clicked()
{
    ui->bottomAddFromFileGroupBox->hide();
}

/*!
 * \fn adminWindow::populateDeleteCollegeCB
 */
void adminWindow::populateDeleteCollegeCB()
{
    ui->deleteCollegeDB->clear();
    QVector<QString> collegesList;
    QSqlQuery query;
    query.prepare("SELECT distinct StartingCollege FROM College_Campus_Distances ORDER BY StartingCollege ASC");

    collegesList.push_back("Select A School");
    if (query.exec())
    {
        while(query.next())
        {
            collegesList.push_back(query.value(0).toString());
        }
    }

    for(int i = 0; i < collegesList.size(); i++)
    {
        ui->deleteCollegeDB->addItem(collegesList[i]);
    }
}

void adminWindow::on_addToDbFromFileButton_clicked()
{
    QSqlQuery query;
    QVector<college*> colleges;

    query.prepare("SELECT * FROM New_Colleges");

    if(query.exec())
    {
        while(query.next())
        {
            colleges.push_back((new college(query.value(0).toString(), query.value(1).toString() ,false ,query.value(2).toDouble())));
        }
    }

    QSqlQuery Query;

    for(int i = 0; i < colleges.size(); ++i)
    {
        Query.prepare("INSERT INTO College_Campus_Distances (StartingCollege, EndingCollege, Distance)"
                      "VALUES (:tempCollege, :tempSouvenirName, :tempSouvenirPrice)");
        Query.bindValue(":tempCollege", colleges[i]->startingCollege);
        Query.bindValue(":tempSouvenirName", colleges[i]->endingCollege);
        Query.bindValue(":tempSouvenirPrice", colleges[i]->distance);

        if(!Query.exec())
        {
            qDebug() << "Brian's character will die next game"  << i;
        }
    }


    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery otherQuery;

    otherQuery.prepare("SELECT * FROM College_Campus_Distances ORDER BY StartingCollege ASC");

    otherQuery.exec();

    model->setQuery(otherQuery);

    ui->collegeTableView->setModel(model);
    ui->collegeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->collegeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->collegeTableView->show();
    ui->bottomAddFromFileGroupBox->hide();

}

void adminWindow::on_deleteFromDbButton_clicked()
{
    if(ui->deleteCollegeDB->currentText() != "Select A School")
    {
        QSqlQuery query;

        query.prepare("DELETE FROM College_Campus_Distances WHERE StartingCollege = ? OR EndingCollege = ?");
        query.addBindValue(ui->deleteCollegeDB->currentText());
        query.addBindValue(ui->deleteCollegeDB->currentText());

        if(!query.exec())
        {
            qDebug() << "WE ALL GET CANCER!";
        }
        QSqlQueryModel* model = new QSqlQueryModel;
        QSqlQuery otherQuery;

        otherQuery.prepare("SELECT * FROM College_Campus_Distances ORDER BY StartingCollege ASC");

        otherQuery.exec();

        model->setQuery(otherQuery);

        ui->collegeTableView->setModel(model);
        ui->collegeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->collegeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->collegeTableView->show();
        ui->rightDeleteCollegeGroupBox->hide();

    }
}

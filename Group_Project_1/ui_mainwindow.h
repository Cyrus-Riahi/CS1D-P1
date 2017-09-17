/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tripPlannerTab;
    QWidget *distanceTrackerTab;
    QComboBox *CB_Distance_Tracker;
    QTableWidget *tableWidget2;
    QWidget *souvenirsTab;
    QComboBox *CB_School_Souvenirs;
    QTableView *souvenirTable;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(813, 398);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 811, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tripPlannerTab = new QWidget();
        tripPlannerTab->setObjectName(QStringLiteral("tripPlannerTab"));
        tabWidget->addTab(tripPlannerTab, QString());
        distanceTrackerTab = new QWidget();
        distanceTrackerTab->setObjectName(QStringLiteral("distanceTrackerTab"));
        CB_Distance_Tracker = new QComboBox(distanceTrackerTab);
        CB_Distance_Tracker->setObjectName(QStringLiteral("CB_Distance_Tracker"));
        CB_Distance_Tracker->setGeometry(QRect(10, 10, 271, 22));
        CB_Distance_Tracker->setEditable(false);
        tableWidget2 = new QTableWidget(distanceTrackerTab);
        if (tableWidget2->columnCount() < 2)
            tableWidget2->setColumnCount(2);
        tableWidget2->setObjectName(QStringLiteral("tableWidget2"));
        tableWidget2->setGeometry(QRect(290, 10, 501, 301));
        tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget2->setProperty("showDropIndicator", QVariant(false));
        tableWidget2->setDragDropOverwriteMode(false);
        tableWidget2->setAlternatingRowColors(true);
        tableWidget2->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget2->setSortingEnabled(true);
        tableWidget2->setRowCount(0);
        tableWidget2->setColumnCount(2);
        tableWidget2->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget2->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget2->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget2->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget2->horizontalHeader()->setStretchLastSection(false);
        tableWidget2->verticalHeader()->setVisible(false);
        tabWidget->addTab(distanceTrackerTab, QString());
        souvenirsTab = new QWidget();
        souvenirsTab->setObjectName(QStringLiteral("souvenirsTab"));
        CB_School_Souvenirs = new QComboBox(souvenirsTab);
        CB_School_Souvenirs->setObjectName(QStringLiteral("CB_School_Souvenirs"));
        CB_School_Souvenirs->setGeometry(QRect(10, 10, 161, 22));
        souvenirTable = new QTableView(souvenirsTab);
        souvenirTable->setObjectName(QStringLiteral("souvenirTable"));
        souvenirTable->setGeometry(QRect(210, 10, 256, 192));
        tabWidget->addTab(souvenirsTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 813, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(CB_Distance_Tracker, SIGNAL(currentTextChanged(QString)), tableWidget2, SLOT(clearContents()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tripPlannerTab), QApplication::translate("MainWindow", "Trip Planner", Q_NULLPTR));
        CB_Distance_Tracker->clear();
        CB_Distance_Tracker->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select A School", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Arizona State University", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Massachusetts Institute of Technology (MIT)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Northwestern", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Ohio State University", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Saddleback College", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of  Michigan", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of California, Irvine (UCI)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of California, Los Angeles (UCLA)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of Oregon", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of the Pacific", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of Wisconsin", Q_NULLPTR)
        );
        CB_Distance_Tracker->setCurrentText(QApplication::translate("MainWindow", "Select A School", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(distanceTrackerTab), QApplication::translate("MainWindow", "Distance Tracker", Q_NULLPTR));
        CB_School_Souvenirs->clear();
        CB_School_Souvenirs->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Saddleback", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of Michigan", Q_NULLPTR)
         << QApplication::translate("MainWindow", "UCI (University of California Irvine)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "UCLA (University of California, Los Angelas)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of Oregon", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of Texas", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of the Pacific", Q_NULLPTR)
         << QApplication::translate("MainWindow", "University of Wisconsin", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(souvenirsTab), QApplication::translate("MainWindow", "Souvenirs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

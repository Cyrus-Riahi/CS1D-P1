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
    QComboBox *comboBox;
    QTableView *tableView;
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
        MainWindow->resize(495, 280);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 491, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tripPlannerTab = new QWidget();
        tripPlannerTab->setObjectName(QStringLiteral("tripPlannerTab"));
        tabWidget->addTab(tripPlannerTab, QString());
        distanceTrackerTab = new QWidget();
        distanceTrackerTab->setObjectName(QStringLiteral("distanceTrackerTab"));
        comboBox = new QComboBox(distanceTrackerTab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 30, 55, 22));
        tableView = new QTableView(distanceTrackerTab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(200, 10, 256, 192));
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
        menuBar->setGeometry(QRect(0, 0, 495, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tripPlannerTab), QApplication::translate("MainWindow", "Trip Planner", Q_NULLPTR));
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

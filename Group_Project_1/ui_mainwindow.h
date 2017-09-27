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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tripPlannerTab;
    QPushButton *backToLoginButton;
    QWidget *distanceTrackerTab;
    QComboBox *CB_Distance_Tracker;
    QTableWidget *tableWidget2;
    QWidget *souvenirsTab;
    QComboBox *CB_School_Souvenirs;
    QTableWidget *souvenirTable;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(896, 475);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tripPlannerTab = new QWidget();
        tripPlannerTab->setObjectName(QStringLiteral("tripPlannerTab"));
        backToLoginButton = new QPushButton(tripPlannerTab);
        backToLoginButton->setObjectName(QStringLiteral("backToLoginButton"));
        backToLoginButton->setGeometry(QRect(210, 270, 75, 23));
        backToLoginButton->setAutoFillBackground(false);
        backToLoginButton->setFlat(false);
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
        tableWidget2->setGeometry(QRect(290, 10, 571, 361));
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
        CB_School_Souvenirs->setGeometry(QRect(10, 10, 271, 22));
        souvenirTable = new QTableWidget(souvenirsTab);
        if (souvenirTable->columnCount() < 3)
            souvenirTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        souvenirTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        souvenirTable->setObjectName(QStringLiteral("souvenirTable"));
        souvenirTable->setGeometry(QRect(290, 10, 571, 361));
        souvenirTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        souvenirTable->setProperty("showDropIndicator", QVariant(false));
        souvenirTable->setDragDropOverwriteMode(false);
        souvenirTable->setAlternatingRowColors(true);
        souvenirTable->setSelectionMode(QAbstractItemView::SingleSelection);
        souvenirTable->setSortingEnabled(true);
        souvenirTable->setRowCount(0);
        souvenirTable->setColumnCount(3);
        souvenirTable->horizontalHeader()->setCascadingSectionResizes(false);
        souvenirTable->horizontalHeader()->setDefaultSectionSize(120);
        souvenirTable->horizontalHeader()->setMinimumSectionSize(50);
        souvenirTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        souvenirTable->horizontalHeader()->setStretchLastSection(false);
        souvenirTable->verticalHeader()->setVisible(false);
        tabWidget->addTab(souvenirsTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(CB_Distance_Tracker, SIGNAL(currentTextChanged(QString)), tableWidget2, SLOT(clearContents()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        backToLoginButton->setText(QApplication::translate("MainWindow", "Back to Login", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tripPlannerTab), QApplication::translate("MainWindow", "Trip Planner", Q_NULLPTR));
        CB_Distance_Tracker->setCurrentText(QString());
        tabWidget->setTabText(tabWidget->indexOf(distanceTrackerTab), QApplication::translate("MainWindow", "Distance Tracker", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = souvenirTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(souvenirsTab), QApplication::translate("MainWindow", "Souvenirs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

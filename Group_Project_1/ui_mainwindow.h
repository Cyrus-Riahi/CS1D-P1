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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tripPlannerTab;
    QLabel *Us_pixelmap;
    QTextBrowser *testBrowser;
    QPushButton *SaddlebackButton;
    QPushButton *UCIButton;
    QPushButton *UCLAButton;
    QCheckBox *automaticRouteTrackingCheckBox;
    QLabel *TotalMilesLabel;
    QPushButton *UniversityOfPacificButton;
    QPushButton *UniversityOfOregonButton;
    QPushButton *ASUButton;
    QPushButton *UniversityOfWisconsinButton;
    QPushButton *NorthwesternButton;
    QPushButton *UniversityOfMichiganButton;
    QPushButton *OSUButton;
    QPushButton *MITButton;
    QPushButton *keyButton;
    QPushButton *FullertonButton;
    QPushButton *TexasButton;
    QSpinBox *numOfSchoolsWheel;
    QLabel *numOfSchoolsToVisitLabel;
    QPushButton *removePrevDesButton;
    QWidget *distanceTrackerTab;
    QComboBox *CB_Distance_Tracker;
    QTableWidget *tableWidget2;
    QWidget *souvenirsTab;
    QComboBox *CB_School_Souvenirs;
    QTableWidget *souvenirTable;
    QWidget *tab;
    QLabel *label;
    QTextBrowser *helpTextBrowser;
    QPushButton *backToLoginButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 521);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tripPlannerTab = new QWidget();
        tripPlannerTab->setObjectName(QStringLiteral("tripPlannerTab"));
        Us_pixelmap = new QLabel(tripPlannerTab);
        Us_pixelmap->setObjectName(QStringLiteral("Us_pixelmap"));
        Us_pixelmap->setGeometry(QRect(0, 0, 651, 341));
        testBrowser = new QTextBrowser(tripPlannerTab);
        testBrowser->setObjectName(QStringLiteral("testBrowser"));
        testBrowser->setGeometry(QRect(660, 20, 201, 311));
        SaddlebackButton = new QPushButton(tripPlannerTab);
        SaddlebackButton->setObjectName(QStringLiteral("SaddlebackButton"));
        SaddlebackButton->setGeometry(QRect(60, 220, 12, 12));
        SaddlebackButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        UCIButton = new QPushButton(tripPlannerTab);
        UCIButton->setObjectName(QStringLiteral("UCIButton"));
        UCIButton->setGeometry(QRect(50, 210, 12, 12));
        UCIButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        UCLAButton = new QPushButton(tripPlannerTab);
        UCLAButton->setObjectName(QStringLiteral("UCLAButton"));
        UCLAButton->setGeometry(QRect(40, 200, 12, 12));
        UCLAButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        automaticRouteTrackingCheckBox = new QCheckBox(tripPlannerTab);
        automaticRouteTrackingCheckBox->setObjectName(QStringLiteral("automaticRouteTrackingCheckBox"));
        automaticRouteTrackingCheckBox->setGeometry(QRect(660, 0, 151, 17));
        TotalMilesLabel = new QLabel(tripPlannerTab);
        TotalMilesLabel->setObjectName(QStringLiteral("TotalMilesLabel"));
        TotalMilesLabel->setGeometry(QRect(660, 340, 111, 16));
        UniversityOfPacificButton = new QPushButton(tripPlannerTab);
        UniversityOfPacificButton->setObjectName(QStringLiteral("UniversityOfPacificButton"));
        UniversityOfPacificButton->setGeometry(QRect(20, 150, 12, 12));
        UniversityOfPacificButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        UniversityOfOregonButton = new QPushButton(tripPlannerTab);
        UniversityOfOregonButton->setObjectName(QStringLiteral("UniversityOfOregonButton"));
        UniversityOfOregonButton->setGeometry(QRect(30, 70, 12, 12));
        UniversityOfOregonButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        ASUButton = new QPushButton(tripPlannerTab);
        ASUButton->setObjectName(QStringLiteral("ASUButton"));
        ASUButton->setGeometry(QRect(130, 230, 12, 12));
        ASUButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        UniversityOfWisconsinButton = new QPushButton(tripPlannerTab);
        UniversityOfWisconsinButton->setObjectName(QStringLiteral("UniversityOfWisconsinButton"));
        UniversityOfWisconsinButton->setGeometry(QRect(410, 100, 12, 12));
        UniversityOfWisconsinButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        NorthwesternButton = new QPushButton(tripPlannerTab);
        NorthwesternButton->setObjectName(QStringLiteral("NorthwesternButton"));
        NorthwesternButton->setGeometry(QRect(430, 120, 12, 12));
        NorthwesternButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        UniversityOfMichiganButton = new QPushButton(tripPlannerTab);
        UniversityOfMichiganButton->setObjectName(QStringLiteral("UniversityOfMichiganButton"));
        UniversityOfMichiganButton->setGeometry(QRect(470, 100, 12, 12));
        UniversityOfMichiganButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        OSUButton = new QPushButton(tripPlannerTab);
        OSUButton->setObjectName(QStringLiteral("OSUButton"));
        OSUButton->setGeometry(QRect(490, 130, 12, 12));
        OSUButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        MITButton = new QPushButton(tripPlannerTab);
        MITButton->setObjectName(QStringLiteral("MITButton"));
        MITButton->setGeometry(QRect(610, 70, 12, 12));
        MITButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        keyButton = new QPushButton(tripPlannerTab);
        keyButton->setObjectName(QStringLiteral("keyButton"));
        keyButton->setGeometry(QRect(780, 340, 75, 23));
        FullertonButton = new QPushButton(tripPlannerTab);
        FullertonButton->setObjectName(QStringLiteral("FullertonButton"));
        FullertonButton->setGeometry(QRect(60, 210, 12, 12));
        FullertonButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        TexasButton = new QPushButton(tripPlannerTab);
        TexasButton->setObjectName(QStringLiteral("TexasButton"));
        TexasButton->setGeometry(QRect(320, 270, 12, 12));
        TexasButton->setStyleSheet(QLatin1String("background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius: 5px;\n"
" border-color: blue;\n"
" max-width:10px;\n"
" max-height:10px;\n"
" min-width:10px;\n"
" min-height:10px;"));
        numOfSchoolsWheel = new QSpinBox(tripPlannerTab);
        numOfSchoolsWheel->setObjectName(QStringLiteral("numOfSchoolsWheel"));
        numOfSchoolsWheel->setGeometry(QRect(210, 360, 42, 22));
        numOfSchoolsWheel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        numOfSchoolsToVisitLabel = new QLabel(tripPlannerTab);
        numOfSchoolsToVisitLabel->setObjectName(QStringLiteral("numOfSchoolsToVisitLabel"));
        numOfSchoolsToVisitLabel->setGeometry(QRect(10, 360, 201, 16));
        numOfSchoolsToVisitLabel->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        numOfSchoolsToVisitLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        removePrevDesButton = new QPushButton(tripPlannerTab);
        removePrevDesButton->setObjectName(QStringLiteral("removePrevDesButton"));
        removePrevDesButton->setGeometry(QRect(400, 360, 231, 23));
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
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 531, 61));
        label->setStyleSheet(QLatin1String("font: 75 36pt \"MS Shell Dlg 2\";\n"
""));
        helpTextBrowser = new QTextBrowser(tab);
        helpTextBrowser->setObjectName(QStringLiteral("helpTextBrowser"));
        helpTextBrowser->setGeometry(QRect(30, 70, 811, 311));
        helpTextBrowser->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        backToLoginButton = new QPushButton(centralWidget);
        backToLoginButton->setObjectName(QStringLiteral("backToLoginButton"));
        backToLoginButton->setAutoFillBackground(false);
        backToLoginButton->setFlat(false);

        gridLayout_2->addWidget(backToLoginButton, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(CB_Distance_Tracker, SIGNAL(currentTextChanged(QString)), tableWidget2, SLOT(clearContents()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Us_pixelmap->setText(QString());
        SaddlebackButton->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        UCIButton->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        UCLAButton->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        automaticRouteTrackingCheckBox->setText(QApplication::translate("MainWindow", "Automatic Route Tracking", Q_NULLPTR));
        TotalMilesLabel->setText(QString());
        UniversityOfPacificButton->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        UniversityOfOregonButton->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        ASUButton->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        UniversityOfWisconsinButton->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        NorthwesternButton->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        UniversityOfMichiganButton->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        OSUButton->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        MITButton->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        keyButton->setText(QApplication::translate("MainWindow", "Key", Q_NULLPTR));
        FullertonButton->setText(QApplication::translate("MainWindow", "12", Q_NULLPTR));
        TexasButton->setText(QApplication::translate("MainWindow", "13", Q_NULLPTR));
        numOfSchoolsToVisitLabel->setText(QApplication::translate("MainWindow", "Number of Schools to Visit:", Q_NULLPTR));
        removePrevDesButton->setText(QApplication::translate("MainWindow", "Remove Previous Destination", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tripPlannerTab), QApplication::translate("MainWindow", "Trip Planner", Q_NULLPTR));
        CB_Distance_Tracker->setCurrentText(QString());
        tabWidget->setTabText(tabWidget->indexOf(distanceTrackerTab), QApplication::translate("MainWindow", "Distance Tracker", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = souvenirTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(souvenirsTab), QApplication::translate("MainWindow", "Souvenirs", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Welcome to the help tab!", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "HELP", Q_NULLPTR));
        backToLoginButton->setText(QApplication::translate("MainWindow", "Back to Login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

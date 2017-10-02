#include <QVector>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "routetracker.h"
#include "souvenir.h"

/*! \namespace UI*/
namespace Ui {
class MainWindow;
}

/*! * \class MainWindow class*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! \fn MainWindow*/
    /*! \param parent*/
    explicit MainWindow(QWidget *parent = 0);
    /*! \fn Destructor*/
    ~MainWindow();

private slots:
    /*! * \fn on_CB_School_Souvenirs_currentIndexChanged*/
    /*! * \param arg1*/
    void on_CB_School_Souvenirs_currentIndexChanged(const QString &arg1);

    /*! * \fn on_CB_Distance_Tracker_currentTextChanged*/
    /*! * \param arg1*/
    void on_CB_Distance_Tracker_currentTextChanged(const QString &arg1);

    /*! * \fn populate_CD_Distance_Tracker_Combo_Box*/
    void populate_CD_Distance_Tracker_Combo_Box();

    /*! \fn populate_CD_School_Souvenirs_Combo_Box*/
    void populate_CD_School_Souvenirs_Combo_Box();

    /*! \fn on_backToLoginButton_clicked*/
    void on_backToLoginButton_clicked();

    void loadCollegesToVisit();

    void mouseMoveEvent(QMouseEvent *event);

    void on_SaddlebackButton_clicked();

    void on_UCIButton_clicked();

    void on_UCLAButton_clicked();

    void routeTracker(QString schoolName,           // Name of school that gets passed in
                      int numOfSchoolsVisiting,     // Total number of schools visiting
                      int &totalMiles,              // Total mileage of the trip
                      QVector<college*> collegesToVisit);// Vector of schools we are visiting


    void on_UniversityOfPacificButton_clicked();

    void on_UniversityOfOregonButton_clicked();

    void on_ASUButton_clicked();

    void on_UniversityOfWisconsinButton_clicked();

    void on_NorthwesternButton_clicked();

    void on_UniversityOfMichiganButton_clicked();

    void on_MITButton_clicked();

    void on_OSUButton_clicked();

private:
    /*! \var ui*/
    Ui::MainWindow *ui;

    QVector<college*> colleges;
};

#endif // MAINWINDOW_H

#include <QVector>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "collegestovisit.h"
#include "souvenir.h"
#include "account.h"
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

    /*!
     * \fn getNumOfSchool
     * \return
     */
    int getNumOfSchool();

    /*!
     * \fn showFullertonAndTexas
     */
    void showFullertonAndTexas();

    /*!
     * \fn hideAllButtons
     */
    void hideAllButtons();

    /*!
     * \fn checkSchoolsForButtons
     */
    void checkSchoolsForButtons();

    /*!
     * \fn updateUserUI
     */
    void updateUserUI();

    /*!
     * \fn incAutoTripIndex
     */
    void incAutoTripIndex();

    /*!
     * \fn getCurrentAccount
     * \return
     */
    QString getCurrentAccount() const;

    /*!
     * \fn setCurrentAccount
     * \param value
     */
    void setCurrentAccount(const QString &value);

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

    /*!
     * \fn loadCollegesToVisit
     */
    void loadCollegesToVisit();

    /*!
     * \fn on_SaddlebackButton_clicked
     */
    void on_SaddlebackButton_clicked();

    /*!
     * \fn on_UCIButton_clicked
     */
    void on_UCIButton_clicked();

    /*!
     * \fn on_UCLAButton_clicked
     */
    void on_UCLAButton_clicked();

    /*!
     * \fn routeTracker
     * \param schoolName
     * \param numOfSchoolsVisiting
     * \param totalMiles
     * \param collegesToVisit
     */
    void routeTracker(QString schoolName,           // Name of school that gets passed in
                      int numOfSchoolsVisiting,     // Total number of schools visiting
                      double &totalMiles,              // Total mileage of the trip
                      QVector<college*> collegesToVisit);// Vector of schools we are visiting


    /*!
     * \fn on_UniversityOfPacificButton_clicked
     */
    void on_UniversityOfPacificButton_clicked();

    /*!
     * \fn on_UniversityOfOregonButton_clicked
     */
    void on_UniversityOfOregonButton_clicked();

    /*!
     * \fn on_ASUButton_clicked
     */
    void on_ASUButton_clicked();

    /*!
     * \fn on_UniversityOfWisconsinButton_clicked
     */
    void on_UniversityOfWisconsinButton_clicked();

    /*!
     * \fn on_NorthwesternButton_clicked
     */
    void on_NorthwesternButton_clicked();

    /*!
     * \fn on_UniversityOfMichiganButton_clicked
     */
    void on_UniversityOfMichiganButton_clicked();

    /*!
     * \fn on_MITButton_clicked
     */
    void on_MITButton_clicked();

    /*!
     * \fn on_OSUButton_clicked
     */
    void on_OSUButton_clicked();

    /*!
     * \fn on_keyButton_clicked
     */
    void on_keyButton_clicked();

    /*!
     * \fn on_FullertonButton_clicked
     */
    void on_FullertonButton_clicked();

    /*!
     * \fn on_TexasButton_clicked
     */
    void on_TexasButton_clicked();

    /*!
     * \fn on_automaticRouteTrackingCheckBox_clicked
     * \param checked
     */
    void on_automaticRouteTrackingCheckBox_clicked(bool checked);

    /*!
     * \fn on_removePrevDesButton_clicked
     */
    void on_removePrevDesButton_clicked();

private:
    /*! \var ui*/
    Ui::MainWindow *ui;
    QVector<college*> manualTrip;   /*! \var manualTrip*/
    QVector<college*> autoTrip;     /*! \var autoTrip*/
    QString currentSchool;          /*! \var currentSchool*/
    QVector<college*> colleges;     /*! \var colleges*/
    double totalMiles;              /*! \var totalMiles*/
    int autoTripIndex;              /*! \var autoTripIndex*/
    QString currentAccount;         /*! \var currentAccount*/
};

#endif // MAINWINDOW_H

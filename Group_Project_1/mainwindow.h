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

private:
    /*! \var ui*/
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

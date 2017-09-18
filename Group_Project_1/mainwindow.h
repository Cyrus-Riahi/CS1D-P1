#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "routetracker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_CB_School_Souvenirs_currentIndexChanged(const QString &arg1);

    void on_CB_Distance_Tracker_currentTextChanged(const QString &arg1);

    void populate_CD_Distance_Tracker_Combo_Box();

    void populate_CD_School_Souvenirs_Combo_Box();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

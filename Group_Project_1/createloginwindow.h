#ifndef CREATELOGINWINDOW_H
#define CREATELOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreateLoginWindow;
}

class CreateLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateLoginWindow(QWidget *parent = 0);
    ~CreateLoginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateLoginWindow *ui;
};

#endif // CREATELOGINWINDOW_H

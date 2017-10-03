#ifndef KEYWINDOW_H
#define KEYWINDOW_H

#include <QMainWindow>

namespace Ui {
class keyWindow;
}

class keyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit keyWindow(QWidget *parent = 0);
    ~keyWindow();

private:
    Ui::keyWindow *ui;
    int numOfSchools;
};

#endif // KEYWINDOW_H

#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include <QWidget>
namespace Ui {
class CheckoutWindow;
}

class CheckoutWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CheckoutWindow(QWidget *parent = 0);
    bool invalidCVV(QString cvv);
    bool invalidCardNumber(QString cardNum);
    bool checkNum(QChar postion);
    void setUserameLabel();
    ~CheckoutWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::CheckoutWindow *ui;
};

#endif // CHECKOUTWINDOW_H

#include "keywindow.h"
#include "ui_keywindow.h"

/*!
 * \fn keyWindow::keyWindow
 * \param parent
 */
keyWindow::keyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::keyWindow)
{
    numOfSchools = 10;
    ui->setupUi(this);

    ui->KeyTextBrowser->setText("1: Saddleback College");
    ui->KeyTextBrowser->append("2: University of California, Irvine (UCI)");
    ui->KeyTextBrowser->append("3: University of California, Los Angeles (UCLA)");
    ui->KeyTextBrowser->append("4: University of the Pacific");
    ui->KeyTextBrowser->append("5: University of Oregon");
    ui->KeyTextBrowser->append("6: Arizona State University");
    ui->KeyTextBrowser->append("7: University of Wisconsin");
    ui->KeyTextBrowser->append("8: Northwestern");
    ui->KeyTextBrowser->append("9: University of Michigan");
    ui->KeyTextBrowser->append("10: Ohio State University");
    ui->KeyTextBrowser->append("11: Massachusetts Institute of Technology (MIT)");
    ui->KeyTextBrowser->append("12: California State University, Fullerton");
    ui->KeyTextBrowser->append("13: University of Texas");

}

/*!
 * \fn keyWindow::~keyWindow
 */
keyWindow::~keyWindow()
{
    delete ui;
}

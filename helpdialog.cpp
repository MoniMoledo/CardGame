#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Freecell");
    ui->tabWidget->setTabText(1, "Klondike");
    ui->tabWidget->setTabText(2, "Spider");
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

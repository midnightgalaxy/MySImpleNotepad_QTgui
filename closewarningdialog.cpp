#include "closewarningdialog.h"
#include "ui_closewarningdialog.h"

CloseWarningDialog::CloseWarningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloseWarningDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Warning! File changes unsaved!");
}

CloseWarningDialog::~CloseWarningDialog()
{
    delete ui;
}

void CloseWarningDialog::slotCloseAnyway()
{
    emit closeBut();
}

void CloseWarningDialog::slotSave()
{
    emit saveBut();
}

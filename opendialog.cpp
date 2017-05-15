#include "opendialog.h"
#include "ui_opendialog.h"

OpenDialog::OpenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Open");
}

OpenDialog::~OpenDialog()
{
    delete ui;
}

void OpenDialog::on_OpenDialog_accepted()
{
    emit acceptBut();
    close();
}

void OpenDialog::on_OpenDialog_rejected()
{
    openLoc = "";
    ui->lineEdit->setText("");
    close();
}

const std::string & OpenDialog::getOpenLoc() const
{
    return openLoc;
}

void OpenDialog::slotSyncLineEditAndOpenLoc(QString x)
{
    openLoc = x.toStdString();
}

#include "saveasdialog.h"
#include "ui_saveasdialog.h"

SaveAsDialog::SaveAsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveAsDialog)
{
    ui->setupUi(this);
    setWindowTitle("Save as");
}

SaveAsDialog::~SaveAsDialog()
{
    delete ui;
}

void SaveAsDialog::on_buttonBox_accepted()
{
    emit acceptBut();
    close();
}

void SaveAsDialog::on_buttonBox_rejected()
{
    saveLoc = "";
    ui->lineEdit->setText("");
    close();
}

const std::string & SaveAsDialog::getSaveLoc() const
{
    return saveLoc;
}

void SaveAsDialog::slotSyncLineEditAndSaveLoc(QString x)
{
    saveLoc = x.toStdString();
}

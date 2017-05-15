#ifndef SAVEASDIALOG_H
#define SAVEASDIALOG_H

#include <QDialog>

namespace Ui {
class SaveAsDialog;
}

class SaveAsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveAsDialog(QWidget *parent = 0);
    ~SaveAsDialog();
    const std::string & getSaveLoc() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void slotSyncLineEditAndSaveLoc(QString);

signals:
    void acceptBut();

private:
    Ui::SaveAsDialog *ui;
    std::string saveLoc;
};

#endif // SAVEASDIALOG_H

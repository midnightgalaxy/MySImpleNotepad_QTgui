#ifndef CLOSEWARNINGDIALOG_H
#define CLOSEWARNINGDIALOG_H

#include <QDialog>

namespace Ui {
class CloseWarningDialog;
}

class CloseWarningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloseWarningDialog(QWidget *parent = 0);
    ~CloseWarningDialog();

private slots:
    void slotSave();
    void slotCloseAnyway();

signals:
    void closeBut();
    void saveBut();

private:
    Ui::CloseWarningDialog *ui;
};

#endif // CLOSEWARNINGDIALOG_H

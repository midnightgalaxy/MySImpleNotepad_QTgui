#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QDialog>

namespace Ui {
class OpenDialog;
}

class OpenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDialog(QWidget *parent = 0);
    ~OpenDialog();
    const std::string & getOpenLoc() const;

private slots:
    void on_OpenDialog_accepted();
    void on_OpenDialog_rejected();
    void slotSyncLineEditAndOpenLoc(QString);

signals:
    void acceptBut();

private:
    Ui::OpenDialog *ui;
    std::string openLoc;
};

#endif // OPENDIALOG_H

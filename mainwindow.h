#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "opendialog.h"
#include "saveasdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_Qt_triggered();

    void slotSave();
    void slotImport();
    void slotExport();
    void slotUpdateUnsaved();
    void slotOpenDialog();
    void slotSaveAsDialog();

private:
    Ui::MainWindow *ui;
    OpenDialog * openDialog;
    SaveAsDialog * saveAsDialog;

    std::string openLocation;
    //bool unsaved;
};

#endif // MAINWINDOW_H

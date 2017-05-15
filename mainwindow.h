#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QCloseEvent>

#include "opendialog.h"
#include "saveasdialog.h"
#include "closewarningdialog.h"

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
    void slotCloseMainWindow();
    void slotCloseCurrentFile();
    void slotSetForceClose();

private:
    void closeEvent(QCloseEvent *event);

    Ui::MainWindow *ui;
    OpenDialog * openDialog;
    SaveAsDialog * saveAsDialog;
    CloseWarningDialog * closeWarningDialog;
    QShortcut * saveShortCut;

    std::string openLocation;
    bool forceClose;
    bool unsaved;
};

#endif // MAINWINDOW_H

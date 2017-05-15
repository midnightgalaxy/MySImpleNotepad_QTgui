#include <fstream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
    setWindowTitle("MySImpleNotepad");

    unsaved = false;
    forceClose = false;

    openDialog = new OpenDialog(this);
    openDialog->setModal(true);
    saveAsDialog = new SaveAsDialog(this);
    saveAsDialog->setModal(true);
    closeWarningDialog = new CloseWarningDialog(this);
    closeWarningDialog->setModal(true);

    saveShortCut = new QShortcut(QKeySequence("Ctrl+S"), this);

    connect(openDialog, SIGNAL(acceptBut()), this, SLOT(slotImport()));      // IMPORTANT FOR THE IMPORT VIA openDialog. Couldn't do this graphically in IDE
    connect(saveAsDialog, SIGNAL(acceptBut()), this, SLOT(slotExport()));
    connect(closeWarningDialog, SIGNAL(closeBut()), this, SLOT(slotSetForceClose()));
    connect(closeWarningDialog, SIGNAL(closeBut()), this, SLOT(close()));
    connect(closeWarningDialog, SIGNAL(saveBut()), this, SLOT(slotSave()));

    connect(saveShortCut, SIGNAL(activated()), this, SLOT(slotSave()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::slotImport()
{
    openLocation = openDialog->getOpenLoc();

    if (openLocation.size() == 0)   // avoid crash
        return;

    std::fstream input(openLocation.c_str());
    std::string tempLine;
    std::string temp;
    while (std::getline(input, tempLine))
    {
        temp += tempLine;
        temp += "\n";
    }

    if (temp.size() == 0)       // avoid crash
        return;

    temp.erase(temp.size()-1);  // remove the last \n
    ui->plainTextEdit->setPlainText(temp.c_str());

    std::string title;
    title = "MySImpleNotepad :: ";
    title += openLocation;
    setWindowTitle(title.c_str());

    input.close();
}

void MainWindow::slotExport()
{
    openLocation = saveAsDialog->getSaveLoc();

    if (openLocation.size() == 0)   // avoid crash
        return;

    std::ofstream output(openLocation.c_str());
    output << ui->plainTextEdit->toPlainText().toStdString();

    std::string title;
    title = "MySImpleNotepad :: ";
    title += openLocation;
    setWindowTitle(title.c_str());

    unsaved = false;
    output.close();
}

void MainWindow::slotSave()
{
    if (openLocation.size() != 0) {
        std::ofstream output(openLocation);
        output << ui->plainTextEdit->toPlainText().toStdString();
        output.close();
        std::string title;
        title = "MySImpleNotepad :: ";
        title += openLocation;
        setWindowTitle(title.c_str());
        unsaved = false;
    } else {    // If it's a new file then pass the work to saveAs
        slotSaveAsDialog();
    }
}

void MainWindow::slotUpdateUnsaved()
{
    unsaved = true;

    std::string title;
    title = "MySImpleNotepad :: ";
    if (openLocation.size() != 0)
        title += openLocation;
    title += " - UNSAVED!";
    setWindowTitle(title.c_str());
}

void MainWindow::slotOpenDialog()
{
    openDialog->show();
}

void MainWindow::slotSaveAsDialog()
{
    saveAsDialog->show();
}

void MainWindow::slotCloseMainWindow()
{
    if (unsaved)
        closeWarningDialog->show();
    else
        close();
}

void MainWindow::slotCloseCurrentFile()
{
    openLocation = "";
    ui->plainTextEdit->setPlainText("");
    setWindowTitle("MySImpleNotepad");
    unsaved = false;
}

void MainWindow::slotSetForceClose()
{
    forceClose = true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (forceClose) {
        event->accept();
        return;
    }

    if (unsaved) {
        event->ignore();
        closeWarningDialog->show();
    }
}


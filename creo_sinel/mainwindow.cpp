#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList dbConfig = getConfig();
    //int intA = 5;

    ui->setupUi(this);
    ui->projectsList->addItems(dbConfig);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_project_triggered()
{

    add_to_db addDbDialog;
    addDbDialog.exec();
}


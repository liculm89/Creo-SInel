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

    connectToDatabase();
    fillTabelsList();
    //ui->projectsList->addItems(dbConfig);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QStringList dbConfig = getConfig();
    db.setHostName(dbConfig[0]);
    db.setDatabaseName(dbConfig[1]);
    db.setUserName(dbConfig[2]);
    db.setPassword(dbConfig[3]);

    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
    }
}

void MainWindow::fillTabelsList()
{
    QSqlQuery query2("SHOW TABLES");
    QStringList tables;

    while (query2.next())
    {
        int j = 0;
        while (j < query2.record().count())
        {
            QString line = query2.value(j).toString();
            tables << line;
            j++;
            qDebug("%s", qUtf8Printable(line));
        }
    }
    ui->projectsList->addItems(tables);
}

void MainWindow::generateTableView()
{
    QSqlQuery query("SELECT * FROM " + List_curr);


    ui->tableWidget->setColumnCount(query.record().count());
    ui->tableWidget->setRowCount(query.size());
    int index=0;

    while (query.next())
    {
        int j = 0;
        while (j < query.record().count())
        {
            ui->tableWidget->setItem(index, j, new QTableWidgetItem(query.value(j).toString()));
            j++;
        }

        index++;
    }
    ui->tableWidget->show();
}

void MainWindow::on_actionAdd_project_triggered()
{
    add_to_db addDbDialog;
    addDbDialog.exec();
}


void MainWindow::on_projectsList_clicked(const QModelIndex &index)
{
    List_curr = (ui->projectsList->currentItem()->text());
    qDebug("%s", qUtf8Printable(qUtf8Printable(List_curr)));
    generateTableView();
}


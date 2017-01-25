#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <add_to_db.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList dbConfig = getConfig();

    ui->setupUi(this);

    connectToDatabase();
    fillTabelsList();

    QObject::connect(addDialog, SIGNAL(foo(QStringList)), this, SLOT(addProject(QStringList)));

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

void MainWindow::addProject(QStringList args)
{
    for (int i = 0; i < args.size(); ++i)
    {
        qDebug()<<("%s", qUtf8Printable(args[i]));

    }
    qDebug()<<"Signal recieved ... Adding to project";

    QSqlQuery query1("INSERT INTO projects (ProjNo, ProjName, MainDir, LocDir) VALUES ('"+args[0]+"','"+args[1]+"','"+args[2]+"','"+args[3]+"')");

}

void MainWindow::on_actionAdd_project_triggered()
{
    addDialog->exec();
}

void MainWindow::on_projectsList_clicked(const QModelIndex &index)
{
    List_curr = (ui->projectsList->currentItem()->text());
    qDebug("%s", qUtf8Printable(qUtf8Printable(List_curr)));
    generateTableView();
}


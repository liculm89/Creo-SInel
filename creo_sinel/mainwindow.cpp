#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <add_to_db.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();
    fillTabelsList();


    QString server_dir = "\\\\nserver/Public/PROJEKTI/PROJEKTI-2016/SELK KUTINA/Automatizacija procesa prosijavanja SMD komponenti N018_16";
    //QString server_dir = "\\\\nserver\\Public\\PROJEKTI\\PROJEKTI-2016\\SELK KUTINA\\Automatizacija procesa prosijavanja SMD komponenti N018_16";
    qDebug() << server_dir;

    int asm_files = count_files(server_dir, "N018_16", "pdf");

    qDebug() << asm_files;

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

    if(!dbConfig.empty())
     {
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
    else
    {
        QMessageBox::critical(0, QObject::tr("Configuration error"), "Check if config file exists");
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
    ui->databaseTables->addItems(tables);
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

    QSqlQuery query2("SELECT ProjNo FROM " + List_curr);

    //qDebug() << query2.lastError();
    QStringList projectsFromDatabase;

    while (query2.next())
    {
        for(int i = 0; i < query2.record().count(); i++)
        {
            projectsFromDatabase << query2.value(i).toString();
            qDebug() << query2.value(i).toString();
        }
    }
    ui->projectsList->addItems(projectsFromDatabase);
}

int MainWindow::count_files(QString directory, QString proj_name, QString extension)
{

    int counter;
    counter = 0;
    QString dir = directory;
    QDirIterator it(dir, QStringList() << proj_name + "*." + extension + "*", QDir::Files, QDirIterator::Subdirectories);
    QStringList files_list;
    qDebug() << directory;

    while (it.hasNext())
    {
      QFileInfo fi(it.next());
      QString base = fi.completeBaseName();
      files_list.append(base);
      files_list.removeDuplicates();
    }

    for (QStringList::Iterator S =  files_list.begin(); S != files_list.end(); S++)
          {
               counter++;
               //qDebug() << *S;
          }
    //qDebug() << counter;
    return counter;
}


void MainWindow::addProject(QStringList args)
{
    for (int i = 0; i < args.size(); ++i)
    {
       // qDebug()<<"%s", args[i];
    }
    qDebug()<<"Signal recieved ... Adding to project";
    QString assembly = "asm";
    QString prt = "prt";
    QString drw = "drw";
    int num_asm = count_files(args[2], args[0], assembly);
    int num_prt = count_files(args[2], args[0], prt);
    int num_drw = count_files(args[2], args[0], drw);

    qDebug() << QString::number(num_asm);

    QSqlQuery query1("INSERT INTO projects (ProjNo, ProjName, MainDir, LocDir, Asm, Prt, Drw) \
    VALUES ('"+args[0]+"','"+args[1]+"','"+args[2]+"','"+args[3]+"', \
    '"+ QString::number(num_asm)+"','"+QString::number(num_prt)+"', '"+QString::number(num_drw)+"')");

    /*if( !query1.exec() )
    qDebug() << "> Query exec() error." << query1.lastError();
    */
    generateTableView();
}

void MainWindow::on_actionAdd_project_triggered()
{
    addDialog->exec();
}

void MainWindow::on_databaseTables_clicked(const QModelIndex)
{
    List_curr = (ui->databaseTables->currentItem()->text());


    //count_files()
    //qDebug("%s", qUtf8Printable(qUtf8Printable(List_curr)));

    generateTableView();
}


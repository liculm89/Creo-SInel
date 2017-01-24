#include "add_to_db.h"
#include "ui_add_to_db.h"

add_to_db::add_to_db(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_to_db)
{
   ui->setupUi(this);
}

add_to_db::~add_to_db()
{
    delete ui;
}

void add_to_db::on_addToDbButtonBox_accepted()
{
    //QString test;
    newProject.clear();
    newProject << ui->LEProjnb->text();
    newProject << ui->LEProjName->text();
    newProject << ui->LEMainDir->text();
    newProject << ui->LELocalDirs->text();
    emit foo(newProject);
    for (int i = 0; i < newProject.size(); ++i)
    {
        qDebug()<<("%s", qUtf8Printable(newProject[i]));

    }
}


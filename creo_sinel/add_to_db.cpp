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

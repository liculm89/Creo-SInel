#include "project_details.h"
#include "ui_project_details.h"

project_details::project_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::project_details)
{
    ui->setupUi(this);
}

project_details::~project_details()
{
    delete ui;
}

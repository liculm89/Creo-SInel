#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <add_to_db.h>
#include <QMainWindow>
#include <QFile>
#include "iostream"
#include "QDebug"
#include <qlist.h>
#include <QtSql>
#include <QMessageBox>
#include <qwindowdefs.h>
#include <QWidget>
#include <QDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectToDatabase();
    void fillTabelsList();
    void generateTableView();
    int count_files(QString directory, QString proj_name, QString extension);

    add_to_db *addDialog = new add_to_db(this);

public slots:
    void addProject(QStringList args);

private slots:
    void on_actionAdd_project_triggered();
    void on_databaseTables_clicked(const QModelIndex);

private:
    QString List_curr;
    Ui::MainWindow *ui;
    //add_to_db *addDialog;

};


QStringList getConfig();

#endif // MAINWINDOW_H

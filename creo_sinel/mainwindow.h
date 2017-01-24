#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
//#include <QtCore>
#include "add_to_db.h"
#include "iostream"
#include "QDebug"
#include <QtSql>
#include <QMessageBox>
using namespace std;

QStringList getConfig();

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



private slots:
    void on_actionAdd_project_triggered();

    void on_projectsList_clicked(const QModelIndex &index);

private:
    QString List_curr;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

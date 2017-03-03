#ifndef SQL_CONNECTION_H
#define SQL_CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/*
    This file defines a helper function to open a connection to an
    in-memory SQLITE database and to create a test table.

    If you want to use another database, simply modify the code
    below. All the examples in this directory use this function to
    connect to a database.
*/
//! [0]


static bool createConnection()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("localhost");
   db.setDatabaseName("parts");
   db.setUserName("mauro");
   db.setPassword("part_user");

   return true;
}
//! [0]

#endif // SQL_CONNECTION_H

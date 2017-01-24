#include "mainwindow.h"
#include <QApplication>

QStringList getConfig()
{
    QStringList dbConfig;
    QFile inputFile("config");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          dbConfig << line;
          //qDebug("%s", qUtf8Printable(line));
       }
       inputFile.close();
    }
    return dbConfig;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

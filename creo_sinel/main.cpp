#include "mainwindow.h"
#include <QApplication>

QStringList getConfig()
{
    QStringList dbConfig;

    QString fileName = QDir(qApp->applicationDirPath()).absoluteFilePath("config");

    QFile inputFile(fileName);
    qDebug() << fileName;
    qDebug() << inputFile.exists();

    if(inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            dbConfig << line;
            //qDebug("%s", qUtf8Printable(line));
        }
        inputFile.close();
        // qDebug() << dbConfig;
    }
    else
    {
        qDebug() << "fail";
    }
    return dbConfig;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    getConfig();
    QString myUnixPath = QDir::toNativeSeparators("start C:\\Program Files\\PTC\\Creo 2.0\\View Express\\bin\\pvexpress.exe");
    qDebug() << myUnixPath;


    QProcess *process = new QProcess();
    QString program = "pvexpress.exe";
    QString folder = "C:\\Program Files\\PTC\\Creo 2.0\\View Express\\bin\\";

    process->start("\"C:\\Program Files\\PTC\\Creo 2.0\\View Express\\bin\\pvexpress.exe""");

    MainWindow w;
    w.show();

    return a.exec();
}

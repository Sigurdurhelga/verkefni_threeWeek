#include "mainwindow.h"
#include "Model.h"
#include "Controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model db;
    QSqlDatabase dataBase = db.openConnection();
    MainWindow w;
    w.show();
    dataBase.close();

    return a.exec();
}

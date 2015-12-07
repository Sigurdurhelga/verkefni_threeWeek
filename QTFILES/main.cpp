#include <QCoreApplication>
#include "Model.h"
#include "Controller.h"
#include <QtSql>





using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Model db;
    QSqlDatabase dataBase = db.openConnection();
    Controller startProgram;
    startProgram.functionHandler();
    dataBase.close();
    return 0;
}

#include <QCoreApplication>
#include "View.h"
#include "Model.h"
#include <QtSql>





using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Model db;
    QSqlDatabase dataBase = db.openConnection();
    View newView;
    newView.displayInterface();

    return 0;
}

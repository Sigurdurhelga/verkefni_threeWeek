#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Model
{
public:
     QSqlQuery queryList(int way);
     QSqlQuery queryListSci(int way);
     QSqlQuery queryListComp(int way);
     QSqlQuery searchSci(QString name);
     QSqlQuery getConnectionsSC(int id);
     vector<Scientist> retDB();
     QSqlDatabase openConnection();
     void rmRowSci(int);
     void writeToDB(Scientist guy);
     void overwriteDB(vector<Scientist>& list);
     void addScientistToDatabase(Scientist& guy);
     void addComputerToDatabase(Computers& comp);
     bool checkConnection(QSqlDatabase db);
};

#endif // MODEL_H
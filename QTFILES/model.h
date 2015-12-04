#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include <vector>
#include <QtSql>

class Model
{
public:
     QSqlQuery queryList(int way);
     vector<Scientist> retDB();
     QSqlDatabase openConnection();
     void writeToDB(Scientist guy);
     void overwriteDB(vector<Scientist>& list);
     void addScientistToDatabase(Scientist& guy);
     bool checkConnection(QSqlDatabase db);
};

#endif // MODEL_H

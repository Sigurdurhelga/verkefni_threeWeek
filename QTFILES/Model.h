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
     void rmRow(QString name);
     void writeToDB(Scientist guy);
     void overwriteDB(vector<Scientist>& list);
     void addScientistToDatabase(QSqlDatabase db, QString name, bool gender, QDate birthDate, QDate deathDate, QString fact);
     bool checkConnection(QSqlDatabase db);
};

#endif // MODEL_H

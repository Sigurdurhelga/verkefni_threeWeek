#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include <vector>
#include <QtSql>

class Model
{
public:
     vector<Scientist> retDB();
     QSqlDatabase openConnection();
     void writeToDB(Scientist guy);
     void overwriteDB(vector<Scientist>& list);
};

#endif // MODEL_H

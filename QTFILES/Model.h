#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Model
{
public:
     QSqlQuery queryListSci(int way);
     QSqlQuery queryListComp(int way);
     void rmRowSci(int id);
     void rmRowComp(int id);
     QSqlQuery searchSci(QString name);
     QSqlQuery getConnectionsSC(int id);
     bool checkConnection(QSqlDatabase db);
     QSqlDatabase openConnection();
     void addScientistToDatabase(Scientist& guy);
     void addComputerToDatabase(Computers& comp);
};

#endif // MODEL_H

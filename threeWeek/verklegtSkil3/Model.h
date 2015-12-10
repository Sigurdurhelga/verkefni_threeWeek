#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Model
{
public:
    // Database connection functions
    QSqlDatabase openConnection();
    bool checkConnection(QSqlDatabase db);

    // List functions
    QSqlQuery queryListSci(int way);
    QSqlQuery queryListComp(int way);
    QSqlQuery linkListSci();
    QSqlQuery linkListComp();

    // Search functions
    QSqlQuery searchSciName(QString name);
    QSqlQuery searchSciID(int id);
    QSqlQuery scientistConnComp(int id);
    QSqlQuery searchCompName(QString name);
    QSqlQuery searchCompID(int id);

    // Add functions
    void addScientistToDatabase(Scientist& guy);
    void addComputerToDatabase(Computers& comp);

    // Reomve functions
    void rmRowSci(int);
    void rmRowComp(int id);

    // Link functions
    void linkSciToComp(int SciID, int CompID);
    QSqlQuery computersConnSci(int id);

    // Edit functions
    void modSci(int, QString, int);
    void modComp(int, QString, int);
};

#endif // MODEL_H

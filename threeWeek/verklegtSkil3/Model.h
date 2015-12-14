#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include "Computers.h"
#include <QVector>
#include <QtSql>

class Model
{
public:
    // Database connection functions
    QSqlDatabase openConnection();
    bool checkConnection(QSqlDatabase db);

    // List functions
    QVector<Scientist> queryScientists(QSqlQuery);
    QVector<Computers> queryComputers(QSqlQuery);

    QSqlQuery queryListSci();
    QSqlQuery queryListComp();
    QSqlQuery linkListSci();
    QSqlQuery linkListComp();

    // Search functions
    QSqlQuery searchSci(QString name);
    QSqlQuery searchComp(QString name);

    // Add functions
    void add(QString one, QString two, QString three, QString four, QString five, bool which);
    void addScientistToDatabase(Scientist& guy);
    void addComputerToDatabase(Computers& comp);

    // Reomve functions
    void remove(QString ID, bool which);


    // Link functions
    void linkSciToComp(int SciID, int CompID);
    QSqlQuery computersConnSci(int id);

    // Edit functions
    void edit(QString ID, QString newThing, int column, bool which);
    void modSci(int, QString, int);
    void modComp(int, QString, int);

private:
};

#endif // MODEL_H

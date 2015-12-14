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

    // List functions
    QVector<Scientist> queryScientists(QSqlQuery);
    QVector<Computers> queryComputers(QSqlQuery);
    QSqlQuery queryListSci();
    QSqlQuery queryListComp();

    // Search functions
    QSqlQuery searchSci(QString name);
    QSqlQuery searchComp(QString name);

    // Add functions
    void add(QString one, QString two, QString three, QString four, QString five, bool which);

    // Reomve functions
    void remove(QString ID, bool which);

    // Link functions
    QSqlQuery queryGetNameForLinking(int id, bool which);
    void linkSciToComp(int SciID, int CompID);
    QSqlQuery computersConnSci(QString id);
    QSqlQuery getLinks(QString id, bool which);

    // Edit functions
    void edit(QString ID, QString newThing, int column, bool which);

private:
};

#endif // MODEL_H

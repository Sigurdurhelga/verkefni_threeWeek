#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include "Computers.h"
#include <QVector>
#include <QtSql>

class Model
{
public:
    // Database connection
    QSqlDatabase openConnection();

    // Get database contents and store them in a vector
    QVector<Scientist> queryScientists(QSqlQuery);
    QVector<Computers> queryComputers(QSqlQuery);

    // List functions
    QSqlQuery queryListSci();
    QSqlQuery queryListComp();

    // Search functions
    QSqlQuery searchSci(QString name);
    QSqlQuery searchComp(QString name);

    // Linking functions
    QSqlQuery queryGetNameForLinking(bool which);
    QSqlQuery getLinks(QString id, bool which);
    void link(QString id, QString name, bool which);

    // Add, remove, edit
    void add(QString one, QString two, QString three, QString four, QString five, bool which);
    void remove(QString ID, bool which);
    void edit(QString ID, QString newThing, int column, bool which);

private:
};

#endif // MODEL_H

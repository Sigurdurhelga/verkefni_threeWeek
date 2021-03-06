#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Scientist.h"
#include "Computers.h"
#include <QVector>
#include <QtSql>

class Controller
{
public:
    // These functions store info from the database in a vector to make it easier to work with.
    QVector<Scientist> getScientists(QString);
    QVector<Computers> getComputers(QString);
    QVector<QString> showLinks(QString id, bool which);
    QVector<QString> getNameForLinks(bool which);

    // Functions that add/remove, search or edit the database
    void add(QString, QString, QString, QString, QString, bool);   
    void remove(QString, bool);
    void search(QString, bool);
    void edit(QString id, QString newThing, int column, bool which);
    void link(QString id, QString name, bool which);
};

#endif // CONTROLLER_H

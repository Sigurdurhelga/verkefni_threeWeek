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

    void add(QString, QString, QString, QString, QString, bool);   
    void remove(QString, bool);
    void search(QString, bool);
    void edit(QString id, QString newThing, int column, bool which);
<<<<<<< HEAD

=======
    void link(QString id, QString name, bool which);
    QVector<QString> getNameForLinks(bool which);
    QVector<QString> showLinks(QString id, bool which);
>>>>>>> 84c5c2c3b8bab87d48f0ee3e12315d455b7808e9
};

#endif // CONTROLLER_H

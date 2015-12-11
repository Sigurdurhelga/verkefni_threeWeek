#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Controller
{
public:

    QVector<Scientist> getScientists();
    QVector<Computers> getComputers();

    // List functions
    void linkFunctions();
    void listFunctions();
    QSqlQuery sortByInSci(int comp);
    QSqlQuery sortByInComp(int comp);

    // Add functions
    void add(QString, QString, QString, QString, QString, bool);
    void addFunctions();

    // Remove functions
    void removeFunctions();
    void removeScientist();
    void removeComputer();

    // Search functions
    void searchFunctions();
    void searchScientistName();
    void searchScientistHandler(int& select);
    void searchComputerName();
    void searchComputerHandler(int& select);
    int searchScientistID();
    int searchComputerID();


    // Edit functions
    void edit(QString id, QString newThing, int column, bool which);
    void editFunctions();
    void editSpecific(int, bool);
    void editScientistHandler();
    void editComputerHandler();
    void editLoopScientist(int id);
    void editLoopComputer(int id);
    void extraScientistHandler(int id);
    void extraComputerHandler(int id);

    // Misc
    void errorHandling();
    void functionHandler();
};

#endif // CONTROLLER_H

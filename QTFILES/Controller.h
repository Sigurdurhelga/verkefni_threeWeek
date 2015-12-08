#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Controller
{
public:
    // List functions
    void linkFunctions();
    void listFunctions();
    void listScientists();
    QSqlQuery sortByInSci(int comp);
    QSqlQuery sortByInComp(int comp);

    // Add functions
    void addFunctions();

    // Remove functions
    void removeFunctions();
    void removeScientist();
    void removeComputer();

    // Search functions
    void searchFunctions();
    void searchScientistName();
    void searchComputerName();
    int searchScientistID();
    int searchComputerID();

    // Edit functions
    void editFunctions();
    void editSpecific(int, bool);

    // Misc
    void errorHandling();
    void functionHandler();
};

#endif // CONTROLLER_H

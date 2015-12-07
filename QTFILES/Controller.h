#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Controller
{
public:
    void listScientists();
    void removeScientist();
    void removeComputer();
    void searchScientistName();
    void searchComputerName();
    int searchScientistID();
    int searchComputerID();
    void functionHandler();
    void listFunctions();
    void addFunctions();
    void removeFunctions();
    void searchFunctions();
    void linkFunctions();
    void editFunctions();
    void errorHandling();
    QSqlQuery sortByInSci(int comp);
    QSqlQuery sortByInComp(int comp);
};

#endif // CONTROLLER_H

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
    void searchScientist();
    void functionHandler(int n);
    void listFunctions();
    void addFunctions();
    void removeFunctions();
    void searchFunctions();
    QSqlQuery sortByInSci(int comp);
    QSqlQuery sortByInComp(int comp);


};

#endif // CONTROLLER_H

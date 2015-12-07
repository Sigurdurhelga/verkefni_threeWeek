#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <QtSql>

class Controller
{
public:
    vector<Scientist> getDB();
    void addScientist();
    void writeToDB(Scientist guy);
    void listScientists(vector<Scientist>& list);
    void listScientists();
    void printTheList(vector<Scientist>& list);
    void printAlive(vector<Scientist>& list);
    void removeScientist();
    void searchScientist();
    void editScientist(vector<Scientist>& list);
    void overwriteDB(vector<Scientist>& list);
    void functionHandler(int n);
    void listFunctions();
    void addFunctions();
    void removeFunctions();
    void searchFunctions();
    void sortTheList(vector<Scientist>& list);
    QSqlQuery sortBy(int comp);
    QSqlQuery sortByInSci(int comp);
    QSqlQuery sortByInComp(int comp);


};

#endif // CONTROLLER_H

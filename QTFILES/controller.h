#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Scientist.h"
#include <vector>
class Controller
{
public:
    vector<Scientist> getDB();
    void addScientist();
    void writeToDB(Scientist guy);
    void listScientists(vector<Scientist>& list);
    void printTheList(vector<Scientist>& list);
    void printAlive(vector<Scientist>& list);
    void removeScientist(vector<Scientist>& list);
    void searchScientist(vector<Scientist>& list);
    void editScientist(vector<Scientist>& list);
    void overwriteDB(vector<Scientist>& list);
    void functionHandler(int n);
    void sortTheList(vector<Scientist>& list);
    vector<Scientist> sortByName(vector<Scientist>& list, bool comp);
    vector<Scientist> sortByDate(vector<Scientist>& list, bool comp);
    vector<Scientist> getAllAlive(vector<Scientist>& list);
};

#endif // CONTROLLER_H

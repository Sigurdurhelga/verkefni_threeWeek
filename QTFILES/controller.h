#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "scientist.h"
#include <vector>
class controller
{
public:
    vector<scientist> getDB();
    void addScientist();
    void writeToDB(scientist guy);
    void listScientists(vector<scientist>& list);
    void printTheList(vector<scientist>& list);
    void printAlive(vector<scientist>& list);
    void removeScientist(vector<scientist>& list);
    void searchScientist(vector<scientist>& list);
    void editScientist(vector<scientist>& list);
    void overwriteDB(vector<scientist>& list);
    void functionHandler(int n);
    void sortTheList(vector<scientist>& list);
    vector<scientist> sortByName(vector<scientist>& list, bool comp);
    vector<scientist> sortByDate(vector<scientist>& list, bool comp);
    vector<scientist> getAllAlive(vector<scientist>& list);
};

#endif // CONTROLLER_H

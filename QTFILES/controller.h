#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include "scientist.h"

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
};

#endif // CONTROLLER_H

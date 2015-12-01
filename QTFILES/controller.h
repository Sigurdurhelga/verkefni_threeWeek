#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include "scientist.h"

class controller
{
public:
    vector<scientist> getDB();
    void functionHandler(int n);
    void addScientist();
    void writeToDB(scientist guy);
    void overwriteDB(vector <scientist>& list);
    void removeScientist(vector<scientist>& list);
    void listScientists(vector<scientist>& list);
    void printTheList(vector<scientist>& list);
    bool sortName(const scientist& s1, const scientist& s2);
};

#endif // CONTROLLER_H

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
    void removeScientist(vector<scientist>& list);
    void listScientists(vector<scientist>& list);
};

#endif // CONTROLLER_H

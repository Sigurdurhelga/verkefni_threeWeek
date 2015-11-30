#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include "scientist.h"

class controller
{
public:
    void getDB();
    void functionHandler(int n);
    void addScientist();
    void writeToDB(scientist guy);
    void removeScientist(string name);
    void listScientists(vector<scientist> list);
};

#endif // CONTROLLER_H

#ifndef VIEW_H
#define VIEW_H

#include "Scientist.h"
#include <vector>

class View
{
public:
    View();
    static void displayInterface();
    void printTheList(const vector<Scientist>& list);
    void printAllAlive(const vector<Scientist>& list);
};

#endif // VIEW_H

#ifndef VIEW_H
#define VIEW_H

#include "scientist.h"
#include <vector>

class view
{
public:
    view();
    static void displayInterface();
    void printTheList(const vector<scientist>& list);
};

#endif // VIEW_H

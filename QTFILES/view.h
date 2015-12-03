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
    void howToList(int& selection);
    void askName(string& name);
    void askGender(string& sex);
    QDate askDateOfBirth();
    QDate askDateOfDeath();
    void askRemoveName(QString& rmName);
};

#endif // VIEW_H

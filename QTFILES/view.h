#ifndef VIEW_H
#define VIEW_H

#include "Scientist.h"
#include <vector>
#include <string>
#include <QtSql>

class View
{
public:
    View();
    static void displayInterface();
    void printResult(QSqlQuery& result);
    void printTheList(const vector<Scientist>& list);
    void printAllAlive(const vector<Scientist>& list);
    void howToList(int& selection);
    void askName(string& name);
    void askGender(bool& sex);
    void populateScientist(Scientist& newGuy);
    QDate askDateOfBirth();
    QDate askDateOfDeath();
    void askFact(QString& fact);
    void nameNotFound();
    void printSearchMatch(QString currName, bool currSex, QString currBirth, QString currDeath, QString currFact);
    void editSelection(int& select);
    string getGenderString(bool sex);
    void invalidInput();
    void invalidDate();
};

#endif // VIEW_H

#ifndef VIEW_H
#define VIEW_H

#include "Scientist.h"
#include "Computers.h"
#include <vector>
#include <string>
#include <QtSql>

class View
{
public:
    View();
    static void displayInterface();
    void listInterface(int&);
    void addInterface(int&);
    void removeInterface(int& select);
    int displayListFuncsSci();
    int displayListFuncsComp();
    void removePrint(int& id);
    void printResult(QSqlQuery& result);
    void printTheList(const vector<Scientist>& list);
    void printAllAlive(const vector<Scientist>& list);
    void populateScientist(Scientist& guy);
    void populateComputer(Computers& comp);
    void howToList(int& selection);
    void askName(string& name);
    void askGender(bool& sex);
    QDate askDateOfBirth();
    QDate askDateOfDeath();
    void askFact(QString& fact);
    void compAskName(string& name);
    void compAskCreated(bool& created);
    void compAskCreationDate(int& year);
    void compAskDescription(QString& description);
    void nameNotFound();
    void printSearchMatch(QString currName, bool currSex, QString currBirth, QString currDeath, QString currFact);
    void editSelection(int& select);
    string getGenderString(bool sex);
    void invalidInput();
    void invalidDate();
};

#endif // VIEW_H

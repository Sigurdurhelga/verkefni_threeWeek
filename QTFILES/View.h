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
    static void displayInterface(int &select);
    void listInterface(int&);
    void addInterface(int&);
    void removeInterface(int& select);
    void searchInterface(int& select);
    void searchSecond(int& select);
    void searchExtended(int& select);
    void editWhich(int& select);
    void linkWhich(int& select);
    void editSelectionScientist(int&);
    void editSelectionComputer(int&);
    int displayListFuncsSci();
    int displayListFuncsComp();
    void idGet(int& id);
    void printResult(QSqlQuery& result);
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
    void compAskType(QString& type);
    void compAskDescription(QString& description);
    void nameNotFound();
    void editSelection(int& select);
    string getGenderString(bool sex);
    void invalidInput();
    void invalidDate();
    void askForSciID(int &id);
    void askForCompID(int &id);
};

#endif // VIEW_H

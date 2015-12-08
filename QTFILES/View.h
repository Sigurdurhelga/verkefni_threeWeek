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

    // Interface
    static void displayInterface(int &select);
    void addInterface(int&);
    void removeInterface(int& select);
    void searchInterface(int& select);
    void searchSecond(int& select);
    void searchExtended(int& select);
    void editWhich(int& select);
    void linkWhich(int& select);
    void showLinks(int &select);
    void editSelectionScientist(int&);
    void editSelectionComputer(int&);
    void howToList(int& selection);
    void listInterface(int&);
    int displayListFuncsSci();
    int displayListFuncsComp();

    // Functions that add or edit information
    void askName(string& name);
    void askGender(bool& sex);
    void askFact(QString& fact);
    void compAskName(string& name);
    void compAskCreated(bool& created);
    void compAskCreationDate(int& year);
    void compAskType(QString& type);
    void compAskDescription(QString& description);
    void idGet(int& id);
    void populateScientist(Scientist& guy);
    void populateComputer(Computers& comp);
    void askForSciID(int &id);
    void askForCompID(int &id);
    QDate askDateOfBirth();
    QDate askDateOfDeath();

    // Error handling functions
    void invalidDate();
    void invalidInput();
    void nameNotFound();

    // Misc
    void printResult(QSqlQuery& result);
    string getGenderString(bool sex);
};

#endif // VIEW_H

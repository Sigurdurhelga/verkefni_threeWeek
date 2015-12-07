#include "Model.h"
#include "Controller.h"
#include "View.h"
#include <iostream>
#include <vector>
#include <string>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <algorithm>
#include <QtSql>

using namespace std;


void Controller::listScientists(){   //function that defines how the list of Scientists should be ordered
    int select = 0;
    View screen;
    QSqlQuery query;

    screen.howToList(select);
    query = sortByInSci(select);
    screen.printResult(query);

    return;
}



void Controller::removeScientist(){      //function that finds a Scientist to erase
    View screen;
    Model db;
    int id;
    screen.idGet(id);
    db.rmRowSci(id);

    return;
}

void Controller::removeComputer(){
    View screen;
    Model db;
    int id;
    screen.idGet(id);
    db.rmRowComp(id);

    return;
}

void Controller::searchScientistName(){              //function that searches the database
    View screen;
    Model db;
    string name;
    screen.askName(name);
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query = db.searchSciName(qName);
    screen.printResult(query);

    return;
}

int Controller::searchScientistID(){
    View screen;
    Model db;
    int id;
    screen.idGet(id);
    QSqlQuery query;
    query = db.searchSciID(id);
    screen.printResult(query);
    return id;
}

void Controller::functionHandler(int n){                    //function that receives the user selection and executes accordingly
    Model db;
    View UI;
    Scientist currentScientist;
    int listSelect;
    switch(n){
        case 1:
            listFunctions();
            break;
        case 2:
            addFunctions();
            break;
        case 3:
            removeFunctions();
            break;
        case 4:
            searchFunctions();
            break;
        case 5:
            //editScientist(database);
            break;
        case 6:
            //linkProgram();
            break;
    }

    return;
}

void Controller::listFunctions(){
    int which;
    View UI;
    QSqlQuery query;
    UI.listInterface(which);
    int select = 25;
    switch(which){
        case 1:
            while(select != 0){
                select = UI.displayListFuncsSci();
                query = sortByInSci(select);
                UI.printResult(query);
            }
            break;
        case 2:
            while(select != 0){
                select = UI.displayListFuncsComp();
                query = sortByInComp(select);
                UI.printResult(query);
            }
            break;
        case 0:
            break;
        default:
            listFunctions();
            break;
    }

    return;
}

void Controller::addFunctions(){
    int which = 0;
    View UI;
    Model db;
    QSqlQuery query;
    Scientist guy;
    Computers comp;
    UI.addInterface(which);
    switch(which){
        case 1:
            UI.populateScientist(guy);
            db.addScientistToDatabase(guy);
            break;
        case 2:
            UI.populateComputer(comp);
            db.addComputerToDatabase(comp);
            break;
        case 0:
            break;
        default:
            addFunctions();

    }

    return;
}

void Controller::removeFunctions(){
    int which = 0;
    View UI;
    UI.removeInterface(which);
    switch(which){
        case 1:
            removeScientist();
            break;
        case 2:
            removeComputer();
            break;
    }

    return;
}

void Controller::searchFunctions(){
    int which = 0;
    View UI;
    Model db;
    QSqlQuery query;
    int select = 25;
    int secondSelect = 25;
    int currID = 0;
    UI.searchInterface(which);
    switch(which){
        case 1:
            while(select != 0){
                UI.searchSecond(select);
                if(select == 1){
                    searchScientistName();
                }
                else if (select == 2){
                    currID = searchScientistID();
                    while(secondSelect != 0){
                        UI.searchExtended(secondSelect);
                        switch(secondSelect){
                            case 1:
                                query = db.scientistConnComp(currID);
                                UI.printResult(query);
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                        }
                    }
                }
            }
            break;
        case 2:
            break;

    }

    return;
}

QSqlQuery Controller::sortByInSci(int comp){
    Model db;
    QSqlQuery ret;
    ret = db.queryListSci(comp);

    return ret;
}
QSqlQuery Controller::sortByInComp(int comp){
    Model db;
    QSqlQuery ret;
    ret = db.queryListComp(comp);

    return ret;
}

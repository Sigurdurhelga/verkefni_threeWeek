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

void Controller::searchComputerName(){              //function that searches the database
    View screen;
    Model db;
    string name;
    screen.askName(name);
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query = db.searchCompName(qName);
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

int Controller::searchComputerID(){
    View screen;
    Model db;
    int id;
    screen.idGet(id);
    QSqlQuery query;
    query = db.searchCompID(id);
    screen.printResult(query);

    return id;
}


void Controller::functionHandler(){                    //function that receives the user selection and executes accordingly
    View UI;
    int which = 25;
    while(which != 0){
        UI.displayInterface(which);
        switch(which){
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
                linkFunctions();
                break;
            case 6:
                editFunctions();
                break;
            default:
                errorHandling();
                which = 25;
                break;
        }
    }
    return;
}

void Controller::listFunctions(){
    int which = 25;
    int select = 25;
    View UI;
    QSqlQuery query;


    while(which != 0){
        UI.listInterface(which);
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
                errorHandling();
                which = 25;
                break;
            }
        }

    return;
}

void Controller::addFunctions(){
    int which = 25;
    View UI;
    Model db;
    QSqlQuery query;
    Scientist guy;
    Computers comp;

    while(which != 0){
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
                errorHandling();
                which = 25;
                break;
        }
    }

    return;
}

void Controller::removeFunctions(){
    int which = 25;
    View UI;

    while(which != 0){
        UI.removeInterface(which);
        switch(which){
            case 1:
                removeScientist();
                break;
            case 2:
                removeComputer();
                break;
            case 0:
                break;
            default:
                errorHandling();
                which = 25;
                break;
        }
    }

    return;
}

void Controller::searchFunctions(){
    int which = 25;
    View UI;
    Model db;
    QSqlQuery query;
    int select = 25;
    int secondSelect = 25;
    int currID = 0;
    while(which != 0){
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
                                case 0:
                                    break;
                                default:
                                    errorHandling();
                                    which = 25;
                                    break;
                            }
                        }
                    }
                }
                break;
            case 2:
                while(select != 0){
                    UI.searchSecond(select);
                    if(select == 1){
                        searchComputerName();
                    }
                else if(select == 2){
                        currID = searchComputerID();
                        while(secondSelect != 0){
                            UI.searchExtended(secondSelect);
                            switch(secondSelect){
                                case 1:
                                    query = db.computersConnSci(currID);
                                    UI.printResult(query);
                                    break;
                                case 0:
                                    break;
                                default:
                                    errorHandling();
                                    which = 25;
                                    break;
                            }
                        }
                    }
                }
                break;
            case 0:
                break;
            default:
                errorHandling();
                which = 25;
                break;
            }
        }

    return;
}

void Controller::linkFunctions(){
    int which = 25;
    int currSciID;
    int currCompID;
    View UI;
    Model db;
    QSqlQuery query;

    while(which != 0){
        UI.linkWhich(which);
        switch(which){
            case 1:
                query = db.linkListSci();
                UI.printResult(query);
                break;
            case 2:
                query = db.linkListComp();
                UI.printResult(query);
                break;
            case 3:
                UI.askForSciID(currSciID);
                UI.askForCompID(currCompID);
                db.linkSciToComp(currSciID, currCompID);
            case 0:
                break;
            default:
                errorHandling();
                which = 25;
                break;
        }
    }

    return;
}

void Controller::editFunctions(){
    int which = 25;
    int select = 25;
    int currID;

    string name;
    QString qName;
    bool sex;
    QString genderStr = "0";
    QDate doB;
    QDate doD;
    QString fact;
    int year;

    View UI;
    Model db;

    while(which != 0){
    UI.editWhich(which);
    switch(which){
        case 1:
            UI.idGet(currID);
            while(select != 0){
                UI.editSelectionScientist(select);
                switch(select){
                    case 1:
                        UI.askName(name);
                        qName = QString::fromStdString(name);
                        db.modSci(select, qName, currID);
                        break;
                    case 2:
                        UI.askGender(sex);
                        if(sex){
                            genderStr = "1";
                        }
                        db.modSci(select, genderStr, currID);
                        break;
                    case 3:
                        doB = UI.askDateOfBirth();
                        db.modSci(select, doB.toString("yyyy-MM-dd"), currID);
                        break;
                    case 4:
                        doD = UI.askDateOfDeath();
                        db.modSci(select,doD.toString("yyyy-MM-dd"), currID);
                        break;
                    case 5:
                        UI.askFact(fact);
                        db.modSci(select, fact, currID);
                        break;
                    case 0:
                        break;
                    default:
                        errorHandling();
                        which = 25;
                        break;
                }
            }
            break;
        case 2:
            UI.idGet(currID);
            while(select != 0){
                UI.editSelectionComputer(select);
                switch(select){
                    case 1:
                        UI.askName(name);
                        qName = QString::fromStdString(name);
                        db.modComp(select, qName, currID);
                        break;
                    case 2:
                        UI.compAskCreated(sex);
                        if(sex){
                            genderStr = "1";
                        }
                        db.modComp(select, genderStr, currID);
                        break;
                    case 3:
                        UI.compAskCreationDate(year);
                        db.modComp(select, QString::number(year), currID);
                        break;
                    case 4:
                        UI.compAskDescription(fact);
                        db.modSci(select, fact, currID);
                        break;
                    case 0:
                        break;
                    default:
                        errorHandling();
                        which = 25;
                        break;
                }
            }
            break;
        case 0:
            break;
        default:
            errorHandling();
            which = 25;
            break;
        }
    }

    return;
}

void Controller::errorHandling(){
    View UI;
    cin.clear();
    cin.ignore();
    UI.invalidInput();

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

#include "Model.h"
#include "Controller.h"
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


QVector<Scientist> Controller::getScientists(){
    Model db;
    QVector<Scientist> listSci;

    listSci = db.queryScientists();

    return listSci;

}

QVector<Computers> Controller::getComputers(){
    Model db;
    QVector<Computers> listComp;
    QSqlQuery query = QSqlQuery();

    listComp = db.queryComputers();

    return listComp;
}

void Controller::add(QString one, QString two, QString three, QString four, QString five, bool which){
    Model db;
    db.add(one, two, three, four, five, which);
}

void Controller::linkFunctions(){
    int which = 25, select = 25;
    int currSciID;
    int currCompID;
    Model db;
    QSqlQuery query;

    while(which != 0){
        switch(which){
            case 1:
                query = db.linkListSci();
                break;
            case 2:
                query = db.linkListComp();
                break;
            case 3:
                db.linkSciToComp(currSciID, currCompID);
                break;
            case 4:
                if(select == 1){
                    query = db.scientistConnComp(currSciID);
                }
                else if(select == 2){
                    query = db.computersConnSci(currCompID);
                }
                else{
                    errorHandling();
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

void Controller::listFunctions(){
    int which = 25;
    int select = 25;
    QSqlQuery query;


    while(which != 0){
        switch(which){
            case 1:
                while(select != 0){
                    query = sortByInSci(select);
                    if(select != 0){
                    }
                }
                select = 25;
                break;
            case 2:
                while(select != 0){
                    query = sortByInComp(select);
                    if(select != 0){
                    }
                }
                select = 25;
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

void Controller::addFunctions(){
    int which = 25;
    Model db;
    QSqlQuery query;
    Scientist guy;
    Computers comp;

    while(which != 0){
        switch(which){
            case 1:
                which = 25;
                db.addScientistToDatabase(guy);
                break;
            case 2:
                which = 25;
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

    while(which != 0){
        switch(which){
            case 1:
                which = 25;
                removeScientist();
                break;
            case 2:
                which = 25;
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


void Controller::removeScientist(){
    Model db;
    int id;

    db.rmRowSci(id);

    return;
}

void Controller::removeComputer(){
    Model db;
    int id;
    db.rmRowComp(id);

    return;
}

void Controller::searchFunctions(){
    int which = 25;
    QSqlQuery query;
    int select = 25;
    while(which != 0){
        switch(which){
            case 1:
                which = 25;
                select = 25;
                searchScientistHandler(select);
                break;
            case 2:
                which = 25;
                select = 25;
                searchComputerHandler(select);
                break;
            case 0:
                break;
            default:
                errorHandling();
                which = 25;
                select = 25;
                break;
            }
        }

    return;
}

//function that searches the database
void Controller::searchScientistName(){
    string name;
    QSqlQuery query;
    QString qName = QString::fromStdString(name);

    return;
}

void Controller::searchScientistHandler(int& select){
    QSqlQuery query;
    Model db;
    int secondSelect = 25;
    int currID = 0;
    while(select != 0){
        if(select == 1){
            searchScientistName();
        }
        else if (select == 2){
            secondSelect = 25;
            currID = searchScientistID();
            while(secondSelect != 0){
                switch(secondSelect){
                    case 1:
                        query = db.scientistConnComp(currID);
                        secondSelect = 25;
                        break;
                    case 2:
                        editSpecific(currID, true);
                        secondSelect = 25;
                        break;
                    case 0:
                        break;
                    default:
                        errorHandling();
                        secondSelect = 25;
                        break;
                }
                select = 25;
            }
        }
        else if (select == 0){
            break;
        }
        else{
            errorHandling();
            select = 25;
            break;
        }
    }

    return;
}

//function that searches the database
void Controller::searchComputerName(){
    Model db;
    string name;
    QSqlQuery query;
    QString qName = QString::fromStdString(name);
    query = db.searchCompName(qName);

    return;
}

void Controller::searchComputerHandler(int& select){
    int secondSelect = 25;
    int currID = 0;
    Model db;
    QSqlQuery query;

    while(select != 0){
        if(select == 1){
            select = 25;
            searchComputerName();
        }
        else if(select == 2){
            select = 25;
            secondSelect = 25;
            currID = searchComputerID();
            while(secondSelect != 0){
                switch(secondSelect){
                    case 1:
                        query = db.computersConnSci(currID);
                        break;
                    case 2:
                        secondSelect = 25;
                        editSpecific(currID, false);
                        break;
                    case 0:
                        break;
                    default:
                        errorHandling();
                        secondSelect = 25;
                        break;
                }
            }
        }
        else if (select == 0){
            break;
        }
        else{
            errorHandling();
            select = 25;
        }
    }

    return;
}

int Controller::searchScientistID(){
    Model db;
    int id;
    QSqlQuery query;
    QSqlQuery query2;
    query = db.searchSciID(id);

    return id;
}

int Controller::searchComputerID(){
    Model db;
    int id;
    QSqlQuery query;
    query = db.searchCompID(id);

    return id;
}

void Controller::editFunctions(){
    int which = 25;

    while(which != 0){
    switch(which){
        case 1:
            editScientistHandler();
            break;
        case 2:
            editComputerHandler();
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

void Controller::editSpecific(int ID, bool which){

    if(which){
        extraScientistHandler(ID);
    }
    else{
        extraComputerHandler(ID);
    }

    return;
}

void Controller::editScientistHandler(){
    int currID = 0;

    editLoopScientist(currID);

    return;
}

void Controller::editComputerHandler(){
    int currID = 0;

    editLoopComputer(currID);

    return;
}

void Controller::editLoopScientist(int id){
    int select = 25;
    string name;
    QString qName;
    bool sex;
    QString genderStr = "0";
    QDate doB;
    QDate doD;
    QString type;
    QString fact;

    Model db;
    while(select != 0){
        switch(select){
            case 1:
                qName = QString::fromStdString(name);
                db.modSci(select, qName, id);
                break;
            case 2:
                if(sex){
                    genderStr = "1";
                }
                db.modSci(select, genderStr, id);
                break;
            case 3:
                db.modSci(select, doB.toString("yyyy-MM-dd"), id);
                break;
            case 4:
                db.modSci(select,doD.toString("yyyy-MM-dd"), id);
                break;
            case 5:
                db.modSci(select, fact, id);
                break;
            case 0:
                break;
            default:
                errorHandling();
                select = 25;
                break;
        }
    }

    return;
}

void Controller::editLoopComputer(int id){
    int select = 25;
    string name;
    QString qName;
    bool sex;
    QString genderStr = "0";
    QDate doB;
    QDate doD;
    QString type;
    QString fact;
    int year;
    Model db;

    while(select != 0){
        switch(select){
            case 1:
                qName = QString::fromStdString(name);
                db.modComp(select, qName, id);
                break;
            case 2:
                if(sex){
                    genderStr = "1";
                }
                db.modComp(select, genderStr, id);
                break;
            case 3:
                db.modComp(select, QString::number(year), id);
                break;
            case 4:
                db.modComp(select, type, id);
                break;
            case 5:
                db.modComp(select, fact, id);
                break;
            case 0:
                break;
            default:
                errorHandling();
                select = 25;
                break;
        }
    }

    return;
}

void Controller::extraScientistHandler(int id){

    editLoopScientist(id);

    return;
}

void Controller::extraComputerHandler(int id){

    editLoopComputer(id);

    return;
}

void Controller::errorHandling(){

    return;
}

//function that receives the user selection and executes accordingly
void Controller::functionHandler(){
    int which = 25;
    while(which != 0){
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

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
    screen.howToList(select);

    QSqlQuery query;
    query = sortBy(select);
    screen.printResult(query);
    return;
}

void Controller::addScientist(){            //function that creates a Scientist in the database
    View screen;
    string name = "";
    bool sex = false;
    QDate doB;
    QDate doD;
    QString fact;

    screen.askName(name);
    screen.askGender(sex);
    doB = screen.askDateOfBirth();
    doD = screen.askDateOfDeath();
    screen.askFact(fact);

    QString qName = QString::fromStdString(name);
    Scientist newScientist = Scientist(qName, sex, doB, doD, fact);
    Model db;
    db.writeToDB(newScientist);

    return;
}

void Controller::removeScientist(){      //function that finds a Scientist to erase
    View screen;
    Model db;
    int id;
    screen.removePrint(id);
    db.rmRowSci(id);
    return;
}

void Controller::searchScientist(){              //function that searches the database
    View screen;
    Model db;
    string name;
    screen.askName(name);
    QSqlQuery query;
    QSqlQuery query2;
    QString qName = QString::fromStdString(name);
    query = db.searchSci(qName);
    query2 = query;
    query2.next();
    int id = query2.value(0).toInt();
    screen.printResult(query);
    cout << query.size() << endl;
    if(query.size() == 2){
        int select = 25;
        while(select != 0){
            screen.searchExtended(select);
            switch(select){
                case 1:
                    query = db.getConnectionsSC(id);
                    break;
            }
        }
    }
    return;
}

void Controller::editScientist(vector<Scientist>& list){            //function that changes the information in the database
    string editName = "";
    QString name;
    View screen;

    screen.askName(editName);

    name = QString::fromStdString(editName);
    name = name.toLower();

    QString currName = "";
    QString doB;
    QString doD;
    QString fact;

    int selection = 1;



    bool check = false;

    for(unsigned int i = 0; i < list.size(); i++){

        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            check = true;
            screen.editSelection(selection);
            if((selection == 1) | (selection == 6)){
                string name = "";
                screen.askName(name);
                QString currName = QString::fromStdString(name);
                list[i].setName(currName);
            }
            if((selection == 2) | (selection == 6)){
                bool sex = false;
                screen.askGender(sex);
                list[i].setGender(sex);
            }
            if((selection == 3) | (selection == 6)){
                QDate doB;
                doB = screen.askDateOfBirth();
                list[i].setdoB(doB);
            }
            if((selection == 4) | (selection == 6)){
                QDate doD;
                doD = screen.askDateOfDeath();
                list[i].setdoD(doD);
            }
            if((selection == 5) | (selection == 6)){
                QString fact;
                screen.askFact(fact);
                list[i].setFact(fact);
            }
        }
    }
    if(!check)
        screen.nameNotFound();

    Model db;
    db.overwriteDB(list);

    return;
}

void Controller::functionHandler(int n){                    //function that receives the user selection and executes accordingly
    Model db;
    View UI;
    vector<Scientist> database = db.retDB();                //get db as a vector
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
            editScientist(database);
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
}

void Controller::removeFunctions(){
    int which = 0;
    View UI;
    UI.removeInterface(which);
    switch(which){
        case 1:
            removeScientist();
            break;

    }
}

void Controller::searchFunctions(){
    int which = 0;
    View UI;
    UI.searchInterface(which);
    switch(which){
        case 1:
            searchScientist();
            break;
        case 2:
            break;

    }

}

QSqlQuery Controller::sortBy(int comp){
    Model db;
    QSqlQuery ret;
    ret = db.queryList(comp);
    return ret;
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

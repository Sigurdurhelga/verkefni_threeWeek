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

struct compareNamesAscending{    //checks which Scientist is printed first in ascending order

    bool operator ()(Scientist s1, Scientist s2) const {
        int comparison = QString::localeAwareCompare((s1.returnName()), (s2.returnName()));

        if(comparison < 0)
            return true;
        else
            return false;
    }
};

struct compareNamesDescending{          //checks which Scientist is printed first in ascending order

    bool operator ()(Scientist s1, Scientist s2) const {
        int comparison = QString::localeAwareCompare((s1.returnName()), (s2.returnName()));

        if(comparison > 0)
            return true;
        else
            return false;
    }
};
struct compareDateAscending{

    bool operator ()(Scientist s1, Scientist s2) const {
        bool comparison = (s1.dateofBirth() < s2.dateofBirth());

        if(comparison)
            return true;
        else
            return false;
    }
};


struct compareDateDescending{

    bool operator ()(Scientist s1, Scientist s2) const {
        bool comparison = (s1.dateofBirth() > s2.dateofBirth());

        if(comparison)
            return true;
        else
            return false;
    }
};


void Controller::listScientists(vector<Scientist>& list){   //function that defines how the list of Scientists should be ordered
    int select = 0;

    View screen;

    screen.howToList(select);

    vector<Scientist> temp = list;

    switch(select){
        case 1:
            temp = sortByName(temp, true);
            screen.printTheList(temp);
            break;
        case 2:
            temp = sortByName(temp, false);
            screen.printTheList(temp);
            break;
        case 3:
            screen.printAllAlive(temp);
            break;
        case 4:
            screen.printTheList(list);
            break;
        case 5:
            temp = sortByDate(temp, true);
            screen.printTheList(temp);
            break;
        case 6:
            temp = sortByDate(temp, false);
            screen.printTheList(temp);
            break;
        default:
            break;
    }

    return;
}

void Controller::addScientist(){            //function that creates a Scientist in the database
    View screen;
    string name = "";
    string sex = "";
    QDate doB;
    QDate doD;

    screen.askName(name);
    screen.askGender(sex);
    doB = screen.askDateOfBirth();
    doD = screen.askDateOfDeath();

    QString qName = QString::fromStdString(name);
    QString qSex = QString::fromStdString(sex);
    Scientist newScientist = Scientist(qName, qSex, doB, doD);
    Model db;
    db.writeToDB(newScientist);

    return;
}

void Controller::removeScientist(vector<Scientist>& list){      //function that finds a Scientist to erase
    QString name;
    string rmName = "";
    View screen;

    screen.askName(rmName);

    name = QString::fromStdString(rmName);
    name = name.toLower();

    bool check = false;

    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            check = true;
            list.erase(list.begin()+i);
        }
    }

    if(!check)
        screen.nameNotFound();

    Model db;
    db.overwriteDB(list);

    return;
}

void Controller::searchScientist(vector<Scientist>& list){              //function that searches the database
    View screen;
    string searchName = "";
    QString name;

    screen.askName(searchName);

    name = QString::fromStdString(searchName);
    name = name.toLower();

    QString currName = "";
    QString currSex = "";
    QString currBirth;
    QString currDeath;

    bool check = false;
    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            check = true;
            currName = list[i].returnName();
            currSex = list[i].returnSex();
            currBirth = list[i].dateofBirthQString();
            currDeath = list[i].dateofDeathQString();
            screen.printSearchMatch(currName, currSex, currBirth, currDeath);
        }
    }
    if(!check)
       screen.nameNotFound();

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
    QString currSex = "";
    QString doB;
    QString doD;

    int selection = 1;



    bool check = false;

    for(unsigned int i = 0; i < list.size(); i++){

        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            check = true;
            screen.editSelection(selection);
            if((selection == 1) | (selection == 5)){
                string name = "";
                screen.askName(name);
                QString currName = QString::fromStdString(name);
                list[i].setName(currName);
            }
            if((selection == 2) | (selection == 5)){
                string sex = "";
                screen.askGender(sex);
                QString currSex = QString::fromStdString(sex);
                list[i].setGender(currSex);
            }
            if((selection == 3) | (selection == 5)){
                QDate doB;
                doB = screen.askDateOfBirth();
                list[i].setdoB(doB);
            }
            if((selection == 4) | (selection == 5)){
                QDate doD;
                doD = screen.askDateOfDeath();
                list[i].setdoD(doD);
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
    QSqlDatabase dataBase = db.openConnection();
    vector<Scientist> database = db.retDB();                //get db as a vector
    switch(n){
        case 1:
            listScientists(database);
            break;
        case 2:
            addScientist();
            break;
        case 3:
            removeScientist(database);
            break;
        case 4:
            searchScientist(database);
            break;
        case 5:
            editScientist(database);
            break;
    }

    return;
}

vector<Scientist> Controller::sortByName(vector<Scientist>& list, bool comp){
    if(comp){
        sort(list.begin(), list.end(), compareNamesAscending());
    }
    else{
        sort(list.begin(), list.end(), compareNamesDescending());
    }

    return list;
}

vector<Scientist> Controller::sortByDate(vector<Scientist>& list, bool comp){
    if(comp){
        sort(list.begin(), list.end(), compareDateAscending());
    }
    else{
        sort(list.begin(), list.end(), compareDateDescending());
    }

    return list;
}

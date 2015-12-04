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
    QString name;
    string rmName = "";
    View screen;
    Model db;
    screen.askName(rmName);
    name = QString::fromStdString(rmName);
    db.rmRow(name);
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
    bool currSex = false;
    QString currBirth;
    QString currDeath;
    QString currFact;

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
            currFact = list[i].returnFact();
            screen.printSearchMatch(currName, currSex, currBirth, currDeath, currFact);
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
    bool currSex = "";
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
    QSqlDatabase dataBase = QSqlDatabase::database();
    QSqlQuery query;
    query = dataBase.exec("SELECT * FROM people");
    while (query.next()) {
            QString name = query.value(0).toString();
            cout << name.toStdString();
        }
    vector<Scientist> database = db.retDB();                //get db as a vector
    Scientist currentScientist;
    switch(n){
        case 1:
            listScientists();
            break;
        case 2:

            //db.addScientistToDatabase(dataBase, "swag123", true, QDate(1995, 12, 12),QDate(1,1,1), "Nothing interesing");
            break;
        case 3:
            removeScientist();
            break;
        case 4:
            searchScientist(database);
            break;
        case 5:
            editScientist(database);
            break;
    }
    //dataBase.close();
    return;
}

QSqlQuery Controller::sortBy(int comp){
    Model db;
    QSqlQuery ret;
    ret = db.queryList(comp);
    return ret;
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

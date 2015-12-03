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
    View screen;

    screen.askRemoveName(name);

    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            list.erase(list.begin()+i);
        }
    }
    Model db;
    db.overwriteDB(list);

    return;
}

void Controller::searchScientist(vector<Scientist>& list){              //function that searches the database
    View screen;
    QString name;

    screen.askSearchName(name);

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
    string editName;
    QString name;
    cout << "Enter the Name of the Scientist you want to Edit: " << endl;

    while(editName == ""){
        getline(cin, editName);
    }
    cout << endl;

    name = QString::fromStdString(editName);
    name = name.toLower();
    QString currName = "";
    QString currSex = "";
    QString doB;
    QString doD;

    int selection = 1;
    cout << "What would you like to change?" << endl
         << "1. Edit Name." << endl
         << "2. Edit gender." << endl
         << "3. Edit date of birth." << endl
         << "4. Edit date of death." << endl
         << "5. Edit everything." << endl
         << "0. Cancel."<< endl;
    cin >> selection;

    for(unsigned int i = 0; i < list.size(); i++){

        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            if((selection == 1) | (selection == 5)){
                string name = "";
                cout << "Write a Name for the Scientist: " << endl;
                while(name == ""){
                    getline(cin, name);
                }
                QString currName = QString::fromStdString(name);
                list[i].setName(currName);
            }
            int check = 0;
            if((selection == 2) | (selection == 5)){
                string sex = "";
                while(check == 0){
                    cout << "Write 'male' for Male and 'female' for Female: ";
                    cin >> sex;
                    if(sex == "male" || sex == "female"){
                        check = 1;
                    }
                    else{
                        cout << "Invalid input try again." << endl;
                    }
                }
                QString currSex = QString::fromStdString(sex);
                list[i].setGender(currSex);
            }
            check = 0;
            if((selection == 3) | (selection == 5)){
                int bDay = 0;
                int bMonth = 0;
                int bYear = 0;
                QDate doB;
                while(check == 0){
                    cout << "Write the Day of the Date of Birth for your Scientist: ";
                    cin >> bDay;
                    cout << "Write the Month of the Date of Birth for your Scientist: ";
                    cin >> bMonth;
                    cout << "Write the Year of the Date of Birth for your Scientist: ";
                    cin >> bYear;
                    doB = QDate(bYear, bMonth, bDay);
                    if(doB.isValid()){
                        check = 1;
                    }
                    else{
                        cout << "Invalid date, please try again." << endl;
                    }
                }
                doB = QDate(bYear, bMonth, bDay);
                list[i].setdoB(doB);
            }
            check = 0;
            if((selection == 4) | (selection == 5)){
                int dDay = 0;
                int dMonth = 0;
                int dYear = 0;
                QDate doD;
                while(check == 0){
                    cout << "Write the Day of the date of Death for your Scientist (0 if he's alive): ";
                    cin >> dDay;
                    if(dDay != 0){
                        cout << "Write the Month of the date of Death for your Scientist: ";
                        cin >> dMonth;
                        cout << "Write the Year of the date of Death for your Scientist: ";
                        cin >> dYear;
                    }
                    else{
                        dDay = 1, dMonth = 1, dYear = 1;
                    }
                    doD = QDate(dYear, dMonth, dDay);
                    if(doD.isValid()){
                        check = 1;
                    }
                    else{
                        cout << "Invalid date, please try again." << endl;
                    }
                }
                doD = QDate(dYear, dMonth, dDay);
                list[i].setdoD(doD);
            }
        }
    }
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

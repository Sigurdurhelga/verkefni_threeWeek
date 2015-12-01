#include "model.h"
#include "controller.h"
#include "view.h"
#include <iostream>
#include <vector>
#include <string>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <algorithm>

using namespace std;

struct compareNamesAscending{    //checks which scientist is printed first in ascending order

    bool operator ()(scientist s1, scientist s2) const {
        int comparison = QString::localeAwareCompare((s1.returnName()), (s2.returnName()));

        if(comparison < 0)
            return true;
        else
            return false;
    }
};

struct compareNamesDescending{          //checks which scientist is printed first in ascending order

    bool operator ()(scientist s1, scientist s2) const {
        int comparison = QString::localeAwareCompare((s1.returnName()), (s2.returnName()));

        if(comparison > 0)
            return true;
        else
            return false;
    }
};
struct compareDateAscending{

    bool operator ()(scientist s1, scientist s2) const {
        bool comparison = (s1.dateofBirth() < s2.dateofBirth());

        if(comparison)
            return true;
        else
            return false;
    }
};


struct compareDateDescending{

    bool operator ()(scientist s1, scientist s2) const {
        bool comparison = (s1.dateofBirth() > s2.dateofBirth());

        if(comparison)
            return true;
        else
            return false;
    }
};


void controller::listScientists(vector<scientist>& list){   //function that defines how the list of scientists should be ordered
    int select = 0;

    view screen;

    cout << "1. List by name in ascending order\n"
            "2. List by name in descending order\n"
            "3. List all alive\n"
            "4. List by date added\n"
            "5. List by birth date ascending \n"
            "6. List by birth date descending"
         << endl;
    cin >> select;

    vector<scientist> temp = list;

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

void controller::addScientist(){            //function that creates a scientist in the database

    string name = "";
    string sex = "";

    int bDay = 0;
    int bMonth = 0;
    int bYear = 0;

    int dDay = 0;
    int dMonth = 0;
    int dYear = 0;

    QDate doB;
    QDate doD;

    int check = 0;
    cout << "Write a Name for the Scientist: " << endl;
    while(name == ""){
        getline(cin, name);
    }

    while(check == 0){
        cout << "Write 'male' for Male and 'female' for Female: ";
        cin >> sex;
        if(sex == "male" || sex == "female"){           //checks for errors in input
            check = 1;
        }
        else{
            cout << "Invalid input try again." << endl;
        }
    }
    check = 0;

    while(check == 0){
        cout << "Write the Day of the Date of Birth for your Scientist: ";
        cin >> bDay;
        cout << "Write the Month of the Date of Birth for your Scientist: ";
        cin >> bMonth;
        cout << "Write the Year of the Date of Birth for your Scientist: ";
        cin >> bYear;
        doB = QDate(bYear, bMonth, bDay);
        if(doB.isValid()){                              //checks for errors in input
            check = 1;
        }
        else{
            cout << "Invalid date try again." << endl;
        }
    }
    check = 0;

    while(check == 0){
    cout << "Write the Day of the Date of Death for your Scientist (0 if he's alive): ";
    cin >> dDay;
    if(dDay != 0){
        cout << "Write the Month of the Date of Death for your Scientist: ";
        cin >> dMonth;
        cout << "Write the Year of the Date of Death for your Scientist: ";
        cin >> dYear;
        }
        else{
            dDay = 1, dMonth = 1, dYear = 1;
        }

    doD = QDate(dYear, dMonth, dDay);
    if(doD.isValid()){                                  //checks for errors in input
        check = 1;
    }
    else{
        cout << "Invalid date try again." << endl;
    }
    }

    QString qName = QString::fromStdString(name);
    QString qSex = QString::fromStdString(sex);
    doB = QDate(bYear, bMonth, bDay);
    doD = QDate(dYear, dMonth, dDay);
    scientist newScientist = scientist(qName, qSex, doB, doD);
    model db;
    db.writeToDB(newScientist);

    return;
}

void controller::removeScientist(vector<scientist>& list){      //function that finds a scientist to erase
    string rmName;
    QString name;

    cout << "Enter the name of the Scientist you want to remove: " << endl;
    while(rmName == ""){
        getline(cin, rmName);
    }
    cout << endl;

    name = QString::fromStdString(rmName);
    name = name.toLower();

    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            list.erase(list.begin()+i);
        }
    }
    model db;
    db.overwriteDB(list);

    return;
}

void controller::searchScientist(vector<scientist>& list){              //function that searches the database
    string searchName;
    QString name;
    cout << "Enter the name of the scientist you want to look for: " << endl;

    while(searchName == ""){
        getline(cin, searchName);
    }
    cout << endl;

    name = QString::fromStdString(searchName);
    name = name.toLower();
    QString currName = "";
    QString currSex = "";
    QString currBirth;
    QString currDeath;


    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        temp = temp.toLower();
        if(temp == name){
            currName = list[i].returnName();
            currSex = list[i].returnSex();
            currBirth = list[i].dateofBirthQString();
            currDeath = list[i].dateofDeathQString();
            cout << currName.toStdString() << " " << currSex.toStdString() << " " << currBirth.toStdString() << " " << currDeath.toStdString() << endl;
        }
    }

    return;
}

void controller::editScientist(vector<scientist>& list){            //function that changes the information in the database
    string editName;
    QString name;
    cout << "Enter the name of the scientist you want to edit: " << endl;

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
         << "0. Cancel"<< endl;
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
                    cout << "Write the Day of the date of birth for your Scientist: ";
                    cin >> bDay;
                    cout << "Write the Month of the date of birth for your Scientist: ";
                    cin >> bMonth;
                    cout << "Write the Year of the date of birth for your Scientist: ";
                    cin >> bYear;
                    doB = QDate(bYear, bMonth, bDay);
                    if(doB.isValid()){
                        check = 1;
                    }
                    else{
                        cout << "Invalid date try again." << endl;
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
                        cout << "Invalid date try again." << endl;
                    }
                }
                doD = QDate(dYear, dMonth, dDay);
                list[i].setdoD(doD);
            }
        }
    }
    model db;
    db.overwriteDB(list);

    return;
}

void controller::functionHandler(int n){                    //function that receives the user selection and executes accordingly
    model db;
    vector<scientist> database = db.retDB();                //get db as a vector
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

vector<scientist> controller::sortByName(vector<scientist>& list, bool comp){
    if(comp){
        sort(list.begin(), list.end(), compareNamesAscending());
    }
    else{
        sort(list.begin(), list.end(), compareNamesDescending());
    }

    return list;
}

vector<scientist> controller::sortByDate(vector<scientist>& list, bool comp){
    if(comp){
        sort(list.begin(), list.end(), compareDateAscending());
    }
    else{
        sort(list.begin(), list.end(), compareDateDescending());
    }

    return list;
}

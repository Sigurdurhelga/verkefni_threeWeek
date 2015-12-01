#include "model.h"
#include "controller.h"
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

vector<scientist> controller::getDB(){          //returns database to the vector <scientist>
    vector<scientist> dataBase;
    model DB;
    dataBase = DB.retDB();

    return dataBase;
}

void controller::printTheList(vector<scientist>& list){     //function that prints the database to screen
    QString currName = "";
    QString currSex = "";

    QString currBirth;
    QString currDeath;

    for(unsigned int i = 0; i < list.size(); i++){          //goes through each scientist and prints his information to screen
        scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        if(currGuy.dateofDeath() == QDate(1,1,1)){          //checks whether the scientist is alive
            cout << currName.toStdString() << " " << currSex.toStdString() << " " << currBirth.toStdString() << " ALIVE" << endl;
        }
        else{
            cout << currName.toStdString() << " " << currSex.toStdString() << " " << currBirth.toStdString() << " " << currDeath.toStdString() << endl;
        }
    }

    return;
}
void controller::printAlive(vector<scientist>& list){       //goes through each scientist and prints only alive scientist to screen
    QString currName = "";
    QString currSex = "";

    QString currBirth;
    QString currDeath;

    for(unsigned int i = 0; i < list.size(); i++){
        scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        if(currGuy.dateofDeath() == QDate(1,1,1)){          //finds only those scientists that are alive
            cout << currName.toStdString() << " " << currSex.toStdString() << " " << currBirth.toStdString() << endl;
        }
    }

    return;
}


void controller::listScientists(vector<scientist>& list){   //function that defines how the list of scientists should be ordered
    int select = 0;
    //int check = 0;
    cout << "1. List by name in ascending order\n"
            "2. List by name in descending order\n"
            "3. List all alive\n"
            "4. List by date added" << endl;
    cin >> select;

    vector<scientist> temp = list;

    switch(select){
        case 1:
            temp = sortByName(temp, true);
            printTheList(temp);
            break;
        case 2:
            temp = sortByName(temp, false);
            printTheList(temp);
            break;
        case 3:
            printAlive(list);
            break;
        case 4:
            printTheList(list);
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
    cout << "Write a Name for the scientist: " << endl;
    while(name == ""){
        getline(cin, name);
    }

    while(check == 0){
        cout << "Write 'male' for male and 'female' for female: ";
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
        cout << "Write the Day of the date of birth for your Scientist: ";
        cin >> bDay;
        cout << "Write the Month of the date of birth for your Scientist: ";
        cin >> bMonth;
        cout << "Write the Year of the date of birth for your Scientist: ";
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
    cout << "Write the Day of the date of Death for your Scientist (0 if he's alive): ";
    cin >> dDay;
    if(dDay != 0){
        cout << "Write the Month of the date of Death for your Scientist (0 if he's alive): ";
        cin >> dMonth;
        cout << "Write the Year of the date of Death for your Scientist (0 if he's alive): ";
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
    writeToDB(newScientist);

    return;
}

void controller::writeToDB(scientist guy){              //Function that writes a new line at the end of the database
    QFile file("database.txt");
    QString format = "dd.MM.yyyy";
    file.open(QIODevice::Append | QIODevice::Text);
    QString name = guy.returnName();
    QString sex = guy.returnSex();
    QString birth = guy.dateofBirthQString();
    QString death = guy.dateofDeathQString();
    QTextStream out(&file);

    out << name << "@" << sex << "@" << birth << "@" << death << endl;

    return;
}

void controller::removeScientist(vector<scientist>& list){      //function that finds a scientist to erase
    string rmName;
    QString name;

    cout << "Enter the name of the scientist you want to remove: " << endl;
    while(rmName == ""){
        getline(cin, rmName);
    }
    cout << endl;

    name = QString::fromStdString(rmName);

    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        if(temp == name){
            list.erase(list.begin()+i);
        }
    }

    overwriteDB(list);

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
    QString currName = "";
    QString currSex = "";
    QString currBirth;
    QString currDeath;


    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
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
        if(temp == name){
            if((selection == 1) | (selection == 5)){
                string name = "";
                cout << "Write a Name for the scientist: " << endl;
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
                    cout << "Write 'male' for male and 'female' for female: ";
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
                        cout << "Write the Month of the date of Death for your Scientist (0 if he's alive): ";
                        cin >> dMonth;
                        cout << "Write the Year of the date of Death for your Scientist (0 if he's alive): ";
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
    overwriteDB(list);

    return;
}

void controller::overwriteDB(vector<scientist>& list){          //function that overwrites the entire database
    QFile file("database.txt");
    QString format = "dd.MM.yyyy";

    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);

    for(unsigned int i = 0; i < list.size(); i++){
        QString name = list[i].returnName();
        QString sex = list[i].returnSex();
        QString birth = list[i].dateofBirthQString();
        QString death = list[i].dateofDeathQString();
        QTextStream out(&file);
        out << name << "@" << sex << "@" << birth << "@" << death << endl;
    }

    return;
}

void controller::functionHandler(int n){                    //function that receives the user selection and executes accordingly
    vector<scientist> database = getDB();
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

vector<scientist> controller::sortByName(vector<scientist>& list, bool comp){       //using sort algorithm from the library to sort every object within the vector

    if(comp){
        sort(list.begin(), list.end(), compareNamesAscending());
    }
    else{
        sort(list.begin(), list.end(), compareNamesDescending());
    }

    return list;
}


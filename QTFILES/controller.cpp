#include "model.h"
#include "controller.h"
#include <iostream>
#include <vector>
#include <string>
#include <QDateTime>
#include <QString>
#include <Qfile>
#include <QTextStream>
#include <fstream>

using namespace std;

vector<scientist> controller::getDB(){
    vector<scientist> dataBase;
    model DB;
    dataBase = DB.retDB();
    return dataBase;
}

void controller::listScientists(vector<scientist>& list){
    QString currName = "";
    QString currSex = "";

    QString format = "dd.MM.yyyy";

    QString currBirth;
    QString currDeath;

    for(unsigned int i = 0; i < list.size(); i++){
        scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        cout << currName.toStdString() << " " << currSex.toStdString() << " " << currBirth.toStdString() << " " << currDeath.toStdString() << endl;
    }
}

void controller::addScientist(){

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
    cout << "Write a name for the scientist: " << endl;
    while(name == ""){
        getline(cin, name);
    }

    while(check == 0){
        cout << "Write 'male' for male and 'female' for female: ";
        cin >> sex;
        if(sex == "male" || sex == "female"){
            check = 1;
        }
        else{
            cout << "invalid input try again" << endl;
        }
    }
    check = 0;

    while(check == 0){
        cout << "Write the Day of the date of birth for your scientist: ";
        cin >> bDay;
        cout << "Write the Month of the date of birth for your scientist: ";
        cin >> bMonth;
        cout << "Write the Year of the date of birth for your scientist: ";
        cin >> bYear;
        doB = QDate(bYear, bMonth, bDay);
        if(doB.isValid()){
            check = 1;
        }
        else{
            cout << "invalid date try again" << endl;
        }
    }
    check = 0;

    while(check == 0){
    cout << "Write the Day of the date of death for your scientist (0 if he's alive): ";
    cin >> dDay;
    if(dDay != 0){
        cout << "Write the Month of the date of death for your scientist (0 if he's alive): ";
        cin >> dMonth;
        cout << "Write the Year of the date of death for your scientist (0 if he's alive): ";
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
        cout << "invalid date try again" << endl;
    }
    }

    QString qName = QString::fromStdString(name);
    QString qSex = QString::fromStdString(sex);
    doB = QDate(bYear, bMonth, bDay);
    doD = QDate(dYear, dMonth, dDay);
    scientist newScientist = scientist(qName, qSex, doB, doD);
    writeToDB(newScientist);

}

void controller::writeToDB(scientist guy){
    QFile file("database.txt");
    QString format = "dd.MM.yyyy";
    file.open(QIODevice::Append | QIODevice::Text);
    QString name = guy.returnName();
    QString sex = guy.returnSex();
    QString birth = guy.dateofBirthQString();
    QString death = guy.dateofDeathQString();
    QTextStream out(&file);
    out << name << "@" << sex << "@" << birth << "@" << death << endl;
}

void controller::removeScientist(vector<scientist>& list){

    string rmName;
    QString name;
    cout << "Enter the name of the scientist you want to remove: " << endl;

    while(rmName == ""){
        getline(cin, rmName);
    }



    name = QString::fromStdString(rmName);

    cout << endl;

    for(unsigned int i = 0; i < list.size(); i++){
        QString temp = list[i].returnName();
        cout << temp.toStdString() << " "<< rmName <<endl;
        if(temp == name){
            list.erase(list.begin()+i);
        }
    }
}

void controller::functionHandler(int n){
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
    }
}


#include <iostream>
#include <iomanip>
#include "View.h"
#include "Controller.h"


using namespace std;

View::View()
{
    // This should never happen
}

// This function takes the users input and forwards it to the Controller.
void View::displayInterface()
{
    Controller cont;
    int select = 25;
      cout << "This is commandline interface for a CS Scientist program" << endl;
    while (select != 0){
        cout << "1. List all Scientists" << endl
             << "2. Add new Scientist" << endl
             << "3. Remove Scientist" << endl
             << "4. Search by Name" << endl
             << "5. Edit a Scientist" << endl
             << "0. Quit the Application" << endl;
        cin >> select;
        if(select != 0)
        {
            cont.functionHandler(select);
        }
    }

    return;
}

void View::printTheList(const vector<Scientist>& list){     //function that prints the database to screen
    QString currName = "";
    QString currSex = "";

    QString currBirth;
    QString currDeath;
    cout  << left << setfill(' ') << setw(25) << "Name"  << setw(15)<< "Gender" << setw(15) << "BirthDate" << setw(18) << "Deathdate" << endl << setfill('-') << setw(73) << '-' <<  endl;

    for(unsigned int i = 0; i < list.size(); i++){          //goes through each Scientist and prints his information to screen
        Scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        if(currGuy.dateofDeath() == QDate(1,1,1)){          //checks whether the scientist is alive
            cout << left << "| " << setfill(' ') << setw(25) << currName.toStdString() << setw(13)<< currSex.toStdString() << setw(15) << currBirth.toStdString() << setw(17) << "ALIVE" << "|" << endl;
        }
        else{
            cout << left << "| " << setfill(' ') << setw(25) << currName.toStdString() << setw(13) << currSex.toStdString() << setw(15) << currBirth.toStdString() << setw(17) << currDeath.toStdString() << right << "|" << endl;
        }
    }
    cout << setfill('-') << setw(73) << "-" <<  endl;
    return;
}

void View::printAllAlive(const vector<Scientist>& list){     //function that prints the database to screen
    QString currName = "";
    QString currSex = "";

    QString currBirth;
    QString currDeath;
    cout  << left << setfill(' ') << setw(25) << "Name"  << setw(15)<< "Gender" << setw(15) << "BirthDate" << endl << setfill('-') << setw(58) << '-' <<  endl;

    for(unsigned int i = 0; i < list.size(); i++){          //goes through each Scientist and prints his information to screen
        Scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        if(currGuy.dateofDeath() == QDate(1,1,1)){          //checks whether the Scientist is alive
            cout << left << "| " << setfill(' ') << setw(25) << currName.toStdString() << setw(15)<< currSex.toStdString() << setw(15) << currBirth.toStdString() << setw(15) << "|" << endl;
        }
    }
    cout << setfill('-') << setw(58) << "-" <<  endl;
    return;
}

void View::howToList(int& selection){


    cout << "1. List by name in ascending order\n"
            "2. List by name in descending order\n"
            "3. List all alive\n"
            "4. List by date added\n"
            "5. List by birth date ascending \n"
            "6. List by birth date descending"
         << endl;

    cin >> selection;

    return;
}

void View::askName(string& name){
    cout << "Write a Name for the Scientist: " << endl;
    while(name == ""){
        getline(cin, name);
    }

    return;
}

void View::askGender(string& sex){
    int check = 0;

    while(check == 0){
        cout << "Write 'male' for Male and 'female' for Female: ";
        cin >> sex;
        if(sex == "male" || sex == "female"){           //checks for errors in input
            check = 1;
        }
        else{
            cout << "Invalid input, please try again." << endl;
        }
    }

    return;
}

QDate View::askDateOfBirth(){
    int check = 0;
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
        if(doB.isValid()){                              //checks for errors in input
            check = 1;
        }
        else{
            cout << "Invalid date, please try again." << endl;
        }
    }


    return doB;
}

QDate View::askDateOfDeath(){
    int check = 0;
    int dDay = 0;
    int dMonth = 0;
    int dYear = 0;

    QDate doD;

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
            cout << "Invalid date, please try again." << endl;
        }
    }

    return doD;
}

void View::askRemoveName(QString& rmName){
    string name = "";

    cout << "Enter the name of the Scientist you want to remove: " << endl;
    while(name == ""){
        getline(cin, name);
    }
    cout << endl;

    rmName = QString::fromStdString(name);
    rmName = rmName.toLower();


    return;
}

void View::askSearchName(QString& searchName){
    string name;

    cout << "Enter the Name of the Scientist you want to look for: " << endl;

    while(name == ""){
        getline(cin, name);
    }
    cout << endl;

    searchName = QString::fromStdString(name);
    searchName = searchName.toLower();

    return;
}

void View::nameNotFound(){
     cout << "Name was not found in the Database." << endl;

     return;
}

void View::printSearchMatch(QString currName, QString currSex, QString currBirth, QString currDeath){
    cout << currName.toStdString() << " " << currSex.toStdString() << " " << currBirth.toStdString() << " " << currDeath.toStdString() << endl;

    return;
}

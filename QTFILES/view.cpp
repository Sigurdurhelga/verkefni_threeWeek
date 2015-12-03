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

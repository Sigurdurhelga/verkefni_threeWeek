#include <iostream>
#include <iomanip>
#include "View.h"
#include "Controller.h"
#include <QtSql>


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
        cout << "1. List records" << endl
             << "2. Add record" << endl
             << "3. Remove record" << endl
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

int View::displayListFuncsSci(){
    int select = 0;
    cout << "1. List by ID ascending" << endl
         << "2. List by ID descending" << endl
         << "3. List by name ascending" << endl
         << "4. List by name descing" << endl
         << "5. List by date of birth ascending" << endl
         << "6. List by date of birth descending" << endl
         << "7. Go back" << endl;
    cin >> select;
    return select;
}
int View::displayListFuncsComp(){
    int select = 0;
    cout << "1. List by ID ascending" << endl
         << "2. List by ID descending" << endl
         << "3. List those who were created" << endl
         << "4. List those who were not created" << endl
         << "5. List by creation date ascending" << endl
         << "6. List by creation date descending" << endl
         << "7. Go back" << endl;
    cin >> select;
    return select;
}

void View::listInterface(int& select){
    cout << "1. List scientists" << endl
         << "2. List computers" << endl
         << "0. Go back" << endl;
    cin >> select;
}

void View::addInterface(int& select){
    cout << "1. Add scientists" << endl
         << "2. Add computers" << endl
         << "0. Go back" << endl;
    cin >> select;
}

void View::printResult(QSqlQuery& result){
    int i = 0;
    QString val;
    while(result.next()){
        while(!result.value(i).isNull()){
            val = result.value(i).toString();
            cout << val.toStdString() << "  |  ";
            i++;
        }
        cout << endl;
        i = 0;
    }

}

void View::populateScientist(Scientist& guy){
    string name;
    bool gender;
    QString fact;
    askName(name);
    askGender(gender);
    QDate doB = askDateOfBirth();
    QDate doD = askDateOfDeath();
    askFact(fact);

    guy.setName(QString::fromStdString(name));
    guy.setGender(gender);
    guy.setdoB(doB);
    guy.setdoD(doD);
    guy.setFact(fact);
}

void View::populateComputer(Computers& comp){
    string name;
    bool created;
    int year;
    QString desc;
    compAskName(name);
    compAskCreated(created);
    compAskCreationDate(year);
    compAskDescription(desc);
    comp.setName(QString::fromStdString(name));
    comp.setCreated(created);
    comp.setCreationYear(year);
    comp.setDescription(desc);
}

void View::printTheList(const vector<Scientist>& list){     //function that prints the database to screen
    QString currName = "";
    bool currSex = false;

    QString currBirth;
    QString currDeath;

    QString currFact;
    cout  << left << setfill(' ') << setw(25) << "Name"  << setw(15)<< "Gender" << setw(15) << "BirthDate" << setw(18) << "Deathdate" << endl << setfill('-') << setw(73) << '-' <<  endl;

    for(unsigned int i = 0; i < list.size(); i++){          //goes through each Scientist and prints his information to screen
        Scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        currFact = currGuy.returnFact();
        if(currGuy.dateofDeath() == QDate(1,1,1)){          //checks whether the scientist is alive
            cout << left << "| " << setfill(' ') << setw(25) << currName.toStdString() << setw(13)<< getGenderString(currSex) << setw(15) << currBirth.toStdString() << setw(17) << "ALIVE" << currFact.toStdString() << "|" << endl;
        }
        else{
            cout << left << "| " << setfill(' ') << setw(25) << currName.toStdString() << setw(13) << getGenderString(currSex) << setw(15) << currBirth.toStdString() << setw(17) << currDeath.toStdString() << currFact.toStdString() << right << "|" << endl;
        }
    }
    cout << setfill('-') << setw(73) << "-" <<  endl;
    return;
}

void View::printAllAlive(const vector<Scientist>& list){     //function that prints the database to screen
    QString currName = "";
    bool currSex = false;

    QString currBirth;
    QString currDeath;

    QString currFact;
    cout  << left << setfill(' ') << setw(25) << "Name"  << setw(15)<< "Gender" << setw(15) << "BirthDate" << endl << setfill('-') << setw(58) << '-' <<  endl;

    for(unsigned int i = 0; i < list.size(); i++){          //goes through each Scientist and prints his information to screen
        Scientist currGuy = list[i];
        currName = currGuy.returnName();
        currSex = currGuy.returnSex();
        currBirth = currGuy.dateofBirthQString();
        currDeath = currGuy.dateofDeathQString();
        currFact = currGuy.returnFact();
        if(currGuy.dateofDeath() == QDate(1,1,1)){          //checks whether the Scientist is alive
            cout << left << "| " << setfill(' ') << setw(25) << currName.toStdString() << setw(15)<< getGenderString(currSex) << setw(15) << currBirth.toStdString() << setw(15) << currFact.toStdString() <<"|" << endl;
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

void View::askGender(bool& sex){
    int check = 0;
    View screen;

    while(check == 0){
        cout << "Write '0' for Male and '1' for Female: ";
        cin >> sex;
        if(sex == 1){           //checks for errors in input
            sex = true;
            check = 1;
        }
        else if(sex == 0){
            sex = false;
            check = 1;
        }
        else{
            screen.invalidInput();
        }
    }

    return;
}

QDate View::askDateOfBirth(){
    int check = 0;
    int bDay = 0;
    int bMonth = 0;
    int bYear = 0;
    View screen;

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
            screen.invalidDate();
        }
    }


    return doB;
}

QDate View::askDateOfDeath(){
    int check = 0;
    int dDay = 0;
    int dMonth = 0;
    int dYear = 0;
    View screen;

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
           screen.invalidDate();
        }
    }

    return doD;
}

void View::askFact(QString& fact){
    string sFact;
    cout << "Write a small factoid about the scientist: ";
    while(sFact == ""){
        getline(cin, sFact);
    }
    fact = QString::fromStdString(sFact);

}

void View::compAskName(string& name){
    cout << "Write a Name for the Computer:" << endl;
    while(name == ""){
        getline(cin, name);
    }
    return;
}

void View::compAskCreated(bool& created){
    int check = 0;
    View screen;

    while(check == 0){
        cout << "Write '0' for if your computer was never created or was just a concept"
             << endl << "and '1' if it was actually made: ";
        cin >> created;
        if(created == 1){           //checks for errors in input
            created = true;
            check = 1;
        }
        else if(created == 0){
            created = false;
            check = 1;
        }
        else{
            screen.invalidInput();
        }
    }

    return;
}

void View::compAskCreationDate(int& year){
    int check = year;
    while(year == check){
        cout << "Write the Year of the creation date for your Computer: ";
        cin >> year;
    }
    return;
}

void View::compAskDescription(QString& description){
    string sDesc;
    cout << "Write a small description about the computer:";
    while(sDesc == ""){
        getline(cin, sDesc);
    }
    description = QString::fromStdString(sDesc);
    return;
}

void View::nameNotFound(){
     cout << "Name was not found in the Database." << endl;

     return;
}

void View::printSearchMatch(QString currName, bool currSex, QString currBirth, QString currDeath, QString currFact){
    cout << currName.toStdString() << " " << getGenderString(currSex) << " " << currBirth.toStdString() << " " << currDeath.toStdString() << " " << currFact.toStdString() << endl;

    return;
}

void View::editSelection(int& select){
    cout << "What would you like to change?" << endl
         << "1. Edit Name." << endl
         << "2. Edit gender." << endl
         << "3. Edit date of birth." << endl
         << "4. Edit date of death." << endl
         << "5. Edit fact." << endl
         << "6. Edit everything." << endl
         << "0. Cancel."<< endl;
    cin >> select;

    return;
}

string View::getGenderString(bool sex){
    if(sex){
        return "Female";
    }
    else{
        return "Male";
    }
}

void View::invalidInput(){
    cout << "Invalid input try again." << endl;

    return;
}

void View::invalidDate(){
    cout << "Invalid date, please try again." << endl;

    return;
}

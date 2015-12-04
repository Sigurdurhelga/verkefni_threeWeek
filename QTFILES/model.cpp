#include "Model.h"
#include "Scientist.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDataStream>
#include <vector>

using namespace std;



QSqlQuery Model::queryListName(bool way){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    if(way){
        ret = db.exec("SELECT * FROM people ORDER BY name");

    }
    return ret;
}




bool Model::checkConnection(QSqlDatabase db){
    return db.open();
}

QSqlDatabase Model::openConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("data.dat");
    bool db_ok = db.open();
    if(db_ok){
        return db;
    }
    else{
        cout << "DATABASE CONNECTION FAILED!" << endl;
    }
}

void Model::addScientistToDatabase(Scientist guy){
    QSqlDatabase db = QSqlDatabase::database();
    if(checkConnection(db)){

        QSqlQuery query;
        QString name = guy.returnName();
        bool gender = guy.returnSex();
        QString doB = guy.dateofBirthQString();
        QString doD = guy.dateofDeathQString();
        QString fact = guy.returnFact();

        QString boolToNums = "0";

        if(gender){
            boolToNums = "1";
        }
        if(doD != "0001-01-01"){
            query.prepare("INSERT INTO people(name, gender, birthDate, deathDate, fact) "
                          "VALUES(\":name\", :gender, \":birthDate\", \":deathDate\", \":fact\"");

            query.bindValue(":name", name);
            query.bindValue(":gender", boolToNums);
            query.bindValue(":birthDate", doB);
            query.bindValue(":deathDate", doD);
            query.bindValue(":fact", fact);
        }
        else{

            query.prepare("INSERT INTO people(name, gender, birthDate, deathDate, fact) "
                          "VALUES(\":name\", :gender, \":birthDate\", \":fact\"");

            query.bindValue(":name", guy.returnName());
            query.bindValue(":gender", boolToNums);
            query.bindValue(":birthDate", guy.dateofBirthQString());
            query.bindValue(":fact", guy.returnFact());
        }

        query.exec();
    }
    else{
        cout << "no connection to database" << endl;
    }
}

vector<Scientist> Model::retDB(){
    vector<Scientist> ret;
    QFile inputFile("database.txt");
    QString line = "";
    QStringList currList;

    QString currName;
    bool currSex = true;
    QDate currBirth;
    QDate currDeath;
    QString fact;

    if(inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            line = in.readLine();
            currList = line.split("@");
            if(currList[1] != "0"){
                currSex = false;
            }
            currName = currList[0];
            currBirth = QDate::fromString(currList[2],"dd.MM.yyyy");
            currDeath = QDate::fromString(currList[3],"dd.MM.yyyy");
            fact = currList[4];
            Scientist guy(currName, currSex, currBirth, currDeath, fact);
            ret.push_back(guy);
        }
        inputFile.close();
    }
    return ret;
}

void Model::writeToDB(Scientist guy){           //Function that writes a new line at the end of the database
    QFile file("database.txt");
    QString format = "dd.MM.yyyy";
    file.open(QIODevice::Append | QIODevice::Text);
    QString name = guy.returnName();
    bool sex = guy.returnSex();
    QString birth = guy.dateofBirthQString();
    QString death = guy.dateofDeathQString();
    QString fact = guy.returnFact();
    QTextStream out(&file);
    QString sSex;
    if(sex){
        sSex = "Female";
    }
    else{
        sSex = "Male";
    }

    out << name << "@" << sSex << "@" << birth << "@" << death << "@" << fact << endl;

    return;
}

void Model::overwriteDB(vector<Scientist>& list){
    QFile file("database.txt");
    QString format = "dd.MM.yyyy";

    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);

    QString sSex;

    for(unsigned int i = 0; i < list.size(); i++){
        QString name = list[i].returnName();
        bool sex = list[i].returnSex();
        QString birth = list[i].dateofBirthQString();
        QString death = list[i].dateofDeathQString();
        QTextStream out(&file);
        QString fact = list[i].returnFact();
        if(sex){
            sSex = "Female";
        }
        else{
            sSex = "Male";
        }
        out << name << "@" << sSex << "@" << birth << "@" << death << "@" << fact << endl;
    }

    return;
}


















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



QSqlQuery Model::queryList(int way){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    switch(way){
        case 1:
            ret = db.exec("SELECT * FROM people ORDER BY name");
            break;
        case 2:
            ret = db.exec("SELECT * FROM people ORDER BY name DESC");
            break;
        case 3:
            ret = db.exec("SELECT * FROM people WHERE deathDate = '0001-01-01'");
            break;
        case 4:
            ret = db.exec("SELECT * FROM people");
            break;
        case 5:
            ret = db.exec("SELECT * FROM people ORDER BY birthDate");
            break;
        case 6:
            ret = db.exec("SELECT * FROM people ORDER BY birthDate DESC");
            break;


    }
    return ret;
}


void Model::rmRow(QString name){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("DELETE FROM people WHERE name = :name");
    query.bindValue(":name", name);
    query.exec();
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

void Model::addScientistToDatabase(QSqlDatabase db, QString name, bool gender, QDate birthDate, QDate deathDate, QString fact){
    if(checkConnection(db)){
        QString boolToNums = "0";
        if(gender){
            boolToNums = "1";
        }
        QString format = QString("yyyy-MM-dd");
        QString command = QString("INSERT INTO people(name, gender, birthDate, deathDate, fact) VALUES(\""+name+"\", "+boolToNums+", \""+
                         birthDate.toString(format)+"\", \""+
                         deathDate.toString(format)+"\", \""+
                         fact+"\") ");
        QSqlQuery query = db.exec(command);
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


















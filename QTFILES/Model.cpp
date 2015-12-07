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

QSqlQuery Model::queryListSci(int way){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    switch(way){
        case 1:
            ret = db.exec("SELECT * FROM people ORDER BY id");
            break;
        case 2:
            ret = db.exec("SELECT * FROM people ORDER BY id DESC");
            break;
        case 3:
            ret = db.exec("SELECT * FROM people ORDER BY name");
            break;
        case 4:
            ret = db.exec("SELECT * FROM people ORDER BY name DESC");
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
QSqlQuery Model::queryListComp(int way){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    switch(way){
        case 1:
            ret = db.exec("SELECT * FROM computers ORDER BY id");
            break;
        case 2:
            ret = db.exec("SELECT * FROM computers ORDER BY id desc");
            break;
        case 3:
            ret = db.exec("SELECT * FROM computers WHERE created = 1 ORDER BY id");
            break;
        case 4:
            ret = db.exec("SELECT * FROM computers WHERE created = 0 ORDER BY is");
            break;
        case 5:
            ret = db.exec("SELECT * FROM computers ORDER BY creationDate");
            break;
        case 6:
            ret = db.exec("SELECT * FROM computers ORDER BY creationDate");
            break;
    }
    return ret;
}


void Model::rmRowSci(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("DELETE FROM people WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
}

QSqlQuery Model::searchSci(QString name){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    QString query = "SELECT * FROM people WHERE name LIKE '%"+name+"%'";
    ret = db.exec(query);
    return ret;
}

QSqlQuery Model::getConnectionsSC(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("SELECT computers.name FROM computers "
                  "INNER JOIN computers.id ON compGroups.id "
                  "INNER JOIN compGroups.id ON people.id WHERE people.id = :id");
    query.bindValue(":id", id);
    query.exec();
    return query;
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


void Model::addScientistToDatabase(Scientist& guy){
    QSqlDatabase db = QSqlDatabase::database();
    if(checkConnection(db)){
        QSqlQuery query;

        QString name = guy.returnName();
        bool gender = guy.returnSex();
        QString doB = guy.dateofBirthQString();
        QString doD = guy.dateofDeathQString();
        QString fact = guy.returnFact();
        QString boolToString = "0";
        if(gender){
            boolToString = "1";
        }
        query.prepare("INSERT INTO people (name, gender, birthDate, deathDate, fact) VALUES (:name, :gender, :doB, :doD, :fact)");
        query.bindValue(":name", name);
        query.bindValue(":gender", boolToString);
        query.bindValue(":doB", doB);
        query.bindValue(":doD", doD);
        query.bindValue(":fact", fact);
        query.exec();

    }
    else{
        cout << "no connection to database" << endl;
    }
}

void Model::addComputerToDatabase(Computers& comp){
    QSqlDatabase db = QSqlDatabase::database();
    if(checkConnection(db)){
        QSqlQuery query;

        QString name = comp.returnName();
        bool created = comp.returnCreated();
        int creationYear = comp.returnCreationYear();
        QString desc = comp.returnDescription();
        QString boolToString = "0";
        if(created){
            boolToString = "1";
        }
        query.prepare("INSERT INTO computers(name, created, creationDate, description) VALUES (:name, :created, :creationDate, :desc)");
        query.bindValue(":name", name);
        query.bindValue(":created", boolToString);
        query.bindValue(":creationDate", creationYear);
        query.bindValue(":desc", desc);
        query.exec();

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

















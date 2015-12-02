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

QSqlDatabase Model::openConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("db.sl3");
    bool db_ok = db.open();
    if(db_ok){
        return db;
    }
}

vector<Scientist> Model::retDB(){
    vector<Scientist> ret;
    QFile inputFile("database.txt");
    QString line = "";
    QStringList currList;

    QString currName;
    QString currSex;
    QDate currBirth;
    QDate currDeath;

    if(inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            line = in.readLine();
            currList = line.split("@");
            currName = currList[0];
            currSex = currList[1];
            currBirth = QDate::fromString(currList[2],"dd.MM.yyyy");
            currDeath = QDate::fromString(currList[3],"dd.MM.yyyy");
            Scientist guy(currName, currSex, currBirth, currDeath);
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
    QString sex = guy.returnSex();
    QString birth = guy.dateofBirthQString();
    QString death = guy.dateofDeathQString();
    QTextStream out(&file);

    out << name << "@" << sex << "@" << birth << "@" << death << endl;

    return;
}

void Model::overwriteDB(vector<Scientist>& list){
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


















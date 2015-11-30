#include "model.h"
#include "scientist.h"
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

vector<scientist> model::retDB(){
    vector<scientist> ret;
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
            currBirth = QDate::fromString(currList[2],"dd:MM:yyyy");
            currDeath = QDate::fromString(currList[3],"dd:MM:yyyy");
            scientist guy(currName, currSex, currBirth, currDeath);
            ret.push_back(guy);
        }
        inputFile.close();
    }
    return ret;
}


















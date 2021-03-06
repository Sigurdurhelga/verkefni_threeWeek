#include "Scientist.h"
#include <QString>

using namespace std;

Scientist::Scientist(){
    // empty
}



Scientist::Scientist(QString sID, QString Sname, QString Ssex, QString SdoB, QString SdoD, QString Sfact){
    id = sID;
    name = Sname;
    sex = Ssex;
    doB = SdoB;
    doD = SdoD;
    description = Sfact;
}



void Scientist::setName(QString Sname){
    name = Sname;
}

void Scientist::setGender(QString Sgender){
    sex = Sgender;
}

void Scientist::setdoB(QString SdoB){
    doB = SdoB;
}

void Scientist::setdoD(QString SdoD){
    doD = SdoD;
}

void Scientist::setDescription(QString Sdescription){
    description = Sdescription;
}

QString Scientist::returnID(){
    return id;
}

QString Scientist::returnName(){
    return name;
}


QString Scientist::returnSex(){
    return sex;
}

QString Scientist::dateofBirth(){
    return doB;
}

QString Scientist::dateofDeath(){
    return doD;
}

QString Scientist::dateofBirthQString(){
    return doB;
}

QString Scientist::dateofDeathQString(){
    return doD;
}

QString Scientist::returnDescription(){
    return description;
}

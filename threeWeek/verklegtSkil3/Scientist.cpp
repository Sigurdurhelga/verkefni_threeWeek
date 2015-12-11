#include "Scientist.h"
#include <iostream>
#include <QString>
#include <ctime>

using namespace std;

Scientist::Scientist()
{
    // empty
}



Scientist::Scientist(int sID, QString Sname, QString Ssex, QString SdoB, QString SdoD, QString Sfact)

{
    id = sID;
    name = Sname;
    sex = Ssex;
    doB = SdoB;
    doD = SdoD;
    fact = Sfact;
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

void Scientist::setFact(QString Sfact)
{
    fact = Sfact;
}

QString Scientist::returnName()
{
    return name;
}


QString Scientist::returnSex()
{
    return sex;
}

QString Scientist::dateofBirth()
{
    return doB;
}

QString Scientist::dateofDeath()
{
    return doD;
}

QString Scientist::dateofBirthQString()
{
    return doB;
}

QString Scientist::dateofDeathQString()
{
    return doD;
}

QString Scientist::returnFact()
{
    return fact;
}

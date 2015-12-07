#include "Scientist.h"
#include <iostream>
#include <QString>
#include <ctime>

using namespace std;

Scientist::Scientist()
{
    name = "John Doe";
    sex = "male";
    doB = QDate(2012,01,01);
    doD = QDate(2013,01,01);
}



Scientist::Scientist(QString Sname, bool Ssex, QDate SdoB, QDate SdoD, QString Sfact)

{
    name = Sname;
    sex = Ssex;
    doB = SdoB;
    doD = SdoD;
    fact = Sfact;
}

QString Scientist::returnName()
{
    return name;
}

void Scientist::setName(QString Sname){
    name = Sname;
}

void Scientist::setGender(bool Sgender){
    sex = Sgender;
}

void Scientist::setdoB(QDate SdoB){
    doB = SdoB;
}

void Scientist::setdoD(QDate SdoD){
    doD = SdoD;
}

void Scientist::setFact(QString Sfact)
{
    fact = Sfact;
}

bool Scientist::returnSex()
{
    return sex;
}

QDate Scientist::dateofBirth()
{
    return doB;
}

QDate Scientist::dateofDeath()
{
    return doD;
}
QString Scientist::dateofBirthQString()
{
    return doB.toString("dd:MM:yyyy");
}
QString Scientist::dateofDeathQString()
{
    return doD.toString("dd:MM:yyyy");
}
QString Scientist::returnFact()
{
    return fact;
}

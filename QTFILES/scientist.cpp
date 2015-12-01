#include "scientist.h"
#include <iostream>
#include <QString>
#include <ctime>

using namespace std;

scientist::scientist()
{
    name = "John Doe";
    sex = "male";
    doB = QDate(2012,01,01);
    doD = QDate(2013,01,01);
}



scientist::scientist(QString Sname, QString Ssex, QDate SdoB, QDate SdoD)

{
    name = Sname;
    sex = Ssex;
    doB = SdoB;
    doD = SdoD;
}

QString scientist::returnName()
{
    return name;
}

void scientist::setName(QString sName){
    name = sName;
}

void scientist::setGender(QString sGender){
    sex = sGender;
}

void scientist::setdoB(QDate SdoB){
    doB = SdoB;
}

void scientist::setdoD(QDate SdoD){
    doD = SdoD;
}

QString scientist::returnSex()
{
    return sex;
}

QDate scientist::dateofBirth()
{
    return doB;
}

QDate scientist::dateofDeath()
{
    return doD;
}
QString scientist::dateofBirthQString()
{
    return doB.toString("dd.MM.yyyy");
}
QString scientist::dateofDeathQString()
{
    return doD.toString("dd.MM.yyyy");
}

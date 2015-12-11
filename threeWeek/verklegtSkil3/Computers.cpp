#include "Computers.h"

Computers::Computers()
{

}



Computers::Computers(int SID, QString Sname, bool Screated, int ScreationYear, QString Stype, QString Sdescription)
{
    ID = SID;
    name = Sname;
    created = Screated;
    creationYear = ScreationYear;
    type = Stype;
    description = Sdescription;
}

void Computers::setName(QString Sname){
    name = Sname;
}

void Computers::setCreated(bool sCreated){
    created = sCreated;
}

void Computers::setCreationYear(int sCreationYear){
    creationYear = sCreationYear;
}

void Computers::setType(QString sType){
    type = sType;
}

void Computers::setDescription(QString sDescription){
    description = sDescription;
}

bool Computers::returnCreated(){
    return created;
}

int Computers::returnCreationYear(){
    return creationYear;
}

QString Computers::returnName(){
    return name;
}

QString Computers::returnType(){
    return type;
}

QString Computers::returnDescription(){
    return description;
}

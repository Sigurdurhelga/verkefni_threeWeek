#include "Computers.h"

Computers::Computers()
{

}



Computers::Computers(QString Sid, QString Sname, QString Screated, QString ScreationYear, QString Stype, QString Sdescription)
{
    id = Sid;
    name = Sname;
    created = Screated;
    creationYear = ScreationYear;
    type = Stype;
    description = Sdescription;
}

void Computers::setName(QString Sname){
    name = Sname;
}

void Computers::setCreated(QString sCreated){
    created = sCreated;
}

void Computers::setCreationYear(QString sCreationYear){
    creationYear = sCreationYear;
}

void Computers::setType(QString sType){
    type = sType;
}

void Computers::setDescription(QString sDescription){
    description = sDescription;
}

QString Computers::returnID(){
    return id;
}

QString Computers::returnCreated(){
    return created;
}

QString Computers::returnCreationYear(){
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

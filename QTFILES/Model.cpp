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
        default:
            way = 25;
            cin.clear();
            cin.ignore();
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
            ret = db.exec("SELECT * FROM computers ORDER BY id DESC");
            break;
        case 3:
            ret = db.exec("SELECT * FROM computers WHERE created = 1 ORDER BY id");
            break;
        case 4:
            ret = db.exec("SELECT * FROM computers WHERE created = 0 ORDER BY id");
            break;
        case 5:
            ret = db.exec("SELECT * FROM computers ORDER BY creationDate");
            break;
        case 6:
            ret = db.exec("SELECT * FROM computers ORDER BY creationDate DESC");
            break;
        default:
            way = 25;
            cin.clear();
            cin.ignore();

    }
    return ret;
}


void Model::rmRowSci(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("DELETE FROM people WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    return;
}

void Model::rmRowComp(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("DELETE FROM computers WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    return;
}

QSqlQuery Model::searchSciName(QString name){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    QString query = "SELECT * FROM people WHERE name LIKE '%"+name+"%'";
    ret = db.exec(query);
    return ret;
}

QSqlQuery Model::searchSciID(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    ret.prepare("SELECT * FROM people WHERE id = :id");
    ret.bindValue(":id", id);
    ret.exec();
    return ret;
}

QSqlQuery Model::scientistConnComp(int id){
    QSqlQuery ret;
    ret.prepare("SELECT computers.name FROM computers "
                "INNER JOIN compGroups ON computers.id = compGroups.computerID "
                "INNER JOIN people ON compGroups.peopleID = people.id "
                "WHERE people.id = :id");
    ret.bindValue(":id", id);
    ret.exec();
    return ret;
}


QSqlQuery Model::searchCompName(QString name){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    QString query = "SELECT * FROM computers WHERE name LIKE '%"+name+"%'";
    ret = db.exec(query);
    return ret;
}

QSqlQuery Model::searchCompID(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    ret.prepare("SELECT * FROM computers WHERE id = :id");
    ret.bindValue(":id", id);
    ret.exec();
    return ret;
}

QSqlQuery Model::computersConnSci(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    ret.prepare("SELECT people.name FROM people "
                "INNER JOIN compGroups ON people.id = compGroups.peopleID "
                "INNER JOIN people ON compGroups.computerID = computers.id "
                "WHERE computers.id = :id");
    ret.bindValue(":id", id);
    ret.exec();
    return ret;
}

void Model::modSci(int select, QString entry, int id){
    QSqlDatabase db = QSqlDatabase::database();
    QString field;
    switch(select){
        case 1:
            field = "name";
            break;
        case 2:
            field = "gender";
            break;
        case 3:
            field = "birthDate";
            break;
        case 4:
            field = "deathDate";
            break;
        case 5:
            field = "fact";
            break;
    }
    QString qQuery = "UPDATE people SET "+field+" = '"+entry+"' "
                     "WHERE id = "+QString::number(id);
    db.exec(qQuery);
}

void Model::modComp(int select, QString entry, int id){
    QSqlDatabase db = QSqlDatabase::database();
    QString field;
    switch(select){
        case 1:
            field = "name";
            break;
        case 2:
            field = "created";
            break;
        case 3:
            field = "creationDate";
            break;
        case 4:
            field = "type";
            break;
        case 5:
            field = "description";
            break;
    }
    QString qQuery = "UPDATE computers SET "+field+" = '"+entry+"' "
                     "WHERE id = "+QString::number(id);
    db.exec(qQuery);
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
        query.prepare("INSERT INTO people (name, gender, birthDate, deathDate, fact) "
                      "VALUES (:name, :gender, :doB, :doD, :fact)");
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
        query.prepare("INSERT INTO computers(name, created, creationDate, description) "
                      "VALUES (:name, :created, :creationDate, :desc)");
        query.bindValue(":name", name);
        query.bindValue(":created", boolToString);
        query.bindValue(":creationDate", creationYear);
        query.bindValue(":desc", desc);
        query.exec();

    }

    return;
}

QSqlQuery Model::linkListSci(){
    QSqlQuery query;
    query.prepare("SELECT id, name FROM people");
    query.exec();

    return query;
}

QSqlQuery Model::linkListComp(){
    QSqlQuery query;
    query.prepare("SELECT id, name FROM computers");
    query.exec();

    return query;
}

void Model::linkSciToComp(int SciID, int CompID){
    QSqlQuery query;
    query.prepare("INSERT INTO compGroups(peopleID, computerID) "
                  "VALUES(:SciID, :CompID)");
    query.bindValue(":SciID", SciID);
    query.bindValue(":CompID", CompID);
    query.exec();

    return;
}


















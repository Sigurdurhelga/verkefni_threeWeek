#include "Model.h"
#include "Scientist.h"
#include <sstream>
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
    db.setDatabaseName("data.dat");
    bool db_ok = db.open();
    if(db_ok){
        return db;
    }
    else{
        qDebug() << "Database failed";
    }
}

bool Model::checkConnection(QSqlDatabase db){
    return db.open();
}

QVector<Scientist> Model::queryScientists(QSqlQuery query){
    QVector<Scientist> scientists;
    while(query.next()){
        QString id = query.value("id").toString();
        QString name = query.value("name").toString();
        QString sex = query.value("gender").toString();
        QString doB = query.value("birthDate").toString();
        QString doD = query.value("deathDate").toString();
        QString description = query.value("description").toString();

        scientists.push_back(Scientist(id, name, sex, doB, doD, description));

    }

    return scientists;
}

QVector<Computers> Model::queryComputers(QSqlQuery query){
    QVector<Computers> computers;

    while(query.next()){
        QString id = query.value("id").toString();
        QString name = query.value("name").toString();
        QString created = query.value("created").toString();
        QString creationYear = query.value("creationDate").toString();
        QString type = query.value("type").toString();
        QString description = query.value("description").toString();

        computers.push_back(Computers(id, name, created, creationYear, type, description));

    }

    return computers;
}

void Model::add(QString one, QString two, QString three, QString four, QString five, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QString queryString;
    QSqlQuery query;
    queryString += "INSERT INTO ";
    if(which){
        queryString += "people (name, gender, birthDate, deathDate, description) ";
    }
    else{
        queryString += "computers (name, created, creationDate, type, description) ";
    }
    queryString += "VALUES (:one, :two, :three, :four, :five)";
    query.prepare(queryString);
    query.bindValue(":one", one);
    query.bindValue(":two", two);
    query.bindValue(":three", three);
    query.bindValue(":four", four);
    query.bindValue(":five", five);
    query.exec();
}

void Model::remove(QString ID, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    QString queryString;
    queryString += "DELETE FROM ";
    if(which){
        queryString += "people WHERE id = :ID";
    }
    else{
        queryString += "computers WHERE id = :ID";
    }
    query.prepare(queryString);
    query.bindValue(":ID", ID);
    query.exec();
}

QSqlQuery Model::searchSci(QString name){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    QString queryString;
    queryString += "SELECT * FROM people WHERE name LIKE '%"+name+"%' ORDER BY name";
    query.prepare(queryString);
    query.exec();
    return query;
}
QSqlQuery Model::searchComp(QString name){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    QString queryString;
    queryString += "SELECT * FROM computers WHERE name LIKE '%"+name+"%' ORDER BY name";
    query.prepare(queryString);
    query.exec();
    return query;
}

void Model::edit(QString ID, QString newThing, int column, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    QString queryString = "UPDATE ";

    if(which){
        queryString += "people SET ";
        switch(column){
            case 1:
                queryString += "name = ";
                break;
            case 2:
                queryString += "gender = ";
                break;
            case 3:
                queryString += "birthDate = ";
                break;
            case 4:
                queryString += "deathDate = ";
                break;
            case 5:
                queryString += "description = ";
                break;
        }
    }
    else{
        queryString += "computers SET ";
        switch(column){
            case 1:
                queryString += "name = ";
                break;
            case 2:
                queryString += "created = ";
                break;
            case 3:
                queryString += "creationDate = ";
                break;
            case 4:
                queryString += "type = ";
                break;
            case 5:
                queryString += "description = ";
                break;
        }
    }
    queryString += ":new WHERE id = :id ";
    query.prepare(queryString);
    query.bindValue(":new", newThing);
    query.bindValue(":id", ID);
    query.exec();


}

QSqlQuery Model::queryListSci(int way){
    QSqlQuery ret(QSqlDatabase::database());

    switch(way){
        case 1:
            ret.exec("SELECT * FROM people ORDER BY name");
            break;
        case 2:
            ret.exec("SELECT * FROM people ORDER BY id DESC");
            break;
        case 3:
            ret.exec("SELECT * FROM people ORDER BY name");
            break;
        case 4:
            ret.exec("SELECT * FROM people ORDER BY name DESC");
            break;
        case 5:
            ret.exec("SELECT * FROM people ORDER BY birthDate");
            break;
        case 6:
            ret.exec("SELECT * FROM people ORDER BY birthDate DESC");
            break;
        case 7:
            ret.exec("SELECT * FROM people WHERE deathDate = 'ALIVE' ORDER BY id");
            break;
        default:
            way = 25;
            cin.clear();
            cin.ignore();
    }
    return ret;
}
QSqlQuery Model::queryListComp(int way){
    QSqlQuery ret;

    switch(way){
        case 1:
            ret.exec("SELECT * FROM computers ORDER BY name");
            break;
        case 2:
            ret.exec("SELECT * FROM computers ORDER BY id DESC");
            break;
        case 3:
            ret.exec("SELECT * FROM computers WHERE created = 1 ORDER BY id");
            break;
        case 4:
            ret.exec("SELECT * FROM computers WHERE created = 0 ORDER BY id");
            break;
        case 5:
            ret.exec("SELECT * FROM computers ORDER BY creationDate");
            break;
        case 6:
            ret.exec("SELECT * FROM computers ORDER BY creationDate DESC");
            break;
        case 7:
            ret.exec("SELECT * FROM computers ORDER BY type");
            break;
        case 8:
            ret.exec("SELECT * FROM computers ORDER BY type DESC");
            break;
        default:
            way = 25;
            cin.clear();
            cin.ignore();
            break;
    }
    return ret;
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

QSqlQuery Model::computersConnSci(int id){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery ret;
    ret.prepare("SELECT people.name FROM people "
                "INNER JOIN compGroups ON people.id = compGroups.peopleID "
                "INNER JOIN computers ON compGroups.computerID = computers.id "
                "WHERE computers.id = :id");
    ret.bindValue(":id", id);
    ret.exec();
    return ret;
}


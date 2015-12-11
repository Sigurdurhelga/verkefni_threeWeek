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
        cout << "DATABASE CONNECTION FAILED!" << endl;
    }
}

bool Model::checkConnection(QSqlDatabase db){
    return db.open();
}

QVector<Scientist> Model::queryScientists(){
    QVector<Scientist> scientists;
    QSqlQuery query = QSqlQuery();
    query = queryListSci(1);


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

QVector<Computers> Model::queryComputers(){
    QSqlDatabase db = QSqlDatabase::database();
    QVector<Computers> computers;
    QSqlQuery query = QSqlQuery();
    query = queryListComp(1);

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

void Model::remove(int ID, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("DELETE FROM :which WHERE id = :ID");
    if(which){
        query.bindValue(":which", "people");
    }
    else{
        query.bindValue(":which", "computers");
    }
    query.bindValue(":ID", ID);
    query.exec();
}

QSqlQuery Model::queryListSci(int way){
    QSqlQuery ret(QSqlDatabase::database());

    switch(way){
        case 1:
            ret.exec("SELECT * FROM people ORDER BY id");
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
            ret.exec("SELECT * FROM computers ORDER BY id");
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

void Model::addScientistToDatabase(Scientist& guy){
    QSqlDatabase db = QSqlDatabase::database();
    if(checkConnection(db)){
        QSqlQuery query;

        QString name = guy.returnName();
        QString gender = guy.returnSex();
        QString doB = guy.dateofBirthQString();
        QString doD = guy.dateofDeathQString();
        QString description = guy.returnDescription();

        if(doD == "0001-01-01"){
            doD = "ALIVE";
        }

        QString boolToString = "0";

            boolToString = "1";

        query.prepare("INSERT INTO people (name, gender, birthDate, deathDate, description) "
                      "VALUES (:name, :gender, :doB, :doD, :description)");
        query.bindValue(":name", name);
        query.bindValue(":gender", boolToString);
        query.bindValue(":doB", doB);
        query.bindValue(":doD", doD);
        query.bindValue(":description", description);
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
        QString created = comp.returnCreated();
        QString creationYear = comp.returnCreationYear();
        QString type = comp.returnType();
        QString desc = comp.returnDescription();
        QString boolToString = "0";

        boolToString = "1";

        query.prepare("INSERT INTO computers(name, created, creationDate, type, description) "
                      "VALUES (:name, :created, :creationDate, :type, :desc)");
        query.bindValue(":name", name);
        query.bindValue(":created", boolToString);
        query.bindValue(":creationDate", creationYear);
        query.bindValue(":type", type);
        query.bindValue(":desc", desc);
        query.exec();

    }

    return;
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
            field = "description";
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























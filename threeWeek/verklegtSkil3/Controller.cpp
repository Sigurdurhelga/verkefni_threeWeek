#include "Model.h"
#include "Controller.h"
#include <QVector>
#include <QString>
#include <QtSql>

using namespace std;

QVector<Scientist> Controller::getScientists(QString name){
    Model db;
    QVector<Scientist> listSci;
    QSqlQuery query;

    if(name == ""){
        query = db.queryListSci();
    }
    else{
        query = db.searchSci(name);
    }

    listSci = db.queryScientists(query);

    return listSci;
}

QVector<Computers> Controller::getComputers(QString name){
    Model db;
    QVector<Computers> listComp;
    QSqlQuery query;

    if(name == ""){
        query = db.queryListComp();
    }
    else{
        query = db.searchComp(name);
    }

    listComp = db.queryComputers(query);

    return listComp;
}

QVector<QString> Controller::showLinks(QString id, bool which){
    Model db;
    QVector<QString> list;
    QSqlQuery query;

    query = db.getLinks(id, which);

    while(query.next()){
        list.push_back(query.value("name").toString());
    }

    return list;
}

QVector<QString> Controller::getNameForLinks(bool which){
    Model db;
    QVector<QString> list;
    QSqlQuery query;
    query = db.queryGetNameForLinking(which);
    while(query.next()){
        list.push_back(query.value("name").toString());
    }
    return list;
}

void Controller::add(QString one, QString two, QString three, QString four, QString five, bool which){
    Model db;

    db.add(one, two, three, four, five, which);

    return;
}

void Controller::remove(QString id, bool which){
    Model db;

    db.remove(id, which);

    return;
}

void Controller::edit(QString id, QString newThing, int column, bool which){
    Model db;

    db.edit(id, newThing, column, which);

    return;
}

void Controller::link(QString id, QString name, bool which){
    Model db;
    db.link(id, name, which);
}







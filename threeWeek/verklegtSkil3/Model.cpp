#include "Model.h"
#include <QString>
#include <QVector>

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

QSqlQuery Model::queryListSci(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());

    query.exec("SELECT * FROM people ORDER BY name");

    return query;
}

QSqlQuery Model::queryListComp(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());

    query.exec("SELECT * FROM computers ORDER BY name");

    return query;
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

QSqlQuery Model::queryGetNameForLinking(bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());
    QString queryString;

    queryString = "SELECT name FROM ";
    if(which){
        queryString += "computers";
    }
    else{
        queryString += "people";
    }
    query.prepare(queryString);
    query.exec();

    return query;
}

QSqlQuery Model::getLinks(QString id, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());

    if(which){
    query.prepare("SELECT computers.name FROM computers "
                "INNER JOIN compGroups ON computers.id = compGroups.computerID "
                "INNER JOIN people ON compGroups.peopleID = people.id "
                "WHERE people.id = :id");
    }
    else{
        query.prepare("SELECT people.name FROM people "
                    "INNER JOIN compGroups ON people.id = compGroups.peopleID "
                    "INNER JOIN computers ON compGroups.computerID = computers.id "
                    "WHERE computers.id = :id");
    }
    query.bindValue(":id", id);
    query.exec();

    return query;
}

void Model::link(QString id, QString name, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());
    QString queryString = "INSERT INTO compGroups VALUES(";
    if(which){
        queryString += id + ", (SELECT id FROM computers WHERE name = '" + name + "'))";
    }
    else{
        queryString += "(SELECT id FROM people WHERE name = '" + name + "'), "+ id +")";
    }
    query.prepare(queryString);
    query.exec();

    return;
}

void Model::add(QString one, QString two, QString three, QString four, QString five, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QString queryString;
    QSqlQuery query(QSqlDatabase::database());

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

    return;
}

void Model::remove(QString ID, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());
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

    return;
}

void Model::edit(QString ID, QString newThing, int column, bool which){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(QSqlDatabase::database());
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

    return;
}








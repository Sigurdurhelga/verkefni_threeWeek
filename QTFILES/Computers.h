#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <QDateTime>
#include <string>

class Computers
{
    private:
        int ID;
        bool created;
        QDate creationDate;
        QString name;
        QString description;


    public:
        Computers();
        Computers(int ID, bool created, QDate creationDate, QString name, QString description);
};

#endif // COMPUTERS_H

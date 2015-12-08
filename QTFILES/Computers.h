#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <QDateTime>
#include <string>

class Computers
{
    private:
        int ID;
        QString name;
        bool created;
        int creationYear;
        QString type;
        QString description;


    public:
        Computers();
        Computers(int SID, QString Sname, bool Screated, int ScreationYear, QString type, QString Sdescription);
        QString returnName();
        bool returnCreated();
        int returnCreationYear();
        QString returnType();
        QString returnDescription();
        void setName(QString name);
        void setCreated(bool sCreated);
        void setCreationYear(int sCreationYear);
        void setType(QString sType);
        void setDescription(QString sDescription);
};

#endif // COMPUTERS_H

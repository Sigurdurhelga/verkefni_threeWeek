#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <QString>

class Computers
{
    private:
        QString id;
        QString name;
        QString created;
        QString creationYear;
        QString type;
        QString description;

    public:
        // Constructors
        Computers();
        Computers(QString SID, QString Sname, QString Screated, QString ScreationYear, QString type, QString Sdescription);

        // Set functions
        void setName(QString name);
        void setCreated(QString sCreated);
        void setCreationYear(QString sCreationYear);
        void setType(QString sType);
        void setDescription(QString sDescription);

        // Get functions
        QString returnID();
        QString returnCreated();
        QString returnCreationYear();
        QString returnName();
        QString returnType();
        QString returnDescription();
};

#endif // COMPUTERS_H

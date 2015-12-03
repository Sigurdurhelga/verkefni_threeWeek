#include "Computers.h"

Computers::Computers()
{

}

Computers::Computers(int SID, QString Sname, bool Screated, int ScreationYear, QString Sinventor, QString Sdescription)
{
    ID = SID;
    name = Sname;
    created = Screated;
    creationYear = ScreationYear;
    inventor = Sinventor;
    description = Sdescription;
 }

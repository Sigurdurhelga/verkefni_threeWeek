#ifndef MODEL_H
#define MODEL_H
#include "scientist.h"
#include <vector>

class model
{
public:
     vector<scientist> retDB();
     void writeToDB(scientist guy);
     void overwriteDB(vector<scientist>& list);
};

#endif // MODEL_H

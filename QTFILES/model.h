#ifndef MODEL_H
#define MODEL_H
#include "Scientist.h"
#include <vector>

class Model
{
public:
     vector<Scientist> retDB();
     void writeToDB(Scientist guy);
     void overwriteDB(vector<Scientist>& list);
};

#endif // MODEL_H

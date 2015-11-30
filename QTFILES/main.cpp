#include <QCoreApplication>
#include "scientist.h"
#include "view.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    view newView;
    newView.displayInterface();

    return 0;
}

#include <QCoreApplication>
#include "view.h"





using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    view newView;
    newView.displayInterface();

    return 0;
}

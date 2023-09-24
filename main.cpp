#include "mainwindow.h"
#include "math.h"
#include <QApplication>
//float TX_Power, Ant, PL;
//float f,d,max;
int main(int argc, char *argv[])
{


   /* PL = 28.0 + 22 * log10(f) + 20 * log10(d);
    max = TX_Power + Ant - PL;*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

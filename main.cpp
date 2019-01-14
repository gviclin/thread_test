#include "mainwindow.h"
#include <QApplication>
#include "testthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestThread threadElt;
    threadElt.LaunchThread();

   // MainWindow w;
  //  w.show();

    return a.exec();
}

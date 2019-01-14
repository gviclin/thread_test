#include "mainwindow.h"
#include <QApplication>
#include "testthread.h"
#include "lambdafunctiontest.h"
#include "iostream"
#include <QtDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LambdaFunctionTest lambdaTest;

    TestThread threadElt;
    //threadElt.LaunchThreads();
/*
   MainWindow w;
   w.show();

    return a.exec();*/
}

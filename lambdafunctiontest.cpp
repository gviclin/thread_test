#include "lambdafunctiontest.h"
#include <QtDebug>
#include <iostream>

static int sum = 0;
static void somme(int value){sum += value;}

LambdaFunctionTest::LambdaFunctionTest()
{
    std::vector<int> vect = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Lambda fonction 1
    int sum1=0;
    std::for_each(vect.begin(), vect.end(), [&sum1](int value) {
        sum1 += value;
    });
    qDebug() << "sum : " << sum1;

     //without Lambda fonction
    sum=0;
    std::for_each(vect.begin(), vect.end(), &somme);
    qDebug() << "sum2 : " << sum;

    //Lambda fonction 2
    std::transform(vect.begin(), vect.end(), vect.begin(),
                     [](int value) { return value *value; });
    int i=0;
    for(int value : vect) {
    qDebug()  << i << " : " << value;
    }
}

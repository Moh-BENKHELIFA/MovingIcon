#include "movingimage.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MovingImage w;
    w.show();


    std::vector<int> rp1(3, 5) ;

    for(int i: rp1){
        std::cout<<i<<std::endl;

    }

   // rp1.data();
    std::cout<<"Hello World"<<std::endl ;


    return a.exec();


}

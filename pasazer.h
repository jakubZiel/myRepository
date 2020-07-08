#ifndef PASAZER_H
#define PASAZER_H
#include <string>
#include "pojazd.h"

using namespace std;
class Pasazer
{
                friend class Riksza;
                friend class RikszaMotor;
    private:


    int ilosc;
    int waga;
    double trasa;
    double kasa;
    public:

        Pasazer(int number=1,int mass=73,double road=4.5,double money=21);
        ~Pasazer();

};


#endif

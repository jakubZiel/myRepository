#ifndef CZAS_H
#define CZAS_H
#include <string>
#include <iostream>
#include "pojazd.h"
using namespace std;
class Czas
{
    friend class Rower;
    friend class RikszaMotor;
    friend class Riksza;
    int godzina;
    int minuta;
    int ileMinelo;

    public :
    Czas(int hour=8,int minute=0,int passed=0);
    void ktoraGodzina();
    void setCzas();
    void szukanieNowegoPasazera(int mins=15);


};


#endif

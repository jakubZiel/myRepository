#include "czas.h"

Czas::Czas(int hour,int minute,int passed)
{
    godzina=hour;
    minuta=minute;
    ileMinelo=passed;

}

void Czas::ktoraGodzina()
{
    cout<<godzina<<":";
    if(minuta<=9)cout<<"0"<<minuta<<endl;
    else cout<<minuta<<endl;
}
void Czas::szukanieNowegoPasazera(int mins)
{
    ileMinelo=ileMinelo+mins;
}
void Czas::setCzas()
{
    godzina=8+ileMinelo/60;
    minuta=0+ileMinelo-(ileMinelo/60)*60;
}


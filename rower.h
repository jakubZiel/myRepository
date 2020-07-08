#ifndef ROWER_H
#define ROWER_H
#include  "pojazd.h"
#include  "riksza.h"

using namespace std;

class Rower:public Pojazd
{

    public:

    Rower(string mdl="rower nowy",double mass=30,double areo=1.5,Kierowca *mK=0);
    virtual void addKierowca();
    virtual void display();
    virtual void deleteKierowca();
    virtual void setKierowca(string name="Filip",string surname="Szczesniak",string nation="PL",int age=26,double mass=85,double salary=0,int forKM=5);
    friend ostream &operator<<(ostream &out,const Rower&var);
    friend istream &operator>>(istream &in, Rower &var);
    virtual string getMDL();
    virtual double getWaga();
    virtual double getAreo();
    virtual Kierowca* getKierowca();

    virtual void saveToFile();
    virtual void loadFromFile();
    virtual void Dzien();
};


#endif

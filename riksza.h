#ifndef RIKSZA_H
#define RIKSZA_H
#include <string>
#include "pojazd.h"
#include <fstream>
#include "pasazer.h"
using namespace std;

class Riksza:public Pojazd
{
    private:
    Pasazer *mojPasazer;
    public:

    ~Riksza();
    Riksza(string mdl="riksza F1",double mass=100,double areo=1.5,Kierowca *mK=0,Pasazer *pasazer=0);
    virtual void addKierowca();
    virtual void display();
    virtual void deleteKierowca();
    virtual void setKierowca(string name="Jan",string surname="Kowalski",string nation="PL",int age=55,double mass=85,double salary=0,int forKM=5);
    friend ostream &operator<<(ostream &out,const Riksza&var);
    friend istream &operator>>(istream &in, Riksza&var);
    virtual void saveToFile();
    virtual void loadFromFile();
    virtual string getMDL();
    virtual double getWaga();
    virtual double getAreo();
    virtual Kierowca* getKierowca();
    virtual void Dzien();

};
#endif

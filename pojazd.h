#ifndef POJAZD_H
#define POJAZD_H
#include <string>
#include "kierowca.h"
#include "czas.h"
#include <cstdlib>
using namespace std; //klasa abstrakcyjna

class Pojazd
{
    protected:

    string id;
    string model;
    double waga;
    double areodynamika;
    Kierowca *mojKierowca;

        public:
        virtual ~Pojazd();
        virtual void addKierowca()=0;
        virtual void display()=0;
        virtual void deleteKierowca()=0;
        virtual void setKierowca(string name="Filip",string surname="Szczeniak",string nation="PL",int age=55,double mass=85,double salary=0,int forKM=5)=0;
        virtual void saveToFile()=0;
        virtual void loadFromFile()=0;
        virtual string getMDL()=0;
        virtual double getWaga()=0;
        virtual double getAreo()=0;
        virtual Kierowca* getKierowca()=0;
        virtual void Dzien()=0;
        friend istream &operator>>(istream &in,Pojazd *&var);

        string getId();
};

#endif

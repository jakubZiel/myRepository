#ifndef RIKSZAMOTOR_H
#define RIKSZAMOTOR_H
#include "riksza.h"
#include "pasazer.h"
#include <cstdlib>
using namespace std;

class RikszaMotor:public Riksza
{

    Pasazer *przyczepa[4];
    int miejsca;

    public:
    RikszaMotor();
    ~RikszaMotor();
    virtual void display();
    friend ostream &operator<<(ostream &out,RikszaMotor&var);
    friend istream &operator>>(istream &in, RikszaMotor&var);
    virtual string getMDL();
    virtual double getWaga();
    virtual double getAreo();
    virtual Kierowca* getKierowca();
    Pasazer *getPasazer(int);
    virtual void saveToFile();
    virtual void loadFromFile();
    virtual void Dzien();
};
#endif

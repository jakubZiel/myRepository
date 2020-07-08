#ifndef KIEROWCA_H
#define KIEROWCA_H
#include <string>
using namespace std;
class Kierowca
{
    friend class Rower;
    friend class RikszaMotor;
    friend class Riksza;
    private:
    string imie;
    string nazwisko;
    string narod;
    int wiek;
    double waga;
    double dniowka;
    int zaKM;

    public :
        Kierowca(string name="Filip",string surname="Szczesniak",string nation="PL",int age=20,double mass=75,double salary=0,int forKM=4);
        void showKierowca();
        void setKierowca(string name,string surname,string nation,int age,double mass,double salary,int forKM);
        int podajIleZaKm();
        ~Kierowca();
        friend ostream &operator<<(ostream &out,const Kierowca&var);
        void saveKierowcaToFile();
        void loadKierowcaFromFile();


};


#endif

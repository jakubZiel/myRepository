#include <iostream>
#include <string>
#include "riksza.h"
#include <cstdlib>
#include <time.h>
using namespace std;

Riksza::Riksza(string mdl,double mass,double areo,Kierowca *mK,Pasazer* pasaz)
{
    id="r";
    model=mdl;
    waga=mass;
    areodynamika=areo;
    mojKierowca=mK;
    mojPasazer=pasaz;
}
Riksza::~Riksza()
{
    if(mojPasazer!=0){delete mojPasazer;mojPasazer=0;}
    cout<<"destruktor Riksza"<<endl;
}
void Riksza::addKierowca()
{
    if(mojKierowca==0)
    mojKierowca=new Kierowca;
    else cout<<"riksza ma kierowce!!!"<<endl;
}


void Riksza::display()
{
    cout<<*this;
    if(mojKierowca==0)cout<<0<<endl;
    else mojKierowca->showKierowca();
}

void Riksza::deleteKierowca()
{
  if(mojKierowca!=0)
  {
  delete this->mojKierowca;
  mojKierowca=0;
  cout<<"usunieto Kierowce z rikszy: "<<this->model<<endl;
  }
}
void Riksza::setKierowca(string name,string surname,string nation,int age,double mass,double salary,int forKM)
{
    if(mojKierowca!=0)
    this->mojKierowca->setKierowca(name,surname,nation,age,mass,salary,forKM);
    else cout<<"brak Kierowcy,uzyj addKierowca()!!!"<<endl;
}
ostream& operator<<(ostream &out,const Riksza&var)
     {
            out<<var.model<<endl<<var.waga<<endl<<var.areodynamika<<endl;
            return out;
    }
istream &operator>>(istream &in,Riksza &var)
{
    string buf;
    getline(in,var.model);

    getline(in,buf);
    var.waga=atof(buf.c_str());

    getline(in,buf);
    var.areodynamika=atof(buf.c_str());

    return in;

}
void Riksza::saveToFile()
{
    fstream file;
    file.open("plikMain.txt",ios::out|ios::app);
    file<<"##"<<this->id<<endl;
    file<<*this;
    if(mojKierowca==0)file<<0<<endl;
    else {
            file<<"-->";
            mojKierowca->saveKierowcaToFile();
         }

    file.close();
}
void Riksza::loadFromFile()
{
    fstream file;
    file.open("plik.txt",ios::in);
    if(file.good()==false)
    {
        cout<<"plik nie istnieje"<<endl;
    }
    else
    {
        string bufor;
        while(!file.eof())
        {

            file>>*this;
            getline(file,bufor);
            getline(file,bufor);
            getline(file,bufor);

            if(bufor=="0" && mojKierowca!=0){delete mojKierowca;mojKierowca=0;}
            if(bufor=="0" && mojKierowca==0)break;
            if(bufor!="0" && mojKierowca==0)
            {
                mojKierowca=new Kierowca;
                mojKierowca->loadKierowcaFromFile();
            }
            if(bufor!="0" && mojKierowca!=0);
            {
                mojKierowca->loadKierowcaFromFile();
            }
        }

    }

    file.close();

}

string Riksza::getMDL()
{
    return this->model;
}
double Riksza::getWaga()
{
    return this->waga;
}
double Riksza::getAreo()
{
    return this->areodynamika;
}
Kierowca* Riksza::getKierowca()
{
    return this->mojKierowca;
}
void Riksza::Dzien()
{
    if(mojKierowca!=0)
    {
        srand(time(NULL));
        int counter=0;
        double interval;
        Czas time;
        double predkosc;
        while(time.ileMinelo<720)
        {

            cout<<"szukanie nowego pasazera(15min)"<<endl;
            time.szukanieNowegoPasazera();

            time.setCzas();
            time.ktoraGodzina();

            mojPasazer=new Pasazer;

            predkosc=60*3.2*(400/(areodynamika*(waga+mojPasazer->waga+mojKierowca->waga)));

            interval=350*(rand()%2+2)*mojPasazer->trasa/predkosc;


            time.ileMinelo+=interval;
            cout<<"Przejazd nr : "<<counter+1<<endl;
            time.setCzas();
            time.ktoraGodzina();

            counter++;        }
    }
    else
        cout<<"brak kierowcy,blad"<<endl;
}


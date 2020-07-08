#include "rower.h"
#include <iostream>
#include <cstdlib>
Rower::Rower(string mdl,double mass,double areo,Kierowca *mK)
{
    id="ro";
    model=mdl;
    waga=mass;
    areodynamika=areo;
    mojKierowca=mK;
}
void Rower::addKierowca()
{
    if(mojKierowca==0)
    mojKierowca=new Kierowca;
    else cout<<"rower ma kierowce!!!"<<endl;
}

void Rower::display()
{
    cout<<*this;
    if(mojKierowca==0)cout<<0<<endl;
    else mojKierowca->showKierowca();
}

void Rower::deleteKierowca()
{
  if(mojKierowca!=0)
  {
  delete this->mojKierowca;
  mojKierowca=0;
  cout<<"usunieto Kierowce z roweru: "<<this->model<<endl;
  }
}

void Rower::setKierowca(string name,string surname,string nation,int age,double mass,double salary,int forKM)
{
    if(mojKierowca!=0)
    this->mojKierowca->setKierowca(name,surname,nation,age,mass,salary,forKM);
    else cout<<"brak Kierowcy,uzyj addKierowca()!!!"<<endl;
}
ostream& operator<<(ostream &out,const Rower&var)
{
            out<<var.model<<endl<<var.waga<<endl<<var.areodynamika<<endl;
            return out;
}

 istream &operator>>(istream &in,Rower &var)
{
    string buf;
    getline(in,var.model);

    getline(in,buf);
    var.waga=atof(buf.c_str());

    getline(in,buf);
    var.areodynamika=atof(buf.c_str());

    return in;

}
string Rower::getMDL()
{
    return this->model;
}
double Rower::getWaga()
{
    return this->waga;
}
double Rower::getAreo()
{
    return this->areodynamika;
}
Kierowca* Rower::getKierowca()
{
    return this->mojKierowca;
}

void Rower::saveToFile()
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
void Rower::loadFromFile()
{
    fstream file;
    file.open("plikRower.txt",ios::in);
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
}
void Rower::Dzien()
{
    double predkosc;
    double moc=320;
    Czas time;
    double interval;
    double distance=5000;

    if(mojKierowca==0)cout<<"brak Kierowcy blad!!!"<<endl;
    else
        {
            cout<<"Poczatek dnia o 8:00"<<endl;
            predkosc=35*3.2*(moc/(areodynamika*(waga+mojKierowca->waga)));


            int counter=0;
            while(time.ileMinelo<720)
            {
                interval=distance/predkosc;
                cout<<"Podroz numer: "<<counter+1<<endl;
                time.ileMinelo+=interval;
                time.setCzas();
                time.ktoraGodzina();
                distance+=500;
                counter++;
            }

        }
}

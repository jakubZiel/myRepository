#include <iostream>
#include <string>
#include "kierowca.h"
#include <fstream>
#include <cstdlib>
using namespace std;

Kierowca::Kierowca(string name,string surname,string nation,int age,double mass,double salary,int forKM)
{
     imie=name;
     nazwisko=surname;
     narod=nation;
     wiek=age;
     waga=mass;
     dniowka=salary;
     zaKM=forKM;
}
Kierowca::~Kierowca()
{
    cout<<"destruktor Kierowca"<<endl;
}
void Kierowca::showKierowca()
{
    cout<<"imie,nazwisko: "<<imie<<" "<<nazwisko<<endl;
    cout<<"narodowosc: "<<narod<<endl;
    cout<<"wiek: "<<wiek<<endl;
    cout<<"waga: "<<waga<<endl;
    cout<<"zarobil:"<<dniowka<<endl;
    cout<<"bierze za KM: "<<zaKM<<endl;
}
void Kierowca::setKierowca(string name,string surname,string nation,int age,double mass,double salary,int forKM)
{

     if(this!=0)
     {
     imie=name;
     nazwisko=surname;
     narod=nation;
     wiek=age;
     waga=mass;
     dniowka=salary;
     zaKM=forKM;
     }
     else cout<<"brak kierowcy"<<endl;
}
int Kierowca::podajIleZaKm()
{
        return this->zaKM;
}
ostream& operator<<(ostream &out,const Kierowca&var)
     {
            out<<var.imie<<endl<<var.nazwisko<<endl<<var.narod<<endl<<var.wiek<<endl<<var.waga<<endl<<var.dniowka<<endl<<var.zaKM;
            return out;
    }
void Kierowca::saveKierowcaToFile()
    {
        fstream file;
        file.open("plikKierowca.txt",ios::out);

        file<<*this;

        file.close();
    }
void Kierowca::loadKierowcaFromFile()
{

    fstream file;
    file.open("plikKierowca.txt",ios::in);
    if(file.good()==false)
    {
        cout<<"plik nie istnieje"<<endl;
    }
    else
    {
        string bufor;
        while(!file.eof())
        {
            getline(file,bufor);
            imie=bufor;

            getline(file,bufor);
            nazwisko=bufor;

            getline(file,bufor);
            narod=bufor;

            getline(file,bufor);
            wiek=atoi(bufor.c_str());

            getline(file,bufor);
            waga=atof(bufor.c_str());

            getline(file,bufor);
            dniowka=atof(bufor.c_str());

            getline(file,bufor);
            zaKM=atoi(bufor.c_str());
        }

    }

    file.close();

}

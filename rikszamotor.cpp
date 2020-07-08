#include "rikszamotor.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

  RikszaMotor::RikszaMotor():Riksza()
   {
       id="rm";

       przyczepa[0]=0;
       przyczepa[1]=0;
       przyczepa[2]=0;
       przyczepa[3]=0;
       miejsca=0;
   }

void RikszaMotor::display()
{
      this->Riksza::display();

      cout<<przyczepa[0]<<endl;
      cout<<przyczepa[1]<<endl;
      cout<<przyczepa[2]<<endl;
      cout<<przyczepa[3]<<endl;
}
RikszaMotor::~RikszaMotor()
{
    cout<<"destrukotr RikszaMotor"<<endl;
    for(int i=0;i>=3;i++)
    {
        if(przyczepa[i]!=0){delete przyczepa[i];przyczepa[i]=0;}
    }
}

istream &operator>>(istream &in,RikszaMotor&var)
{
    string buf;
    getline(in,var.model);

    getline(in,buf);
    var.waga=atof(buf.c_str());

    getline(in,buf);
    var.areodynamika=atof(buf.c_str());

    return in;
}

string RikszaMotor::getMDL()
{
    return this->model;
}
double RikszaMotor::getWaga()
{
    return this->waga;
}
double RikszaMotor::getAreo()
{
    return this->areodynamika;
}
Kierowca* RikszaMotor::getKierowca()
{
    return this->mojKierowca;
}
Pasazer*RikszaMotor::getPasazer(int i)
{
    return this->przyczepa[i];
}
ostream& operator<<(ostream &out,RikszaMotor &var)
     {
            out<<var.getMDL()<<endl<<var.getWaga()<<endl<<var.getAreo()<<endl;
            if(var.mojKierowca==0)out<<0<<endl;
            else out<<*(var.mojKierowca)<<endl;
            out<<var.getPasazer(0)<<endl<<var.getPasazer(1)<<endl<<var.getPasazer(2)<<endl<<var.getPasazer(3)<<endl;
            return out;
     }
void RikszaMotor::saveToFile()
{
    fstream file;
    file.open("plikMain.txt",ios::out|ios::app);
    file<<"##"<<this->id<<endl;
    file<<*this;
    file.close();

    if(mojKierowca!=0){
    file.open("plikMain.txt",ios::out|ios::app);
    mojKierowca->saveKierowcaToFile();
    }
    file.close();
}
void RikszaMotor::loadFromFile()
{
   fstream file;
    file.open("plikRikszaMotor.txt",ios::in);
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
            if(bufor=="0" && mojKierowca!=0)
            {   delete mojKierowca;
                mojKierowca=0;

                for(int i=1;i<=4;i++)
                    {
                    getline(file,bufor);
                    if(bufor=="0")przyczepa[i-1]=0;
                    }
                    break;
            }
            else
            if(bufor=="0" && mojKierowca==0)
            {
             for(int i=1;i<=4;i++)
            {
                getline(file,bufor);
                if(bufor=="0")przyczepa[i-1]=0;
            }
                break;
            }
            else
            if(bufor!="0" && mojKierowca!=0)
            {
                mojKierowca->loadKierowcaFromFile();
            }
            else
            if(bufor!="0" && mojKierowca==0)
            {
                mojKierowca=new Kierowca;
                mojKierowca->loadKierowcaFromFile();
            }

            for(int i=1;i<=7;i++)getline(file,bufor);
            for(int i=1;i<=4;i++)
            {
                getline(file,bufor);
                if(bufor=="0")przyczepa[i-1]=0;
            }
        }


    }

    file.close();
}
void RikszaMotor::Dzien()
{
    srand(time(NULL));
    int los;

    Czas time;
    if(mojKierowca==0)cout<<"brak Kierowcy, blad !!!"<<endl;
    else
    {
        double predkosc;
        double interval;
        int counter=0;
        while (time.ileMinelo<720)
        {
            cout<<"szukanie nowego pasazera(15min)"<<endl;
            time.szukanieNowegoPasazera();

            time.setCzas();
            time.ktoraGodzina();

            los=rand()%5;
            Pasazer potencjalny;

            if(los!=0)
            {

            predkosc=60*3.2*(990/(areodynamika*(waga+los*potencjalny.waga+mojKierowca->waga)));


            interval=1500*potencjalny.trasa/predkosc;
            time.ileMinelo+=interval;

            cout<<"Podroz nr : "<<counter+1<<"zabrano : "<<los<<" pasazerow."<<endl;

            time.setCzas();
            time.ktoraGodzina();

            counter++;
            miejsca=0;
            }
        }
    }
}

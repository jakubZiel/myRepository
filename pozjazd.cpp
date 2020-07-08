#include <iostream>
#include <string>
#include "pojazd.h"
using namespace std;


Pojazd::~Pojazd()
{
    cout<<"destruktor Pojazd"<<endl;
    if(mojKierowca!=0)
    delete this->mojKierowca;
}
string Pojazd::getId()
{
    return id;
}
 istream &operator>>(istream &in,Pojazd *&var)
{
    string buf;
    getline(in,var->model);

    getline(in,buf);
    var->waga=atof(buf.c_str());

    getline(in,buf);
    var->areodynamika=atof(buf.c_str());

    return in;

}

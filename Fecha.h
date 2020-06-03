#include <iostream>
using namespace std;

class Fecha
{
  public:
    //constructores
    Fecha();
    Fecha(int d, int m, int a);
    //metodos acceso
    int getDia() { return dd;};
    int getMes() { return mm;};
    int getAnio() { return aa;};
    //metodos
    string nombreMes();
    void setFecha(int d, int m, int a);
    //sobrecarga operadores
    int operator+(int x);
    bool operator>=(Fecha f);
    bool operator<=(Fecha f);
    bool operator>(Fecha f);
    bool operator<(Fecha f);
    bool operator==(Fecha f);
    friend ostream &operator << (ostream &os, Fecha f);
    friend istream &operator >> (istream &os, Fecha &c);
  
  private:
    int dd,mm,aa;
};

//constructores
Fecha::Fecha(){
  dd=0;
  mm=0;
  aa=0;
}

Fecha::Fecha(int d, int m, int a){
  dd=d;
  mm=m;
  aa=a;
}

//metodos 
string Fecha :: nombreMes(){
    switch ( mm )
    {
        case  1 : return "Enero" ;
                break;
        case  2 : return "Feb";
                  break;
        case  3 : return "Mar";
                  break;
        case  4 : return "Abr";
                  break;
        case  5 : return "May";
                  break;
        case  6 : return "Jun";
                  break;
        case  7 : return "Jul";
                  break;
        case  8 : return "Ago";
                  break;
        case  9 : return "Sept";
                  break;
        case 10 : return "Oct";
                  break;
        case 11 : return "Nov";
                  break;
        case 12 : return "Dic";
                  break;
    }
}

void Fecha::setFecha(int d, int m, int a){
  dd=d;
  mm=m;
  aa=a;
  //cout << dd << "/" << mm << "/" << aa << endl;
}

//sobrecarga de operadores

//servira para sumarle una cantidad de días
int Fecha :: operator+(int x){
  int dias = dd + x;
  //validar si mes es par o impar para ver cuantos dias tiene el mes
    if(mm%2 == 0){
    //30 dias
      if(dias>30){
        mm = mm+1;
        dd = 1;
      }
      if(dias<30){
        dd=dias;
      }
    }
    else if(mm%2 == 1){
    //31 dias
      if(dias>31){
        mm = mm+1;
        dd = 1;
      }
      if(dias<31){
        dd=dias;
      }
    }
}

//se usarán para realizar las consultas
bool Fecha :: operator>=(Fecha f){
  bool respuesta = false;
    if(aa >= f.getAnio()){
      respuesta = true;
    }
    if(aa == f.getAnio() && mm >= f.getMes()){
      respuesta = true;
    }
    if(aa == f.getAnio() && mm == f.getMes() && dd >= f.getDia()){
      respuesta = true;
    }
  return respuesta;
}

bool Fecha :: operator<=(Fecha f){
  bool respuesta = false;
    if(aa <= f.getAnio()){
      respuesta = true;
        if(aa == f.getAnio() && mm <= f.getMes()){
          respuesta = true;
            if(aa == f.getAnio() && mm == f.getMes() && dd <= f.getDia()){
             respuesta = true;
             }
            else {
              return false;
            }
        }
        else{
          return false;
        }
      }
    else {
      return false;
    }
  return respuesta;
}

bool Fecha :: operator>(Fecha f){
    bool respuesta = false;
    if(aa > f.getAnio()){
      respuesta = true;
    }
    if(aa == f.getAnio() && mm > f.getMes()){
      respuesta = true;
    }
    if(aa == f.getAnio() && mm == f.getMes() && dd > f.getDia()){
      respuesta = true;
    }
  return respuesta;
}

bool Fecha :: operator<(Fecha f){
    bool respuesta = false;
    if(aa < f.getAnio()){
      respuesta = true;
    }
    if(aa == f.getAnio() && mm < f.getMes()){
      respuesta = true;
    }
    if(aa == f.getAnio() && mm == f.getMes() && dd < f.getDia()){
      respuesta = true;
    }
  return respuesta;
}


bool Fecha :: operator==(Fecha f){
  if(aa == f.getAnio() && mm == f.getMes() && dd == f.getDia()){
    return true;
  }
  else{
    return false;
  }
}

//serviran para utilizar objetos de tipo Fecha con cin y cout
ostream &operator << (ostream &os, Fecha f){
    os << f.dd << " / ";
    switch ( f.mm )
    {
        case  1 : os << "Enero" ;
                break;
        case  2 : os << "Feb";
                  break;
        case  3 : os <<  "Mar";
                  break;
        case  4 : os << "Abr";
                  break;
        case  5 : os << "May";
                  break;
        case  6 : os <<  "Jun";
                  break;
        case  7 : os << "Jul";
                  break;
        case  8 : os <<  "Ago";
                  break;
        case  9 : os <<  "Sept";
                  break;
        case 10 : os <<  "Oct";
                  break;
        case 11 : os <<  "Nov";
                  break;
        case 12 : os << "Dic";
                  break;
    }
    os << " / " << f.aa;
    return os;
  }


istream &operator >> (istream &os, Fecha &f){
  cout << "Escribe el dia:" << endl;
  os >> f.dd;
  cout << "Escribe el Mes: " << endl;
  os >> f.mm;
  cout << "Escribe el Año:" << endl;
  os >> f.aa;
  return os;
}


#include <iostream>
using namespace std;

#include "Fecha.h"

class Reserva
{
  public:
    //Constructores
    Reserva();
    Reserva(int, int, Fecha);
    //metodos de modificación
    void setFechaReservacion(Fecha f){fechaReservacion =f;};
    void setIdMaterial(int d){ idMaterial = d;};
    void setIdCliente(int d){ idCliente = d;};
    //metodos de acceso
    Fecha getFechaReservacion(){return fechaReservacion;};
    int getIdMaterial(){ return idMaterial; };
    int getIdCliente(){ return idCliente;};
    //metodos
    Fecha calculaFechaFinReserva(int);

  private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;

};

Reserva::Reserva(){
  idMaterial=0;
  idCliente=0;
  Fecha x(00,00,00);
  fechaReservacion = x;
}

Reserva::Reserva(int idM, int idC, Fecha fR){
  idMaterial=idM;
  idCliente=idC;
  fechaReservacion = fR;
}

Fecha Reserva::calculaFechaFinReserva(int x){
  //Fecha obj(dd,mm,aa);
  //dd= dd+x;
}
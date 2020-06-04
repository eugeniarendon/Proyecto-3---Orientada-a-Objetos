
//Eugenia Rendon Guajado
#include <iostream>
#include <fstream>
using namespace std;
#include "Reserva.h"
#include "Material.h"


int checarID(int idMaterial,Reserva ArregloReservaciones[]){
    for(int x=0;x<60;x++){
      if(ArregloReservaciones[x].getIdMaterial() == idMaterial){
        return x;
     }
    }
  return -1;
}

int encuentraPosicion(int idMaterial, Material *ArregloMateriales[]){
    for(int x=0;x<60;x++){
      if(ArregloMateriales[x]->getIdMaterial() == idMaterial){
        return x;
     }
    }
  return -1;
}


int main() {
  //Arreglos importantes
  Reserva ArregloReservaciones[60];
  Material *ArregloMateriales[30];
  Libro ArregloLibros[30];
  Disco ArregloDiscos[30];
  Software ArregloSoftwares[30];
  Fecha Fechas[60];

  //Variables
  int idMaterial,numPag,duracion,version, idCliente,cont2=1;
  char clave;
  string titulo,autor,genero,so;
  
  //Hacer carga de archivos de Material 
  ifstream archivoEntrada;
  archivoEntrada.open("Material.txt");
  int a=0,libro=0,disco=0,software=0;
  while(archivoEntrada>>idMaterial>>titulo>>clave){ 
    //Libro
   if(clave == 'L'){
        archivoEntrada>>numPag>>autor;
        ArregloLibros[libro].setIdMaterial(idMaterial);
        ArregloLibros[libro].setTitulo(titulo);
        ArregloLibros[libro].setNumPag(numPag);
        ArregloLibros[libro].setAutor(autor); 
        //aquí se utilizan apuntadores y se le da la dirección del arreglo de su tipo de material
        ArregloMateriales[a] = &ArregloLibros[libro];
        libro++;
    }

    //Disco
    if(clave == 'D'){
        archivoEntrada>>duracion>>genero;
        ArregloDiscos[disco].setIdMaterial(idMaterial);
        ArregloDiscos[disco].setTitulo(titulo);
        ArregloDiscos[disco].setDuracion(duracion);
        ArregloDiscos[disco].setGenero(genero);
        ArregloMateriales[a] = &ArregloDiscos[disco];
        disco++;
      }
  
    //Software
    if(clave == 'S'){   
        archivoEntrada>>version>>so;
        ArregloSoftwares[software].setIdMaterial(idMaterial);
        ArregloSoftwares[software].setTitulo(titulo);
        ArregloSoftwares[software].setVersion(version);
        ArregloSoftwares[software].setSO(so);
        ArregloMateriales[a] = &ArregloSoftwares[software];
        software++;
    }
    a++;
  }
  archivoEntrada.close();

//Hacer carga archivo Reserva
  ifstream archivoEntrada2;
  archivoEntrada2.open("Reserva.txt");
  int b=0,dd,mm,aa,pos;
  Fecha f[30];
  while(archivoEntrada2>>dd>>mm>>aa>>idMaterial>>idCliente)
  { f[b].setFecha(dd,mm,aa);
    ArregloReservaciones[b].setFechaReservacion(f[b]);
    ArregloReservaciones[b].setIdMaterial(idMaterial);
    ArregloReservaciones[b].setIdCliente(idCliente);
    //Nuevo arreglo c fechas finales
    pos = encuentraPosicion(idMaterial, ArregloMateriales);
    Fechas[b]=ArregloReservaciones[b].calculaFechaFinReserva(ArregloMateriales[pos]->cantidadDiasPrestamo());
    //cout << Fechas[b] << " " << b << endl;     
    b++;
  }
archivoEntrada2.close();

 /*for(int x;x<b;x++){
  cout << ArregloReservaciones[x].getFechaReservacion() << "      ";
  pos = encuentraPosicion(ArregloReservaciones[x].getIdMaterial(), ArregloMateriales);
  Fechas[x]=ArregloReservaciones[x].calculaFechaFinReserva(ArregloMateriales[pos]->cantidadDiasPrestamo());
  cout << Fechas[x] << endl;
}*/

//MENU
int opcion;

cout << "Sistema de Prestamo de Libros, Discos y Softwares de la Biblioteca" << endl;

do{
cout << " " << endl;
cout << "                            MENU " << endl;
cout << "-----------------------------------------------------------" << endl;
cout << "1. Consultar la lista de Materiales" << endl;
cout << "2. Consultar la lista de reservaciones" << endl;
cout << "3. Consultar las reservaciones de un material especifico" << endl;
cout << "4. Consultar las reservaciones de una fecha especifica" << endl;
cout << "5. Hacer una reservación" << endl;
cout << "6. Terminar" << endl;
cout << "Digite una opcion:"<< endl;
cin>> opcion;

  switch(opcion){
    case 1:
   {//Consultar la lista de Materiales
      cout << "Lista de Materiales" << endl;
      for(int i=0;i<a;i++){
        cout<<"[ #"<<i+1<<" ]"<< endl;
        ArregloMateriales[i]->muestraDatos();
        cout << " " << endl;
      }
    }
    break;

    case 2:
   {//Consultar la lista de reservaciones
      cout << "Lista de Reseraciones" << endl;
      for(int i=0;i<b;i++){
        cout<<"[ #"<<i+1<<" ]" << endl;
        cout << " ID Cliente: " << ArregloReservaciones[i].getIdCliente()<< endl;
        cout << " ID Material:" << ArregloReservaciones[i].getIdMaterial() << endl;
        cout << " Fecha de Reservación: " << ArregloReservaciones[i].getFechaReservacion() << endl;
        cout << " " << endl;
      }
    }
    break;

    case 3:
    {//Consultar las reservaciones de un material 
        int d,e;
        string titulo3;
        do{
          cout << "Inserta el ID del material que desea consultar: ";
          cin>> idMaterial;
          d=checarID(idMaterial, ArregloReservaciones);
          if(d>=0){
            e=encuentraPosicion(ArregloReservaciones[d].getIdMaterial(), ArregloMateriales);
            cout << " " << endl;
            cout << "El titulo del Material es: " << ArregloMateriales[e]->getTitulo() << endl;
            cout << "La fecha de reservacion inicial es: " << ArregloReservaciones[d].getFechaReservacion() << endl;
            cout << "La fecha final de regreso: " << Fechas[d].getDia() << " / " << Fechas[d].nombreMes() << " / " << Fechas[d].getAnio() << endl;
           }
          else{
          cout << "La clave no existe porfavor intente denuevo" << endl;
          }
      }while(d<0);
    }
    break;

    case 4:
    {//Consultar las reservaciones de una fecha dada
    int d,m,a;
    char r;
    do{
      do{
        cout << "Ingrese el dia:" << endl;
        cin >> d;
      }while(d<0 || d>31);
      do{
         cout << "Ingrese el mes:" << endl;
         cin >> m;
      }while(m<0 || m>12);
      do{
         cout << "Ingrese el año:" << endl;
         cin >> a;
      }while(a<1980 || a>2020);      
      Fecha case4(d,m,a);
      int cont=0;
      for(int z;z<b;z++){
        int cont=0;
        if((case4 <= Fechas[z])){
          int g=encuentraPosicion(ArregloReservaciones[z].getIdMaterial(), ArregloMateriales);
          cout << ArregloMateriales[g]->getTitulo() << " NO esta disponible" << endl;
          cout << "Id Cliente: " << ArregloReservaciones[z].getIdCliente() << endl;
        }
        else{
        cont++;
        if(cont>=b){
            cout << "Todo el material esta disponible" << endl;
          }
        }
      } 
    cout << "Desea checar otra fecha?" << endl;
    cin>> r;
    }while(r == tolower('s'));
    }
    break;

    case 5:
    {//Hacer una reservación
    int d,m,a,r,t;
      do{
        cout << "Escriba la fecha del dia de hoy dd-mm-año:" << endl;
        cin>>d>>m>>a;
      }while((d<0 || d>31) && (m<0 || 12<m) && (a<1980 || 2021<a));
      do{
        cout<< "Escriba el ID del Cliente" << endl;
        cin>> idCliente;
        cout << "Escriba el ID del Material" << endl;
        cin>>idMaterial;
        t=encuentraPosicion(idMaterial, ArregloMateriales);
        if(t==-1){
          cout << "El id del Material no existe." << endl;
        }
      }while(t<0);
      r=checarID(idMaterial, ArregloReservaciones);
      Fecha reserva(d,m,a);
      //Si existe en arreglo reservaciones
      if(r>0){
        if(reserva <= Fechas[r]){
          int g=encuentraPosicion(ArregloReservaciones[r].getIdMaterial(), ArregloMateriales);
          cout << ArregloMateriales[g]->getTitulo() << " NO esta disponible" << endl;
        }
        else if(reserva > Fechas[r]){
          int g=encuentraPosicion(ArregloReservaciones[r].getIdMaterial(), ArregloMateriales);
          cout << ArregloMateriales[g]->getTitulo() << " esta disponible." << "Há sido reservado." << endl;
          //Set info en Arreglo Reservaciones
          ArregloReservaciones[b+cont2].setFechaReservacion(reserva);
          ArregloReservaciones[b+cont2].setIdMaterial(idMaterial);
          ArregloReservaciones[b+cont2].setIdCliente(idCliente);
           cont2++;
        }
      }
      //Si NO existe en arreglo reservaciones
      if(r<0){
        cout << ArregloMateriales[t]->getTitulo() << " esta disponible." << endl;
        cout << "Há sido reservado." << endl;
        ArregloReservaciones[b+cont2].setFechaReservacion(reserva);
        ArregloReservaciones[b+cont2].setIdMaterial(idMaterial);
        ArregloReservaciones[b+cont2].setIdCliente(idCliente);
        cont2++;
      }
    }
    break;
    
    case 6:
    {//actualizar la información del archivo
       /*ofstream archivo;
       archivo.open("Reserva.txt");
        for(int a=0; a < cont2; a++){
          archivo >>  ArregloReservaciones[b+a].getFechaReservacion() >> " " >> ArregloReservaciones[b+a].getIdMaterial()>> " " >> ArregloReservaciones[b+a].setIdCliente(idCliente) >> endl;
           }
        cout << " El archivo ha sido actualizado." << endl;*/
     }
    break;

    default:{
     if(opcion <0 || opcion >6){
       cout << "Esta opcion no es valida!"<< endl;
      }
    }
  }

}while(opcion!=7);


}




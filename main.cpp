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

int main() {
  //Arreglos importantes
  Reserva ArregloReservaciones[60];
  Material *ArregloMateriales[30];
  Libro ArregloLibros[30];
  Disco ArregloDiscos[30];
  Software ArregloSoftwares[30];
  Fecha Fechas[60];

  //Variables
  int idMaterial,numPag,duracion,version, idCliente;
  char clave;
  string titulo,autor,genero,so;

  //Hacer carga de archivos de Material 
  ifstream archivoEntrada;
  archivoEntrada.open("Material.txt");
  int a=0,libro=0,disco=0,software=0;
  while(archivoEntrada>>idMaterial){ 
    archivoEntrada>>titulo;
    archivoEntrada>>clave;
    cout << clave;
    cout << "hola";
    //Libro
    if(clave == 'L'){
        archivoEntrada>>numPag>>autor;
        ArregloLibros[libro].setIdMaterial(idMaterial);
        ArregloLibros[libro].setTitulo(titulo);
        ArregloLibros[libro].setNumPag(numPag);
        ArregloLibros[libro].setAutor(autor); 
        libro++;
        cout << "hola";
    }

    //Disco
    if(clave == 'D'){
        archivoEntrada>>duracion>>genero;
        ArregloDiscos[disco].setIdMaterial(idMaterial);
        ArregloDiscos[disco].setTitulo(titulo);
        ArregloDiscos[disco].setDuracion(duracion);
        ArregloDiscos[disco].setGenero(genero);
        //aquí se utilizan apuntadores y se le da la dirección del arreglo de su tipo de material
        ArregloMateriales[a] = &ArregloDiscos[disco];
        //ArregloMateriales[a]->muestraDatos();
        disco++;
        cout << "hola";
      }

    //Software
    if(clave == 'S'){
        archivoEntrada>>version>>so;
        ArregloSoftwares[software].setIdMaterial(idMaterial);
        ArregloSoftwares[software].setTitulo(titulo);
        ArregloSoftwares[software].setVersion(version);
        ArregloSoftwares[software].setSO(so);
        ArregloMateriales[a] = &ArregloDiscos[software];
        software++;

        cout << "hola";
     }
    a++;
  }
  archivoEntrada.close();

 //ArregloMateriales[1]->getTitulo();

//ArregloMateriales[0]->muestraDatos();

//Carga de datos del arreglo de Reservaciones 
  ifstream archivoEntrada2;
  archivoEntrada2.open("Reserva.txt");
  int b=0,dd,mm,aa;
  while(archivoEntrada2>>dd>>mm>>aa>>idMaterial>>idCliente)
  { 
    Fechas[b].setFecha(dd,mm,aa);
    ArregloReservaciones[b].setFechaReservacion(Fechas[b]);
    ArregloReservaciones[b].setIdMaterial(idMaterial);
    ArregloReservaciones[b].setIdCliente(idCliente);
    b++;
  }
  archivoEntrada2.close();

//MENU
int opcion;

cout << "Sistema de Prestamo de Libros, Discos y Softwares de la Biblioteca" << endl;

//do{
cout << "MENU " << endl;
cout << "1. Consultar la lista de Materiales" << endl;
cout << "2. Consultar la lista de reservaciones" << endl;
cout << "3. Consultar las reservaciones de un material especifico" << endl;
cout << "4. Consultar las reservaciones de una fecha especifica" << endl;
cout << "5.  Hacer una reservación" << endl;
cout << "6. Terminar" << endl;
cout << "Digite una opcion:"<< endl;
cin>> opcion;

  switch(opcion){
    case 1:
   {//Consultar la lista de Materiales
      cout << "Lista de Materiales" << endl;
      for(int i=0;i<a;i++){
        cout<<"#"<<i<<" ";
        ArregloMateriales[i]->muestraDatos();
      }
    }
    break;

    case 2:
   {//Consultar la lista de reservaciones
      cout << "Lista de Reseraciones" << endl;
      for(int i=0;i<b;i++){
        cout<<"[#"<<i<<"]" << endl;
        cout << "ID Cliente: " << ArregloReservaciones[i].getIdCliente()<< endl;
        cout << " ID Material:" << ArregloReservaciones[i].getIdMaterial() << endl;
        cout << " Fecha de Reservación: " << ArregloReservaciones[i].getFechaReservacion() << endl;
        cout << " " << endl;
      }
    }
    break;

    case 3:
    {//Consultar las reservaciones de un material dadoque muestre para cada reservación el nombre del material, su fecha de inicio de reservación y su fecha de terminación.
      //do{
      int d;
      cout << " Inserta el ID del material que desea consultar" << endl;
      cin>> idMaterial;
      d=checarID(idMaterial, ArregloReservaciones);
      cout << "La fecha de reservacion inicial es: " << ArregloReservaciones[d].getFechaReservacion();

    //}while(<0)
    }

    case 4:
    {//Consultar las reservaciones de una fecha dada


    }


//}while(opcion!=7);


}

}
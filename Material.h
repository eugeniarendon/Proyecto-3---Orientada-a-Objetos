#include <iostream>
using namespace std;

class Material
{
  public:
    Material();
    Material(int idm, string t);
    void setIdMaterial(int id) {idMaterial = id;};
    void setTitulo(string t) { titulo = t;};
    int getIdMaterial(){return idMaterial;};
    string getTitulo(){return titulo;};
    //metodos abstractos
    virtual void muestraDatos() = 0;
    virtual int cantidadDiasPrestamo() = 0;
  
  protected:
    int idMaterial;
    string titulo;
};

Material :: Material(){
  idMaterial = 0;
  titulo = "N/A";
}

Material :: Material(int idm, string t){
  idMaterial=idm;
  titulo=t;
}

//clase derivada de la clase Material = LIRBO

class Libro : public Material
{

  public:
    //constructores
    Libro();
    Libro(int numero, string a);
    //metodos acceso y modificación
    void setNumPag(int n) {numPag = n;};
    void setAutor(string t) { autor = t;};
    int getNumPag(){return numPag;};
    string getAutor(){return autor;};
    //metodos abstractos
    void muestraDatos();
	  int cantidadDiasPrestamo();

  protected:
    int numPag;
    string autor;
};

Libro :: Libro(){
  numPag = 0;
  autor = "N/A";
}

Libro :: Libro(int numero, string t){
  numPag=numero;
  autor=t;
}

void Libro::muestraDatos()
{
  cout << "Tipo de Material : Libro" << endl;
  cout << "Id Libro: " << idMaterial << endl;
  cout << "Titulo del Libro: " << titulo << endl;
  cout << "Numero de Paginas: " << numPag << endl;
  cout << "Nombre del Autor: " << autor << endl;
}

int Libro::cantidadDiasPrestamo(){
  //cout << "Cantidad de Dias de Prestamo" << 7 << endl;
  return 7;
}

//clase derivada de la clase Material = DISCO
class Disco : public Material
{

  public:
    //constructores
    Disco();
    Disco(int , string );
    //metodos acceso y modificación
    void setDuracion(int n) {duracion = n;};
    void setGenero(string t) { genero = t;};
    int getDuracion(){return duracion;};
    string getGenero(){return genero;};
    //metodos abstractos
    void muestraDatos();
	  int cantidadDiasPrestamo();

  protected:
    int duracion;
    string genero;
};

Disco :: Disco(){
  duracion = 0;
  genero = "N/A";
}

Disco :: Disco(int x, string y){
  duracion = x;
  genero = y;
}

void Disco::muestraDatos()
{
  cout << "Tipo de Material : Disco" << endl;
  cout << "Id Disco: " << idMaterial << endl;
  cout << "Titulo del Disco: " << titulo << endl;
  cout << "Duración del Disco: " << duracion << endl;
  cout << "Genero : " << genero << endl;
}

int Disco::cantidadDiasPrestamo(){
  //cout << "Cantidad de Dias de Prestamo" << 7 << endl;
  return 2;
}

//clase derivada de la clase Material = DISCO
class Software : public Material
{

  public:
    //constructores
    Software();
    Software(int x, string y);
    //metodos acceso y modificación
    void setVersion(int n) {version = n;};
    void setSO(string t) { so = t;};
    int getVersion(){return version;};
    string getSO(){return so;};
    //metodos abstractos
    void muestraDatos();
	  int cantidadDiasPrestamo();

  protected:
    int version;
    string so;
};

Software :: Software(){
  version = 0;
  so = "N/A";
}

Software :: Software(int x, string y){
  version = x;
  so = y;
}

void Software::muestraDatos()
{
  cout << "Tipo de Material : Software" << endl;
  cout << "Id Software: " << idMaterial << endl;
  cout << "Titulo del Software: " << titulo << endl;
  cout << "Versión: " << version << endl;
  cout << "SO : " << so << endl;
}

int Software::cantidadDiasPrestamo(){
  //cout << "Cantidad de Dias de Prestamo" << 7 << endl;
  return 1;
}
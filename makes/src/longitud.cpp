/* Módulo que calcula la longitud de un trayecto entre puntos.*/

#include <iostream>
#include <fstream>
#include "punto.h"
using namespace std;

const char COM = '#'; // Comienzo de comentario.

// Avanza hasta la siguiente linea con puntos.
void Avanzar(istream& is)
{
  while (isspace(is.peek()) || is.peek() == COM) {
    if (is.peek() == COM)
      is.ignore(1024,'\n');
    else
      is.ignore();
  }
}

// Lee puntos de un flujo dado y devuelve la distancia del trayecto que forman.
double Longitud(istream& is)
{
  double l = 0;
  Punto p1, p2;

  Avanzar(is);
  Leer(is, p1);
  Avanzar(is);

  while (Leer(is, p2)){
    l += Distancia(p1, p2);
    Avanzar(is);
    p1 = p2;
  }

  return l;
}

int main(int argc, char* argv[]){

  double longitud= 0;
  bool todo_correcto;
  if (argc==1) {
    longitud = Longitud(cin);
    todo_correcto = cin.eof();
  }
  else {
    ifstream f(argv[1]);
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }
    longitud = Longitud(f);
    todo_correcto = f.eof();
  }

  if (!todo_correcto) {
     cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     return 1;
  }

  cout << "Longitud del trayecto: " << longitud << endl;
}

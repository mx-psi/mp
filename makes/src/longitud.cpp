/* Módulo para el cálculo de la longitud de un trayecto dado por una serie de puntos.*/

#include <iostream>
#include <fstream>
#include "punto.h"
using namespace std;

const char COM = '#'; // Comienzo de comentario.

// Avanza hasta la siguiente línea legible.
void Avanzar(istream& is)
{
  while (isspace(is.peek()) || is.peek() == COM) {
    if (is.peek() == COM)
      is.ignore(1024,'\n');
    else
      is.ignore();
  }
}

// Lee puntos desde un flujo dado y calcula la longitud del trayecto.
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

  double longitud = 0;
  bool fin_entrada;

  if (argc==1) {
    // Si sólo hay un argumento se lee de la entrada estandar.
    longitud = Longitud(cin);
    fin_entrada = cin.eof();
  }
  else {
    // En otro caso se toma el primer argumento como nombre del archivo a leer.
    ifstream f(argv[1]);
    if (!f) {
      cerr << "Error: no se abre " << argv[1] << endl;
      return 1;
    }
    longitud = Longitud(f);
    fin_entrada = f.eof();
  }

  if (!fin_entrada) {
     cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     return 1;
  }

  cout << "Longitud del trayecto: " << longitud << endl;
}

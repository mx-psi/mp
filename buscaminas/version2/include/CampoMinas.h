#ifndef _CAMPOMINAS_H_
#define _CAMPOMINAS_H_

#include <cstdlib>
#include <ctime>
#include <iomanip>  // setw
#include <fstream>
#include <cstring>
#include <assert.h>
#include "Tablero.h" // iostream
using namespace std;

/* Cabeceras de las funciones del módulo CampoMinas.cpp */

class CampoMinas{
  Tablero tab;
  bool explotado;

  bool CoordCorrectas(int x, int y) const;
  bool HayBomba(int x, int y) const;
  int NumeroBombas(int x, int y) const;

public:
  CampoMinas(int filas, int columnas, int minas)
  :tab(filas, columnas)
  {
    int minas_puestas = 0;
    srand (time(0));
    int aleatorio;
    Casilla con_bomba;
    con_bomba.bomba = true;

    while (minas_puestas < minas)
    {
      aleatorio = rand()%(filas*columnas);
      int fila = aleatorio/columnas;
      int columna = aleatorio%columnas;
      if (!tab(fila, columna).bomba)
      {
        tab(fila,  columna) =  con_bomba;
        minas_puestas++;
      }
    }
  }

  // Constructor para lectura de archivo
  CampoMinas(const Tablero& t):tab(t) {}

  inline int Filas() const {return tab.Filas();}
  inline int Columnas() const {return tab.Columnas();}
  inline bool Explotado() const {return explotado;}
  bool Ganado() const;
  bool Marca(int x, int y);
  bool Abre(int x, int y);
  void PrettyPrint(ostream& os = std::cout) const;
  void ImprimeTablero(ostream& os = std::cout) const;


  // Lectura desde archivo
  bool Leer(const char* nombre);
  // Escritura a archivo
  bool Escribir(const char* nombre);
 };

#endif

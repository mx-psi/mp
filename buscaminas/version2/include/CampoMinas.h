#ifndef _CAMPOMINAS_H_
#define _CAMPOMINAS_H_

#include <cstdlib>   // atoi, rand, srand
#include <iomanip>   // setw
#include <fstream>   // ifstream, ofstream
#include <cstring>   // strcmp
#include <assert.h>  // assert
#include "Tablero.h" // iostream
using namespace std;

/* Cabeceras de las funciones del módulo CampoMinas.cpp */

class CampoMinas{
  Tablero tab;
  bool explotado;

  // Devuelve si las coordenadas son correctas
  bool CoordCorrectas(int x, int y) const;

  // Devuelve si hay una bomba en la coordenada dada
  bool HayBomba(int x, int y) const;

  // Devuelve el número de bombas en casillas adyacentes
  int NumeroBombas(int x, int y) const;

public:
  CampoMinas(int filas, int columnas, int minas)
  :tab(filas, columnas),explotado(false)
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

  // Constructor por defecto
  CampoMinas():tab(0,0),explotado(false){}

  // Operador de asignación
  CampoMinas& operator=(const CampoMinas& c)
  {
    if (&c != this)
    {
      tab = c.tab;
      explotado = c.explotado;
    }

    return *this;
  }

  /* Obtención de estado */
  // Devuelve el número de filas del campo
  inline int Filas() const {return tab.Filas();}

  // Devuelve el número de columnas del campo
  inline int Columnas() const {return tab.Columnas();}

  // Indica si ha explotado
  inline bool Explotado() const {return explotado;}

  // Indica si se ha ganado la partida
  bool Ganado() const;

  /* Cambiar el estado */
  // Marca o desmarca una casilla cerrada. Devuelve éxito
  bool Marca(int x, int y);

  // Obtiene una lista de casillas a abrir y las abre
  bool Abre(int x, int y);

  /* Impresión */
  // Imprime el estado actual del tablero
  void PrettyPrint(ostream& os = std::cout) const;

  // Imprime el estado final del tablero
  void ImprimeTablero(ostream& os = std::cout) const;

  /* E/S */
  // Lectura desde archivo
  bool Leer(const char* nombre);
  // Escritura a archivo
  bool Escribir(const char* nombre);
 };

#endif

#include <cstdlib>   // rand, srand
#include <iostream>  // cin, cout, endl
#include <iomanip>   // setw
#include <assert.h>  // assert
#include "Tablero.h" // Casilla y Tablero

/* Cabeceras de las funciones del módulo CampoMinas.cpp */


class CampoMinas{
  Tablero tab;

  // Devuelve si las coordenadas son correctas
  bool CoordCorrectas(int x, int y) const;
  // Devuelve si hay una bomba en la coordenada dada
  bool HayBomba(int x, int y) const;
  // Devuelve el número de bombas en casillas adyacentes
  int NumeroBombas(int x, int y) const;


public:

  // Constructor dadas filas, columnas y minas
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
      if (!tab.Get(fila, columna).bomba)
      {
        tab.Set(fila, columna, con_bomba);
        minas_puestas++;
      }
    }
  }

  // Devuelve el número de filas del campo
  inline int Filas() const {return tab.Filas();}
  // Devuelve el número de columnas del campo
  inline int Columnas() const {return tab.Columnas();}

  // Comprueba si alguna mina ha explotado
  bool Explotado() const;
  // Indica si se ha ganado la partida
  bool Ganado() const;

  // Marca o desmarca una casilla cerrada. Devuelve éxito
  bool Marca(int x, int y);
  // Abre una casilla y comprueba apertura del resto
  bool Abre(int x, int y);

  // Imprime el estado actual del tablero
  void PrettyPrint() const;
  // Imprime el estado final del tablero
  void ImprimeTablero() const;
};

/* Cabeceras de las funciones del módulo CampoMinas.cpp */

#include <cstdlib>
#include <ctime>
#include <iostream> // cin, cout
#include <iomanip>  // setw
#include <assert.h>

#include "Tablero.h"


class CampoMinas{
  Tablero tab;

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
      if (!tab.Get(fila, columna).bomba)
      {
        tab.Set(fila, columna, con_bomba);
        minas_puestas++;
      }
    }
  }

  inline int Filas() const ;
  inline int Columnas() const ;

  bool Explotado() const;
  bool Ganado() const;
  bool Marca(int x, int y);

  bool Abre(int x, int y);
  void PrettyPrint() const;
  void ImprimeTablero() const;
};

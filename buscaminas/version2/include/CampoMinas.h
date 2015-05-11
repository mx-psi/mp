#include "Tablero.h"
#include <cstdlib>
#include <ctime>
#include <iostream> // cin, os
#include <iomanip>  // setw
#include <assert.h>
#include "CampoMinas.h" // Tablero.h

/* Cabeceras de las funciones del módulo CampoMinas.cpp */

class CampoMinas{
  Tablero tab;
  bool explotado;

  bool CoordCorrectas(int x, int y) const
  {
    /* Devuelve si las coordenadas son correctas. */
    return x < tab.Filas() && y < tab.Columnas() && x >= 0 && y >= 0;
  }

  bool HayBomba(int x, int y) const
  {
    /* Devuelve si hay una bomba en la coordenada dada. */
    return CoordCorrectas(x, y) && tab.Get(x, y).bomba;
  }

  int NumeroBombas(int x, int y) const
  {
    /* Devuelve el número de bombas en casillas adyacentes. */
    int n = 0;
    for(int i = -1; i <= 1; i++)
      for(int j = -1; j <= 1; j++)
        n += (i != 0 || j != 0) && HayBomba(x + i, y + j);
    return n;
  }

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

  inline int Filas() const {return tab.Filas();}
  inline int Columnas() const {return tab.Columnas();}
  inline bool Explotado() const {return explotado;}

  bool Ganado() const
  {
    /* Indica si se ha ganado la partida. */
    for(int i = 0; i < Filas(); i++)
      for(int j = 0; j < Columnas(); j++)
        if(!tab.Get(i,j).bomba && !tab.Get(i,j).abierta)
          return false;

    return true;
  }

  bool Marca(int x, int y)
  {
    /* Marca o desmarca una casilla cerrada. Devuelve éxito. */
    assert(CoordCorrectas(x, y));

    if(tab.Get(x,y).abierta)
      return false;

    Casilla nueva = tab.Get(x,y);
    nueva.marcada = !nueva.marcada;
    tab.Set(x,y,nueva);
    return true;
  }

  bool Abre(int x, int y){
    /* Abre una casilla y comprueba apertura del resto */

    if (!CoordCorrectas(x, y))
      return false;

    Casilla cas = tab.Get(x, y);

    // Comprueba si está marcada o abierta
    if(cas.marcada || cas.abierta)
      return false;

    cas.abierta = true;
    explotado  |= cas.bomba
    tab.Set(x, y, cas);

    // Comprueba si tiene bombas alrededor
    int n = NumeroBombas(x, y);
    if(cas.bomba || n != 0)
      return true;

    // Abre las casillas adyacentes
    for(int i = -1; i <= 1; i++)
      for(int j = -1; j <= 1; j++)
        if(i != 0 || j != 0)
          Abre(x + i, y + j);

    return true;
  }

  void PrettyPrint(ostream& os = std::cout) const
  {
    /* Imprime el estado actual del tablero. */

    // Columnas
    os << ' ';
    for(int i = 0; i < Columnas(); i++)
      os << setw(3) << i;
    os << std::endl;

    // Linea
    for(int i = 0; i < Columnas(); i++)
      os << "----";

    // Tablero
    for(int i = 0; i < Filas(); i++)
    {
      os << std::endl << " " << i << "|";
      for(int j = 0; j < Columnas(); j++)
      {
        Casilla actual = tab.Get(i,j);
        if(actual.marcada)
          os << " ?|";
        else if(!actual.abierta)
          os << " *|";
        else{
          int n = NumeroBombas(i, j);
          if(n == 0)
            os << "  |";
          else
            os << n << " |";
        }
      }
    }

    // Linea
    os << std::endl;
    for(int i = 0; i < Columnas(); i++)
      os << "----";
    os << std::endl;
  }

  void ImprimeTablero(ostream& os = std::cout) const
  {
    /* Imprime el estado final del tablero. */

    if(!Ganado() && !Explotado())
      os << "No hagas trampa.";
    else
    {
      // Columnas
      os << ' ';
      for(int i = 0; i < Filas(); i++)
        os << setw(3) << i;
      os << std::endl;

      // Linea
      for(int i = 0; i < Filas(); i++)
        os << "----";

      // Tablero
      for(int i = 0; i < Filas(); i++)
      {
        os << std::endl << i << " |";
        for(int j = 0; j < Columnas(); j++)
        {
          Casilla actual = tab.Get(i,j);
          if(actual.bomba)
            os << " X|";
          else{
            int n = NumeroBombas(i, j);
            if(n == 0)
              os << "  |";
            else
              os << n << " |";
          }
        }
      }

      // Linea
      os << std::endl;
      for(int i = 0; i < Filas(); i++)
        os << "----";
      os << std::endl;
    }
  }
};

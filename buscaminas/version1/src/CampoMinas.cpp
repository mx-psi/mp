#include "tablero.h"
using namespace std;

class CampoMinas
{
  Tablero tab;

public:
  CampoMinas(int filas, int columnas, int minas):tab(filas, columnas){}

  int Filas() {return tab.Filas();}
  int Columnas() {return tab.Columnas();}

  bool Explotado()
  {
    /* Comprueba si alguna mina ha explotado. */
    for(int i = 0; i < Filas(); i++)
      for(int j = 0; j < Columnas(); j++)
        if(tab.Get(i,j).bomba && tab.Get(i,j).abierta)
          return true;

    return false;
  }

  bool Ganado()
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

    if(tab.Get(x,y).abierta) || x > tab.Filas()
      || y > Tab.Columnas() || x < 0 || y < 0)
      return false;

    Casilla nueva = tab.Get(x,y);
    nueva.marcada = !nueva.marcada;
    tab.Set(x,y,nueva);
  }
};

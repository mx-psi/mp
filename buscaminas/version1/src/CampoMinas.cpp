#include "tablero.h"

CampoMinas::CampoMinas(int filas, int columnas, int minas):tab(filas, columnas){}

int CampoMinas::Filas() const {return tab.Filas();}
int CampoMinas::Columnas() const {return tab.Columnas();}

bool CampoMinas::Explotado() const
{
  /* Comprueba si alguna mina ha explotado. */
  for(int i = 0; i < Filas(); i++)
    for(int j = 0; j < Columnas(); j++)
      if(tab.Get(i,j).bomba && tab.Get(i,j).abierta)
        return true;

  return false;
}

bool CampoMinas::Ganado() const
{
  /* Indica si se ha ganado la partida. */
  for(int i = 0; i < Filas(); i++)
    for(int j = 0; j < Columnas(); j++)
      if(!tab.Get(i,j).bomba && !tab.Get(i,j).abierta)
        return false;

  return true;
}

bool CampoMinas::Marca(int x, int y)
{
  /* Marca o desmarca una casilla cerrada. Devuelve éxito. */

  if(tab.Get(x,y).abierta) || x > tab.Filas()
    || y > Tab.Columnas() || x < 0 || y < 0)
    return false;

  Casilla nueva = tab.Get(x,y);
  nueva.marcada = !nueva.marcada;
  tab.Set(x,y,nueva);
}

void CampoMinas::PrettyPrint() const
{
  /* Imprime el estado actual del tablero. */
}

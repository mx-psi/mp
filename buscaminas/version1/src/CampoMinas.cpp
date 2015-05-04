#include "Tablero.h"
using namespace std;

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
  // TODO: Assert?
  if(tab.Get(x,y).abierta) && CoordCorrectas(x,y))
    return false;

  Casilla nueva = tab.Get(x,y);
  nueva.marcada = !nueva.marcada;
  tab.Set(x,y,nueva);
  return true;
}

bool CampoMinas::CoordCorrectas(int x, int y)
{
  /* Devuelve si las coordenadas son correctas. */
  return x <= tab.Filas() && y <= Tab.Columnas() && x >= 0 && y >= 0;
}

bool CampoMinas::HayBomba(int x, int y)
{
  /* Devuelve si hay una bomba en la coordenada dada. */
  return CoordCorrectas(x, y) && tab.Get(x, y).bomba;
}

int CampoMinas::NumeroBombas(int x, int y)
{
  /* Devuelve el número de bombas en casillas adyacentes. */
  int n = 0;
  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
      n += (i + j) != 0 && HayBomba(x + i, y + j);
  return n;
}

void CampoMinas::PrettyPrint()
{
  /* Imprime el estado actual del tablero. */

  // Columnas
  for(int i = 0; i < Filas(); i++)
    cout << setw(3) << i;
  cout << endl;

  // Linea
  for(int i = 0; i < Filas(); i++)
    cout << "----";

  // Tablero
  for(int i = 0; i < Filas(); i++)
  {
    cout << endl << i << " |";
    for(int j = 0; j < Columnas(); j++)
    {
      Casilla actual = tab.Get(i,j);
      if(!actual.abierta)
        cout << " *|";
      else if(actual.marcada)
        cout << " ?|";
      else{
        int n = NumeroBombas(i, j);
        if(n == 0)
          cout << "  |";
        else
          cout << n << " |";
      }
    }
  }

  // Linea
  cout << endl;
  for(int i = 0; i < Filas(); i++)
    cout << "----";
  cout << endl;
}

void CampoMinas::ImprimeTablero()
{
  /* Imprime el estado final del tablero. */

  if(!Ganado())
    cout << "No hagas trampa.";
  else
  {
    // Columnas
    for(int i = 0; i < Filas(); i++)
      cout << setw(3) << i;
    cout << endl;

    // Linea
    for(int i = 0; i < Filas(); i++)
      cout << "----";

    // Tablero
    for(int i = 0; i < Filas(); i++)
    {
      cout << endl << i << " |";
      for(int j = 0; j < Columnas(); j++)
      {
        Casilla actual = tab.Get(i,j);
        if(actual.bomba)
          cout << " X|";
        else{
          int n = NumeroBombas(i, j);
          if(n == 0)
            cout << "  |";
          else
            cout << n << " |";
        }
      }
    }

    // Linea
    for(int i = 0; i < Filas(); i++)
      cout << "----";
    cout << endl;
  }
}

#include "CampoMinas.h"
using namespace std;

/* Métodos de la clase CampoMinas */

// Devuelve si las coordenadas son correctas
bool CampoMinas::CoordCorrectas(int x, int y) const
{
  return x < tab.Filas() && y < tab.Columnas() && x >= 0 && y >= 0;
}

// Devuelve si hay una bomba en la coordenada dada
bool CampoMinas::HayBomba(int x, int y) const
{
  return CoordCorrectas(x, y) && tab.Get(x, y).bomba;
}

// Devuelve el número de bombas en casillas adyacentes
int CampoMinas::NumeroBombas(int x, int y) const
{
  int n = 0;
  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
      n += (i != 0 || j != 0) && HayBomba(x + i, y + j);
  return n;
}

// Comprueba si alguna mina ha explotado
bool CampoMinas::Explotado() const
{
  for(int i = 0; i < Filas(); i++)
    for(int j = 0; j < Columnas(); j++)
      if(tab.Get(i,j).bomba && tab.Get(i,j).abierta)
        return true;

  return false;
}

// Indica si se ha ganado la partida
bool CampoMinas::Ganado() const
{
  for(int i = 0; i < Filas(); i++)
    for(int j = 0; j < Columnas(); j++)
      if(!tab.Get(i,j).bomba && !tab.Get(i,j).abierta)
        return false;

  return true;
}

// Marca o desmarca una casilla cerrada. Devuelve éxito
bool CampoMinas::Marca(int x, int y)
{
  assert(CoordCorrectas(x, y));

  if(tab.Get(x,y).abierta)
    return false;

  Casilla nueva = tab.Get(x,y);
  nueva.marcada = !nueva.marcada;
  tab.Set(x,y,nueva);
  return true;
}

// Abre una casilla y comprueba apertura del resto
bool CampoMinas::Abre(int x, int y)
{
  if (!CoordCorrectas(x, y))
    return false;

  Casilla cas = tab.Get(x, y);

  // Comprueba si está marcada o abierta
  if(cas.marcada || cas.abierta)
    return false;

  cas.abierta = true;
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

// Imprime el estado actual del tablero
void CampoMinas::PrettyPrint() const
{
  // Columnas
  cout << ' ';
  if (Filas() > 10)
    cout << ' ';

  for(int i = 0; i < Columnas(); i++)
    cout << setw(3) << i;
  cout << endl;

  // Linea
  for(int i = 0; i <= Columnas(); i++)
    cout << "---";

  // Tablero
  for(int i = 0; i < Filas(); i++)
  {
    cout << endl;
    cout << setw(2) << i << "|";
    for(int j = 0; j < Columnas(); j++)
    {
      Casilla actual = tab.Get(i,j);
      if(actual.marcada)
        cout << " ?|";
      else if(!actual.abierta)
        cout << " *|";
      else{
        int n = NumeroBombas(i, j);
        if(n == 0)
          cout << "  |";
        else
          cout << " " << n << "|";
      }
    }
  }

  // Linea
  cout << endl;
  for(int i = 0; i <= Columnas(); i++)
    cout << "---";
  cout << endl;
}

// Imprime el estado final del tablero
void CampoMinas::ImprimeTablero() const
{
  if(!Ganado() && !Explotado())
    cout << "No hagas trampa.";
  else
  {
    // Columnas
    cout << ' ';
    if (Filas() > 10)
      cout << ' ';

    for(int i = 0; i < Filas(); i++)
      cout << setw(3) << i;
    cout << endl;

    // Linea
    for(int i = 0; i <= Columnas(); i++)
      cout << "---";

    // Tablero
    for(int i = 0; i < Filas(); i++)
    {
      cout << endl;
      cout << setw(2) << i << "|";
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
            cout << " " << n << "|";
        }
      }
    }

    // Linea
    cout << endl;
    for(int i = 0; i <= Columnas(); i++)
      cout << "---";
    cout << endl;
  }
}

#include <cstdlib>
#include <ctime>
#include "Tablero.h"
using namespace std;

CampoMinas::CampoMinas(int filas, int columnas, int minas)
:tab(filas, columnas)
{
  int minas_puestas = 0;
  srand (time(0));
  int aleatorio;

  while (minas_puestas < minas)
  {
    aleatorio = rand()%(filas*columnas);
    fila = aleatorio/columnas;
    columna = aleatorio%columnas;
    if (!tab.Get(fila, columna).bomba)
    {
      tab.Set(fila, columna, {true,false,false});
      minas_puestas++;
    }
  }
}
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

  assert(CoordCorrectas(x, y));
  Casilla cas = tab.Get(x, y);

  // Comprueba si está marcada o abierta
  if(cas.marcada || cas.abierta)
    return false;

  // Comprueba si tiene bombas alrededor
  int n = NumeroBombas(x, y);
  if(cas.bomba || n != 0)
    return true;

  // Abre las casillas adyacentes
  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
      if(i != 0 || j != 0)
        Abre(x + i, y + j);
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
      n += (i != 0 || j != 0) && HayBomba(x + i, y + j);
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

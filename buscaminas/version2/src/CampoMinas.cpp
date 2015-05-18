#include "CampoMinas.h"
using namespace std;

const char* CABECERA = "#MP-BUSCAMINAS-V1";   // Cabecera de archivo de partida

/* Cabeceras de las funciones del módulo CampoMinas.cpp */


bool CampoMinas::CoordCorrectas(int x, int y) const
{
  /* Devuelve si las coordenadas son correctas. */
  return x < tab.Filas() && y < tab.Columnas() && x >= 0 && y >= 0;
}

bool CampoMinas::HayBomba(int x, int y) const
{
  /* Devuelve si hay una bomba en la coordenada dada. */
  return CoordCorrectas(x, y) && tab(x, y).bomba;
}

int CampoMinas::NumeroBombas(int x, int y) const
{
  /* Devuelve el número de bombas en casillas adyacentes. */
  int n = 0;
  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
      n += (i != 0 || j != 0) && HayBomba(x + i, y + j);
  return n;
}

bool CampoMinas::Ganado() const
{
  /* Indica si se ha ganado la partida. */
  for(int i = 0; i < Filas(); i++)
    for(int j = 0; j < Columnas(); j++)
      if(!tab(i,j).bomba && !tab(i,j).abierta)
        return false;

  return true;
}

bool CampoMinas::Marca(int x, int y)
{
  /* Marca o desmarca una casilla cerrada. Devuelve éxito. */
  assert(CoordCorrectas(x, y));

  if(tab(x,y).abierta)
    return false;

  tab(x, y).marcada = !tab(x, y).marcada;
  return true;
}

/* TODO: Viejo Abre, quitar.
bool CampoMinas::Abre(int x, int y){

  if (!CoordCorrectas(x, y))
    return false;

  Casilla cas = tab.Get(x, y);

  // Comprueba si estÃ¡ marcada o abierta
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
}*/

bool CampoMinas::Abre(int x, int y){
  /* Obtiene una lista de casillas a abrir y las abre */
  if (!CoordCorrectas(x, y))
    return false;
  bool algun_cambio = false;
  struct CeldaPosicion
  {
    int fila, columna;
    CeldaPosicion* siguiente;
  };
  CeldaPosicion* pend = new CeldaPosicion;
  pend->fila = x;
  pend->columna = y;
  pend->siguiente = 0;
  while(pend != 0)
  {
    CeldaPosicion* pend_actual = pend;
    if (CoordCorrectas(pend->fila, pend->columna))
    {
      Casilla cas = tab(pend->fila, pend->columna);
      if (!cas.marcada && !cas.abierta)
      {
        algun_cambio = true;
        cas.abierta = true;
        explotado  |= cas.bomba;
        tab(pend->fila,  pend->columna) = cas;
        if (!cas.bomba && NumeroBombas(pend->fila, pend->columna) == 0)
          // Añade las casillas adyacentes
          for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
              if(i != 0 || j != 0)
              {
                CeldaPosicion* pend2 = new CeldaPosicion;
                pend2->fila = pend_actual->fila + i;
                pend2->columna = pend_actual->columna + j;
                pend2->siguiente = pend;
                pend = pend2;
              }
      }
    }
    CeldaPosicion* pend_aux = pend_actual->siguiente;
    delete pend_actual;
    pend_actual = pend_aux;
  }
  return algun_cambio;
}

void CampoMinas::PrettyPrint(ostream& os) const
{
  /* Imprime el estado actual del tablero. */

  // Columnas
  os << ' ';
  if (Filas() > 10)
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
    os << endl;
    if (i < 10 && Filas() > 10)
      os << ' ';

    os << i << "|";
    for(int j = 0; j < Columnas(); j++)
    {
      Casilla actual = tab(i,j);
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

void CampoMinas::ImprimeTablero(ostream& os) const
{
  /* Imprime el estado final del tablero. */

  if(!Ganado() && !Explotado())
    os << "No hagas trampa.";
  else
  {
    // Columnas
    os << ' ';
    if (Filas() > 10)
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
      os << endl;
      if (i < 10 && Filas() > 10)
        os << ' ';

      os << i << "|";
      for(int j = 0; j < Columnas(); j++)
      {
        Casilla actual = tab(i,j);
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

// Lectura desde archivo
bool CampoMinas::Leer(const char* nombre)
{
  ifstream f(nombre);
  if (!f)
    return false;

  char* cabecera = new char[17];
  f.getline(cabecera, 17);
  if (strcmp(cabecera, CABECERA))
    return false;

  return f >> tab;
}

// Escritura a archivo
bool CampoMinas::Escribir(const char* nombre)
{
  ofstream f(nombre);
  return f << CABECERA << '\n' << tab;
}

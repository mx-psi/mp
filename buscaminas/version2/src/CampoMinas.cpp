#include "CampoMinas.h"
using namespace std;
const char* CABECERA = "#MP-BUSCAMINAS-V1";     // Cabecera de archivo de partida
const int LONGITUD_CABECERA = strlen(CABECERA);

/* Métodos de la clase CampoMinas */

// Devuelve si las coordenadas son correctas
bool CampoMinas::CoordCorrectas(int x, int y) const
{
  return x < tab.Filas() && y < tab.Columnas() && x >= 0 && y >= 0;
}

// Devuelve si hay una bomba en la coordenada dada
bool CampoMinas::HayBomba(int x, int y) const
{
  return CoordCorrectas(x, y) && tab(x, y).bomba;
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

// Indica si se ha ganado la partida
bool CampoMinas::Ganado() const
{
  for(int i = 0; i < Filas(); i++)
    for(int j = 0; j < Columnas(); j++)
      if(!tab(i,j).bomba && !tab(i,j).abierta)
        return false;

  return true;
}

// Marca o desmarca una casilla cerrada. Devuelve éxito
bool CampoMinas::Marca(int x, int y)
{
  assert(CoordCorrectas(x, y));

  if(tab(x,y).abierta)
    return false;

  tab(x, y).marcada = !tab(x, y).marcada;
  return true;
}

// Obtiene una lista de casillas a abrir y las abre
bool CampoMinas::Abre(int x, int y){
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
                pend2->fila = (pend->fila + i);
                pend2->columna = (pend->columna + j);
                pend2->siguiente = pend->siguiente;
                pend->siguiente = pend2;
              }
      }
    }
    CeldaPosicion* pend_aux = pend->siguiente;
    delete pend;
    pend = pend_aux;
  }
  return algun_cambio;
}

// Imprime el estado actual del tablero
void CampoMinas::PrettyPrint(ostream& os) const
{
  // Columnas
  os << ' ';
  if (Filas() > 10)
    os << ' ';

  for(int i = 0; i < Columnas(); i++)
    os << setw(3) << i;
  os << endl;

  // Linea
  for(int i = 0; i <= Columnas(); i++)
    os << "---";

  // Tablero
  for(int i = 0; i < Filas(); i++)
  {
    os << endl;
    os << setw(2) << i << "|";

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
          os << " " << n << "|";
      }
    }
  }

  // Linea
  os << endl;
  for(int i = 0; i <= Columnas(); i++)
    os << "---";
  os << endl;
}

// Imprime el estado final del tablero
void CampoMinas::ImprimeTablero(ostream& os) const
{
  if(!Ganado() && !Explotado())
    os << "No hagas trampa.";
  else
  {
    // Columnas
    os << ' ';
    if (Filas() > 10)
      os << ' ';

    for(int i = 0; i < Columnas(); i++)
      os << setw(3) << i;
    os << endl;

    // Linea
    for(int i = 0; i <= Columnas(); i++)
      os << "---";

    // Tablero
    for(int i = 0; i < Filas(); i++)
    {
      os << endl;
      os << setw(2) << i << "|";
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
            os << " " << n << "|";
        }
      }
    }

    // Linea
    os << endl;
    for(int i = 0; i <= Columnas(); i++)
      os << "---";
    os << endl;
  }
}

// Lectura desde archivo
bool CampoMinas::Leer(const char* nombre)
{
  ifstream f(nombre);
  if (!f)
    return false;

  char* cabecera = new char[LONGITUD_CABECERA];
  f.getline(cabecera, LONGITUD_CABECERA+1);
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

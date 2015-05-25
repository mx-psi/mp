#include "Tablero.h"
using namespace std;

// OBSOLETA: Obtiene la estructura de una casilla
// Prec: fila <= 0 < filas, columna <= 0 < columnas
Casilla Tablero::Get(int fila, int columna) const
{
  return datos[Columnas()*fila+columna];
}

// OBSOLETA: Fija la estructura de una casilla
// Prec: fila <= 0 < filas, columna <= 0 < columnas
void Tablero::Set(int fila, int columna, const Casilla &c)
{
  datos[Columnas()*fila+columna] = c;
}

// Imprime en flujo el contenido de una casilla
ostream& operator << (ostream& os, const Casilla& c)
{
  os << c.bomba;
  os << c.abierta;
  os << c.marcada;
  os << " ";
  return os;
}

// Lee el contenido de una casilla desde flujo
istream& operator >> (istream& is, Casilla& c)
{
  bool* campos[3] = {&c.bomba, &c.abierta, &c.marcada};
  is >> ws; //Salta espacios

  for(int i = 0; i < 3; i++)
  {
    if(is.peek() != '1' && is.peek() != '0')
      is.setstate(ios_base::badbit);
    *(campos[i]) =  is.get() == '1' ? 1 : 0;
  }
  return is;
}

// Imprime en flujo el tablero
ostream& operator << (ostream& os, const Tablero& t)
{
  os << t.Filas() << " " << t.Columnas() << endl;
  for(int i = 0; i < t.Filas(); i++)
    for(int j = 0; j < t.Columnas(); j++)
      os << t(i,j);
  return os;
}

// Lee un tablero desde flujo
istream& operator >> (istream& is, Tablero& t)
{
  int filas, columnas;
  is >> filas >> columnas;
  Tablero leido(filas, columnas);
  is.ignore();

  for(int i = 0; i < leido.Filas(); i++)
    for(int j = 0; j < leido.Columnas(); j++)
      if(is.good())
        is >> leido(i,j);

  if(is.good())
    t = leido;

  return is;
}

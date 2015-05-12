#include "Tablero.h"

int Tablero::Filas() const
{
  return filas;
}

int Tablero::Columnas() const
{
  return columnas;
}

Casilla Tablero::Get(int fila, int columna) const
{
  return datos[Columnas()*fila+columna];
}

void Tablero::Set(int fila, int columna, const Casilla &c)
{
  datos[Columnas()*fila+columna] = c;
}

ostream& operator << (ostream& os, const Casilla& c)
{
  os << c.bomba;
  os << c.abierta;
  os << c.marcada;
  return os;
}

istream& operator >> (istream& is, Casilla& c)
{
  while(isspace(is.peek()))
    is.ignore();
  c.bomba   = is.get() == '1' ? 1 : 0;
  c.abierta = is.get() == '1' ? 1 : 0;
  c.marcada = is.get() == '1' ? 1 : 0;
  return is;
}

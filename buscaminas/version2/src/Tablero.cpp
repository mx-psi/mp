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

std::ostream& operator << (std::ostream& os, const Casilla& c)
{
  os << c.bomba;
  os << c.abierta;
  os << c.marcada;
  return os;
}

std::istream& operator >> (std::istream& is, Casilla& c)
{
  while(isspace(is.peek())) //TODO: No sé si esto es necesario
    is.ignore();
  c.bomba   = is.get() == '1' ? 1 : 0; //TODO: Debería fallar si es 'a' p.ej.?
  c.abierta = is.get() == '1' ? 1 : 0; //TODO: Poner fallos
  c.marcada = is.get() == '1' ? 1 : 0;
  return is;
}

std::ostream& operator << (std::ostream& os, const Tablero& t)
{
  os << t.Filas() << " " << t.Columnas() << endl;
  for(int i = 0; i < t.Filas(); i++)
    for(int j = 0; j < t.Columnas(); j++)
      os << t(i,j);
  return os;
}

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

// Imprime en flujo el contenido de una casilla
std::ostream& operator << (std::ostream& os, const Casilla& c)
{
  os << c.bomba;
  os << c.abierta;
  os << c.marcada;
  os << " ";
  return os;
}

// Lee el contenido de una casilla desde flujo
std::istream& operator >> (std::istream& is, Casilla& c)
{
  char actual;
  is >> std::ws;

  bool* campos[3] = {&c.bomba, &c.abierta, &c.marcada};

  for(int i = 0; i < 3; i++)
  {
    actual = is.get();

    if(actual != '1' && actual != '0')
      is.setstate(std::ios_base::badbit);

    *(campos[i]) =  actual == '1' ? 1 : 0;
  }
  return is;
}

// Imprime en flujo el tablero
std::ostream& operator << (std::ostream& os, const Tablero& t)
{
  os << t.Filas() << " " << t.Columnas() << std::endl;

  for(int i = 0; i < t.Filas(); i++)
    for(int j = 0; j < t.Columnas(); j++)
      os << t(i,j);

  return os;
}

// Lee un tablero desde flujo
std::istream& operator >> (std::istream& is, Tablero& t)
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

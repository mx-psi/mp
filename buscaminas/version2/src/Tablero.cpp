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

// Lee el contenido de una casilla desde flujo
std::ostream& operator << (std::ostream& os, const Casilla& c)
{
  os << c.bomba;
  os << c.abierta;
  os << c.marcada;
  os << " ";
  return os;
}

// Imprime en flujo el contenido de una casilla
std::istream& operator >> (std::istream& is, Casilla& c)
{
  char actual;

  while(isspace(is.peek()))
    is.ignore();

  bool& campos[3] = {&c.bomba, &c.abierta, &c.marcada};

  for(int i = 0; i < 3; i++)
  {
    actual = is.get();

    if(actual != '1' || actual != '0')
      is.setstate(std::ios_base::badbit);

    campo[i] = actual == '1' ? 1 : 0;
  }

  return is;
}

// Lee un tablero desde flujo
std::ostream& operator << (std::ostream& os, const Tablero& t)
{
  os << t.Filas() << " " << t.Columnas() << endl;

  for(int i = 0; i < t.Filas(); i++)
    for(int j = 0; j < t.Columnas(); j++)
      os << t(i,j);
      
  return os;
}

// Imprime en flujo el tablero
std::istream& operator >> (std::istream& is, Tablero& t)
{
  int filas, columnas;
  is >> filas >> columnas;
  Tablero leido(filas, columnas);

  for(int i = 0; i < leido.Filas(); i++)
    for(int j = 0; j < leido.Columnas(); j++)
      is >> leido(i,j);

  if(is.good())
    t = leido;

  return is;
}

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
  return datos[fila][columna];
}

void Tablero::Set(int fila, int columna, const Casilla &c)
{
  datos[fila][columna] = c;
}

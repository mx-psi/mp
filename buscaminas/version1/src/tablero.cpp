#include "tablero.h"

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
  return matrix[fila][columna];
}

void Tablero::Set(int fila, int columna, const Casilla &c)
{
  matrix[fila][columna] = c;
}

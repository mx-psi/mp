#include "Tablero.h"

Casilla Tablero::Get(int fila, int columna) const
{
  return datos[fila][columna];
}

void Tablero::Set(int fila, int columna, const Casilla &c)
{
  datos[fila][columna] = c;
}

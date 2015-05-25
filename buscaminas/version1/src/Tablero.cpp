#include "Tablero.h"

// Obtiene el valor de una Casilla
Casilla Tablero::Get(int fila, int columna) const
{
  return datos[fila][columna];
}

// Asigna un valor a una Casilla
void Tablero::Set(int fila, int columna, const Casilla &c)
{
  datos[fila][columna] = c;
}

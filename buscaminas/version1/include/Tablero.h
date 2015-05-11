#ifndef _TABLERO_H_
#define _TABLERO_H_

// Estructura con información para cada casilla
struct Casilla
{
  bool bomba;
  bool abierta;
  bool marcada;

  Casilla()
  :bomba(false),abierta(false),marcada(false)
  {}
};


// Clase Tablero y cabeceras
class Tablero
{
  Casilla datos[20][20];
  const int filas, columnas;

public:
  Tablero(int f, int c)
  :filas(f), columnas(c)
  {}

  // Devuelve el número de filas del tablero
  int Filas() const;

  // Devuelve el número de filas del tablero
  int Columnas() const;

  // Obtiene la estructura de una casilla
  // Prec: fila <= 0 < filas, columna <= 0 < columnas
  Casilla Get(int fila, int columna) const;

  // Fija la estructura de una casilla
  // Prec: fila <= 0 < filas, columna <= 0 < columnas
  void Set(int fila, int columna, const Casilla &c);
};

#endif

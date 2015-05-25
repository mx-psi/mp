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
  inline int Filas() const {return filas;}
  // Devuelve el número de columnas del tablero
  inline int Columnas() const {return columnas;}
  // Obtiene el valor de una Casilla
  Casilla Get(int fila, int columna) const;
  // Asigna un valor a una Casilla
  void Set(int fila, int columna, const Casilla &c);
};

#endif

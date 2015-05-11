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

  inline int Filas() const {return filas;}
  inline int Columnas() const {return columnas;}

  Casilla Get(int fila, int columna) const
  {
    return datos[fila][columna];
  }

  void Set(int fila, int columna, const Casilla &c)
  {
    datos[fila][columna] = c;
  }

};

#endif

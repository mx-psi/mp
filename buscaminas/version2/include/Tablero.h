#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <iostream>

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
  Casilla* datos;
  int filas, columnas;

public:
  Tablero(int f, int c)
  :filas(f), columnas(c)
  {
    datos = new Casilla[filas*columnas];
  }

  // Constructor de copia
  Tablero(const Tablero& t)
  :filas(t.filas), columnas(t.columnas)
  {
    datos = new Casilla[filas*columnas];
    for (int i = 0; i < filas*columnas; i++)
      datos[i] = t.datos[i];
  }

  // Sobrecarga de operador de asignación
  Tablero& operator=(const Tablero& t)
  {
    if (&t != this)
    {
      if (t.filas*t.columnas != filas*columnas)
      {
        delete [] datos;
        filas = t.filas;
        columnas = t.columnas;
        datos = new Casilla[filas*columnas];
      }
      for (int i = 0; i < filas*columnas; i++)
        datos[i] = t.datos[i];
    }

    return *this;
  }

  // Accede a la casilla i, j
  Casilla& operator()(int i, int j)
  {
    return datos[Columnas()*i+j];
  }

  // Accede a la casilla i, j (versión const)
  const Casilla& operator()(int i, int j) const
  {
    return datos[Columnas()*i+j];
  }

  // Destructor
  ~Tablero() {delete [] datos;}

  // Devuelve el número de filas del tablero
  inline int Filas() const
  {
    return filas;
  }

  // Devuelve el número de columnas del tablero
  inline int Columnas() const
  {
    return columnas;
  }

  // OBSOLETA: Obtiene la estructura de una casilla
  // Prec: fila <= 0 < filas, columna <= 0 < columnas
  Casilla Get(int fila, int columna) const;

  // OBSOLETA: Fija la estructura de una casilla
  // Prec: fila <= 0 < filas, columna <= 0 < columnas
  void Set(int fila, int columna, const Casilla &c);
};


/* Operaciones de E/S de contenido del tablero */

// Imprime en flujo el contenido de una casilla
std::ostream& operator << (std::ostream& os, const Casilla& c);
// Lee el contenido de una casilla desde flujo
std::istream& operator >> (std::istream& is, Casilla& c);
// Imprime en flujo el tablero
std::ostream& operator << (std::ostream& os, const Tablero& t);
// Lee un tablero desde flujo
std::istream& operator >> (std::istream& is, Tablero& t);


#endif

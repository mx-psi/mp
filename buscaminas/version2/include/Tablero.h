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

  Casilla& operator()(int i, int j)
  {
    return datos[Columnas()*i+j];
  }

  const Casilla& operator()(int i, int j) const
  {
    return datos[Columnas()*i+j];
  }

  // Destructor
  ~Tablero() {delete [] datos;}

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


// Operaciones de E/S de contenido del tablero

// Lee el contenido de una casilla desde flujo
std::ostream& operator << (std::ostream& os, const Casilla& c);

// Imprime en flujo el contenido de una casilla
std::istream& operator >> (std::istream& is, Casilla& c);

// Lee un tablero desde flujo
std::ostream& operator << (std::ostream& os, const Tablero& t);

// Imprime en flujo el tablero
std::istream& operator >> (std::istream& is, Tablero& t);


#endif

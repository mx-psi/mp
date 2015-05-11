#include "Tablero.h"
/* Cabeceras de las funciones del módulo CampoMinas.cpp */

class CampoMinas{
  Tablero tab;
  bool explotado;
  bool CoordCorrectas(int x, int y) const;
  bool HayBomba(int x, int y) const;
  int NumeroBombas(int x, int y) const;
public:
  CampoMinas(int filas, int columnas, int minas);
  inline int Filas() const;
  inline int Columnas() const;
  inline bool Explotado() const;
  bool Ganado() const;
  bool Marca(int x, int y);
  bool Abre(int x, int y);
  void PrettyPrint() const;
  void ImprimeTablero() const;
};

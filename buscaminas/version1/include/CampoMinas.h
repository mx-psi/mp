/* Cabeceras de las funciones del módulo CampoMinas.cpp */

class CampoMinas{
  Tablero tab;
public:
  CampoMinas(int filas, int columnas, int minas);
  int Filas() const;
  int Columnas() const;
  bool Explotado() const;
  bool Ganado() const;
  bool Marca(int x, int y);
  bool Abre(int x, int y);
  void PrettyPrint() const;
  void ImprimeTablero() const;
};

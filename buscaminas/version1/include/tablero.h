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
  Casilla matriz[20][20];
  int filas, columnas;

public:
  Tablero(int f, int c)
  :filas(f), columnas(c)
  {}

  int Filas() const;
  int Columnas() const;
  Casilla Get(int fila, int columna) const;
  void Set(int fila, int columna, const Casilla &c);
};

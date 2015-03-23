/**
  * @file matriz_bit1.h
  * @brief Cabeceras para la primera representación de matrices.
  */

using namespace std;

struct MatrizBit
{
  int filas, columnas;
  bool mat[10][10];
};

bool Inicializar(MatrizBit& m, int filas, int columnas);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

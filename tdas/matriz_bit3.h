/**
  * @file matriz_bit3.h
  * @brief Cabeceras para la tercera representación de matrices.
  */

using namespace std;

struct MatrizBit
{
  unsigned int fils_cols;
  char vec[100];
};

bool Inicializar(MatrizBit& m, int filas, int columnas);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

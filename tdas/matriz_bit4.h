/**
  * @file matriz_bit4.h
  * @brief Cabeceras para la cuarta representación de matrices.
  */

using namespace std;

struct MatrizBit
{
  unsigned short int fils_cols;
  unsigned int vec[4];
};

bool Inicializar(MatrizBit& m, int filas, int columnas);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

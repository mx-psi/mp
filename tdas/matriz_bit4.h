/**
  * @file matriz_bit4.h
  * @brief Cabeceras para la cuarta representación de matrices.
  */

using namespace std;

const int TAM_DIM = 8; // Tamaño de cada componente guardada en fils_cols

struct MatrizBit
{
  unsigned short int fils_cols;
  unsigned int vec[4];
};

bool Bit(unsigned int bits, int pos);

void CambiaBit(unsigned int& bits, bool valor, int pos);

bool Inicializar(MatrizBit& m, int filas, int columnas);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

/**
  * @file matriz_bit4.h
  * @brief Cabeceras para la cuarta representación de matrices.
  */

const int TAM_DIM = 8; // Tamaño de cada componente guardada en fils_cols

struct MatrizBit
{
  unsigned short int fils_cols;
  unsigned int vec[4];
};

bool Bit(unsigned int bits, int pos);

void CambiaBit(unsigned int& bits, bool valor, int pos);

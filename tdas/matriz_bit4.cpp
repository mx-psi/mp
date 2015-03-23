/**
  * @file matriz_bit4.cpp
  * @brief Fichero para la cuarta representación de matrices.
  */

#include "matriz_bit4.h"
using namespace std;

bool Bit(unsigned int bits, int pos)
{
  return (1 << pos) & bits;
}

void CambiaBit(unsigned int& bits, bool valor, int pos)
{
  if(valor)
    bits |= (1 << pos);
  else
    bits &= ~(1 << pos);
}

bool Inicializar(MatrizBit& m, int filas, int columnas)
{
  if(filas*columnas > 128)
    return false;

  m.fils_cols = (filas << TAM_DIM) + columnas;

  for(int i = 0; i < 4; i++)
    m.vec[i] = 0;
}

int Filas (const MatrizBit& m)
{
  return m.fils_cols >> TAM_DIM;
}

int Columnas( const MatrizBit& m)
{
  return m.fils_cols - (Filas(m) << TAM_DIM);
}

bool Get(const MatrizBit& m, int f, int c)
{
  int pos = (f*Columnas(m) + c) / 32;
  int bit = (f*Columnas(m) + c) % 32;
  return Bit(m.vec[pos], bit);
}

void Set(MatrizBit& m, int f, int c, bool v)
{
  int pos = (f*Columnas(m) + c) / 32;
  int bit = (f*Columnas(m) + c) % 32;
  CambiaBit(m.vec[pos], v, bit);
}

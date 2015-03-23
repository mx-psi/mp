/**
  * @file matriz_bit3.cpp
  * @brief Fichero para la tercera representación de matrices.
  */

#include "matriz_bit3.h"

bool Inicializar(MatrizBit& m, int filas, int columnas)
{
  if(filas*columnas > 100)
    return false;

  m.fils_cols = (filas << TAM_DIM) + columnas;

  for(int i = 0; i < 100; i++)
    m.vec[i] = '0';
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
  return m.vec[f*Columnas(m) + c] == '1';
}

void Set(MatrizBit& m, int f, int c, bool v)
{
  m.vec[f*Columnas(m) + c] = v ? '1' : '0';
}

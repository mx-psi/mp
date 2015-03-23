/**
  * @file matriz_bit1.cpp
  * @brief Fichero para la primera representación de matrices.
  */

#include "matriz_bit1.h"
using namespace std;

bool Inicializar(MatrizBit& m, int filas, int columnas)
{
  if(filas > 10 || columnas > 10)
    return false;

  m.filas = filas;
  m.columnas = columnas;

  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      m.mat[i][j] = false;
}

int Filas (const MatrizBit& m)
{
  return m.filas;
}

int Columnas( const MatrizBit& m)
{
  return m.columnas;
}

bool Get(const MatrizBit& m, int f, int c)
{
  return m.mat[f][c];
}

void Set(MatrizBit& m, int f, int c, bool v)
{
  m.mat[f][c] = v;
}

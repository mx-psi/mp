/**
  * @file matriz_bit1.cpp
  * @brief Fichero para la primera representación de matrices.
  */

using namespace std;

struct MatrizBit
{
  int filas, columnas;
  bool mat[10][10];
}

bool Inicializar(MatrizBit& m, int filas, int columnas)
{
  if(filas > 10 || columnas > 10)
    return false;

  MatrizBit.filas = filas;
  MatrizBit.columnas = columnas;

  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      MatrizBit[i][j] = false;
}

int Filas (const MatrizBit& m)
{
  return MatrizBit.filas;
}

int Columnas( const MatrizBit& m)
{
  return MatrizBit.columnas;
}

bool Get(const MatrizBit& m, int f, int c)
{
  return MatrizBit.m[f][c];
}

void Set(MatrizBit& m, int f, int c, bool v)
{
  MatrizBit.m[f][c] = v;
}

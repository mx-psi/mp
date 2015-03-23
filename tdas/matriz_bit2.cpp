/**
  * @file matriz_bit2.cpp
  * @brief Fichero para la segunda representación de matrices.
  */

using namespace std;


bool Inicializar(MatrizBit& m, int filas, int columnas)
{
  if(filas*columnas > 100)
    return false;

  m.filas = filas;
  m.columnas = columnas;

  for(int i = 0; i < 100; i++)
    m.vec[i] = false;
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
  return m.vec[f*m.columnas + c];
}

void Set(MatrizBit& m, int f, int c, bool v)
{
  m.vec[f*m.columnas + c] = v;
}

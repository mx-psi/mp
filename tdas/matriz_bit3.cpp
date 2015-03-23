/**
  * @file matriz_bit3.cpp
  * @brief Fichero para la tercera representación de matrices.
  */

using namespace std;


bool Inicializar(MatrizBit& m, int filas, int columnas)
{
  if(filas*columnas > 100)
    return false;

  // TODO: NO LO HE PROBADO. NO SÉ SI FUNCIONA.
  m.fils_cols = (filas << 16) + columnas;

  for(int i = 0; i < 100; i++)
    m.vec[i] = '0';
}

int Filas (const MatrizBit& m)
{
  return m.fils_cols >> 16;
}

int Columnas( const MatrizBit& m)
{
  return (m.fils_cols << 16) >> 16;
}

bool Get(const MatrizBit& m, int f, int c)
{
  return m.vec[f*Columnas(m) + c];
}

void Set(MatrizBit& m, int f, int c, bool v)
{
  m.vec[f*Columnas(m) + c] = v ? '1' : '0';
}

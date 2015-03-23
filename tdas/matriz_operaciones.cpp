/**
  * @file matriz_operaciones.cpp
  * @brief Fichero de definiciones para funciones del tipo independientes de la representación
  *
  */

#include <iostream>
#include <fstream>
#include "matriz_operaciones.h"   // Llama a matriz_bit.h

bool Leer(std::istream& is, MatrizBit& m)
{
  int filas, columnas;
  is >> filas >> columnas;
  if (is.fail() || filas < 1 || columnas < 1)
    return false;

  Inicializar(m, filas, columnas);
  char leido;
  for (int i = 0; i < filas; i++)
    for (int j = 0; j < columnas; j++)
    {
      is >> leido;
      if (is.good() && (leido == '0' || leido == '1'))
        Set(m, i, j, leido == '1');
      else
        return false;
    }

  return is.eof();
}

bool Escribir(std::ostream& os, const MatrizBit& m)
{
  os << Filas(m) << ' ' << Columnas(m);
  for (int i = 0; os.good() && i < Filas(m); i++)
    for (int j = 0; j < os.good() && Columnas(m); j++)
      os << (j == 0 ? '\n' : ' ') << Get(m, i, j);

  return os.good();
}

bool Leer(const char nombre[], MatrizBit& m)
{
  std::ifstream f(nombre,ios::in|ios::binary);
  int filas, columnas;
  if (!f)
    return false;

  f >> filas >> columnas;
  if (!f || filas < 1 || columnas < 1)
    return false;

  Inicializar(m, filas, columnas);
  char leido;
  for (int i = 0; i < filas; i++)
    for (int j = 0; j < columnas; j++)
    {
      f >> leido;
      if (f && (leido == '0' || leido == '1'))
        Set(m, i, j, leido == '1');
      else
        return false;
    }

  return f && f.eof();
}

bool Escribir(const char nombre[], const MatrizBit& m)
{
  std::ofstream f(nombre,ios::out|ios::binary);
  if (!f)
    return false;

  f << Filas(m) << ' ' << Columnas(m);
  for (int i = 0; f && i < Filas(m); i++)
    for (int j = 0; f && j < Columnas(m); j++)
      f << (j == 0 ? '\n' : ' ') << Get(m, i, j);

  return f;

}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  Inicializar(res, Filas(m1), Columnas(m1));
  for (int i = 0; i < Filas(m1); i++)
    for (int j = 0; j < Columnas(m1); m++)
      Set(res, i, j, Get(m1, i, j) && Get(m2, i, j));
}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  Inicializar(res, Filas(m1), Columnas(m1));
  for (int i = 0; i < Filas(m1); i++)
    for (int j = 0; j < Columnas(m1); m++)
      Set(res, i, j, Get(m1, i, j) || Get(m2, i, j));
}

void Not(MatrizBit& res, const MatrizBit& m)
{
  Inicializar(res, Filas(m), Columnas(m));
  for (int i = 0; i < Filas(m); i++)
    for (int j = 0; j < Columnas(m); m++)
      Set(res, i, j, !Get(m, i, j));
}

void Traspuesta(MatrizBit& res, const MatrizBit& m)
{
  Inicializar(res, Columnas(m), Filas(m));
  for (int i = 0; i < Filas(m); i++)
    for (int j = 0; j < Columnas(m); m++)
      Set(res, j, i, Get(m, i, j));
}

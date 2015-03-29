/**
  * @file matriz_operaciones.cpp
  * @brief Fichero de definiciones para funciones del tipo independientes de la representación
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
      if ((is >> leido) && !is.eof())
        Set(m, i, j, leido == '1');
      else
        return false;
    }

  return true;
}

bool Escribir(std::ostream& os, const MatrizBit& m)
{
  os << Filas(m) << ' ' << Columnas(m);
  for (int i = 0; os.good() && i < Filas(m); i++)
    for (int j = 0; os.good() && j < Columnas(m); j++)
      os << (j == 0 ? '\n' : ' ') << Get(m, i, j);

  return os.good();
}

bool Leer(const char nombre[], MatrizBit& m)
{
  std::ifstream f(nombre, std::ios::in|std::ios::binary);
  return Leer(f, m);
}

bool Escribir(const char nombre[], const MatrizBit& m)
{
  std::ofstream f(nombre, std::ios::out|std::ios::binary);
  return Escribir(f, m);
}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  Inicializar(res, Filas(m1), Columnas(m1));
  for (int i = 0; i < Filas(m1); i++)
    for (int j = 0; j < Columnas(m1); j++)
      Set(res, i, j, Get(m1, i, j) && Get(m2, i, j));
}

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
  Inicializar(res, Filas(m1), Columnas(m1));
  for (int i = 0; i < Filas(m1); i++)
    for (int j = 0; j < Columnas(m1); j++)
      Set(res, i, j, Get(m1, i, j) || Get(m2, i, j));
}

void Not(MatrizBit& res, const MatrizBit& m)
{
  Inicializar(res, Filas(m), Columnas(m));
  for (int i = 0; i < Filas(m); i++)
    for (int j = 0; j < Columnas(m); j++)
      Set(res, i, j, !Get(m, i, j));
}

void Traspuesta(MatrizBit& res, const MatrizBit& m)
{
  Inicializar(res, Columnas(m), Filas(m));
  for (int i = 0; i < Filas(m); i++)
    for (int j = 0; j < Columnas(m); j++)
      Set(res, j, i, Get(m, i, j));
}

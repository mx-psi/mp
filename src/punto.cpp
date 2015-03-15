/* Módulo de funciones para trabajar con puntos. */

#include <iostream>
#include <cmath>
#include "punto.h"
using namespace std;

// OBSOLETA
Punto LeerPunto()
{
  Punto p;

  cin.ignore();
  cin >> p.x;

  cin.ignore();

  cin >> p.y;
  cin.ignore();

  return p;
}

// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
bool Leer(istream& is, Punto& p){

  if(is.get() != '(') return false;
  is >> p.x;
  if(is.get() != ',') return false;
  is >> p.y;
  if(is.get() != ')') return false;

  return is.good();
}

// OBSOLETA
void EscribirPunto (const Punto& p)
{
  cout << '(' << p.x << ',' << p.y << ')';
}

// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
bool Escribir(ostream& os, const Punto& p){
  os << '(' << p.x << ',' << p.y << ')';
  return os.good();
}

// Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy)
{
  p.x = cx;
  p.y = cy;
}

// Devuelve la coordenada X del punto p
double GetX (const Punto& p)
{
  return p.x;
}

// Devuelve la coordenada Y del punto p
double GetY (const Punto& p)
{
  return p.y;
}

// Devuelve la distancia euclídea entre p1 y p2
double Distancia (const Punto& p1, const Punto& p2)
{
  int d_x = p1.x - p2.x;
  int d_y = p1.y - p2.y;
  return sqrt(d_x*d_x + d_y*d_y);
}

// Devuelve el punto entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (const Punto& p1, const Punto& p2)
{
  Punto medio;
  medio.x = .5*(p1.x + p2.x);
  medio.y = .5*(p1.y + p2.y);

  return medio;
}

/* Módulo de funciones para trabajar con círculos. */

#include "circulo.h"
#include <iostream>
#include <cmath>
using namespace std;


// OBSOLETA.
Circulo LeerCirculo()
{
  Circulo c;
  cin >> c.radio;
  cin.ignore();
  c.centro = LeerPunto();

  return c;
}

// OBSOLETA.
void EscribirCirculo(const Circulo& c)
{
  cout << c.radio << '-';
  EscribirPunto(c.centro);
}

// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
bool Leer(istream& is, Circulo& c){
  is >> c.radio;
  is.ignore();
  Leer(is, c.centro);
  return is.good();
}

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
bool Escribir(ostream& os, const Circulo& c){
  os << c.radio << '-';
  Escribir(os, c.centro);
  return os.good();
}


// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, Punto centro, double radio)
{
  c.centro = centro;
  c.radio  = radio;
}

// Devuelve del centro de c
Punto Centro (const Circulo& c)
{
  return c.centro;
}

// Devuelve el radio de c
double Radio (const Circulo& c)
{
  return c.radio;
}

// Devuelve el área del círculo c
double Area (const Circulo& c)
{
  return M_PI*c.radio*c.radio;
}

// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (const Punto& p, const Circulo& c)
{
  return Distancia(p,c.centro) < c.radio;
}

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (const Circulo& c1, const Circulo& c2)
{
  return Distancia(c1.centro, c2.centro) - (c1.radio + c2.radio);
}

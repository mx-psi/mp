/* Módulo de funciones para manejar rectángulos. */

#include <iostream>
#include <cmath>
#include "rectmod.h"
using namespace std;

// Intercambia dos doubles.
void Intercambia(double &a, double &b)
{
  double auxiliar = a;
  a = b;
  b = auxiliar;
}

// Comprueba si los vértices del rectángulo son los de las esquinas correctas y en el orden deseado.
// En caso contrario los sustituye por los correctos
bool CorrigeVertices(Rectangulo& r)
{
  bool correcto = true;
  if (r.vert1.x > r.vert2.x)
  {
      Intercambia(r.vert1.x, r.vert2.x);
      correcto = false;
  }
  if (r.vert1.y > r.vert2.y)
  {
      Intercambia(r.vert1.y, r.vert2.y);
      correcto = false;
  }

  return correcto;
}

// Lectura de un rectángulo a partir de dos vértices opuestos en formato (a,b)-(c,d)

bool Leer(istream& is, Rectangulo& r)
{
  Leer(is, r.vert1);
  is.ignore();
  Leer(is, r.vert2);

  CorrigeVertices(r);
  return !is.fail();
}

// Escribe un rectángulo en el formato (a,b)-(c,d)

bool Escribir(ostream& os, const Rectangulo& r)
{
  Escribir(os, r.vert1);
  os << '-';
  Escribir(os, r.vert2);

  return !os.fail();
}

// Inicializa un rectángulo a partir de dos vértices
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2)
{
  r.vert1 = p1;
  r.vert2 = p2;
  CorrigeVertices(r);
}

// Devuelve el punto de la esquina inferior izquierda
Punto InferiorIzquierda(const Rectangulo& r)
{
  return r.vert1;
}

// Devuelve el punto de la esquina superior derecha
Punto SuperiorDerecha(const Rectangulo& r)
{
  return r.vert2;
}

// Devuelve el área del rectángulo
double Area(const Rectangulo& r)
{
  double lado_h = r.vert2.x - r.vert1.x;
  double lado_v = r.vert2.y - r.vert1.y;
  return sqrt(lado_h*lado_h + lado_v*lado_v);
}

// Devuelve si un punto está dentro de un rectángulo
bool Interior(const Punto& p, const Rectangulo& r)
{
  return p.x >= r.vert1.x && p.x <= r.vert2.x && p.y >= r.vert1.y && p.y <= r.vert2.y;
}

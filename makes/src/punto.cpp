/* Módulo de funciones para manejar puntos. */
#include <iostream>
#include <cmath>
#include "punto.h"
using namespace std;

// OBSOLETA
// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto()
{
    Punto salida;
    cin.ignore();
    cin >> salida.x;
    cin.ignore();
    cin >> salida.y;
    cin.ignore();
    return salida;
}

// Igual, pero devolviendo si hubo error

bool Leer(istream& is, Punto& p)
{
    is.ignore(65536, '(');
    is >> p.x;
    is.ignore();
    is >> p.y;
    is.ignore();

    return !is.fail();
}

// OBSOLETA
// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (const Punto& p)
{
    cout << '(' << p.x << ',' << p.y << ')';
}

// Igual, pero devolviendo si hubo error
bool Escribir(ostream& os, const Punto& p)
{
    os << '(' << p.x << ',' << p.y << ')';
    return !os.fail();
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
    double dist_x = p1.x-p2.x;
    double dist_y = p1.y-p2.y;
    return sqrt(dist_x*dist_x + dist_y*dist_y);
}

// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (const Punto& p1, const Punto& p2)
{
    Punto salida;
    salida.x = (p1.x + p2.x)/2;
    salida.y = (p1.y + p2.y)/2;
    return salida;
}

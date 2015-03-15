/* Cabeceras de las funciones relacionadas con Circulo. */

#include <iostream>
#include "punto.h"
using namespace std;

struct Circulo {
    Punto centro;
    double radio;
};

Circulo LeerCirculo();
void EscribirCirculo(const Circulo& c);
bool Leer(istream& is, Circulo& c);
bool Escribir(ostream& os, const Circulo& c);
void InicializarCirculo (Circulo& c, Punto centro, double radio);
Punto Centro (const Circulo& c);
double Radio (const Circulo& c);
double Area (const Circulo& c);
bool Interior (const Punto& p, const Circulo& c);
double Distancia (const Circulo& c1, const Circulo& c2);

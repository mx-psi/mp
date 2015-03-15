#ifndef _CIRCULO_H_
#define _CIRCULO_H_

#include "punto.h"

// Definimos tipo Circulo ___________________________________________

struct Circulo {
    Punto centro;
    double radio;
};

// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo();

// Igual, pero devolviendo si hubo error
bool Leer(istream& is, Circulo& c);

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(const Circulo& c);

// Igual, pero devolviendo si hubo error
bool Escribir(ostream& os, const Circulo& c);

// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, const Punto& centro, double radio);

// Devuelve del centro de c
Punto Centro (const Circulo& c);

// Devuelve el radio de c
double Radio (const Circulo& c);

// Devuelve el área del círculo c
double Area (const Circulo& c);

// Devuelve si p está en el interior del círculo c (distancia al centro menor que el radio)
bool Interior (const Punto& p, const Circulo& c);

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (const Circulo& c1, const Circulo& c2);

#endif

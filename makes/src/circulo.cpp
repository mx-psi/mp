/* Módulo de funciones para manejar círculos. */

#include <iostream>
#include <cmath>
#include "circulo.h"
using namespace std;

// Lee círculo en formato radio-centro, incluyendo '-' y leyendo "centro" con LeerPunto
Circulo LeerCirculo()
{
    Circulo salida;
    cin >> salida.radio;
    cin.ignore();
    salida.centro = LeerPunto();
    return salida;
}

// Igual, pero devuelve si se ha leído con éxito

bool Leer(istream& is, Circulo& c)
{
    is >> c.radio;
    is.ignore();
    Leer(is, c.centro);

    return !is.fail();
}

// Escribe círculo en formato radio-centro,  incluyendo '-' y escribiendo "centro" con EscribirPunto
void EscribirCirculo(const Circulo& c)
{
    cout << c.radio << '-';
    EscribirPunto(c.centro);
}

// Igual, pero devolviendo si hubo error
bool Escribir(ostream& os, const Circulo& c)
{
    os << c.radio << '-';
    Escribir(os, c.centro);

    return !os.fail();
}

// Inicializa circulo c con centro y radio
void InicializarCirculo (Circulo& c, const Punto& centro, double radio)
{
    c.centro = centro;
    c.radio = radio;
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
    return Distancia(p, Centro(c)) <= Radio(c);
}

// Devuelve la distancia de c1 a c2 (distancia entre los centros restándole los radios)
double Distancia (const Circulo& c1, const Circulo& c2)
{
    return Distancia(Centro(c1), Centro(c2)) - Radio(c1) - Radio(c2);
}

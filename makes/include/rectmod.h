/* Cabeceras de las funciones para manejar rectángulos. */

#ifndef _RECTMOD_H_
#define _RECTMOD_H_

#include "punto.h"

// Definición del struct Rectangulo

struct Rectangulo {
    Punto vert1, vert2;
};

// Funciones para manejar rectángulos

// Comprueba si los vértices del rectángulo son los de las esquinas correctas y en el orden deseado.
// En caso contrario los sustituye por los correctos
bool CorrigeVertices(Rectangulo& r);

// Lectura de un rectángulo a partir de dos vértices opuestos en formato (a,b)-(c,d)

bool Leer(istream& is, Rectangulo& r);

// Escribe un rectángulo en el formato (a,b)-(c,d)

bool Escribir(ostream& os, const Rectangulo& r);

// Inicializa un rectángulo a partir de dos vértices
void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);

// Devuelve el punto de la esquina inferior izquierda
Punto InferiorIzquierda(const Rectangulo& r);

// Devuelve el punto de la esquina superior derecha
Punto SuperiorDerecha(const Rectangulo& r);

// Devuelve el área del rectángulo
double Area(const Rectangulo& r);

// Devuelve si un punto está dentro de un rectángulo
bool Interior(const Punto& p, const Rectangulo& r);

#endif

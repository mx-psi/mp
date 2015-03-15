/* Cabeceras de las funciones para manejar puntos. */

#ifndef _PUNTO_H_
#define _PUNTO_H_

using namespace std;

// Definición del struct Punto ___________________________________________

struct Punto {
    double x,y;
};

// Lee un punto en el formato (x,y), incluyendo la lectura de '(' ',' y ')'
Punto LeerPunto();

// Igual, pero devolviendo si hubo error
bool Leer(istream& is, Punto& p);

// Escribe un punto en formato (x,y), incluyendo la escritura de '(' ',' y ')'
void EscribirPunto (const Punto& p);

// Igual, pero devolviendo si hubo error
bool Escribir(ostream& os, const Punto& p);

// Inicializa un punto con dos valores cx cy
void InicializarPunto (Punto &p, double cx, double cy);

// Devuelve la coordenada X del punto p
double GetX (const Punto& p);

// Devuelve la coordenada Y del punto p
double GetY (const Punto& p);

// Devuelve la distancia euclídea entre p1 y p2
double Distancia (const Punto& p1, const Punto& p2);

// Devuelve el punto que está entre p1 y p2 (más cercano a igual distancia de p1 y p2)
Punto PuntoMedio (const Punto& p1, const Punto& p2);

#endif

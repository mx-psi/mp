/**
  * @file ocultar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  *
  * Incluye funciones para ocultar o revelar mensajes en imágenes
  *
  */

#include <iostream>
#include <string>
#include "imagenES.h"
using namespace std;

const long long int MAX_TAMANIO = 1000000;

int Capacidad(TipoImagen tipo, int filas, int columnas){
  if (tipo == IMG_PGM)
    return filas*columnas/8;
  else if (tipo == IMG_PPM)
    return (filas*columnas*3)/8;
  else
    return -1;
}

int main(){
  char entrada[256];
  int filas, columnas;
  char salida[256];
  unsigned char buffer[]

  cout << "Introduzca la imagen de entrada: ";

  cin  >> entrada;

  ifstream imagen(entrada);
  TipoImagen tipo = LeerTipoImagen(entrada, filas, columnas);

  if(tipo == IMG_PGM)

  else if (tipo == IMG_PPM)

  if(tipo == IMG_DESCONOCIDO){
    cerr << "Tipo de imagen desconocido.";
    return 1;
  }

  cout << "Introduzca la imagen de salida ";
  cin >> salida;

  cout << "Introduzca el mensaje: ";
  const int capacidad = Capacidad(tipo, filas, columnas);
  string mensaje[capacidad];
  cin >> mensaje;

  cout << "Ocultando...\n";

  Ocultar(buffer, capacidad, mensaje);

  if(tipo == IMG_PGM)
    EscribirImagenPGM(salida, buffer, filas, columnas);
  else
    EscribirImagenPPM(salida, buffer, filas, columnas);
}

/* Fin fichero: ocultar.cpp */

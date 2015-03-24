/**
  * @file revelar.cpp
  * @brief Fichero para revelar mensajes en imágenes.
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

const int MAX_BUFFER  = 1000000;
const int MAX_MENSAJE = MAX_BUFFER/8;
const int MAX_NOMBRES = 256;

int main()
{
  char nombre[MAX_NOMBRES];
  int filas, columnas;

  /* Lectura del tipo de imagen */

  cout << "Introduzca la imagen de entrada: ";
  cin >> nombre;

  TipoImagen tipo = LeerTipoImagen(nombre, filas, columnas);
  if (tipo == IMG_DESCONOCIDO)
  {
    cerr << "revelar: Archivo no existente o tipo de imagen desconocido" << endl;
    return 1;
  }

  unsigned char buffer[MAX_BUFFER];
  bool leer;
  if (tipo == IMG_PGM)
    leer = LeerImagenPGM(nombre, filas, columnas, buffer);
  else
    leer = LeerImagenPPM(nombre, filas, columnas, buffer);

  if (!leer)
  {
    cerr << "revelar: Fallo en la lectura de la imagen" << endl;
    return 1;
  }

  /* Revelar mensaje */

  int bytes = filas*columnas*(1+2*(tipo == IMG_PPM))/8;
  if (bytes > MAX_MENSAJE)
    bytes = MAX_MENSAJE;
  char mensaje[MAX_MENSAJE];

  cout << "Revelando..." << endl;
  if (Revelar(buffer, bytes, mensaje))
    cout << mensaje << endl;
  else
  {
    cerr << "revelar: No se encuentra terminador de cadena en la imagen" << endl;
    return 1;
  }
}

/* Fin fichero: revelar.cpp */

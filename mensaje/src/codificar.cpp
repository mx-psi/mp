/**
  * @file codificar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  *
  * Incluye funciones para ocultar o revelar mensajes en imágenes
  *
  */

#include <string>
#include "imagenES.h"
using namespace std;

bool Bit(const unsigned char &bits, const int &pos){
  return (1<<pos) & bits != 0;
}

void CambiaBit(unsigned char &bits, const bool &bit, const int &pos){
  if(bit)
    bits |= (1 << pos);
  else
    bits &= (1 << pos);
}

/* Fin fichero: codificar.cpp */

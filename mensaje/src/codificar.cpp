/**
  * @file codificar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  *
  * Incluye funciones para ocultar o revelar mensajes en imágenes
  *
  */

#include "imagenES.h"
using namespace std;

bool Bit(const unsigned char &bits, const int &pos)
{
  return (1<<pos) & bits != 0;
}

void CambiaBit(unsigned char &bits, const bool &bit, const int &pos)
{
  if(bit)
    bits |= (1 << pos);
  else
    bits &= (1 << pos);
}

bool Ocultar(unsigned char buffer[], const int &pixeles, char mensaje[])
{
  bool fin_texto = false;
  int i = 0;
  for(int pix = 0; pix < pixeles && !fin_texto; pix++)
  {
    fin_texto = mensaje[i] != '\0';
    for(int b = 7; b >= 0; b--)
      CambiaBit(buffer[pix], Bit(mensaje[i++], b), 1);
  }
}

/* Fin fichero: codificar.cpp */

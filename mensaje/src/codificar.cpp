/**
  * @file codificar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  *
  * Incluye funciones para ocultar o revelar mensajes en imágenes
  *
  */

#include "codificar.h"

bool Bit(unsigned char bits, int pos)
{
  return (1<<pos) & bits;
}

void CambiaBit(unsigned char& bits, bool valor, int pos)
{
  if(valor)
    bits |= (1 << pos);
  else
    bits &= ~(1 << pos);
}

void CambiaBit(char& bits, bool valor, int pos) // TODO: Posiblemente no tenga que separarse en dos, pero es necesario que admita char y unsigned char (o que se modifique Revelar)
{
  if(valor)
    bits |= (1 << pos);
  else
    bits &= ~(1 << pos);
}

// Oculta un mensaje en una imagen
// Prec: La imagen es correcta
bool Ocultar(unsigned char imagen[], int capacidad, char texto[])
{
   bool fin_texto = false;
   int i = 0;  // Posición en la imagen
   for (unsigned int byte = 0; byte < capacidad && !fin_texto; byte++)
   {
      if (texto[byte] == '\0')   // TODO: Discutir si sobreescribir siempre o si comprobar
         fin_texto = true;
      for (int bit = 7; bit > -1; bit--)
         CambiaBit(imagen[i++], Bit(texto[byte], bit), 0);
   }
   return fin_texto;
}

// Revela el mensaje contenido en una imagen
bool Revelar(unsigned char imagen[], int capacidad, char texto[])
{
   bool fin_texto = false;
   int i = 0;
   for (unsigned int byte = 0; byte < capacidad && !fin_texto; byte++)
   {
      for (int bit = 7; bit > -1; bit--)
         CambiaBit(texto[byte], Bit(imagen[i++], 0), bit);

      if (texto[byte] == '\0')
         fin_texto = true; // TODO: Sobreescribir o comprobar
   }

   return fin_texto;
}

/* Fin fichero: codificar.cpp */

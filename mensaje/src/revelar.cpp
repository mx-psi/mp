/**
  * @file revelar.cpp
  * @brief Fichero para revelar mensajes en imágenes.
  *
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

int main()
{
   char nombre[256];
   int filas, columnas;
   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre;
   TipoImagen tipo = LeerTipoImagen(nombre, filas, columnas);
   unsigned char imagen[filas*columnas*(1+2*(tipo == IMG_PPM))];     // TODO: que sea el triple si la imagen es en color pero de forma menos fea. Otro TODO: el estándar no deja usar vectores de longitud variable.

   if (tipo == IMG_PGM && LeerImagenPGM(nombre, filas, columnas, imagen)
    || tipo == IMG_PPM && LeerImagenPPM(nombre, filas, columnas, imagen))
   {
      int bytes = filas*columnas*(1+2*(tipo == IMG_PPM))/8;   // TODO: ídem arriba. Quizá una variable las relacione. Otro TODO: el estándar no deja usar vectores de longitud variable.
      char mensaje[bytes];

      cout << "Revelando..." << endl;
      if (Revelar(imagen, bytes, mensaje))
         cout << mensaje;
      else
      {
         cout << "Error al intentar revelar el mensaje.";
         return 1;
      }
   }
   else
   {
      cout << "Error: Imagen inválida." << endl;   // TODO: Convendría que dijese qué tipo de error se ha producido (lo indica en el guion)
      return 1;
   }
}

/* Fin fichero: revelar.cpp */

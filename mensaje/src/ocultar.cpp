/**
  * @file ocultar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  *
  * Incluye funciones para ocultar o revelar mensajes en imágenes
  *
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;


// TODO global: el ocultar.cpp anterior podría contener cosas interesantes implementables en este
// otro TODO: "Incluye funciones para ocultar o revelar mensajes en imágenes" <-- wat?

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
      char salida[256];
      int bytes = filas*columnas*(1+2*(tipo == IMG_PPM))/8;   // TODO: ídem arriba. Quizá una variable las relacione. Otro TODO: el estándar no deja usar vectores de longitud variable.
      char mensaje[bytes];
      cout << "Introduzca la imagen de salida: ";
      cin >> salida;
      cout << "Introduzca el mensaje: ";
      cin >> mensaje;   // TODO: Modificar para que acepte espacios

      cout << "Ocultando..." << endl;
      if (Ocultar(imagen, bytes, mensaje + '\0'))
         if (tipo == IMG_PGM)
            EscribirImagenPGM(salida, imagen, filas, columnas);   // TODO: Debe añadirse .pgm en salida
         else
            EscribirImagenPPM(salida, imagen, filas, columnas);   // TODO: ídem pero .ppm
      else
      {
         cout << "Error al intentar ocultar el mensaje.";
         return 1;
      }
   }
   else
   {
      cout << "Error: Imagen inválida." << endl;   // TODO: Convendría que dijese qué tipo de error se ha producido (lo indica en el guion)
      return 1;
   }
}

/* Fin fichero: ocultar.cpp */

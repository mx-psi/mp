/**
  * @file ocultar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
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
   unsigned char imagen[filas*columnas*(1+2*(tipo == IMG_PPM))];

   if (tipo == IMG_PGM && LeerImagenPGM(nombre, filas, columnas, imagen)
    || tipo == IMG_PPM && LeerImagenPPM(nombre, filas, columnas, imagen))
   {
      char salida[256];
      int bytes = filas*columnas*(1+2*(tipo == IMG_PPM))/8;
      char mensaje[bytes];
      cout << "Introduzca la imagen de salida: ";
      cin >> salida;
      cout << "Introduzca el mensaje: ";
      cin >> mensaje;

      cout << "Ocultando..." << endl;
      if (Ocultar(imagen, bytes, mensaje + '\0'))
         if (tipo == IMG_PGM)
            EscribirImagenPGM(salida, imagen, filas, columnas);
         else
            EscribirImagenPPM(salida, imagen, filas, columnas);
      else
      {
         cout << "Error al intentar ocultar el mensaje.";
         return 1;
      }
   }
   else
   {
      cout << "Error: Imagen inválida." << endl;
      return 1;
   }
}

/* Fin fichero: ocultar.cpp */

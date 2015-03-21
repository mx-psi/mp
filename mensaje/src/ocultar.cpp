/**
  * @file ocultar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

const int MAX_BUFFER  = 1000000;
const int MAX_MENSAJE = MAX_BUFFER/8;
const int MAX_NOMBRES = 256;


// Devuelve el número de píxeles de una imagen
int Dimension(TipoImagen tipo, int filas, int columnas)
{
  return filas*columnas*(1+2*(tipo == IMG_PPM));
}

// Calcula el número de bytes ocultables en una imagen
int Bytes(TipoImagen tipo, int filas, int columnas)
{
  return Dimension(tipo, filas, columnas)/8;
}

// Añade extensión de tipo
void AniadeExtension(char nombre[], TipoImagen tipo){
  int pos = 0;
  char pgm[5] = ".pgm";
  char ppm[5] = ".ppm";

  while(nombre[pos] != '\0')
    pos++;

  if(tipo == IMG_PGM)
    for(int i = 0; i < 5; i++)
      nombre[pos+i] = pgm[i];
  else
    for(int i = 0; i < 5; i++)
      nombre[pos+i] = ppm[i];
}

int main()
{
   char nombre[MAX_NOMBRES];
   char salida[MAX_NOMBRES];
   int filas, columnas;

   /* Lectura del tipo de imagen */

   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre;

   TipoImagen tipo = LeerTipoImagen(nombre, filas, columnas);
   unsigned char buffer[MAX_BUFFER];

   if(tipo == IMG_DESCONOCIDO){
     cerr << "ocultar: Tipo de imagen desconocido";
     return 1;
   }

   if (tipo == IMG_PGM)
   {
     if(!LeerImagenPGM(nombre, filas, columnas, buffer))
     {
       cerr << "ocultar: Fallo en la lectura de la imagen.";
       return 1;
     }
   }
   else
   {
      if(!LeerImagenPPM(nombre, filas, columnas, buffer))
      {
        cerr << "ocultar: Fallo en la lectura de la imagen.";
        return 1;
      }
   }

    /* Salida y mensaje */

    int bytes = Bytes(tipo, filas, columnas);
    char mensaje[MAX_MENSAJE];

    cout << "Introduzca la imagen de salida: ";
    cin >> salida;
    AniadeExtension(salida, tipo);

    cout << "Introduzca el mensaje: ";
    cin >> mensaje;

    /* Ocultación */

    cout << "Ocultando..." << endl;
    if (Ocultar(buffer, bytes, mensaje + '\0'))
       if (tipo == IMG_PGM)
          EscribirImagenPGM(salida, buffer, filas, columnas);
       else
          EscribirImagenPPM(salida, buffer, filas, columnas);
    else
    {
       cerr << "ocultar: Mensaje demasiado grande.";
       return 1;
    }
}

/* Fin fichero: ocultar.cpp */

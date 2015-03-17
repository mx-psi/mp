/**
  * @file ocultar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  */

#include <iostream>
#include "codificar.h"
#include "bufferES.h"
using namespace std;

const int MAX_BUFFER  = 1000000;
const int MAX_MENSAJE = MAX_BUFFER/8;
const int MAX_NOMBRES = 256;

int Dimension(const TipoImagen &tipo, const int &filas, const int &columnas)
{
  return filas*columnas*(1+2*(tipo == IMG_PPM));
}

int Bytes(const TipoImagen &tipo, const int &filas, const int &columnas)
{
  return Dimension(tipo, filas, columnas)/8;
}

int main(int argc, char* argv[])
{
   char nombre[MAX_NOMBRES];
   char salida[MAX_NOMBRES];
   int filas, columnas;

   /* Lectura del tipo de imagen */

   cout << "Introduzca la buffer de entrada: ";
   cin >> nombre;

   TipoImagen tipo = LeerTipoImagen(nombre, filas, columnas);
   unsigned char imagen[MAX_BUFFER];

   if(tipo == IMG_DESCONOCIDO){
     cerr << argv[0] << ": Tipo de buffer desconocido";
     return 1;
   }

   if (tipo == IMG_PGM)
     if(!LeerImagenPGM(nombre, filas, columnas, buffer))
     {
       cerr << argv[0] << ": Fallo en la lectura de la imagen.";
       return 1;
     }
   else
      if(!LeerImagenPPM(nombre, filas, columnas, buffer))
      {
        cerr << argv[0] << ": Fallo en la lectura de la imagen.";
        return 1;
      }

    /* Salida y mensaje */

    int bytes = Bytes(tipo, filas, columnas);
    char mensaje[MAX_MENSAJE];
    cout << "Introduzca la buffer de salida: ";
    cin >> salida;
    cout << "Introduzca el mensaje: ";
    cin >> mensaje;

    /* Ocultación. */

    cout << "Ocultando..." << endl;
    if (Ocultar(buffer, bytes, mensaje + '\0'))
       if (tipo == IMG_PGM)
          EscribirImagenPGM(salida, buffer, filas, columnas);
       else
          EscribirImagenPPM(salida, buffer, filas, columnas);
    else
    {
       cout << "Error al intentar ocultar el mensaje.";
       return 1;
    }
}

/* Fin fichero: ocultar.cpp */

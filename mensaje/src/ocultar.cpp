/**
  * @file ocultar.cpp
  * @brief Fichero para codificar mensajes en imágenes.
  */

#include <iostream>
#include "codificar.h"
#include "imagenES.h"
using namespace std;

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
   char nombre[256];
   int filas, columnas;
   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre;
   TipoImagen tipo = LeerTipoImagen(nombre, filas, columnas);
   unsigned char imagen[Dimension(tipo, filas, columnas)];

   if(tipo == IMG_DESCONOCIDO){
     cerr << argv[0] << ": Tipo de imagen desconocido";
     return 1;
   }

   if (tipo == IMG_PGM)
     if(!LeerImagenPGM(nombre, filas, columnas, imagen))
     {
       cerr << argv[0] << ": Fallo en la lectura de la imagen.";
       return 1;
     }
   else
      if(!LeerImagenPPM(nombre, filas, columnas, imagen))
      {
        cerr << argv[0] << ": Fallo en la lectura de la imagen.";
        return 1;
      }

    char salida[256];
    int bytes = Bytes(tipo, filas, columnas);
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

/* Fin fichero: ocultar.cpp */

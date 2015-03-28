/**
  * @file codificar.h
  * @brief Fichero cabecera para la E/S de imágenes
  *
  * Incluye funciones para ocultar o revelar mensajes en imágenes
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Lee el bit en la posición dada de un byte
  *
  * @param bits Byte del que se quiere leer un bit
  * @param pos Posición del bit a leer
  * @return Valor del bit
  * @pre -1 < @a pos < 8
  */
bool Bit(unsigned char bits, int pos);

/**
  * @brief Asigna un valor a uno de los bits de un byte
  *
  * @param bits Byte en el que asignar un valor a un bit
  * @param valor Valor a asignar al bit
  * @param pos Posición del bit a cambiar
  */
void CambiaBit(unsigned char& bits, bool valor, int pos);

/**
  * @brief Asigna un valor a uno de los bits de un byte
  *
  * @param bits Byte en el que asignar un valor a un bit
  * @param valor Valor a asignar al bit
  * @param pos Posición del bit a cambiar
  */
void CambiaBit(char& bits, bool valor, int pos);

/**
  * @brief Oculta un mensaje en una imagen
  *
  * @param imagen Imagen en la que ocultar el mensaje
  * @param capacidad Cantidad de bytes de texto insertables en la imagen
  * (como máximo 1/8 de los bytes de la imagen)
  * @param texto Mensaje a guardar en la imagen
  * @retval true si la escritura se ha efectuado con éxito.
  * @retval false si ha habido alguna anomalía en la escritura.
  * @pre @a imagen es una imagen correcta
  */
bool Ocultar(unsigned char imagen[], int capacidad, char texto[]);

/**
  * @brief Revela un mensaje oculto en una imagen.
  *
  * @param imagen Imagen de la que extraer el mensaje
  * @param capacidad Cantidad de bytes de texto que podrían extraerse de la imagen
  * (como máximo 1/8 de los bytes de la imagen)
  * @param texto Cadena en la que almacenar el texto extraído
  * @retval true si la lectura se ha efectuado con éxito.
  * @retval false si ha habido alguna anomalía en la lectura.
  */
bool Revelar(unsigned char imagen[], int capacidad, char texto[]);


#endif

/* Fin Fichero: codificar.h */

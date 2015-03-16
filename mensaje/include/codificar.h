/**
  * @file codificar.h
  * @brief Fichero cabecera para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipos PGM,PPM
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Devuelve el bit en la posición dada
  *
  * @param bits Bits dados.
  * @param pos Posición a leer.
  * @return Valor del bit.
  * @pre @a pos < log2(@a bits)
  */
bool Bit(unsigned char bits, int pos);

/**
  * @brief Cambia el bit en la posción pedida.
  *
  * @param bits Bits dados.
  * @param valor Valor a asignar al bit.
  * @param pos Posición a cambiar.
  */
void CambiaBit(unsigned char& bits, bool valor, int pos);

/**
  * @brief Cambia el bit en la posción pedida.
  *
  * @param bits Bits dados.
  * @param valor Valor a asignar al bit.
  * @param pos Posición a cambiar.
  */
void CambiaBit(char& bits, bool valor, int pos);

/**
  * @brief Oculta un mensaje en una imagen.
  *
  * @param imagen Imagen.
  * @param capacidad Tamaño de la imagen en bytes.
  * @param mensaje Mensaje a guardar.
  * @ret Éxito de la operación.
  */
bool Ocultar(unsigned char imagen[], int capacidad, char texto[]);

/**
  * @brief Revela un mensaje oculto en una imagen.
  *
  * @param buffer Imagen.
  * @param capacidad Tamaño de la imagen en bytes.
  * @param mensaje Mensaje a obtener.
  * @ret Éxito de la operación.
  */
bool Revelar(unsigned char imagen[], int capacidad, char texto[]);


#endif

/* Fin Fichero: codificar.h */

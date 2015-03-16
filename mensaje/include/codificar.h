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
bool Bit(const unsigned char &bits, const int &pos);

/**
  * @brief Cambia el bit en la posción menos significativa.
  *
  * @param bits Bits dados.
  * @param bit Bit cambiado
  */
void CambiaBit(unsigned char &bits, const bool &bit);

/**
  * @brief Oculta un mensaje en una imagen.
  *
  * @param buffer Imagen.
  * @param pixeles Tamaño de la imagen.
  * @param mensaje Mensaje a guardar.
  * @ret Éxito de la operación.
  */
bool Ocultar(unsigned char buffer[], const int &pixeles, char mensaje[]);

/**
  * @brief Revela un mensaje oculto en una imagen.
  *
  * @param buffer Imagen.
  * @param pixeles Tamaño de la imagen.
  * @param mensaje Mensaje a obtener.
  * @ret Éxito de la operación.
  */
bool Revelar(unsigned char buffer[], const int &pixeles, char mensaje[]);


#endif

/* Fin Fichero: codificar.h */

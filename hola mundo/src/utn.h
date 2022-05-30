/*
 * utn.h
 *
 *  Created on: 26 abr. 2022
 *      Author: PC-INC
 */

#ifndef UTN_H_
#define UTN_H_
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 *
 */
void utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
/**
 * @brief
 *
 * @param pResultado solicita un letra al usuario, luego de verificarlo devulve el resultado.
 * @param mensaje  pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensajeError Es el mensaje a ser mostrado
 * @param minimo Es el numero maximo a ser aceptado
 * @param maximo Es el minimo minimo a ser aceptado
 * @return
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo);
/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);


/**
 * @brief La funcion pide un cadena de char
 *
 * @param mensaje Es el mensaje a ser mostrado
 * @param input  direccion de memoria de una variable
 * @param tamMin Es el numero minimo a ser aceptado
 * @param tamMax Es el numero maximo a ser aceptado
 */
void getString(char mensaje[],char input[],int tamMin,int tamMax);
void getIntA(char mensaje[],int *numero,int tamMin,int tamMax);
void getFloat(char mensaje[],float *numero,float tamMin,float tamMax);
#endif /* UTN_H_ */

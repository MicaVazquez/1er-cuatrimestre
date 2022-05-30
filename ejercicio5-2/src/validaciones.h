/*
 * validaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//PROTOTIPO/FIRMA
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/**
 * @brief La funcion pide un entero positivo y valida que sea mayor que 0.
 *
 * @param mensaje  Mensaje para que el usuario sepa que ingresar.
 * @param error    Mensaje para que reingrese.
 * @return         Devuelve un entero.
 */

int pedirEnteroPositivo(char mensaje[],char error[]);


/**
 * @brief solicita un numero al usuario, luego de verificarlo devulve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la operacion.
 * @param mensaje Es el mensaje a ser mostrado.
 * @param mensajeError Es el mensaje error a ser mostrado.
 * @param minimo Es el numero minimo a ser aceptado.
 * @param maximo Es el numero maximo a ser aceptado.
 * @param reintentos Cantidad de veces que se le dejara al usuario reitentar.
 * @return retorna 0 si se obtuvo el numero y -1 si no.
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* VALIDACIONES_H_ */

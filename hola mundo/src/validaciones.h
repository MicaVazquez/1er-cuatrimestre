/*
 * validaciones.h
 *
 *  Created on: 24 abr. 2022
 *      Author: PC-INC
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/**
 * @brief Solicita el numero al usuario, luego de verificar le devulve el resultado
 *
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado.
 * @param minimo Es el numero minimo a ser aceptado
 * @param maximo Es el numero maximo a ser aceptado
 * @param reintentos
 * @return Retorna 0 si se obtuvo el numero y -1 si no
 */
void getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);




int myGets(char* cadena, int longitud);

#endif /* VALIDACIONES_H_ */

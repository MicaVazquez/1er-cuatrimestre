/*
 * avion.h
 *
 *  Created on: 14 may. 2022
 *      Author: PC-INC
 */

#ifndef AVION_H_
#define AVION_H_
#include "arrayPassenger.h"
#include "avion.h"
typedef struct
{
	char IDcodigoDeVuelo[10];//PK
	int estadoDeVuelo;// activo demorado cancelado
	int isEmptyCV;

}eAvion;




/**
 * @brief la funcion permite ingresar un codigo de vuelo nuevo
 *
 * @param listaA Array de aviones
 * @param lenA tam array de aviones
 * @return  devuelve 1 se se cargo uno nuevo y -2 si no.
 */
int altaVuelos(eAvion* listaA,int lenA);

/**
 * @brief busca un lugar libre en el campo de codigo de vuelo
 *
 * @param list lista array avion
 * @param len longitud
 * @return retorno -1 si no hay espacio sino retorna la posicion libre
 */
int buscarLibreCodigoVuelo(eAvion* list, int len);

/**
 * @brief inicializa el isEmpthy de la estructura eAvion es Libre
 *
 * @param listA array aviones
 * @param lenA  longitud
 */
void inicializarCodigosVuelos(eAvion* listA, int lenA);


/**
 * @brief la funcion impide que se ingrese un codigo de vuelo existente
 *
 * @param listaAv array
 * @param lenA   longitud
 * @param input
 * @return retorna 0 si no es igual el nuevo codigo a los que ya existen y 1 si es igual
 */
int buscarRepetido(eAvion* listaAv, int lenA,char* input);



/**
 * @brief la funcion modifica el estado de vuelo
 *
 * @param listaAviones array
 * @param lenA longiud
 */
void modificarEstadoVuelo(eAvion* listaAviones,int lenA);




/**
 * @brief Carga forzada de codigos y estados de vuelos
 *
 * @param list
 */
void hardcodearAvion(eAvion* list);


#endif /* AVION_H_ */

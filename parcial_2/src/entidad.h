/*
 * entidad.h
 *
 *  Created on: 2 jul. 2022
 *      Author: PC-INC
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char descripcion[4000];
	int precio;
	int idTipo;
	int cuotas;
	int precioCuota;

}eEntidad;

eEntidad* eEntidad_new();
eEntidad* eEntidad_newParametros(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr, char* cuotasStr);
void eEntidad_delete(eEntidad* this);
int eEntidad_setId(eEntidad* this,int id);
int eEntidad_getId(eEntidad* this,int* id);
int eEntidad_setIdTipo(eEntidad* this,int idTipo);
int eEntidad_getIdTipo(eEntidad* this,int* idTipo);
int eEntidad_setCuotas(eEntidad* this,int cuotas);
int eEntidad_getCuotas(eEntidad* this,int* cuotas);
int eEntidad_setPrecio(eEntidad* this,int precio);
int eEntidad_getPrecio(eEntidad* this,int* precio);
int eEntidad_setDescripcion(eEntidad* this,char* descripcion);
int eEntidad_getDescripcion(eEntidad* this,char* Descripcion);

int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);
int eEntidad_sortCuotas(void* p1,void* p2);
int eEntidad_setPrecioCuota(eEntidad* this,int precioCuota);
int eEntidad_getPrecioCuota(eEntidad* this,int* precioCuota);
int eEntidad_sortId(void* p1,void* p2);

#endif /* ENTIDAD_H_ */

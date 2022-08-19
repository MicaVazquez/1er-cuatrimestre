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
	char nombre[50];
	char empleo[200];
	int horasTrabajadas;
	int edad;
	char dedicacion[200];

}eEntidad;

eEntidad* eEntidad_new();
eEntidad* eEntidad_newParametros(char* idStr,char* nombreStr,char* empleoStr, char* edadStr,char* horasTrabajadasStr);
void eEntidad_delete(eEntidad* this);
int eEntidad_setId(eEntidad* this,int id);
int eEntidad_getId(eEntidad* this,int* id);
int eEntidad_setEdad(eEntidad* this,int edad);
int eEntidad_getEdad(eEntidad* this,int* edad);
int eEntidad_setHorasTrabajadas(eEntidad* this,int horasTrabajadas);
int eEntidad_getHorasTrabajadas(eEntidad* this,int* horasTrabajadas);
int eEntidad_setNombre(eEntidad* this,char* nombre);
int eEntidad_getNombre(eEntidad* this,char* nombre);
int eEntidad_setEmpleo(eEntidad* this,char* empleo);
int eEntidad_getEmpleo(eEntidad* this,char* empleo);
int eEntidad_setDedicacion(eEntidad* this,char* dedicacion);
int eEntidad_getDedicacion(eEntidad* this,char* dedicacion);
int eEntidad_sortName(void* p1,void*p2);
void eEntidad_printOneDedicacion(eEntidad* unEntidad);
int eEntidad_darValorDedicacion(eEntidad* unEntidad);
int eEntidad_sortDedicacion(void* p1,void* p2);

int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);
int eEntidad_sortCuotas(void* p1,void* p2);
int eEntidad_setPrecioCuota(eEntidad* this,int precioCuota);
int eEntidad_getPrecioCuota(eEntidad* this,int* precioCuota);
int eEntidad_sortId(void* p1,void* p2);

#endif /* ENTIDAD_H_ */

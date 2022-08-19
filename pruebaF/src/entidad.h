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
   char descripcion[400];
   int idPropietario;
   int power;
   int ataque;
}eEntidad;

eEntidad* eEntidad_new();
eEntidad* eEntidad_newParametros(char* idStr,char*descripcion,char*idPropietario,char*power,char*ataque);
void eEntidad_delete(eEntidad* this);
int eEntidad_setId(eEntidad* this,int id);
int eEntidad_getId(eEntidad* this,int* id);
int eEntidad_setDescripcion(eEntidad* this,char* descripcion);
int eEntidad_getDescripcion(eEntidad* this,char* descripcion);
int eEntidad_setIdPropietario(eEntidad* this,int idPropietario);
int eEntidad_getIdPropietario(eEntidad* this,int* idPropietario);
int eEntidad_setPower(eEntidad* this,int power);
int eEntidad_getPower(eEntidad* this,int* power);
int eEntidad_setAtaque(eEntidad* this,int ataque);
int eEntidad_getAtaque(eEntidad* this,int* ataque);


int eEntidad_sortName(void* p1,void*p2);
void eEntidad_printOneDedicacion(eEntidad* unEntidad);
int eEntidad_darValorDedicacion(eEntidad* unEntidad);
int eEntidad_sortDedicacion(void* p1,void* p2);

int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);
int eEntidad_sortPower(void* p1,void* p2);

int eEntidad_sortId(void* p1,void* p2);

#endif /* ENTIDAD_H_ */

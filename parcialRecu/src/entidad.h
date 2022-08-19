/*
 * entidad.h
 *
 *  Created on: 2 jul. 2022
 *      Author: PC-INC
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#include "LinkedList.h"
//id,nombre,sueldo,edad,profesion
typedef struct
{
	int id;
	char nombre[200];
	int edad;
	int idDificultad;
	int score;


}eEntidad;

eEntidad* eEntidad_new();
eEntidad* eEntidad_newParametros(char* idStr,char*nombre,char*edad,char*idDificultad,char*score);
void eEntidad_delete(eEntidad* this);
int eEntidad_setId(eEntidad* this,int id);
int eEntidad_getId(eEntidad* this,int* id);
int eEntidad_setEdad(eEntidad* this,int edad);
int eEntidad_getEdad(eEntidad* this,int* edad);
int eEntidad_setIdDificultad(eEntidad* this,int idDificultad);

int eEntidad_getIdDificultad(eEntidad* this,int* idDificultad);

int eEntidad_setScore(eEntidad* this,int score);

int eEntidad_getScore(eEntidad* this,int* score);
int eEntidad_setNombre(eEntidad* this,char* nombre);
int eEntidad_getNombre(eEntidad* this,char* nombre);
int eEntidad_setProfesion(eEntidad* this,char*profesion);
int eEntidad_getProfesion(eEntidad* this,char*profesion);
int eEntidad_sortName(void* p1,void*p2);

int eEntidad_setDedicacion(eEntidad* this,char* dedicacion);
int eEntidad_getDedicacion(eEntidad* this,char* dedicacion);

void eEntidad_printOneDedicacion(eEntidad* unEntidad);
int eEntidad_darValorDedicacion(eEntidad* unEntidad);
int eEntidad_sortDedicacion(void* p1,void* p2);

int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);
int eEntidad_sortEditorialId(void* p1,void* p2);

#endif /* ENTIDAD_H_ */

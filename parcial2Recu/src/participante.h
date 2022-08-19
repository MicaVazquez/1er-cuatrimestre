/*
 * participante.h
 *
 *  Created on: 4 ago. 2022
 *      Author: PC-INC
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_

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

int eEntidad_sortName(void* p1,void*p2);





int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);



#endif /* PARTICIPANTE_H_ */

/*
 * entidad.h
 *
 *  Created on: 2 jul. 2022
 *      Author: PC-INC
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#include "LinkedList.h"
//id,nombre,anio,genero
typedef struct
{
    int id;
	char nombre[200];
	int anio;
	char genero[200];


}eEntidad;

eEntidad* eEntidad_new();
eEntidad* eEntidad_newParametros(char* idStr,char*nombreStr,char*anioStr,char*generoStr);
void eEntidad_delete(eEntidad* this);
int eEntidad_setId(eEntidad* this,int id);
int eEntidad_getId(eEntidad* this,int* id);
int eEntidad_setNombre(eEntidad* this,char* nombre);
int eEntidad_getNombre(eEntidad* this,char* nombre);
int eEntidad_setAnio(eEntidad* this,int anio);
int eEntidad_getAnio(eEntidad* this,int* anio);
int eEntidad_setGenero(eEntidad* this,char* genero);
int eEntidad_getGenero(eEntidad* this,char* genero);

void depurarPeliculas (LinkedList* pArrayPelisDepu);
int filtraAccion(void* unEntidad);
int filtraAventura(void* unEntidad);
int filtraAnimacion(void* unEntidad);
int filtraFamiliar(void* unEntidad);
int filtraFantasia(void* unEntidad);
int filtraCienciaFiccion(void* unEntidad);

int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);
int eEntidad_sortCuotas(void* p1,void* p2);
int eEntidad_setPrecioCuota(eEntidad* this,int precioCuota);
int eEntidad_getPrecioCuota(eEntidad* this,int* precioCuota);
int eEntidad_sortId(void* p1,void* p2);

#endif /* ENTIDAD_H_ */

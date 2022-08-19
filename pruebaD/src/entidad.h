/*
 * entidad.h
 *
 *  Created on: 2 jul. 2022
 *      Author: PC-INC
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#include "LinkedList.h"
//id,titulo,autor,precio,editorialId
typedef struct
{
    int id;
	char titulo[200];
	char autor[200];
	float precio;
	int editorialId;


}eEntidad;

eEntidad* eEntidad_new();
eEntidad* eEntidad_newParametros(char* idStr,char* tituloStr, char* autorStr,char* precioStr,char* editorialIdStr);
void eEntidad_delete(eEntidad* this);
int eEntidad_setId(eEntidad* this,int id);
int eEntidad_getId(eEntidad* this,int* id);
int eEntidad_setEditorialId(eEntidad* this,int editorialId);
int eEntidad_getEditorialId(eEntidad* this,int* editorialId);
int eEntidad_setTitulo(eEntidad* this,char* titulo);
int eEntidad_getTitulo(eEntidad* this,char* titulo);
int eEntidad_setAutor(eEntidad* this,char* autor);
int eEntidad_getAutor(eEntidad* this,char* autor);
int eEntidad_setPrecio(eEntidad* this,float precio);
int eEntidad_getPrecio(eEntidad* this,float* precio);


void eEntidad_printOneDedicacion(eEntidad* unEntidad);
int eEntidad_darValorDedicacion(eEntidad* unEntidad);
int eEntidad_sortDedicacion(void* p1,void* p2);

int eEntidad_LastId(char* id);
int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger);
int eEntidad_saveLastId(int lastId);
void eEntidad_printOne(eEntidad* unEntidad);
int eEntidad_sortEditorialId(void* p1,void* p2);

#endif /* ENTIDAD_H_ */

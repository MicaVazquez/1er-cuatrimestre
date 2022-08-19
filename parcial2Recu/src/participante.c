/*
 * participante.c
 *
 *  Created on: 4 ago. 2022
 *      Author: PC-INC
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "participante.h"
#include "LinkedList.h"
//participante
//id,nombre,sueldo,edad,profesion
eEntidad* eEntidad_new()
{
	eEntidad* puntero;

	puntero =  (eEntidad*)malloc(sizeof(eEntidad));

	return puntero;
}

eEntidad* eEntidad_newParametros(char* idStr,char*nombre,char*edad,char*idDificultad,char*score)
{

	eEntidad*  unEntidad = eEntidad_new();


	    if(unEntidad != NULL && idStr != NULL && nombre!= NULL && idDificultad != NULL && edad != NULL && score!= NULL)
	    {
            if(eEntidad_setId(unEntidad, atoi(idStr)) == -1 ||
	    			eEntidad_setNombre(unEntidad, nombre) == -1 ||
					eEntidad_setEdad(unEntidad, atoi(edad))== -1 ||
					 eEntidad_setIdDificultad(unEntidad, atoi(idDificultad))== -1 ||
					 eEntidad_setScore(unEntidad, atoi(score)) == -1)

	    	{
	    		eEntidad_delete(unEntidad);
	    	}
	    }
	return unEntidad;
}

//nombre empleo dedicacion
//edad horas
void eEntidad_delete(eEntidad* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int eEntidad_setId(eEntidad* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_getId(eEntidad* this,int* id)
{
	int retorno = -1;

	if(this!= NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}


int eEntidad_setEdad(eEntidad* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getEdad(eEntidad* this,int* edad)
{
	int retorno = -1;

	if(this!= NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setIdDificultad(eEntidad* this,int idDificultad)
{
	int retorno = -1;

	if(this != NULL && idDificultad > 0)
	{
		this->idDificultad = idDificultad;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getIdDificultad(eEntidad* this,int* idDificultad)
{
	int retorno = -1;

	if(this!= NULL && idDificultad > 0)
	{
		*idDificultad = this->idDificultad;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setScore(eEntidad* this,int score)
{
	int retorno = -1;

	if(this != NULL && score > 0)
	{
		this->score = score;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_getScore(eEntidad* this,int* score)
{
	int retorno = -1;

	if(this!= NULL && score != NULL)
	{
		*score = this->score;
		retorno = 0;
	}
	return retorno;
}
int eEntidad_setNombre(eEntidad* this,char* nombre)
{
	int retorno =-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getNombre(eEntidad* this,char* nombre)
{
	int retorno = -1;

	if(this!= NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}




void eEntidad_printOne(eEntidad* unEntidad)
{

	int id;
	char nombre[200];
	int edad;
	int idDificultad;
	int score;
	char dificultad[3][200]={"FACIL","NORMAL","DIFICIL"};

	eEntidad_getId(unEntidad, &id);
	eEntidad_getNombre(unEntidad, nombre);
	eEntidad_getEdad(unEntidad, &edad);
	eEntidad_getIdDificultad(unEntidad, &idDificultad);
	eEntidad_getScore(unEntidad, &score);


	printf("\n%d %s %d %s %d \n",id,nombre,edad,dificultad[idDificultad-1],score);

}

int eEntidad_sortName(void* p1,void*p2)
{
	char name1[50];
	char name2[50];
	int rtn;

	eEntidad* entidad1 = (eEntidad*)p1;
	eEntidad* entidad2 = (eEntidad*)p2;

	if(entidad1 != NULL && entidad2 != NULL)
	{
       eEntidad_getNombre(entidad1, name1);
       eEntidad_getNombre(entidad2, name2);

       rtn =stricmp(name1,name2);
	}

	return rtn;
}

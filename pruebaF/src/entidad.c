/*
 * entidad.c
 *
 *  Created on: 2 jul. 2022
 *      Author: PC-INC
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "entidad.h"
#include "LinkedList.h"
//id,tipo,cantidad,importe
eEntidad* eEntidad_new()
{
	eEntidad* puntero;

	puntero =  (eEntidad*)malloc(sizeof(eEntidad));

	return puntero;
}
eEntidad* eEntidad_newParametros(char* idStr,char*descripcion,char*idPropietario,char*power,char*ataque)
{

	eEntidad*  unEntidad = eEntidad_new();


	    if(unEntidad != NULL && idStr != NULL && descripcion != NULL && idPropietario != NULL && power != NULL && ataque != NULL)
	    {
            if(eEntidad_setId(unEntidad, atoi(idStr)) == -1 ||
	    			eEntidad_setDescripcion(unEntidad, descripcion) == -1 ||
					eEntidad_setIdPropietario(unEntidad,atoi(idPropietario))== -1 ||
					eEntidad_setPower(unEntidad, atoi(power)) == -1 ||
					eEntidad_setAtaque(unEntidad,atoi(ataque))== -1 )
	    	{
	    		eEntidad_delete(unEntidad);
	    	}
	    }
	return unEntidad;
}


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

int eEntidad_setDescripcion(eEntidad* this,char* descripcion)
{
	int retorno =-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getDescripcion(eEntidad* this,char* descripcion)
{
	int retorno = -1;

	if(this!= NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}

	return retorno;
}

int eEntidad_setIdPropietario(eEntidad* this,int idPropietario)
{
	int retorno = -1;

	if(this != NULL && idPropietario > 0)
	{
		this->idPropietario = idPropietario;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getIdPropietario(eEntidad* this,int* idPropietario)
{
	int retorno = -1;

	if(this!= NULL && idPropietario != NULL)
	{
		*idPropietario = this->idPropietario;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setPower(eEntidad* this,int power)
{
	int retorno = -1;

	if(this != NULL && power > 0)
	{
		this->power = power;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getPower(eEntidad* this,int* power)
{
	int retorno = -1;

	if(this!= NULL && power!= NULL)
	{
		*power = this->power;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setAtaque(eEntidad* this,int ataque)
{
	int retorno = -1;

	if(this != NULL && ataque >= 0)
	{
		this->ataque = ataque;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_getAtaque(eEntidad* this,int* ataque)
{
	int retorno = -1;

	if(this!= NULL && ataque!= NULL)
	{
		*ataque = this->ataque;
		retorno = 0;
	}
	return retorno;
}

void eEntidad_printOne(eEntidad* unEntidad)
{

	int id;
	char descripcion[400];
	int idPropietario;
	int power;
	int ataque;

	   char datoSuper[2][100] = {"DC","MARVEL"};

	eEntidad_getId(unEntidad, &id);
	eEntidad_getDescripcion(unEntidad, descripcion);
	eEntidad_getIdPropietario(unEntidad, &idPropietario);
	eEntidad_getPower(unEntidad, &power);
	eEntidad_getAtaque(unEntidad, &ataque);


	printf("\n%d   %s   %s   %d   %d    \n",id,descripcion,datoSuper[idPropietario-1],power,ataque);

}

int eEntidad_sortPower(void* p1,void* p2)
{
	int retorno;
	int power1=0;
	int power2=0;

	eEntidad* entidad1 = (eEntidad*)p1;
	eEntidad* entidad2 = (eEntidad*)p2;

	    if(entidad1!=NULL && entidad2!=NULL)
	    {
	        eEntidad_getPower(entidad1, &power1);
	        eEntidad_getPower(entidad2, &power2);

	       if(power1>power2)
	       {
	           retorno = 1;
	       }
	       else if(power1<power2)
	       {
	           retorno = -1;
	       }
	       else
	       {
	           retorno = 0;
	       }

	    }
	return retorno;
}

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

eEntidad* eEntidad_new()
{
	eEntidad* puntero;

	puntero =  (eEntidad*)malloc(sizeof(eEntidad));

	return puntero;
}
eEntidad* eEntidad_newParametros(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr, char* cuotasStr)
{
	eEntidad*  unEntidad = eEntidad_new();


	    if(unEntidad != NULL && idStr != NULL && descripcionStr != NULL && precioStr != NULL && idTipoStr != NULL && cuotasStr != NULL)
	    {
            if(eEntidad_setId(unEntidad, atoi(idStr)) == -1 ||
	    			eEntidad_setDescripcion(unEntidad, descripcionStr) == -1 ||
					eEntidad_setPrecio(unEntidad, atoi(precioStr)) == -1 ||
					eEntidad_setIdTipo(unEntidad, atoi(idTipoStr)) == -1 ||
					eEntidad_setCuotas(unEntidad, atoi(cuotasStr))== -1)

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


int eEntidad_setIdTipo(eEntidad* this,int idTipo)
{
	int retorno = -1;

	if(this != NULL && idTipo > 0)
	{
		this->idTipo = idTipo;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getIdTipo(eEntidad* this,int* idTipo)
{
	int retorno = -1;

	if(this!= NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setCuotas(eEntidad* this,int cuotas)
{
	int retorno = -1;

	if(this != NULL && cuotas > 0)
	{
		this->cuotas = cuotas;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getCuotas(eEntidad* this,int* cuotas)
{
	int retorno = -1;

	if(this!= NULL && cuotas != NULL)
	{
		*cuotas = this->cuotas;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setPrecio(eEntidad* this,int precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getPrecio(eEntidad* this,int* precio)
{
	int retorno = -1;

	if(this!= NULL && precio != NULL)
	{
		*precio = this->precio;
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


void eEntidad_printOne(eEntidad* unEntidad)
{
	int id;
	char descripcion[4000];
	int precio;
	int idTipo;
	char nombreTipo[2][100] = {"DESKTOP","LAPTOP"};
	int cuotas;
	int precioCuota;

	eEntidad_getId(unEntidad, &id);
	eEntidad_getDescripcion(unEntidad, descripcion);
	eEntidad_getPrecio(unEntidad, &precio);
	eEntidad_getIdTipo(unEntidad, &idTipo);
	eEntidad_getCuotas(unEntidad, &cuotas);
	eEntidad_getPrecioCuota(unEntidad, &precioCuota);

	printf("\n%-5d%-15s  %-15d%-10s%-17d%-5d\n",id,descripcion,precio,nombreTipo[idTipo-1],cuotas, precioCuota);

}

int eEntidad_LastId(char* id)
{
	int exito = 0;

	FILE* pFile;

	pFile = fopen("src/lastId.csv","r");

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^\n]\n",id);

		exito = 1;
	}
	fclose(pFile);

	return exito;
}


int eEntidad_buscarIdMax(LinkedList* pArrayListPassenger)
{
	int i;
	int tam=ll_len(pArrayListPassenger);
	int idMax=0;
	eEntidad* auxEntidad;

	for(i=0;i<tam;i++)
	{
		auxEntidad = (eEntidad*)ll_get(pArrayListPassenger,i);

		if(auxEntidad->id>idMax)
		{
			idMax=auxEntidad->id;
		}
	}

	return idMax;
}

int eEntidad_saveLastId(int lastId)
{
	int rtn = 0;
	FILE* pFile;

	pFile = fopen("src/lastId.csv","w");

	if(pFile != NULL)
	{
		fprintf(pFile,"%d\n",lastId);
		rtn = 1;
	}

	return rtn;
}

int eEntidad_sortCuotas(void* p1,void* p2)
{
	int retorno;
	int cuota1=0;
	int cuota2=0;

	eEntidad* entidad1 = (eEntidad*)p1;
	eEntidad* entidad2 = (eEntidad*)p2;

	    if(entidad1!=NULL && entidad2!=NULL)
	    {
            eEntidad_getCuotas(entidad1, &cuota1);
	        eEntidad_getCuotas(entidad2, &cuota2);

	       if(cuota1>cuota2)
	       {
	           retorno = 1;
	       }
	       else if(cuota1<cuota2)
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

int eEntidad_sortId(void* p1,void* p2)
{
	int retorno;
	int id1=0;
	int id2=0;

	eEntidad* entidad1 = (eEntidad*)p1;
	eEntidad* entidad2 = (eEntidad*)p2;

	    if(entidad1!=NULL && entidad2!=NULL)
	    {
	        eEntidad_getId(entidad1, &id1);
	        eEntidad_getId(entidad2, &id2);

	       if(id1>id2)
	       {
	           retorno = 1;
	       }
	       else if(id1<id2)
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
int eEntidad_setPrecioCuota(eEntidad* this,int precioCuota)
{
	int retorno = -1;

	if(this != NULL && precioCuota > 0)
	{
		this->precioCuota = precioCuota;
		retorno = 0;
	}

	return retorno;
}

int eEntidad_getPrecioCuota(eEntidad* this,int* precioCuota)
{
	int retorno = -1;

	if(this!= NULL && precioCuota != NULL)
	{
		*precioCuota = this->precioCuota;
		retorno = 0;
	}
	return retorno;
}

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

//id,nombre,sueldo,edad,profesion
//idStr,nombreStr,sueldoStr,edadStr,profesionStr
eEntidad* eEntidad_new()
{
	eEntidad* puntero;

	puntero =  (eEntidad*)malloc(sizeof(eEntidad));

	return puntero;
}
eEntidad* eEntidad_newParametros(char* idStr,char* nombreStr,char* sueldoStr, char* edadStr,char* profesionStr)
{

	eEntidad*  unEntidad = eEntidad_new();


	    if(unEntidad != NULL && idStr != NULL && nombreStr != NULL && sueldoStr != NULL && edadStr != NULL && profesionStr != NULL)
	    {
            if(eEntidad_setId(unEntidad, atoi(idStr)) == -1 ||
	    			eEntidad_setNombre(unEntidad, nombreStr) == -1 ||
					eEntidad_setSueldo(unEntidad, atoi(sueldoStr)) == -1 ||
					eEntidad_setEdad(unEntidad, atoi(edadStr)) == -1 ||
					eEntidad_setProfesion(unEntidad, profesionStr)== -1)

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

int eEntidad_setSueldo(eEntidad* this,float sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getSueldo(eEntidad* this,float* sueldo)
{
	int retorno = -1;

	if(this!= NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
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

int eEntidad_setProfesion(eEntidad* this,char* profesion)
{
	int retorno =-1;

	if(this != NULL && profesion != NULL)
	{
		strcpy(this->profesion,profesion);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getProfesion(eEntidad* this,char* profesion)
{
	int retorno = -1;

	if(this!= NULL && profesion != NULL)
	{
		strcpy(profesion,this->profesion);
		retorno = 0;
	}

	return retorno;
}


void eEntidad_printOne(eEntidad* unEntidad)
{

    int id;
	char nombre[50];
	float sueldo;
	int edad;
	char profesion[200];


	eEntidad_getId(unEntidad, &id);
	eEntidad_getNombre(unEntidad, nombre);
	eEntidad_getSueldo(unEntidad, &sueldo);
	eEntidad_getProfesion(unEntidad, profesion);
	eEntidad_getEdad(unEntidad, &edad);


	printf("\n%-5d %-15s  %-15f %-10d %-17s\n",id,nombre,sueldo,edad,profesion);

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


/*
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
	        eEntidad_getIdTipo(entidad1, &id1);
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
*/

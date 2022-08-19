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
eEntidad* eEntidad_newParametros(char* idStr,char* nombreStr,char* empleoStr, char* edadStr,char* horasTrabajadasStr)
{

	eEntidad*  unEntidad = eEntidad_new();


	    if(unEntidad != NULL && idStr != NULL && nombreStr != NULL && empleoStr != NULL && horasTrabajadasStr != NULL && edadStr != NULL)
	    {
            if(eEntidad_setId(unEntidad, atoi(idStr)) == -1 ||
	    			eEntidad_setNombre(unEntidad, nombreStr) == -1 ||
					eEntidad_setEmpleo(unEntidad, empleoStr) == -1 ||
					eEntidad_setHorasTrabajadas(unEntidad, atoi(horasTrabajadasStr)) == -1 ||
					eEntidad_setEdad(unEntidad, atoi(edadStr))== -1)

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

int eEntidad_setHorasTrabajadas(eEntidad* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getHorasTrabajadas(eEntidad* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this!= NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
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

int eEntidad_setEmpleo(eEntidad* this,char* empleo)
{
	int retorno =-1;

	if(this != NULL && empleo != NULL)
	{
		strcpy(this->empleo,empleo);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getEmpleo(eEntidad* this,char* empleo)
{
	int retorno = -1;

	if(this!= NULL && empleo != NULL)
	{
		strcpy(empleo,this->empleo);
		retorno = 0;
	}

	return retorno;
}

int eEntidad_setDedicacion(eEntidad* this,char* dedicacion)
{
	int retorno =-1;

	if(this != NULL && dedicacion != NULL)
	{
		strcpy(this->dedicacion,dedicacion);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getDedicacion(eEntidad* this,char* dedicacion)
{
	int retorno = -1;

	if(this!= NULL && dedicacion != NULL)
	{
		strcpy(dedicacion,this->dedicacion);
		retorno = 0;
	}

	return retorno;
}

void eEntidad_printOne(eEntidad* unEntidad)
{

	int id;
	char nombre[50];
	char empleo[200];
	int horasTrabajadas;
	int edad;


	eEntidad_getId(unEntidad, &id);
	eEntidad_getNombre(unEntidad, nombre);
	eEntidad_getEmpleo(unEntidad, empleo);
	eEntidad_getHorasTrabajadas(unEntidad, &horasTrabajadas);
	eEntidad_getEdad(unEntidad, &edad);


	printf("\n%-5d %-15s  %-15s %-10d %-17d\n",id,nombre,empleo,edad,horasTrabajadas);

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


void eEntidad_printOneDedicacion(eEntidad* unEntidad)
{

	int id;
	char nombre[50];
	char empleo[200];
	int horasTrabajadas;
	int edad;
	char dedicacion[200];

	eEntidad_getId(unEntidad, &id);
	eEntidad_getNombre(unEntidad, nombre);
	eEntidad_getEmpleo(unEntidad, empleo);
	eEntidad_getHorasTrabajadas(unEntidad, &horasTrabajadas);
	eEntidad_getEdad(unEntidad, &edad);
	eEntidad_getDedicacion(unEntidad, dedicacion);

	printf("\n%-5d %-15s  %-15s %-10d %-17d %s\n",id,nombre,empleo,edad,horasTrabajadas,dedicacion);

}

int eEntidad_darValorDedicacion(eEntidad* unEntidad)
{
	int retorno;
	char dedicacion[200];
   eEntidad_getDedicacion(unEntidad, dedicacion);

   if(stricmp(dedicacion,"estandar")==0)
   {
     retorno = 1;
   }

   else if(stricmp(dedicacion,"sobre la media")==0)
   {
	   retorno = 2;
   }

   else if(stricmp(dedicacion,"excesivo")==0)
   {
	   retorno = 3;
   }
   return retorno;
}

int eEntidad_sortDedicacion(void* p1,void* p2)
{
	int retorno;
	int retorno1=0;
	int retorno2=0;

	eEntidad* entidad1 = (eEntidad*)p1;
	eEntidad* entidad2 = (eEntidad*)p2;

	    if(entidad1!=NULL && entidad2!=NULL)
	    {
           retorno1=eEntidad_darValorDedicacion(entidad1);
           retorno2=eEntidad_darValorDedicacion(entidad2);

	       if(retorno1>retorno2)
	       {
	           retorno = 1;
	       }
	       else if(retorno1<retorno2)
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

*/

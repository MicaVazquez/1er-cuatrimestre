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
//id,titulo,autor,precio,editorialId
eEntidad* eEntidad_new()
{
	eEntidad* puntero;

	puntero =  (eEntidad*)malloc(sizeof(eEntidad));

	return puntero;
}

eEntidad* eEntidad_newParametros(char* idStr,char*tituloStr,char*autorStr,char*precioStr,char*editorialIdStr)
{

	eEntidad*  unEntidad = eEntidad_new();


	    if(unEntidad != NULL && idStr != NULL && tituloStr!= NULL && autorStr != NULL && precioStr != NULL && editorialIdStr != NULL)
	    {
            if(eEntidad_setId(unEntidad, atoi(idStr)) == -1 ||
	    			eEntidad_setTitulo(unEntidad, tituloStr) == -1 ||
					 eEntidad_setAutor(unEntidad, autorStr)== -1 ||
					 eEntidad_setPrecio(unEntidad,atof(precioStr))== -1 ||
					eEntidad_setEditorialId(unEntidad,atoi(editorialIdStr)) == -1)

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


int eEntidad_setEditorialId(eEntidad* this,int editorialId)
{
	int retorno = -1;

	if(this != NULL && editorialId > 0)
	{
		this->editorialId = editorialId;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getEditorialId(eEntidad* this,int* editorialId)
{
	int retorno = -1;

	if(this!= NULL && editorialId != NULL)
	{
		*editorialId = this->editorialId;
		retorno = 0;
	}
	return retorno;
}

int eEntidad_setPrecio(eEntidad* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int eEntidad_getPrecio(eEntidad* this,float* precio)
{
	int retorno = -1;

	if(this!= NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
int eEntidad_setAutor(eEntidad* this,char* autor)
{
	int retorno =-1;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor,autor);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getAutor(eEntidad* this,char* autor)
{
	int retorno = -1;

	if(this!= NULL && autor != NULL)
	{
		strcpy(autor,this->autor);
		retorno = 0;
	}

	return retorno;
}

int eEntidad_setTitulo(eEntidad* this,char* titulo)
{
	int retorno =-1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo,titulo);
		retorno = 0;
	}
	return retorno;

}
int eEntidad_getTitulo(eEntidad* this,char* titulo)
{
	int retorno = -1;

	if(this!= NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 0;
	}

	return retorno;
}


void eEntidad_printOne(eEntidad* unEntidad)
{

	int id;
	char titulo[200];
	char autor[200];
	float precio;
	int editorialId;
	char nombreEditorial[6][100]= {"PLANETA","SIGLO XXI EDITORES", "PEARSON", "MINOTAURO","SALAMANDRA", "PENGUIN BOOKS"};
	eEntidad_getId(unEntidad, &id);
	eEntidad_getTitulo(unEntidad, titulo);
	eEntidad_getAutor(unEntidad, autor);
	eEntidad_getPrecio(unEntidad, &precio);
	eEntidad_getEditorialId(unEntidad, &editorialId);

	printf("\n%d  %s %s %.2f %s\n",id,titulo,autor,precio,nombreEditorial[editorialId-1]);

}

int eEntidad_sortEditorialId(void* p1,void* p2)
{
	int retorno;
	int editorial1=0;
	int editorial2=0;

	eEntidad* entidad1 = (eEntidad*)p1;
	eEntidad* entidad2 = (eEntidad*)p2;

	    if(entidad1!=NULL && entidad2!=NULL)
	    {
            eEntidad_getEditorialId(entidad1, &editorial1);
	        eEntidad_getEditorialId(entidad2, &editorial2);

	       if(editorial1>editorial2)
	       {
	           retorno = 1;
	       }
	       else if(editorial1<editorial2)
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

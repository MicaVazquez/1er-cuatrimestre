#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entidad.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
#include <ctype.h>

/*static int idIncremental = 1001;
static int Passenger_obtenerID();
static int Passenger_obtenerID()
{
	return idIncremental++;
}*/

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
  FILE* pFile;
  int exito = 0;

	  if(path != NULL && pArrayList != NULL)
	  {
		  pFile = fopen(path,"r");

		  if(pFile != NULL)
		  {
			  parser_EntidadFromText(pFile, pArrayList);//pide pArchivo y la linkedList
			  exito = 1;
		  }
		  else
		  {
			  printf("\nNo se pudo abrir el archivo...");
		  }

		  fclose(pFile);
	  }
    return exito;
}


/** \brief Listar
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_ListEntidad(LinkedList* pArrayList)
{
	eEntidad* p;
	int cantidad = ll_len(pArrayList);
	int i;

	for(i=0;i<cantidad;i++)
	{
		p = (eEntidad*) ll_get(pArrayList,i);
		eEntidad_printOne(p);

	}
    return 1;
}


/** \brief Ordena
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_sort(LinkedList* pArrayList)
{
	//int orden = 1;// 0 descendente 1 ascendente

	printf("\nOrdenando...espere un momento por favor.\n\n");

	//ll_sort(pArrayList, eEntidad_sortName, orden);

	printf("Ordenamiento terminado\n");

    return 1;
}

int controller_mapea(LinkedList* pArrayList)
{
	if(pArrayList != NULL)
	{
      //ll_map(pArrayList, laQueMapea);

	}

	return 1;
}

LinkedList* controller_filtra(LinkedList* pArrayList)
{
	LinkedList* listaFiltrada = NULL;

	if(pArrayList != NULL)
	{
       listaFiltrada = ll_filter(pArrayList, laQuefiltra);

       if(listaFiltrada != NULL)
       {
    	   controller_ListEntidad(listaFiltrada);
       }
	}
	return listaFiltrada;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	FILE* pFile;

	eEntidad* unEntidad;

	int exito = 0;

    int id;
	char nombre[50];
	float sueldo;
	int edad;
	char profesion[200];
	int i;
	//int idMax;

	pFile = fopen(path,"w");//abre en modo escritura


	if(pFile != NULL)
	{
      fprintf(pFile,"id,nombre,sueldo,edad,profesion\n");

      for(i=0;i<ll_len(pArrayList);i++)
      {
    	  unEntidad = ll_get(pArrayList, i);

    	  eEntidad_getId(unEntidad, &id);
    	  eEntidad_getNombre(unEntidad, nombre);
    	  eEntidad_getSueldo(unEntidad, &sueldo);
    	  eEntidad_getEdad(unEntidad, &edad);
          eEntidad_getProfesion(unEntidad, profesion);

    	  fprintf(pFile,"%d,%s,%f,%d,%s\n", id,nombre,sueldo,edad,profesion);//
      }
      printf("Datos guardados en modo texto!!!\n");
      fclose(pFile);

     // idMax = eEntidad_buscarIdMax(pArrayList);//busca el mayor id del archivo

     // eEntidad_saveLastId(idMax);

      exito = 1;
	}
	else
	{
		printf("\nNo se pudo abrir el archivo...");
	}
    return exito;
}

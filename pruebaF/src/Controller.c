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
//id,tipo,cantidad,importe
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


/** \brief Listar
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_ListEntidadDedicacion(LinkedList* pArrayList)
{
	//eEntidad* p;
	int cantidad = ll_len(pArrayList);
	int i;

	for(i=0;i<cantidad;i++)
	{
		//p = (eEntidad*) ll_get(pArrayList,i);
		//eEntidad_printOneDedicacion(p);

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

	ll_sort(pArrayList, eEntidad_sortPower, 0);

	printf("Ordenamiento terminado\n");

    return 1;
}

int controller_mapea(LinkedList* pArrayList)
{
	if(pArrayList != NULL)
	{
      ll_map(pArrayList, laQueMapea);

	}
	return 1;
}


LinkedList* controller_filtra(LinkedList* pArrayList)
{
	LinkedList* listaFiltrada = NULL;

	if(pArrayList != NULL)
	{
       //listaFiltrada = ll_filter(pArrayList, laQuefiltra);

       if(listaFiltrada != NULL)
       {
    	   //controller_ListEntidadDedicacion(listaFiltrada);
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
	char descripcion[400];
	int idPropietario;
	int power;
	int ataque;

	int i;


	pFile = fopen(path,"w");//abre en modo escritura


	if(pFile != NULL)
	{
      fprintf(pFile,"id,descripcion,idPropietario,power,ataque\n");

      for(i=0;i<ll_len(pArrayList);i++)
      {
    	  unEntidad = ll_get(pArrayList, i);

    	  eEntidad_getId(unEntidad, &id);
    	  eEntidad_getDescripcion(unEntidad, descripcion);
    	  eEntidad_getIdPropietario(unEntidad, &idPropietario);
    	  eEntidad_getPower(unEntidad, &power);
    	  eEntidad_getAtaque(unEntidad, &ataque);


    	  fprintf(pFile,"%d,%s,%d,%d,%d\n",id,descripcion,idPropietario,power,ataque);//
      }
      printf("Datos guardados en modo texto!!!\n");
      fclose(pFile);



      exito = 1;
	}
	else
	{
		printf("\nNo se pudo abrir el archivo...");
	}
    return exito;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entidad.h"
#include "Parser.h"
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


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayList)
{
	FILE* pFile;
	int exito = 0;

	if(path != NULL && pArrayList != NULL)
	{
		pFile = fopen(path,"rb");

		if(pFile != NULL)
		{
			parser_EntidadFromBinary(pFile, pArrayList);
			exito = 1;
		}
		else
		{

			printf("\nError al leer el archivo\n");
		}
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


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_sort(LinkedList* pArrayList)
{
	int orden = 0;// 0 descendente 1 ascendente

	printf("\nOrdenando...espere un momento por favor.\n\n");

	ll_sort(pArrayList, eEntidad_sortCuotas, orden);

	printf("Ordenamiento terminado\n");

    return 1;
}

LinkedList* controller_mapea(LinkedList* pArrayList)
{
	LinkedList* listaMapeada = NULL;
	if(pArrayList != NULL)
	{
		ll_sort(pArrayList, eEntidad_sortId, 1);
       listaMapeada = ll_map(pArrayList, laQueMapea);

       if(listaMapeada != NULL)
       {
    	   controller_ListEntidad(listaMapeada);
       }
	}
	return listaMapeada;
}

int controller_filtra(LinkedList* pArrayList)
{
	int rtn = -1;
	//LinkedList* listaFiltrada = NULL;

	if(pArrayList != NULL)
	{

	}
	return rtn;
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
	char descripcion[4000];
	int precio;
	int idTipo;
	int cuotas;
	int precioCuota;

	int i;
	//int idMax;

	pFile = fopen(path,"w");//abre en modo escritura


	if(pFile != NULL)
	{
      fprintf(pFile,"id,descripcion,precio,idTipo,cuotas,precioCuota\n");

      for(i=0;i<ll_len(pArrayList);i++)
      {
    	  unEntidad = ll_get(pArrayList, i);

    	  eEntidad_getId(unEntidad, &id);
    	  eEntidad_getDescripcion(unEntidad, descripcion);
    	  eEntidad_getPrecio(unEntidad, &precio);
    	  eEntidad_getIdTipo(unEntidad, &idTipo);
    	  eEntidad_getCuotas(unEntidad, &cuotas);
    	  eEntidad_getPrecioCuota(unEntidad, &precioCuota);


    	  fprintf(pFile,"%d,%s,%d,%d,%d,%d\n", id,descripcion,precio,idTipo,cuotas,precioCuota);//
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

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayList)
{
	FILE* pFile;
	eEntidad* unEntidad;

	int i;
	int tam;
	int exito = 0;

	pFile = fopen(path,"wb");

	if(pFile != NULL)
	{
		tam = ll_len(pArrayList);

		for(i=0;i<tam;i++)
		{
			unEntidad = (eEntidad*)ll_get(pArrayList, i);
			fwrite(unEntidad,sizeof(eEntidad),1,pFile);
		}

		printf("Datos guardados en modo binario!!!\n");
		fclose(pFile);
		exito = 1;
	}
	else
	{
		printf("\nNo se pudo abrir el archivo...");
	}

    return exito;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayList)
{
   eEntidad* unEntidad = eEntidad_new();

   // 1=>DESKTOP; 2=>LAPTOP.
   int id;
   char descripcion[4000];
   int precio;
   int idTipo;
   int cuotas;

   int exito = 0;

   char idMax[100];

    eEntidad_LastId(idMax);

    id = atoi(idMax);


 if(unEntidad != NULL)
 {
	// id = Passenger_obtenerID();

     getString("\n Ingrese descripcion ", descripcion, 1, 200);

	 getInt("\nIngrese el precio: ",&precio,1,99999999);

	 getInt("\nIngrese el tipo 1=>DESKTOP;\n 2=>LAPTOP: \n",&idTipo,1,2);

	 getInt("\nIngrese el cuota: ",&cuotas,1,12);



	 if(eEntidad_setId(unEntidad, id + 1) == -1 ||
			 eEntidad_setDescripcion(unEntidad, descripcion) == -1 ||
			 eEntidad_setPrecio(unEntidad, precio) == -1 ||
			 eEntidad_setIdTipo(unEntidad, idTipo) == -1 ||
			 eEntidad_setCuotas(unEntidad, cuotas)== -1)

	 {
		 eEntidad_delete(unEntidad);
	 }
	 else
	 {
		 exito = 1;//exito en alta
		 ll_add(pArrayList, unEntidad);
	 }

 }
   return exito;
}



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
//id,nombre,horasTrabajadas,sueldo
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

	ll_sort(pArrayList, eEntidad_sortId, 0);

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
	//char confirmar[4];
	int option;

	if(pArrayList != NULL)
	{
		getInt("\nElegir un genero \n1.Accion \n2.Aventura \n3.Animacion \n4.Familiar \n5.Fantasia \n6.Ciencia Ficcion \n opcion: \n", &option, 1, 6);
       //listaFiltrada = ll_filter(pArrayList, laQuefiltra);
		switch(option)
		{
		case 1:
            listaFiltrada = ll_filter(pArrayList, filtraAccion);
            controller_ListEntidad(listaFiltrada);
			break;
		case 2:
			listaFiltrada = ll_filter(pArrayList, filtraAventura);
			controller_ListEntidad(listaFiltrada);
			break;
		case 3:
			listaFiltrada = ll_filter(pArrayList, filtraAnimacion);
			controller_ListEntidad(listaFiltrada);
			break;
		case 4:
			listaFiltrada = ll_filter(pArrayList, filtraFamiliar);
			controller_ListEntidad(listaFiltrada);
			break;
		case 5:
			listaFiltrada = ll_filter(pArrayList, filtraFantasia);
			controller_ListEntidad(listaFiltrada);
			break;
		case 6:
			listaFiltrada = ll_filter(pArrayList, filtraCienciaFiccion);
			controller_ListEntidad(listaFiltrada);
			break;
		default:
			printf("\n Opcion  no valida");
			break;
		}

      /* if(listaFiltrada != NULL)
       {
    	   controller_ListEntidad(listaFiltrada);

    	   while((stricmp(confirmar,"si")) && (stricmp(confirmar,"no")))
    	   {
    		   getString("\nDesea guardar la lista (ingrese si o no)?\n\n",confirmar,2,2);
    	   }

    	   if(stricmp(confirmar,"si")==0)
    	   {
               controller_saveAsText("src/filtrado.csv", pArrayList);
    		   printf("Se ha guardado la lista...");

    	   }
    	   else
    	   {
    		   printf("No se han guardado la lista...");

    	   }
       }*/
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
	char nombre[200];
	int anio;
	char genero[200];

	int i;
	//int idMax;

	pFile = fopen(path,"w");//abre en modo escritura


	if(pFile != NULL)
	{
      fprintf(pFile,"id,nombre,anio,genero\n");

      for(i=0;i<ll_len(pArrayList);i++)
      {
    	  unEntidad = ll_get(pArrayList, i);

    	  eEntidad_getId(unEntidad, &id);
    	  eEntidad_getNombre(unEntidad, nombre);
    	  eEntidad_getAnio(unEntidad, &anio);
    	  eEntidad_getGenero(unEntidad, genero);

    	  fprintf(pFile,"%d,%s,%d,%s\n", id,nombre,anio,genero);//
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

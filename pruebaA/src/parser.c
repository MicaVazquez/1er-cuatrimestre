#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entidad.h"

/** \brief Parsea los datos los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_EntidadFromText(FILE* pFile , LinkedList* pArrayList)
{
	char id[50];
	char nombre[50];
	char empleo[200];
	char horasTrabajadas[200];
	char edad[100];

   eEntidad* unEntidad;
   int cant;
   int exito = 0;

  // fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,horasTrabajadas,edad);//falsa lectura

   while(feof(pFile)==0)
   {
	     cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horasTrabajadas);

	     if(cant == 5)//varia segun cantidad de datos del archivo IMPORTANTE
	     {
           unEntidad = eEntidad_newParametros(id,nombre,empleo,edad,horasTrabajadas);

           if(unEntidad != NULL)
           {
        	   ll_add(pArrayList, unEntidad);
        	   exito = 1;
           }
	     }
   }
    return exito;
}

/** \brief Parsea los datos los datos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
/*
int parser_EntidadFromBinary(FILE* pFile , LinkedList* pArrayList)
{
	eEntidad* unEntidad;
	eEntidad auxEntidad;


	while(!feof(pFile))
	{
		unEntidad = eEntidad_new();
		fread(&auxEntidad,sizeof(eEntidad),1,pFile);

		if(feof(pFile))
		{
			break;
		}

		eEntidad_setId(unEntidad, auxEntidad.id);
		eEntidad_setDescripcion(unEntidad, auxEntidad.descripcion);
		eEntidad_setPrecio(unEntidad, auxEntidad.precio);
		eEntidad_setIdTipo(unEntidad, auxEntidad.idTipo);,,,,,,m

		eEntidad_setCuotas(unEntidad, auxEntidad.cuotas);

       ll_add(pArrayList,unEntidad);

	}

    return 1;
}
*/

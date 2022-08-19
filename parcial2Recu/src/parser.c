#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "participante.h"

//id,nombre,sueldo,edad,profesion
/** \brief Parsea los datos los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_EntidadFromText(FILE* pFile , LinkedList* pArrayList)
{
	// CHAR
	char id[200];
	char nombre[200];
	char edad[200];
	char idDificultad[200];
	char score[200];
//id,nombre,edad,idDificultad,score

   eEntidad* unEntidad;
   int cant;
   int exito = 0;

  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,idDificultad,score);//falsa lectura necesario o no

   while(feof(pFile)==0)
   {
	     cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,idDificultad,score);

	     if(cant == 5)//varia segun cantidad de datos del archivo IMPORTANTE
	     {
           unEntidad = eEntidad_newParametros(id,nombre,edad,idDificultad,score);

           if(unEntidad != NULL)
           {
        	   ll_add(pArrayList, unEntidad);
        	   exito = 1;
           }
	     }
   }
    return exito;
}



/*
 * avion.c
 *
 *  Created on: 14 may. 2022
 *      Author: PC-INC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "validaciones.h"
#include "avion.h"

#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

#define CANCELADO 0
#define DEMORADO 1
#define ACTIVO 2


int altaVuelos(eAvion* listaA,int lenA)
{

	int indiceLibre;
	int rtn = -2 ;
	char auxCV[10];


	indiceLibre = buscarLibreCodigoVuelo(listaA,lenA);

	if(indiceLibre != -1 && listaA != NULL)
	{
       getLetrasYNumeros("\n Ingrese un nuevo codigo de vuelo: ", auxCV, 1, 10);//codigo de vuelo
       if(buscarRepetido(listaA, lenA,auxCV )==1)
       {
    	   printf("\nError.Ese codigo ya existe.\n");
       }
       else
       {
    	   strcpy(listaA[indiceLibre].IDcodigoDeVuelo,auxCV);
       }

        listaA[indiceLibre].estadoDeVuelo = CANCELADO;
        listaA[indiceLibre].isEmptyCV = OCUPADO;

		rtn = 1;
	}
	else
	{
		printf("\n No hay espacio...");
	}

return rtn;
}


int buscarLibreCodigoVuelo(eAvion* list, int len)
{
	int i;
	int indice=-1;

	if( list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmptyCV == LIBRE)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}



void inicializarCodigosVuelos(eAvion* listA, int lenA)
{
	int i;
	if(listA != NULL && lenA > 0)
	{

		for(i=0;i<lenA;i++)
		{
			listA[i].isEmptyCV = LIBRE;

		}

	}
}


int buscarRepetido(eAvion* listaAv, int lenA,char* input)
{
     int i;
     int rtn = 0;

     for(i=0;i<lenA;i++)
     {
        if(stricmp(listaAv[i].IDcodigoDeVuelo,input)==0)
        {
        	rtn= 1;//true
        	break;
        }
     }
     return rtn;
}



void modificarEstadoVuelo(eAvion* listaAviones,int lenA)
{

 int i;
 int opcionCodigo;
 int opcionEstado;
 char estado[][31] = {"Cancelado","Demorado","Activo"};

  printf("\nElija un codigo de vuelo: ");

       for(i=0;i<lenA;i++)
       {
    	   if(listaAviones[i].isEmptyCV == OCUPADO)
    	   {
       	      printf("\n\n %d. %s | %s",i+1,listaAviones[i].IDcodigoDeVuelo,estado[listaAviones[i].estadoDeVuelo]);
    	   }
       }

    getInt("\nOpcion: ",&opcionCodigo,1,lenA);

    getInt("\n Elija un estado de vuelo: \n1.Cancelado \n2.Demorado \n3.Activo \n.Opcion: ",&opcionEstado,1,3);

    listaAviones[opcionCodigo-1].estadoDeVuelo = opcionEstado-1;
}

void hardcodearAvion(eAvion* list)
{
	int i;
	char IDcodigoDeVuelo[][10]={"RFG2","DRG3","ERT7","JTU1","CWR9"};//PK
	int estadoDeVuelo[]= {DEMORADO,DEMORADO,ACTIVO,CANCELADO,ACTIVO};
	int isEmptyCV[] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

	for(i=0;i<5;i++)
		{
			strcpy(list[i].IDcodigoDeVuelo,IDcodigoDeVuelo[i]);
			list[i].estadoDeVuelo = estadoDeVuelo[i];
			list[i].isEmptyCV = isEmptyCV[i];
		}
}

/*
 * arrays.c
 *
 *  Created on: 19 abr. 2022
 *      Author: PC-INC
 */
#include <stdio.h>
#include <stdlib.h>
void imprimirArray(int array[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf(" %d ",array[i]);
    }
}

void listarNumerosPares (int array [],int TAM)
{  int i;
	for(i=0;i<TAM;i++)
	         {
	        	 if(array[i]%2==0)
	        	 {
	        		printf(" %d ",array[i]); //B
	        	 }
	         }
}

void listarNumerosPosicionImpar(int array [], int TAM)
{  int i;
	for(i=0;i<TAM;i++)
	     {
	    	 if(i%2==0)
	    	 {
	    		 printf(" %d ",array[i]);
	    	 }
	     }

}

void inicializarVector(int vector[], int tamanio)//siemore hay que paar el tamaño el array
{
	int i;
	for(i=0; i<tamanio;i++)
	{
		vector[i]=0;//inicializar con un valor que no sea valido
	}
}

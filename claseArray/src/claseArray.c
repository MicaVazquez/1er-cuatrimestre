/*
 ============================================================================
 Name        : claseArray.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 5
void inicializarVector(int vector[],int tamanio);// paso el vector en cuestion y el tamaño de dicho vector
int buscarDato (int vector[],int tamanio,int dato);
int main(void) {
	int vec[CANT],i;

//	inicializarVector(vec,CANT);

	puts("lalala"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
void inicializarVector(int vector[], int tamanio)//siemore hay que paar el tamaño el array
{
	int i;
	for(i=0; i<tamanio;i++)
	{
		vector[i]=0;//inicializar con un valor que no sea valido
	}
}
int buscarDato (int vector[],int tamanio,int dato)
{
	int i;
	int retorno=0;
	for(i=0;i<tamanio;i++)//posición seria i siemore tiene que estar
	{
      if(vector[i] == dato)
      {
    	  retorno=dato;
    	  break;
      }

	}
	return retorno;
}

/*
 ============================================================================
 Name        : Ejercicio5-3.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 10

int main(void)
{   setbuf(stdout, NULL);
	int numeros[CANT];
    int i;
    int negativos[CANT];
    int positivos[CANT];
    int contadorPositivos=0;
    int contadorNegativos=0;

    for(i=0;i<CANT;i++)
    {
    	printf("Ingrese un número entero: \n");
    	scanf("%d",&numeros[i]);
    	if(numeros[i]<0)
    	{
    	  negativos[contadorNegativos]= numeros[i];
    	  contadorNegativos++;//contadorNegativos=contadorNegativos+1;
    	}
    	else
    	{
    		if(numeros[i]>0)
    		{
    			positivos[contadorPositivos]= numeros[i];
    			contadorPositivos++;
    		}
    	}
    }

    for(i=0;i<CANT;i++)
    {
      printf("%d\n",numeros[i]);
    }

	return EXIT_SUCCESS;
}

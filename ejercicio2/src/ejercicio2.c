/*
 ============================================================================
 Name        : ejercicio2.c
 Author      : Micaela V�zquez Programaci�n 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int numero3;
	int mayor;

	printf("Ingrese el primer n�mero: ");
	scanf("%d",&numero1);

	printf("Ingrese el segundo n�mero: ");
	scanf("%d",&numero2);

	printf("Ingrese el tercer n�mero: ");
    scanf("%d",&numero3);

    if(numero1>numero2&&numero1>numero3)
    {
      mayor=numero1;
      printf("El mayor de los n�meros es el primero : %d", mayor);
    }
    else
    {
    	if(numero2>numero3)
		{
    		 mayor=numero2;
    		 printf("El mayor de los n�meros es el segundo: %d",mayor);
    	}
    	else
    	{
    		mayor=numero3;
    		printf("El mayor de los numero es el tercero: %d",mayor);
    	}
    }

	return EXIT_SUCCESS;
}

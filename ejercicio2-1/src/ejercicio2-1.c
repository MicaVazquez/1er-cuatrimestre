/*
 ============================================================================
 Name        : ejercicio2-1.c
 Author      : Micaela V�zquez Programaci�n 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 //Ingresar 5 n�meros enteros calcular y mostrar el promedio de los n�meros. Probar la
aplicaci�n con distintos valores.
Ejemplo 1: 3 - 5 - 7 - 9 - 1
Ejemplo 2: 2 - 1 - 8 -1 - 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   setbuf(stdout,NULL);
	int numero;
	int i;
	int acumulador;
	float promedio;

	acumulador=0;

	for(i=0;i<5;i++)
	{
		printf("Ingrese un n�mero : ");
		scanf("%d",&numero);

		acumulador+=numero;
	}

	promedio = (float)acumulador/i;

	printf("El promedio de los n�meros es de : %.2f \n",promedio);
	return EXIT_SUCCESS;
}

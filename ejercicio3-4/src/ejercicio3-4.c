/*
 ============================================================================
 Name        : ejercicio3-4.c
 Author      : Micaela Vázquez DIV 1-K Programacion 1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Especializar la función anterior para que permita validar el entero ingresado en un rango
determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ingreseEntero (void);
int main(void)
{
	setbuf(stdout,NULL);
	int nota;
	nota=ingreseEntero();
	printf("El número que ingreso el usuario es: %d", nota);

	return EXIT_SUCCESS;
}
int ingreseEntero (void)
{
	int a;
	printf("Ingrese un entero: ");
	scanf("%d",&a);

	while(a<1 || a>10)
	{
		printf("Reingrese un entero: ");
		scanf("%d",&a);
	}
	return a;
}

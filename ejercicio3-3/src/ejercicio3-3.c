/*
 ============================================================================
 Name        : ejercicio3-3.c
 Author      : Micaela Vázquez DIV 1-K Programacion 1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int ingresoEntero (void);
int main(void)
{
	setbuf(stdout,NULL);
	int nota;
    nota = ingresoEntero();

    printf("El número que ingreso el usuario es %d",nota);
	return EXIT_SUCCESS;
}
int ingresoEntero (void)
{   int a;
	printf("Ingrese un entero: ");//pide el numero, lo guarda y lo devuelve;
	scanf("%d",&a);
	return a;
}

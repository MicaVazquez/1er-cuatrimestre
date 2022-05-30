/*
 ============================================================================
 Name        : ejercicio.c
 Author      : Micaela Vazquez Programación 1-K ejercicio1
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
	int resultado;

	    printf("ingrese el primer numero: ");
	    scanf("%d",&numero1);

	    printf("ingrese el segundo numero: ");
	    scanf("%d",&numero2);

	    resultado = numero1 + numero2;

	    printf("La suma entre %d y %d da como resultado %d",numero1,numero2,resultado);

	return EXIT_SUCCESS;
}

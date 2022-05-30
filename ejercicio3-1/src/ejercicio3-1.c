/*
 ============================================================================
 Name        : ejercicio3-1.c
 Author      : Micaela Vázquez DIV 1-K Programacion 1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Crear una función que muestre por pantalla el número flotante que recibe como parámetro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mostrar (float);
int main(void)
{   setbuf(stdout,NULL);
	float numeroF;
    printf("Ingrese un número flotante: ");
    scanf("%f",&numeroF);

	mostrar(numeroF);

	return EXIT_SUCCESS;
}

void mostrar (float a)  //void funciona como un ejecutable ene este caso
{
	printf("El número flotante es: %.2f",a);
}

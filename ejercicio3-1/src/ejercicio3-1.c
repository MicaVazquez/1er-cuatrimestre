/*
 ============================================================================
 Name        : ejercicio3-1.c
 Author      : Micaela V�zquez DIV 1-K Programacion 1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Crear una funci�n que muestre por pantalla el n�mero flotante que recibe como par�metro.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void mostrar (float);
int main(void)
{   setbuf(stdout,NULL);
	float numeroF;
    printf("Ingrese un n�mero flotante: ");
    scanf("%f",&numeroF);

	mostrar(numeroF);

	return EXIT_SUCCESS;
}

void mostrar (float a)  //void funciona como un ejecutable ene este caso
{
	printf("El n�mero flotante es: %.2f",a);
}

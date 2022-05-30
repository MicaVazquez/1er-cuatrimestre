/*
 ============================================================================
 Name        : ejercicio3-2.c
 Author      :  Micaela Vázquez DIV 1-K Programacion 1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int parOimpar (int a);
int main(void)
{
	setbuf(stdout,NULL);
	int numero;
	int resultado;
	printf("Ingrese un número: ");
	scanf("%d",&numero);

	resultado=parOimpar(numero);

	if(resultado==1)
	{
		printf("Número par.");
	}
	else
	{
		printf("Número impar.");
	}
	return EXIT_SUCCESS;
}
int parOimpar(int a)
{
    if(a%2==0)
    {
    	return 1;
    }
    else
    {
    	return 0;
    }
}

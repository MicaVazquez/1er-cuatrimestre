/*
 ============================================================================
 Name        : ejercicio3-2.c
 Author      :  Micaela V�zquez DIV 1-K Programacion 1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Crear una funci�n que permita determinar si un n�mero es par o no. La funci�n retorna 1 en caso
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
	printf("Ingrese un n�mero: ");
	scanf("%d",&numero);

	resultado=parOimpar(numero);

	if(resultado==1)
	{
		printf("N�mero par.");
	}
	else
	{
		printf("N�mero impar.");
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

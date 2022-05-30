/*
 ============================================================================
 Name        : ejercicio3.c
 Author      : Micaela V�zquez Programaci�n 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   setbuf(stdout,NULL);
	int nro1;
	int nro2;
	int nro3;
	int medio;

	printf("primer n�mero: ");
	scanf("%d",&nro1);

	printf("segundo n�mero: ");
	scanf("%d",&nro2);

	printf("tercer n�mero: ");
	scanf("%d",&nro3);

	if(nro1 != nro2 && nro2 != nro3 && nro1 != nro3)
	{
		if((nro1 > nro2 && nro1 < nro3) || (nro1 < nro2 && nro1 > nro3))
		{
			medio=nro1;
		}
		else
		{
			if((nro2 > nro1 && nro2 < nro3) || (nro2 > nro3 && nro2 < nro1))
			{// 5    4       5     6      5    4       5    6
				medio=nro2;
			}
			else
			{
				medio=nro3;
			}
		}
		printf("El n�mero del medio es: %d ", medio);
	}
	else
	{
		printf("No existe un n�mero medio.");
	}


	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : ejercicioSabado1-2.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ingresar 5 n�meros. Determinar cu�l es el m�ximo y el m�nimo e indicar en qu� orden fue ingresado.
 No
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int i;
    int numero;
    int numeroMinimo;
    int numeroMaximo;
    int ordenMinimo;
    int ordenMaximo;


	for(i=0;i<5;i++)
	{
		printf("Ingrese un n�mero: ");
		scanf("%d",&numero);

		if(numero<numeroMinimo || i==0)
		{
			numeroMinimo=numero;
			ordenMinimo=i;

		}

		if(numero>numeroMaximo || i==0)
		{
			numeroMaximo=numero;
			ordenMaximo=i;

		}

	}     //no me da bien el orden
   printf("El n�mero minimo es %d y su posici�n %d \n",numeroMinimo,ordenMinimo);
   printf("El n�mero maximo es %d y su posici�n %d \n",numeroMaximo,ordenMaximo);
	return EXIT_SUCCESS;
}

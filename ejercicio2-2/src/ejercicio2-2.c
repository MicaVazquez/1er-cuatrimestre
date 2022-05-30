/*
 ============================================================================
 Name        : ejercicio2-2.c
 Author      : Micaela Vázquez Programacion 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 //Ingresar 10 números enteros, distintos de cero. Mostrar:
  *  a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   setbuf(stdout,NULL);
	int numero;
	int i;
	int contadorPares;
	int contadorImpares;
	int menorNumero;
	int mayorPar;
	int acumuladorPositivos;
	int acumuladorNegativos;
	int contadorNegativos;
	int contadorPositivos;

	contadorPares=0;
	contadorImpares=0;
	acumuladorPositivos=0;
	acumuladorNegativos=1;//lo inicio en uno porque multiplica.
	contadorNegativos=0;
	contadorPositivos=0;

	for(i=0;i<10;i++)
	{
		printf("Ingrese un número: ");
		scanf("%d",&numero);

		while(numero == 0)
		{
			printf("Reingresar numero: ");
			scanf("%d",&numero);
		}

		if(numero%2==0)//par
		{     // mayor numero de los pares
			if(numero>mayorPar || contadorPares == 0)
			{
				mayorPar=numero;
			}
			contadorPares++;
		}
		else  //impar
		{
			contadorImpares++;
		}

		//menor numero ingresado

		if(numero<menorNumero || i==0)
		{
			menorNumero=numero;
		}

      if(numero>0)//positivos
      {
    	  acumuladorPositivos+=numero;
    	  contadorPositivos++;
      }
      else //negativos
      {
    	  acumuladorNegativos*=numero;
    	  contadorNegativos++;
      }
	}

	printf("Cantidad de pares: %d e impares : %d \n",contadorPares,contadorImpares);
	printf("El menor de los numeros ingresados: %d \n",menorNumero);
	printf("De los pares el mayor numero ingresado: %d \n",mayorPar);

	if(contadorPositivos != 0)
	{
	  printf("La suma de los positivos es: %d \n",acumuladorPositivos);
	}
	else
	{
		printf("No hay suma de positivos \n.");
	}

	if(contadorNegativos != 0)
	{
	  printf("Producto de los negativos: %d \n",acumuladorNegativos);
	}
	else
	{
		printf("No hay producto de negativos \n.");
	}


	return EXIT_SUCCESS;
}

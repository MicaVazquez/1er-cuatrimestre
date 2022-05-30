/*
 ============================================================================
 Name        : ejercicioSabado1-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;
	int contador;
	int acumuladorNumeroPositivo;
	int acumuladorNumeroNegativo;
	int contadorNumeroPositivo;
	int contadorNumeroNegativo;
	char respuesta;
	float promedioNumeroNegativo;
	float promedioNumeroPositivo;


	respuesta='s',

    contador=0;
	acumuladorNumeroPositivo=0;
	acumuladorNumeroNegativo=0;
	contadorNumeroPositivo=0;
	contadorNumeroNegativo=0;

	while(respuesta == 's')
	{
		printf("ingrese un número: ");
		scanf("%d",&numeroIngresado);

		if(numeroIngresado>0)
		{
	    acumuladorNumeroPositivo= acumuladorNumeroPositivo + numeroIngresado;
		contadorNumeroPositivo++;
		}
		else
		{
	     acumuladorNumeroNegativo= acumuladorNumeroNegativo + numeroIngresado;
	     contadorNumeroNegativo++;
		}

		printf("Desea continuar 's' o 'n'? ");
		fflush(stdin);
		scanf("%c", &respuesta);
	contador++;
	}

	if(contadorNumeroNegativo != 0)
	{
		promedioNumeroNegativo = (float)acumuladorNumeroNegativo/contadorNumeroNegativo; //division de dos enteros- se cambia el tipo numerico de uno al castear
		printf(" El promedio de los números negativos : %.2f \n", promedioNumeroNegativo);//.2 es para que me muestre dos digitos despues del punto.
	}
	else
	{
		printf("No se ingresaron números negativos para el promedio.\n");
	}

	if(contadorNumeroPositivo != 0)
	{
		promedioNumeroPositivo = (float)acumuladorNumeroPositivo/contadorNumeroPositivo;
		printf(" El promedio de los números positivos : %.2f \n", promedioNumeroPositivo);
	}
	else
	{
		printf("No se ingresaron números positivos para el promedio.\n");
	}

	return EXIT_SUCCESS;
}

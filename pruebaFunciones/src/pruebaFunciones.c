/*
 ============================================================================
 Name        : pruebaFunciones.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
float porcentaje(int precio, float valor);
float aumento(int precio, int incremento);
float dividir(float dividendo, int divisor);
int valorAbsoluto(int x);
int resta(int a, int b);
float multiplicar(int a, float b);
float calcularDescuento(int precio, int rebaja);
float dividirEnteros(int dividendo, int divisor);
int pedirEnteroPositivo(char mensaje[],char error[]);
int calcularFactorial(int numero);
int sumaDeAntecesoresNegativos( int numeroNegativo);
int main(void) {
	setbuf(stdout, NULL);

     int numero=-10;
     int resultado;
     char palabra[10] = {"chau"};
     int len;

     printf(" mostrar palabras: %s\n", palabra);
     len = strlen(palabra);
     printf("len : %d", len);
     resultado = sumaDeAntecesoresNegativos(numero);




    printf("%d", resultado);
	return EXIT_SUCCESS;
}


float porcentaje(int precio, float valor)
{
	float resultado;

	resultado = (precio * valor);
	return resultado;
}

float aumento(int precio, int incremento)
{
	float resultadoAumento;
	resultadoAumento = precio + (precio * (float) incremento / 100);
	return resultadoAumento;
}

float dividir(float dividendo, int divisor)//funciona para dividir bitcoin y precio
{
	float resultadoDivision;

	resultadoDivision = dividendo / divisor;

	return resultadoDivision;
}

float dividirEnteros(int dividendo, int divisor)//
{
	float resultado;
	resultado = (float) dividendo /  divisor;//importante castear
	return resultado;
}

int resta(int a, int b)
{
	int resta;
	resta = a - b;
	return resta;
}

int valorAbsoluto(int x)
{
	int resultado;
	if(x<0)
	{
		resultado=x*-1;
		return resultado;
	}
	return x;
}

float multiplicar(int a, float b)
{
    float resultado;
	resultado = a*b;
	return resultado;
}
float calcularDescuento(int precio, int rebaja)
{
	float resultadoDescuento;

	 resultadoDescuento= precio-(precio*(float)rebaja/100);
	 return resultadoDescuento;
}
int pedirEnteroPositivo(char mensaje[],char error[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d", &numero);

    while(numero < 1)
    {
        printf("%s",error);
        scanf("%d", &numero);
    }

    return numero;
}
int calcularFactorial(int numero)
{
    int acumulador=1;
    int i;
    for(i=1; i<=numero; i++)
    {
        acumulador=acumulador*i;
    }
    return acumulador;
}

int sumaDeAntecesoresNegativos( int numeroNegativo)
{
    int i;
    int acumulador = 0;

    for(i=0;i>numeroNegativo;i--)
    {
      acumulador+=i;
    }
return acumulador;
}

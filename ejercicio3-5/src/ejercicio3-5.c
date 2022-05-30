/*
 ============================================================================
 Name        : ejercicio3-5.c
 Author      : Micaela Vázquez DIV 1K Programación
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4
combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int sumar1 (int a, int b);
int sumar2 (void);
void sumar3(int a, int b);
void sumar4(void);

int numero3;
int numero4;
int resultadoSumaTres;



int main(void)
{
	setbuf(stdout,NULL);
	int x;
	int y;
	int resultadoSuma;


	printf("Ingrese el primer número: ");
	scanf("%d",&x);

	printf("Ingrese el segundo número: ");
	scanf("%d",&y);

	resultadoSuma= sumar1(x,y);

    printf("La suma es: %d", resultadoSuma);

    resultadoSuma= sumar2();

    printf("\nLa segunda suma es: %d",resultadoSuma);

    sumar3(x,y);
    printf("\nLa tercera suma es: %d",resultadoSumaTres);

    sumar4();
    printf("\n La cuarta suma: %d", resultadoSumaTres);

	return EXIT_SUCCESS;
}
int sumar1 (int a, int b)
{
   int total;
   total=a+b;
   return total;
}
int sumar2 (void)
{
	int resultado;
	printf("\ningrese un tercer numero: ");
	scanf("%d",&numero3);

	printf("\ningrese un cuarto número: ");
	scanf("%d",&numero4);
	resultado=numero3+numero4;
	return resultado;
}
void sumar3(int a, int b)
{
	resultadoSumaTres=a+b;
}
void sumar4(void)
{
	printf("\n ingrese un tercer numero: ");
	scanf("%d",&numero3);

	printf("\n ingrese un cuarto número: ");
	scanf("%d",&numero4);
	resultadoSumaTres=numero3+numero4;
}

/*5574*/



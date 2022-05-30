/*
 ============================================================================
 Name        : ejercicio5-2.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Pedir el ingreso de 10 n�meros enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los n�meros ingresados.
e) Listado de los n�meros pares.
f) Listado de los n�meros de las posiciones impares.
Anexo 5-2
g) Los n�meros que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deber�n utilizar funciones y vectores.
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "arrays.h"

#define CANT 10

int main(void)
{     setbuf(stdout,NULL);

     int arrayNumeros[CANT];
     int contadorNegativos=0;
     int contadorPositivos=0;
     int acumuladorParesSuma=0;
     int mayorImpar;
     int banderaMayorImpar=0;

     int arrayNumerosPositivos[CANT];
     int arrayNumerosNegativos[CANT];

     int i;


     for(i=0;i<CANT;i++)
     {
    	 utn_getNumero(&arrayNumeros[i],"Ingrese 10 n�meros enteros entre -1000 y 1000 : \n","Error ingreso un numero fuera del rango permitido.Reingrese\n", -1000,1000,1);

     }

     for(i=0;i<CANT;i++)   //A
     {
    	 if(arrayNumeros[i]>0)
    	 {
    		 contadorPositivos++;
    	 }
    	 else
    	 {
    		 contadorNegativos++;
    	 }
     }

     printf("\nCantidad positivos: %d",contadorPositivos);
     printf("\nCantidad negativos: %d",contadorNegativos);


     for(i=0;i<CANT;i++)
     {
    	 if(arrayNumeros[i]%2==0)
    	 {
    		acumuladorParesSuma+=arrayNumeros[i]; //B
    	 }
     }

     printf("\nLa suma de los pares es de :%d",acumuladorParesSuma);

     //C

     for(i=0;i<CANT;i++)
     {
    	if(arrayNumeros[i]%2!=0)
    	{
    		if(arrayNumeros[i]>mayorImpar || banderaMayorImpar==0)
    		{
    			mayorImpar = arrayNumeros[i];
    			banderaMayorImpar=1;
    		}
    	}
     }
     printf("\nEl mayor de los impares: %d",mayorImpar);


     //D
     printf("\nListado de los numeros ingresados: ");imprimirArray(arrayNumeros,CANT);

     //E
     //LISTADO DE NUMEROS PARES

     printf("\nListado de los numeros pares: "); listarNumerosPares(arrayNumeros,CANT);

     //F

     printf("\nListado de los n�meros de las posiciones impares: "); listarNumerosPosicionImpar(arrayNumeros,CANT);

     //
     inicializarVector(arrayNumerosPositivos, CANT);

     for(i=0;i<CANT;i++)
     {
    	 if(arrayNumeros[i]>0)
    	 {
            arrayNumerosPositivos[i] = arrayNumeros[i];

    	 }
     }

     printf("Array numero positivos:"); imprimirArray(arrayNumerosPositivos,CANT);

	return EXIT_SUCCESS;
}





/*
 ============================================================================
Micaela Vazquez DIV 1-K
 ============================================================================
 Ejercicio 5-1:
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 5
int main(void)
{   setbuf(stdout, NULL);
	int numeros[CANT],i;
	int acumulador=0;

    for(i=0; i<CANT; i++)
    {
       printf("Ingrese un numero: ");
       scanf("%d",&numeros[i]);

    }//PEDIRLOS

    for(i=0; i<CANT; i++)
    {
    	printf("\n%d",numeros[i]);
    }//MOSTRARLOS

    for(i=0; i<CANT; i++)
    {
     	acumulador+=numeros[i];
    }

    printf("\nLa suma de los numeros ingresados es de %d",acumulador);
	return EXIT_SUCCESS;
}

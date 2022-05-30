/*
 ============================================================================
 Vazquez Micaela-1K
Ejercicio 2-1:
Crear una función que reciba como parámetro un número entero. La función retorna 1 en caso de que sea positivo,
 -1 en caso de que sea negativo y 0 en caso de que sea 0. Realizar la prueba lógica de la función en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int positivoNegativo (int x);
int main(void)
{
	int numUno=-43;
	int retorno;
	retorno=positivoNegativo(numUno);
	printf("%d",retorno);
	return EXIT_SUCCESS;
}
int positivoNegativo (int x)
{
	if(x>=1)
	{
		return 1;
	}
	else
	{
		if(x<=-1)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

}

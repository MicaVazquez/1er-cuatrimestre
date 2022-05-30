/*
 ============================================================================
 VAZQUEZ MICAELA DIV 1-k
Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros. Determinar el promedio de los positivos, la cantidad de ceros y del menor de los negativos la suma de los antecesores de ese valor (frenar en cero).
Nota:
Utilizar la función del punto anterior y desarrollar funciones para resolver los procesos que están resaltados.
promedio-suma de los antecesores de ese valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int positivoNegativo (int x);
float calcularPromedio (int a, int b);
int sumarAntecesoresNegativos(int numeroNegativo);
int main(void)
{   setbuf(stdout, NULL);
    int i;
    int numero;
    int retorno;
    int contadorPositivos=0;
    int acumuladorPositivos=0;
    int contadorCeros=0;
    int banderaNegativos=0;
    int menorNumero;
    float promedioPositivos;
    int contadorNegativos=0;
    int resultadoSumaAntecesores;
    for(i=0;i<10;i++)
    {
    	printf("Ingrese un numero: ");
    	scanf("%d",&numero);

    	retorno=positivoNegativo(numero);

        switch(retorno)
        {
        case 1:
        	printf("Es positivo\n");
        	acumuladorPositivos+=numero;//promedio de positivos
        	contadorPositivos++;
        	break;
        case -1:
        	printf("Es negativo\n");
        	if(numero<menorNumero||banderaNegativos==0)
        	{
        		menorNumero=numero;
        		banderaNegativos=1;
        	}
             contadorNegativos++;
		break;

        case 0:
        	printf("Es igual a 0\n");
        	contadorCeros++;
        	break;
        }
    }

    if(contadorPositivos!=0)
    {
    	promedioPositivos=calcularPromedio(acumuladorPositivos,contadorPositivos);//promedio
    	printf("El promedio de los positivos %f\n",promedioPositivos);
    }
    else
    {
    	printf("No se ingresadon positivos.\n");
    }

    if(contadorCeros != 0)
    {
    printf("Cantidad de ceros es %d\n",contadorCeros);
    }
    else
    {
    	printf("No se ingresaron ceros.\n");
    }

    if(contadorNegativos!=0)
    {
    	printf("El menor de los negativos es: %d\n", menorNumero);
    	resultadoSumaAntecesores = sumarAntecesoresNegativos(menorNumero);
    	printf("La suma de los antecesores del menor negativos encontrado es %d\n",resultadoSumaAntecesores);

    }
    else
    {
    	printf("No se ingresaron negativos.\n");
    }


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
float calcularPromedio (int a, int b) //parametros formales
{
	float resultado;//variable local solo tiene visivilidad dentro de esa función.

	resultado=(float)a/b;
	return resultado;
}

int sumarAntecesoresNegativos(int numeroNegativo)
{
    int i;
    int acumulador = 0;

    for(i=0;i>numeroNegativo;i--)
    {
      acumulador+=i;
    }
return acumulador;
}




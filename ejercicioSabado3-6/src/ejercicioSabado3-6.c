/*
 ============================================================================
 Name        : ejercicioSabado3-6.c
 MICAELA VAZQUEZ 1K
 ============================================================================
 Ejercicio 3-6 (CADENAS):
Crear una función que reciba como parámetro una cadena de caracteres.
Dicha función permitirá reemplazar las vocales de la cadena por asteriscos. Retornara la cantidad de reemplazos que se produjeron.
CADENAS -> C*D*N*S

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 100
int cambiarPorAsteriscos(char cadena [], int tam, int len);
int main(void)
{   setbuf(stdout,NULL);

    char cadena[CANT];
    int len;
    printf("Ingrese una palabra:");
    gets(cadena);

    len = strlen(cadena);

	printf("Cantidad de reemplazos %d", cambiarPorAsteriscos(cadena,CANT,len));
	printf("\n%s",cadena);

	return EXIT_SUCCESS;
}

int cambiarPorAsteriscos(char cadena [], int tam, int len)
{   int contadorAsteriscos=0;
	for(int i=0;i<len;i++)
	{
		if(cadena [i] == 'a'|| cadena [i] == 'e' || cadena [i] == 'i' ||  cadena [i] == 'o' ||  cadena [i] == 'u' )
		{
			cadena[i]= '*';
			contadorAsteriscos++;
		}
	}
 return contadorAsteriscos;
}

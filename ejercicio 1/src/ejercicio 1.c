/*
 ============================================================================
 Name        : ejercicio.c
 Author      : Micaela Vazquez Programación 1-K ejercicio1
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getString(char mensaje[],char input[],int tam);
/*
int main(void) {
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int resultado;

	    printf("ingrese el primer numero: ");
	    scanf("%d",&numero1);

	    printf("ingrese el segundo numero: ");
	    scanf("%d",&numero2);

	    resultado = numero1 + numero2;

	    printf("La suma entre %d y %d da como resultado %d",numero1,numero2,resultado);

	return EXIT_SUCCESS;
}
*/
void getString(char mensaje[],char input[],int tam);

int main()
{
    char nombre[20];

    getString("ingrese",nombre,4);
    printf("Es %s",nombre);

    return 0;
}
void getString(char mensaje[],char input[],int tam)
{
    setbuf(stdout,NULL);
    char auxiliar[1024];
    int cantidadLetras;

    printf("%s",mensaje);
    fflush(stdin);
    gets(auxiliar);

    if(mensaje != NULL && input != NULL)
    {
        cantidadLetras = strlen(auxiliar);

        while(cantidadLetras>tam)
        {
            printf("Error.%s",mensaje);
            fflush(stdin);
            gets(auxiliar);
        }
        strcpy(input,auxiliar);
    }
}

void getInt(char mensaje[])
{
	int esNumero;
	char auxiliar[30];
    int i;
    int largo;

    largo = strlen(auxiliar);

    getString(auxiliar,mensaje);
/*
    for(i=0;i<largo;i++)
    {
      if(isdigit(auxiliar[i])!= 0 || auxiliar[0]== '-' || )//devulve 0 si no es un numero y mayor a cero si lo es
      {

      }
    }

*/
}

int esNumerica(char auxiliar[])
{
	int i;
	int largo = strlen(auxiliar);
	int rtn= -1;

	if(auxiliar != NULL)
	{
		rtn = 1;
	 for(i=0;i<largo;i++)
	    {
	      if(isdigit(auxiliar[i])==0)//devulve 0 si no es un numero y mayor a cero si lo es
	      {
              rtn = 0;
              break;
	      }
	    }
	}
	return rtn;
}

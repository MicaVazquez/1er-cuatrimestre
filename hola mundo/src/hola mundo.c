/*
 ============================================================================
 Name        : hola.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "validaciones.h"

void getLetrasYNumeros(char mensaje[],char input[],int tamMin,int tamMax);

int main(void)
{    setbuf(stdout,NULL);
	int numero;
	float numeroFlotante;
	char codigo [10];

	getIntA("Ingresa un numero:", &numero, 1,49);
	getFloat("Ingresa un numero flotante :",&numeroFlotante,2.5,6.7);
	getLetrasYNumeros("Ingrese codigo: ", codigo, 1, 10);

   printf("\n%d",numero);
   printf("\n%f",numeroFlotante);
   printf("\n%s",codigo);


	return EXIT_SUCCESS;
}

void getLetrasYNumeros(char mensaje[],char input[],int tamMin,int tamMax)
{
    int i;
    int retorno=0;

    do
    {

        printf(mensaje);
        fflush(stdin);
        gets(input);

        if(strlen(input)>=tamMin && strlen(input)<=tamMax)
        {
            for(i=0;i<strlen(input);i++)
            {
                if((input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z') && (input[i]<'0' || input[i]>'9'))
                {
                    retorno=0;
                    break;
                }
                else
                {
                    retorno=1;
                }
            }

        }


        if(retorno==0)
        {
            printf("error\n");
        }

    }while(retorno==0);
}

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
void getIntMica(char mensaje[],int *numero,int tamMin,int tamMax);
void getArchive(char mensaje[],char* path,int tamMin,int tamMax);

int main(void)
{    setbuf(stdout,NULL);
    char archive[100];
	//float numeroFlotante;
	//char codigo [10];

	//getIntA("Ingresa un numero:", &numero, 1,49);
	//getFloat("Ingresa un numero flotante :",&numeroFlotante,2.5,6.7);
	//getLetrasYNumeros("Ingrese codigo: ", codigo, 1, 10);

    getArchive("\n Ingrese el archivo csv: ", archive, 1, 100);
   printf("\n%s",archive);
  // printf("\n%f",numeroFlotante);
   //printf("\n%s",codigo);


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

void getIntMica(char mensaje[],int *numero,int tamMin,int tamMax)
{
    char ingreso[50];
    int retorno=0;
    int auxiliar=0;
    int i;
    int contador=0;

    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(ingreso);

            for(i=0;i<=strlen(ingreso);i++)
            {
                if((ingreso[i]<'0' || ingreso[i]>'9'))
                {


                }
                else
                {
                	contador++;
                }
            }
            printf("hay %d errores",contador);

            if(contador==0)
            {
               auxiliar=atoi(ingreso);

               if(auxiliar>=tamMin && auxiliar<=tamMax)
               {
            	   *numero=auxiliar;
            	   retorno=1;
               }
            }
            else
            {
            	printf("\nError.");
            	contador = 0;
            }

    }while(retorno==0);


}
/*
int getStringMati(char palabra[],char mensaje[],int tam)
{
	char auxiliar[1024];
	int cantidadLetras;

	printf("%s",mensaje);
	fflush(stdin);
	gets(auxiliar);

	cantidadLetras = strlen(auxiliar);

	while(cantidadLetras > tam)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(auxiliar);
	}

	strcpy(palabra,auxiliar);
	return 1;
}

int getIntMati(char mensaje[])
{
	int esNumero;
	char auxiliar[30];
	int largo;
	int i;

	getStringMati(auxiliar,mensaje,30);

		return 1;
}

int esNumericaMati(char auxiliar[])
{
	int i;
	int largo;
	int retorno;

	largo = strlen(auxiliar);
	for(i=0;i<largo;i++)
		{
			if(isdigit(auxiliar[i])==0)
			{

			}
		}
return retorno;
}
*/
void getArchive(char mensaje[],char* path,int tamMin,int tamMax)
{
    int retorno;
    FILE * pFile;
    do
    {
        retorno=1;
        printf(mensaje);
        fflush(stdin);
        gets(path);

        if(strlen(path)>=tamMin && strlen(path)<=tamMax)
        {
        	pFile = fopen(path,"r");

        	if(pFile == NULL)//error
        	{
        		retorno = 0;
        	}
        	 fclose(pFile);
        }

        if(retorno==0)
        {
            printf("error\n");
        }

    }
    while(retorno==0);
}

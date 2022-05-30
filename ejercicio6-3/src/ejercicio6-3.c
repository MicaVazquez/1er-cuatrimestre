/*
 ============================================================================
 Name        : ejercicio6-3.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 6-3:
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el
apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void)
{   char nombre[31];
    char apellido[31];
    char apeNom[70]; //
    int i, longitud, contador;

    printf("Apellido: ");
    fflush(stdin);
    scanf("%[^\n]",nombre);//lee all menos el contrabarra n

    printf("Nombre: ");
    fflush(stdin);
    scanf("%[^\n]",nombre);

    strlwr(apellido);
    strlwr(nombre);

    //Quitamos espacio en blanco al comienzo
    longitud = strlen(apellido);
    for(i=0,i<longitud; i++)
    {
    	if()
    }

    apellido[0] = toupper(apellido[0]);//primer letra en mayuscula

    longitud = strlen(apellido);//len es longitud Devuelve un int de acuerdo a la cantudad de caracteres que contiene

    for(i=0; i<longitud; i++)
    {
    	if(apellido[i] == ' ')
    	{
    		apellido[i+1] = toupper(apellido[i+1]);

    	}
    }

    nombre[0] = toupper(nombre[0]);
    longitud = strlen(nombre);

    for(i=0; i<longitud; i++)
       {
       	if(nombre[i] == ' ')
       	{
       		nombre[i+1] = toupper(nombre[i+1]);

       	}
       }


    strcpy(apeNom, apellido);

    stcat(apeNom, ", ");

    strcat(apeNom, nombre);
	return EXIT_SUCCESS;
}

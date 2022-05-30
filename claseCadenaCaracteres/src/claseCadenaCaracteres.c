/*
 ============================================================================
 Name        : claseCadenaCaracteres.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) //strlen devulve lo que tengo ocupado en cantidad de caracteres.Busca la contrabarra 0
{   setbuf(stdout,NULL);
    char nombre[11];//palabra de 10 pero 1 mas para el \0 que termina que termino.
    char auxiliar[30];


    //strncpy
    //Strnlen hace un contador hasta que encuentra un \0 y no se pasa. Me da la longitud del string.

    //strncat
    // sprintf puede guardar
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

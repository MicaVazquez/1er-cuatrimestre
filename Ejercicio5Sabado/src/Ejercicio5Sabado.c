/*
 ============================================================================
 Name        : Ejercicio5Sabado.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Establecer las relaciones entre datos
Usuario (nombre)
Posteo(comentario)
Hashtag(descripcion)

Hardcodear datos para las 3 entidades

Listados
Por cada usuario su comentario junto al hashtag
El porcentaje que representa cada hashtag sobre el total de posteos
E/los hashtags menos utilizado
El nombre de los usuarios que usaron el hashtag #VIVALAFRA
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{

	int idPosteo;
	int idHastag;

}eHashtag_Posteo;

typedef struct
{
    int idHastag;
    char descripcion[51];

}eHashtag;

typedef struct
{
 int idUsuario;
 int idPosteo;
 char comentario[51];

}ePosteo;

typedef struct
{
	int idUsuario;
	char nombre[51];

}eUsuario;

int main(void)
{
     eUsuario usuarios [] = {{1,"Federico"},{2,"Milena"},{3,"Pablo"}};
     ePosteo posteos[] = {{1,10,"Buenos dias!"},{2,11,"Me encanta"},{3,12,"Que frio!"}};
     eHashtag hastags[] = {{100,"#otoño"},{101,"#UTN"},{102,"#sueño"},{103,"#estudiar"}};
     eHashtag_Posteo relacion [] = {{10,102},{10,100},{11,101},{11,103},{12,100}};

	puts("!!!Hello World!!!");
	return EXIT_SUCCESS;
}

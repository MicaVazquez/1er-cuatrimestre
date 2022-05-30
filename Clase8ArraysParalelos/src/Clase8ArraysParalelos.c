/*
 ============================================================================
 Name        : Clase8ArraysParalelos.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 CLASE 8: ESTRUCTURAS Y ARRAYS. ABM*/

#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"
#define TAM 5
int main(void)
{
    setbuf(stdout,NULL);
	int opcion;
	eAlumno alumnos[TAM];
	inicializarVector(alumnos,TAM);


	do
	{
		printf("1-alta\n2-baja\n3-modificar\n4-listar\n20-salir\n");
		scanf("%d",&opcion);

		switch(opcion)
		{

			case 1:    //ALTA
				altaAlumnos(alumnos,TAM);
				break;

			case 2:   //BAJA
				printf("baja!!!\n");
				break;

			case 3:   // MODIFICAR
				printf("Moldificar!!!\n");
				break;


			case 4:   //MOSTRAR LISTADO
				imprimirAlumnos(alumnos,TAM);
				break;


			case 20: //SALISTE
				printf("Saliste!!!\n");
				break;

			default:
				printf("%d Esta opcion no es valida",opcion);
				break;

		}


	}while(opcion != 20);

	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : punteroEstructuras.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int id;
	char descripcion[31];
	float precio;

}eProducto;

int main()
{
    //eProducto miProducto = {1000,"OREO",120.31};
	eProducto* pProducto;
	eProducto lista[3]={{1000,"OREO",120.31},
			{1001,"SONRISAS",100.24},
			{1002,"RUMBAS",106.99}
	};
	int i;

	pProducto = lista;

	for(i=0;i<3;i++)
	{
		printf("\n %d- %s- %.2f\n", (*(pProducto+i)).id, (*(pProducto+i)).descripcion, (*(pProducto+i)).precio);
		printf("\n %d- %s- %.2f\n", (pProducto+i)->id, (pProducto+i)->descripcion, (pProducto+i)->precio);
	}

	//printf("\n %d- %s- %.2f\n", (*pProducto).id, (*pProducto).descripcion, (*pProducto).precio);
	//printf("\n %d- %s- %.2f\n", pProducto->id, pProducto->descripcion, pProducto->precio);
    printf("Hello World");

    return 0;
}

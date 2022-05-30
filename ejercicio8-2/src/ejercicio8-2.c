/*
 ============================================================================
 Name        : ejercicio8-2.c
 Author      : Micaela V
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes
opciones:
1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
disponible en el array.

2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.
3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio
o el tipo.
4. LISTADO Productos.
5. LISTADO ordenado por precio.
6. LISTADO ordenado por descripción.*/

#include <stdio.h>
#include <stdlib.h>
#define CANT 3
#define EEUU  3
#define CHINA 4
#define OTRO  5
#define IPHONE 7
#define MAC  8
#define IPAD 9
#define ACCESORIOS 6


int menu( char opciones[]  );
typedef struct
{   int estado
	int idProducto;
	char descripcion;
	int nacionalidad;
	int tipo;

}eProductoAplee;
int main(void)
{
	eProductoAplee productosAplee[CANT];
	setbuf(stdout,NULL);
	int opcion;
	int i;
	//Inicializamos los estados
	for( i=0; i<CANT; i++ )
	{
		productosAplee[i].estado = 0;
	}

	do
	{
		opcion = menu( "MENU\n1. Alta\n2. Baja\n3. Modificar\n4. Listado productos\n5. Listado ordenado por precio \n6. Listado ordenado por descripcion." );
       switch(opcion)
       {
		   case 1: if(productosAplee[i].estado==0)
		   {

		   }

			   break;
		   case 2: printf("i am 2");
			   break;
		   case 3: printf("i am 3");
			   break;
		   case 4:printf("i am 4");
			   break;
		   case 5:printf("i am 5");
			   break;
		   case 6:printf("i am 6");
			   break;
		   default:
			   printf("Error.Opcion incorrecta.");
			   break;
       }

	}while(opcion!=7);

	return EXIT_SUCCESS;
}

int menu( char opciones[]  )
{
	int opcion;

		printf( opciones );

		printf("\nOpcion: ");
		scanf("%d", &opcion);

		return opcion;
}


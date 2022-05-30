/*
 ============================================================================
 Name        : ejercicioe.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CANT 5

/*int main(void)
{               // ARRAY -CARGA SECUENCIAL
	setbuf(stdout,NULL);
	int vec[CANT], i;

	//llamamos al array
	for(i = 0 ; i<CANT; i++)
	{
		printf("Dato:");
		scanf("%d",&vec[i]);
	}

	//mostramos el array
	for(i = 0; i<CANT; i++)
	{
		printf("\n%d",vec[i]);
	}

	return EXIT_SUCCESS;
}*/


int main(void){
	int vec[CANT], i;
	int menor, mayor, num;
	char opcion;
	int flag = 0, flag_A = 0;

	for(i=0; i<CANT; i++){
		vec[i] = 0; // inicializamos vector
	}

	do{
		printf("A. Alta");
		printf("\nB. Baja");
		printf("\nM. Modificar");
		printf("\nC. Menor");
		printf("\nD. Mayor");
		printf("\nE. Buscar dato");
		printf("\nS. Salir");
		printf("\nOpcion: ");
		fflush(stdin);
		scanf("%c", &opcion);
		opcion = toupper(opcion);

		switch(opcion){
			case 'A':
				for( i=0; i<CANT; i++ ){
					if( vec[i] == 0 ){
						printf("Ingrese valor a cargar en el vector: ");
						scanf("%d", &vec[i]);
						flag_A = 1;
						break;
					}
				}
				break;

			case 'B':
				break;

			case 'M':
				break;
			case 'C':
				//buscar menor
				if( flag_A == 1 ){
					menor = vec[0];

					for( i=0; i<CANT; i++ ){
						if( vec[i] < menor && vec[i] != 0 ){
							menor = vec[i];
						}
					}
						printf("El menor es: %d", menor);
				}
				else{
					printf("No existen datos cargados...");
				}

				break;

			case 'D':
				//buscar mayor
				if( flag_A == 1 ){
					mayor = vec[0];

					for( i=0; i<CANT; i++ ){
						if( vec[i] > mayor ){
							mayor = vec[i];
						}
					}
					printf("El mayor es: %d", mayor);
				}
				else{
					printf("No existen datos cargados...");
				}

				break;

			case 'E':
				if(flag_A==1)
				{
					//buscar un numero dentro del vector
					flag=0;
					printf("Ingrese buscar dato: ");
					scanf("%d",&num);

					for(i=0; i<CANT; i++)
					{
						if(num==vec[i])
						{
							/* asignacionesy modificaciones*/
							printf("Se encontro el número");
							flag = 1;
							break;
						}
						if( flag == 0 ){
							printf("El número no se encontró");
						}
					}
				}
				else
				{
					printf("No existen datos cargados...");
				}
				break;
			default:
				printf("La opción no es valida %d", opcion);
		}
		printf("\n\n");

	}while( opcion != 'S' );

	return 0;
}


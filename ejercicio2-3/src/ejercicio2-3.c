/*
 ============================================================================
 Name        : ejercicio2-3.c
 Author      : Micaela Vázquez Programación 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona
debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),

edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	char respuesta;
	int numeroCliente;
	char estadoCivil;
	int edad;
	int temperaturaCorporal;
	char genero;
	int precioPasajero;
	int contadorViudo;
	int numeroClienteMujer;
	int edadMujerJoven;
	int banderaMujerMasJoven;
	int precioTotal;
	int contadorDePersonas;
	int contadorPersonasMayores;
	int precioConDescuento;

	precioPasajero=600;
	contadorDePersonas=0;
    banderaMujerMasJoven=0;
    contadorViudo=0;
    contadorPersonasMayores=0;
	respuesta = 's';
	do
	{
		printf("Ingrese numero de cliente: ");
		scanf("%d",&numeroCliente);

		printf("Ingrese estado civil (soltero, viudo o casado) :");
		fflush(stdin);
		scanf("%c",&estadoCivil);

		while(estadoCivil != 's' && estadoCivil != 'c'&& estadoCivil != 'v')
		{
			printf("Reingrese estado civil ( soltero, viudo o casado): ");
			fflush(stdin);
			scanf("%c",&estadoCivil);
		}

		printf("Ingrese la edad: ");
		scanf("%d",&edad);

		while(edad<17)
		{
			printf("Reingrese la edad: ");
			scanf("%d",&edad);
		}

        printf("Ingrese la temperatura corporal: ");
        scanf("%d",&temperaturaCorporal);

        while(temperaturaCorporal<35 || temperaturaCorporal>42)
        {
        	 printf("Reingrese la temperatura corporal: ");
        	 scanf("%d",&temperaturaCorporal);
        }


        printf("Ingrese genero: ");
        fflush(stdin);
        scanf("%c",&genero);

        while(genero != 'f' && genero != 'm' && genero != 'o')
        {
        	printf("Reingrese genero: ");
        	 fflush(stdin);
        	 scanf("%c",&genero);
        }
        switch(estadoCivil)
        {
        case 's':
        	if(genero=='f')
        	{
        		if(edad<edadMujerJoven || banderaMujerMasJoven==0)//b
        		{
        			edadMujerJoven=edad;
        		    numeroClienteMujer=numeroCliente;
        			banderaMujerMasJoven=1;
        		}
        	}
        	break;
        case 'c':
        	break;
        case 'v':
        	if(edad>60)
        	{
        		contadorViudo++; //a
        	}
        	break;

        }

        if(edad>60)
        {
           contadorPersonasMayores++;
        }


        contadorDePersonas++;

		printf("Desea continuar? n o s");
		fflush(stdin);
		scanf("%c",&respuesta);
	}while(respuesta == 's');

	precioTotal=contadorDePersonas*precioPasajero; //c

	if(contadorPersonasMayores>contadorDePersonas/2)
	{
		precioConDescuento=precioTotal-(precioTotal*0.25);
		printf("d) Precio con descuento: %d",precioConDescuento);
	}
	else
	{
		printf("d) No hay precio con descuento \n");
	}

	printf("a) %d \n", contadorViudo);
	printf("b) %d y %d \n",numeroClienteMujer,edadMujerJoven);
	printf("c) %d \n",precioTotal);
	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : punteroFuncion.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
void saludar()
{
	printf("Hola!!!\n");
}

int main(void) {

	void (*pFuncion)(void);//tiene que tener la misma firma-trajesito a medida de la firma de la funcion
	pFuncion = saludar;//asigno direccion de memoria
	pFuncion();//la uso como si fuese la funcion saludar
	return EXIT_SUCCESS;
}
 */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int saludar(char* mensaje)
{
    printf("%s",mensaje);
    return 0;
}

int main(void)
{
    int (*pFuncionSaludar)(char*);//puntero a saludar tiene que estar entre parentesis y el *. Solo copio los tipos de datos pero no como se llaman los mismos
    pFuncionSaludar = saludar;//como le asigno a la direccion de memoria de la funcion al puntero?

    if(pFuncionSaludar("Hola\n")==0)//como utilizo a traves del puntero a funcion?Igual que como utlizaba saludar.
    {
        printf("Salio ok");
    }
    return 0;
}

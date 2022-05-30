/*
 ============================================================================
 Name        : ejercicio2-4.c
 Author      : Micaela Vázquez Programación 1-K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   setbuf(stdout,NULL);
	char letra;
    int i;
    int contadorP;
    contadorP=0;
     for(i=0;i<5;i++)
     {
    	 printf("Ingrese un caracter: ");
    	 fflush(stdin);
    	 scanf("%c",&letra);

    	 if(letra=='p')
    	 {
    		 contadorP++;
    	 }
     }

     if(contadorP != 0)
     {
    	 printf("Se ingresaron %d letras p ",contadorP);
     }
     else
     {
    	 printf("No se ingreso la letra p");
     }

	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : pruebaArch.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//"D:\\carpeta\\archivo.txt" RUTA ABSOLUTA-partiendo de la raiz
	//"/home/usuario2/archivo.txt"
 FILE* fp;
 int i;

	fp = fopen("archivo.txt","w");//crear un archivo

	if(fp != NULL)
	{
        // lo usamos
		//MODO TEXTO
		//1 fn para leer y 1 fn para escribir
		i=127;
        //fprintf(fp,"%d",i);

        fwrite(&i,sizeof(int),1,fp);
		// lo cerramos
		fclose(fp);
	}
	else
	{
       printf("Error abriendo archivo\n");
	}

	return EXIT_SUCCESS;
}

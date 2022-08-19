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

typedef struct{
	int id;
	float altura;
	char nombre[51];

}eAlumno;
int main(void) {
	//"D:\\carpeta\\archivo.txt" RUTA ABSOLUTA-partiendo de la raiz
	//"/home/usuario2/archivo.txt"
 FILE* fp;
 //int i;

	fp = fopen("archivo.txt","wb");//crear un archivo

	if(fp != NULL)
	{
        // lo usamos
		//MODO TEXTO
		//1 fn para leer y 1 fn para escribir
		//i=127;
        //fprintf(fp,"%d",i);

        //fwrite(&i,sizeof(int),1,fp);

		eAlumno a;
		a.id = 9;
		a.altura = 3.14;
		sprintf(a.nombre,"Ernesto");

		fread(&a,sizeof(eAlumno),1,fp);

		printf("id:%d nombre: %s altura:%f\n",a.id,a.nombre,a.altura);



		//ESCRIBIR EN MODO TEXTO

		// lo cerramos
		fclose(fp);
	}
	else
	{
       printf("Error abriendo archivo\n");
	}

	return EXIT_SUCCESS;
}

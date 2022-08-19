#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entidad.h"
#include "validaciones.h"

/****************************************************
    Menu:


*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flag=0;

	//char archive[100];


     LinkedList* lista = ll_newLinkedList();
     LinkedList* listaFiltrada = ll_newLinkedList();

        // getArchive("\n Ingrese nombre del archivo: ", archive, 1, 100);//src/datos.csv

        do{
        	getInt("Menu:\
         \n1.Cargar.\
        \n2.Ordenar. \
      \n3.Depurar\
        \n4.Elegir un genero\
        \n5.Guardar\
        \n12. Salir\n\n Opcion: ",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{  //"src/datos_SP.csv"
        			controller_loadFromText("src/peliculas.csv",lista);
        			printf("\n Se cargo exitosamente...\n");
        			flag=1;

        		}
        		else
        		{
        			printf("Ya se ha cargado el archivo\n");
        		}

        		break;
        	case 2:
         		if(ll_len(lista))
         		{
                   controller_sort(lista);
                   controller_ListEntidad(lista);
         		}
         		else
         		{
         			printf("No se han ingresado...\n");
         		}
        		break;
        	case 3:
        		if(ll_len(lista))
        		{
                   depurarPeliculas(lista);
                   controller_ListEntidad(lista);
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 4:
        		if(ll_len(lista))
        		{
        			listaFiltrada = controller_filtra(lista);
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 5:
        		if(ll_len(lista))
        		{
                    controller_saveAsText("src/filtrado.csv", listaFiltrada);
                    controller_saveAsText("src/depurado.csv",lista);
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 12:
        		printf("\nChau!");
        		ll_deleteLinkedList(lista);
        		break;
        	}

        }while(option != 12);

        return 0;
}


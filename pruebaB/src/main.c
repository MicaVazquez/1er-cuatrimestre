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

    char archive[100];


     LinkedList* lista = ll_newLinkedList();
     LinkedList* listaFiltrada = ll_newLinkedList();

        getArchive("\n Ingrese nombre del archivo: ", archive, 1, 100);//src/MOCK_DATA.csv

        do{
        	getInt("Menu:\
         \n1.Cargar los datos desde el archivo data.csv (modo texto).\
        \n2.Todos los empleados mayores de 30 y profesion programador. \
      \n3.Guardar datos de los empleados mayores de 30 y profesion programador. \
        \n12. Salir\n\n Opcion: ",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{  //"src/datos_SP.csv"
        			controller_loadFromText(archive,lista);
        			controller_ListEntidad(lista);
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
         			listaFiltrada = controller_filtra(lista);
         		}
         		else
         		{
         			printf("No se han ingresado...\n");
         		}
        		break;
        	case 3:
        		if(ll_len(listaFiltrada))
        		{
                   controller_saveAsText("src/out.csv", listaFiltrada);
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



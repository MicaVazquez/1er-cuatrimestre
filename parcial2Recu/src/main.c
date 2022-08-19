#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "participante.h"
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





        do{
        	getInt("\nMenu:\
         \n1.Carga\
        \n2.Ordena\
      \n3.Lista\
        \n4.Filtra\
        \n5.Guarda \
       \n. \
        \n12. Salir\n\n Opcion: ",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{  //"src/datos_RSP.csv"
        			getArchive("\n Ingrese nombre del archivo: ", archive, 1, 100);//src/datos.csv
        			controller_loadFromText("src/datos_RSP.csv",lista);
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
         		}
         		else
         		{
         			printf("No se han ingresado...\n");
         		}
        		break;
        	case 3:
        		if(ll_len(lista))
        		{
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


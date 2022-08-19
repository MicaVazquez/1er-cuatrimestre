#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entidad.h"
#include "validaciones.h"

/****************************************************
    Menu:
1) Realizar un programa que lea un archivo .csv (cuyo nombre se pasa como parámetro por
línea de comandos), con los datos de equipos de cómputo, guardándolos en un
linkedList de entidades eComputer.
2) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio
cuotas, de manera descendente.
3) Imprimir por pantalla los datos de las computadoras. En lugar de idTipo, se deberá
imprimir dependiendo el caso: 1=>DESKTOP; 2=>LAPTOP.
4) Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una
función. La función ll_map ejecutará la función recibida como parámetro por cada ítem
de la lista, de esta manera, agregará el valor de la cuota sin interés sobre el precio del
equipo.
5) Generar el archivo de salida mapeado.csv conteniendo la lista del ítem anterior.

*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flag=0;
	int flag4 = 0;
	char archive[100];

	 LinkedList* listaMapeada;
     LinkedList* lista = ll_newLinkedList();



        do{
        	getInt("Menu:\
         \n1.Cargar los datos desde el archivo data.csv (modo texto).\
        \n2.Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio cuotas, de manera descendente. \
      \n3.Imprimir por pantalla los datos de las computadoras. En lugar de idTipo, se deberá imprimir dependiendo el caso: 1=>DESKTOP; 2=>LAPTOP. \
        \n4.Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una función. La función ll_map ejecutará la función recibida como parámetro por cada ítem de la lista, de esta manera, agregará el valor de la cuota sin interés sobre el precio del equipo. \
        \n5.Generar el archivo de salida mapeado.csv conteniendo la lista del ítem anterior.\
        \n12. Salir\n\n Opcion: ",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{  //"src/datos_SP.csv"
        			getArchive("\n Ingrese nombre del archivo: ", archive, 1, 100);//src/datos_SP.csv
        			controller_loadFromText(archive,lista);
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
        			listaMapeada = controller_mapea(lista);
        			flag4 = 1;
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 5:
        		if(ll_len(lista) && flag4 == 1)
        		{
                   controller_saveAsText("mapeado.csv", listaMapeada);
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


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entidad.h"
#include "validaciones.h"

/****************************************************
    Menu:
1) Realizar un programa que lea un archivo .csv (cuyo nombre se pasa como par�metro por
l�nea de comandos), con los datos de equipos de c�mputo, guard�ndolos en un
linkedList de entidades eComputer.
2) Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio
cuotas, de manera descendente.
3) Imprimir por pantalla los datos de las computadoras. En lugar de idTipo, se deber�
imprimir dependiendo el caso: 1=>DESKTOP; 2=>LAPTOP.
4) Desarrollar la funci�n ll_map en la biblioteca linkedList, la cual recibir� la lista y una
funci�n. La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem
de la lista, de esta manera, agregar� el valor de la cuota sin inter�s sobre el precio del
equipo.
5) Generar el archivo de salida mapeado.csv conteniendo la lista del �tem anterior.

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
        \n2.Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio cuotas, de manera descendente. \
      \n3.Imprimir por pantalla los datos de las computadoras. En lugar de idTipo, se deber� imprimir dependiendo el caso: 1=>DESKTOP; 2=>LAPTOP. \
        \n4.Desarrollar la funci�n ll_map en la biblioteca linkedList, la cual recibir� la lista y una funci�n. La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem de la lista, de esta manera, agregar� el valor de la cuota sin inter�s sobre el precio del equipo. \
        \n5.Generar el archivo de salida mapeado.csv conteniendo la lista del �tem anterior.\
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


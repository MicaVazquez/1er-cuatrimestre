#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entidad.h"
#include "validaciones.h"

/****************************************************
    Menu:
1. Realizar un programa que lea de un archivo .csv los datos de empleados y los guarde de
manera dinámica en un arraylist de entidades eEmpleado (id, nombre,
empleo,edad,horasTrabajadas).
2. Listar todos los empleados ordenados de manera ascendente por nombre.
Nota: Utilizar constructores, Getters y Setter.

*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flag=0;
	int flag5=0;

	//char archive[100];


     LinkedList* lista = ll_newLinkedList();
     LinkedList* listaFiltrada = ll_newLinkedList();

        // getArchive("\n Ingrese nombre del archivo: ", archive, 1, 100);//src/datos.csv

        do{
        	getInt("Menu:\
         \n1.Cargar los datos desde el archivo data.csv (modo texto).\
        \n2.Listar todos los empleados ordenados de manera ascendente por nombre. \
      \n3.Cargar su “Dedicación” a cada uno de los empleados leídos. \
        \n4.Listar los empleados ordenados de manera ascendente por dedicación. \
        \n5.Listado con los empleados que tengan menos de 21 años de edad .\
        \n6.Guardar en un archivo llamado “resultados.cvs” los resultados de esa búsqueda .\
        \n12. Salir\n\n Opcion: ",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{  //"src/datos_SP.csv"
        			controller_loadFromText("src/datos.csv",lista);
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
        			controller_mapea(lista);
        			controller_ListEntidadDedicacion(lista);
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 4:
        		if(ll_len(lista))
        		{
        			ll_sort(lista, eEntidad_sortDedicacion, 1);
        			controller_ListEntidadDedicacion(lista);
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 5:
        		if(ll_len(lista))
        		{
                   listaFiltrada = controller_filtra(lista);
                   flag5 = 1;
        		}
        		else
        		{
        			printf("No se han ingresado...\n");
        		}
        		break;
        	case 6:
        		if(ll_len(lista) && flag5 == 1 )
        		{
                   controller_saveAsText("src/resultados.csv", listaFiltrada);
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


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

	//char archive[100];


     LinkedList* lista = ll_newLinkedList();

        // getArchive("\n Ingrese nombre del archivo: ", archive, 1, 100);//src/datos.csv

        do{
        	getInt("Menu:\
         \n1.Cargar los datos desde el archivo data.csv (modo texto).\
        \n2.Listar empleados \
      \n3.Calcular sueldo.\
        \n4.Generar archivo de salida. \
        \n5..\
        \n12. Salir\n\n Opcion: ",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{  //"src/datos_SP.csv"
        			controller_loadFromText("src/mockdata.csv",lista);
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
                   controller_saveAsText("src/info.csv", lista);
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


/*
 * album.c
 *
 *  Created on: 30 abr. 2022
 *      Author: PC-INC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "album.h"


#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
static int idIncremental = 1005;
static int eAlbum_obtenerID();
static int eAlbum_obtenerID()
{
	return idIncremental++;
}

//eTipoArtista  listaDeTipoArtista[2] = {{1,"solista"},{2,"banda"}};
//eDiscografica listaDeDiscograficas[5] = {{200,"Columbia Records"}, {201,"PolyGram"},{202,"EMI"},{203,"Island Records"},{204,"Warner Music"} };
//eArtista listaDeArtistas[5] = { {100,"Camilo"}, {101,"Beatles"}, {102,"Camila Cabello"},{103,"Coldplay"},{104,"Dua Lipa"}};

void hardcodearTipoArtista(eTipoArtista lista[], int lim)
{
    int i;

    int codigoTipoArtista[] = {1,2};
    char descripcionTipoArtista[][51] = {"solista","banda"};

    if( lista != NULL && lim > 0)
    {
    	 for(i=0;i<lim;i++)
    	    {
    	    	lista[i].codigoTipoArtista = codigoTipoArtista[i];
    	    	strcpy(lista[i].descripcionTipoArtista,descripcionTipoArtista[i]);
    	    }
    }
}

void hardcodearDiscograficas(eDiscografica lista[], int lim)
{
	int codigoDeDiscografica []= {200,201,202,203,204};
	char descripcionDiscografica[][51] = {"Columbia Records","PolyGram","EMI","Island Records","Warner Music"};
	int i;


    if( lista != NULL && lim > 0)
    {
    	 for(i=0;i<lim;i++)
    	    {
    	    	lista[i].codigoDeDiscografica = codigoDeDiscografica[i];
    	    	strcpy(lista[i].descripcionDiscografica,descripcionDiscografica[i]);
    	    }
    }

}

void hardcodearArtistas(eArtista lista[], int lim)
{
	int codigoDeArtista[] = {100,101,102,103,104};
	char nombreArtista[][51] = {"Camilo","Beatles","Camila Cabello","Coldplay","Dua Lipa"};
	int i;


    if( lista != NULL && lim > 0)
    {
    	 for(i=0;i<lim;i++)
    	    {
    	    	lista[i].codigoDeArtista = codigoDeArtista[i];
    	    	strcpy(lista[i].nombreArtista,nombreArtista[i]);
    	    }
    }
}


eFecha pedirFecha()
{
    int dia;
    int mes;
    int anio;

    eFecha fecha;

    getInt("Dia: ",&dia,1,31);
    getInt("Mes: ",&mes,1,12);
    getInt("Anio: ",&anio,1902,3000);

    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;
    return fecha;
}

int eAlbum_inicializar(eAlbum* list, int len)
{  int retorno = -1;
   int i;
    if(list != NULL && len > 0)
    {
    	retorno =0;
    	for(i=0;i<len;i++)
    	{
            list[i].estado = LIBRE;

    	}
    }
	return retorno;
}


void eAlbum_imprimirUno(eAlbum unAlbum)
{

	printf("|%-20s|%-2d/%-2d/%-2d|%-20d|%-20d|\n",unAlbum.titulo,
									  unAlbum.fechaDePublicacion.dia,
									  unAlbum.fechaDePublicacion.mes,
									  unAlbum.fechaDePublicacion.anio,
									  unAlbum.importe,
									  unAlbum.codigoDeAlbum);
}

void eAlbum_imprimirTodos(eAlbum* list, int largo)
{
	int i=0;
    printf("Titulo               Fecha de publ.      Importe        Codigo de album\n");
    if(list != NULL && largo > 0)
    {
		for(i=0;i<largo;i++)
		{
			if(list[i].estado == OCUPADO)
			{
				eAlbum_imprimirUno(list[i]);
			}
		}
    }
}

int eAlbum_alta(eAlbum list[], int len,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,eArtista listaDeArtistas[], int limArt)
{

	int indiceLibre;
    int rtn=-1;
	 if(list != NULL && len > 0)
	 {
       indiceLibre =  buscarLibre(list,len);

       if(indiceLibre != -1)
       {

           list[indiceLibre] = cargarUno(listaDeTipoArtista,limTipoArtista,listaDeDiscograficas,limDisc,listaDeArtistas,limArt);
    	   list[indiceLibre].codigoDeAlbum = eAlbum_obtenerID();
    	   list[indiceLibre].estado = OCUPADO;

    	   rtn=0;
       }
       else
       {
    	   printf("No hay espacio...");
       }

	 }
	 return rtn;
}


int buscarLibre(eAlbum* list, int len)
{
	int i;
	int indice=-1;
	for(i=0;i<len;i++)
	{
		if(list[i].estado == LIBRE)
		{
			indice=i;
			break;
		}
	}
 return indice;
}


eAlbum cargarUno(eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,eArtista listaDeArtistas[], int limArt)
{
	eAlbum unAlbum;

	int i;
	int codigoTipoArtista;//FK
	int codigoDeArtista;//FK
	int codigoDeDiscografica;//FK
	char titulo[51];
	eFecha fechaDePublicacion;

	int importe;

    getString("\nIngrese el titulo del album: ",titulo,1,51);
    fechaDePublicacion = pedirFecha();
    getInt("\nIngrese el importe: ",&importe,1,9999999);

    printf("\nElija un artista: ");

    for(i=0;i<limArt;i++)
    {
    	printf("\n\n %d-%s",listaDeArtistas[i].codigoDeArtista,listaDeArtistas[i].nombreArtista);
    }
    getInt("\nIngrese le codigo del artista: ",&codigoDeArtista,100,104);

    printf("\n\nElija una discografica: ");
    for(i=0;i<limDisc;i++)
    {
    	printf("\n\n %d-%s",listaDeDiscograficas[i].codigoDeDiscografica,listaDeDiscograficas[i].descripcionDiscografica);
    }

    getInt("\nIngrese el codigo de la discografica: ",&codigoDeDiscografica,200,204);

    printf("\n\nElija un tipo de artista: ");
    for(i=0;i<limTipoArtista;i++)
    {
    	printf("\n\n %d-%s",listaDeTipoArtista[i].codigoTipoArtista,listaDeTipoArtista[i].descripcionTipoArtista);
    }
    getInt("\n Ingrese opcion de tipo de artista: ",&codigoTipoArtista,1,2);

    strncpy(unAlbum.titulo,titulo,sizeof(unAlbum.titulo));
    unAlbum.fechaDePublicacion = fechaDePublicacion;
    unAlbum.importe = importe;
    unAlbum.codigoDeArtista = codigoDeArtista;
    unAlbum.codigoDeDiscografica = codigoDeDiscografica;
    unAlbum.codigoTipoArtista = codigoTipoArtista;



	  return unAlbum;
}


int eAlbum_encontrarPorCodigo(eAlbum* list, int len,int codigo)
{
	int i;
   int indice = -1;

	if(list != NULL && len > 0)
	{
        for(i=0;i<len;i++)
        {
        	if(list[i].codigoDeAlbum == codigo && list[i].estado == OCUPADO)
        	{
        		indice = i;
               break;
        	}
        }
	}
   return indice;
}

//void eAlbum_modificar(eAlbum list[], int len,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,eArtista listaDeArtistas[], int limArt)
void eAlbum_modificar(eAlbum list[], int len, eTipoArtista listaDeTipoArtista[],int tamTipoArtista,eDiscografica listaDeDiscograficas[],int tamDisc,eArtista listaDeArtistas[], int tamArt)
{
	int auxCodigo;
    int datoEncontrado;
    int opcionModificar;
    int codigoDeArtista;
    int codigoDeDiscografica;
    int codigoTipoArtista;
    int i;

	eAlbum_imprimirTodos(list, len);
	getInt("\nIngrese el codigo del album a modificar: ",&auxCodigo,1000,999999);
	datoEncontrado = eAlbum_encontrarPorCodigo(list, len,auxCodigo);
	if(datoEncontrado != -1 )
	{
		printf("\nSe encontro el dato: \n");

		eAlbum_imprimirUno(list[datoEncontrado]);


		do{
			getInt("\n\nQue desea modificar?\n1. Titulo\n2. Fecha de publicacion\n3. Importe\n4. Artista\n5. Discografica \n6. Tipo de artista\n7. Salir\nOpcion para modificar: ",&opcionModificar,1,7);
			switch(opcionModificar)
			{

			case 1:
				getString("\nIngrese titulo: ",list[datoEncontrado].titulo , 1, 51);
				break;
			case 2:
				list[datoEncontrado].fechaDePublicacion = pedirFecha();
				break;
			case 3:
				getInt("\nIngrese importe: ",&list[datoEncontrado].importe, 1, 999999);
				break;
			case 4:
					printf("\nElija un artista: ");

					for(i=0;i<5;i++)
					{
						printf("\n\n %d-%s",listaDeArtistas[i].codigoDeArtista,listaDeArtistas[i].nombreArtista);
					}
					getInt("\nIngrese el codigo del artista: ",&codigoDeArtista,100,104);
					list[datoEncontrado].codigoDeArtista = codigoDeArtista;
				break;

			case 5:
				    printf("\nElija una discografica: ");
				    for(i=0;i<5;i++)
				    {
				    	printf("\n\n %d-%s",listaDeDiscograficas[i].codigoDeDiscografica,listaDeDiscograficas[i].descripcionDiscografica);
				    }

				    getInt("\nIngrese el codigo de la discografica: ",&codigoDeDiscografica,200,204);
				    list[datoEncontrado].codigoDeDiscografica = codigoDeDiscografica;
				break;
			case 6:
					printf("\nElija un tipo de artista: ");
					for(i=0;i<2;i++)
					{
						printf("\n\n %d-%s",listaDeTipoArtista[i].codigoTipoArtista,listaDeTipoArtista[i].descripcionTipoArtista);
					}
					getInt("\nIngrese opcion de tipo de artista: ",&codigoTipoArtista,1,2);
					list[datoEncontrado].codigoTipoArtista = codigoTipoArtista;
				break;
			case 7:
				printf("Saliendo de modificar.");
				break;
			}

		}while(opcionModificar != 7);

	}
	else
	{
		printf("No se encontro el dato");
	}
}

int eAlbum_baja(eAlbum* list, int len)
{
	int auxCodigo;
	int datoEncontrado;
	char confirmar;
	int rtn = 0;

	eAlbum_imprimirTodos(list, len);
	getInt("\nIngrese el codigo del album a dar de baja: ",&auxCodigo,1000,999999);
	datoEncontrado = eAlbum_encontrarPorCodigo(list, len,auxCodigo);

	if(datoEncontrado != -1)
	{
		eAlbum_imprimirUno(list[datoEncontrado]);
		getCaracter(&confirmar, "Dar de baja? [S|N]: ", "Error.", 'n', 's');
		confirmar = toupper(confirmar);

		if(confirmar == 'S')
		{
			list[datoEncontrado].estado = BAJA;
			rtn = 1;
			printf("Se han borrado los datos...");
		}
		else
		{
			printf("No se han borrado los datos...");
		}

	}
	return rtn;
}




void eAlbum_hardcodearDatos(eAlbum lista[])
{
	  int tam = 5;

	  int codigoTipoArtista[]={1,2,1,2,1};
	  int codigoDeArtista[]={100,101,102,103,104};
	  int codigoDeDiscografica[]={200,201,202,203,204};
	  int estado[]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
	  int codigoDeAlbum[]={1000,1001,1002,1003,1004};
	  char titulo[][51]={"Mi manos","Help","Familia","Ghost Stories","Future Nostalgia"};
	  eFecha fechaDePublicacion[]={{4,3,2021},{6,8,1965},{8,4,2022},{19,4,2014},{27,3,2020}};

	  int importe[]={3000,8000,4000,5000,3500};

	  int i;
	  for(i=0;i<tam;i++)
	  {
		  lista[i].codigoTipoArtista = codigoTipoArtista[i];
		  lista[i].codigoDeArtista = codigoDeArtista[i];
		  lista[i].codigoDeDiscografica = codigoDeDiscografica[i];
		  lista[i].estado = estado[i];
		  lista[i].codigoDeAlbum = codigoDeAlbum[i];
		  strcpy(lista[i].titulo,titulo[i]);
		  lista[i].fechaDePublicacion = fechaDePublicacion[i];
		  lista[i].importe = importe[i];
	  }


}


void eAlbum_importeTotalPromedio(eAlbum lista[], int tam)
{   int i;
    int acumulador = 0;
    int contador = 0;
    int contadorMenores = 0;
    float promedio;
	if(lista != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].estado == OCUPADO)
			{
				acumulador+= lista[i].importe;
				contador++;
			}
		}

	}
	if(contador != 0)
	{
	  printf("\nEl total de los importes: %d\n",acumulador);
      promedio = (float)acumulador/contador;
      printf("\nEl promedio de los importes: %.2f\n",promedio);

      for(i=0;i<tam;i++)
      {
    	  if(lista[i].estado == OCUPADO && lista[i].importe < promedio)
    	  {
              contadorMenores++;
    	  }
      }

      if(contadorMenores > 0)
      {
    	  printf("\nLa cantidad de albumes que no superan el promedio: %d\n",contadorMenores);
      }

	}

}

void eAlbum_posterior(eAlbum list[], int len)
{
	int i;

   if(list != NULL && len > 0)
   {
		for(i=0;i<len;i++)
		{
			if(list[i].fechaDePublicacion.anio > 1999 && list[i].estado == OCUPADO)
			{
                eAlbum_imprimirUno(list[i]);
			}
		}

   }
}


void eAlbum_informar(eAlbum list[], int len)
{
	int opcionInformar;
	do
	{
		getInt("\nQue desea informar?\n1.Total y promedio de los importes, y cu�ntos �lbumes no superan ese promedio.\n2.Albumes posteriores a 31/12/1999.\n3. Volver al menu\nOpcion: ",&opcionInformar,1,3);
		switch(opcionInformar)
		{
		case 1:
			eAlbum_importeTotalPromedio(list,len);
			break;

		case 2:
			eAlbum_posterior(list,len);
			break;

		case 3:
			break;
		}

	}while(opcionInformar != 3);
}


void eAlbum_listar(eAlbum list[], int tam,eTipoArtista listaTipoArtista[],int lenTipoArtista,eDiscografica listaDiscograficas[],int lenDisc,eArtista listaArtistas[],int lenArt)
{
	int opcionListar;

	do
	{
		getInt("\nQue desea listar?\n 1.Todas las discograficas.\n 2.Todos los tipos de artistas musicales.\n 3.Todos los artistas.\n 4.Todos los albumes.\n 5.Listado ordenado de los albumes por importe/titulo\n 6.Los �lbumes cuya fecha de publicaci�n es posterior a 31/12/1999.\n 7.Todos los �lbumes que no superan el promedio de los importes.\n 8.Todos los �lbumes de un artista determinado.\n 9.Todos los �lbumes de cada a�o.\n 10.El �lbum o los �lbumes m�s baratos.\n 11.Volver al menu.\nOpcion:",&opcionListar,1,11);

		switch(opcionListar)
		{
			case 1:
				listarDiscograficas(list, tam, listaDiscograficas, lenDisc);
				break;
			case 2:
				listarTiposArtistas(list, tam, listaTipoArtista, lenTipoArtista);
				break;
			case 3:
				listarArtistas(list, tam, listaArtistas, lenArt);
				break;
			case 4:
				printf("\n -ALBUMES-");
				eAlbum_imprimirTodos(list, tam);
				break;
			case 5:
                ordenarAlbumes(list, tam);
                eAlbum_imprimirTodos(list, tam);
				break;
			case 6:
				listarPosteriores(list,tam);
				break;
			case 7:
                listarMenorAlPromedio(list, tam);
				break;
			case 8:
				listarAlbumesPorArtistas(list, tam, listaArtistas, lenArt);
				break;
			case 9:
				ordenarPorAnio(list, tam);
				eAlbum_imprimirTodos(list, tam);
				break;
			case 10:
				break;
			case 11:
				break;
		}

	}while(opcionListar != 11);
}


void listarDiscograficas(eAlbum albumes[], int len, eDiscografica listaDeDiscograficas[], int lenDisc)
{
	int i;
	int j;
	if(albumes != NULL && len > 0)
	{   printf(" \n-DISCOGRAFICAS-\n");
		for(i=0;i<len;i++)
		{
			if(albumes[i].estado == OCUPADO)
			{

				for(j=0; j<lenDisc;j++)
				{
					if(albumes[i].codigoDeDiscografica == listaDeDiscograficas[j].codigoDeDiscografica)
					{
						printf(" %s\n",listaDeDiscograficas[j].descripcionDiscografica);
					}
				}
			}
		}
	}

}

void listarArtistas(eAlbum albumes[], int len, eArtista listaDeArtistas[], int lenArt)
{
	int i;
	int j;

	if(albumes != NULL && len > 0)
	{
		printf("\n -ARTISTAS-\n");
		for(i=0;i<len;i++)
		{
			if(albumes[i].estado == OCUPADO)
			{
				for(j=0; j<lenArt;j++)
				{
					if(albumes[i].codigoDeArtista == listaDeArtistas[j].codigoDeArtista)
					{
						printf(" %s\n",listaDeArtistas[j].nombreArtista);
					}
				}
			}
		}
	}

}


void listarTiposArtistas(eAlbum albumes[], int len, eTipoArtista listaDeTipoArtista[], int lenTipoArtista)
{
	int i;
	int j;

	if(albumes != NULL && len > 0)
	{
		printf("\n -TIPO DE ARTISTAS-\n");
		for(i=0;i<len;i++)
		{
			if(albumes[i].estado == OCUPADO)
			{
				for(j=0; j<lenTipoArtista;j++)
				{
					if(albumes[i].codigoTipoArtista == listaDeTipoArtista[j].codigoTipoArtista)
					{
						printf(" %s\n",listaDeTipoArtista[j].descripcionTipoArtista);
					}
				}
			}
		}
	}
}

void ordenarAlbumes(eAlbum list[],int len)
{
	int i;
	int j;

	eAlbum aux;

	if(list != NULL && len>0)
	{
       for(i=0;i<len-1;i++)
       {
    	   for(j=i+1;j<len;j++)//importe-descendente
    	   {
              if(list[i].importe<list[j].importe)
              {
            	  aux = list[i];
            	  list[i] = list[j];
            	  list[j] = aux;
              }
              else
              {
            	  if(list[i].importe == list[j].importe)//si son iguales
            	  {
            		  if(stricmp(list[i].titulo,list[j].titulo)>0)//ascendete-titulo
            		  {
            			  aux = list[i];
            			  list[i] = list[j];
            			  list[j] = aux;
            		  }
            	  }
              }
    	   }
       }
	}
}

void listarPosteriores(eAlbum list[],int len)
{
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].estado==OCUPADO)
			{
				if(list[i].fechaDePublicacion.anio>=2000)
				{
                    eAlbum_imprimirUno(list[i]);
				}
			}
		}
	}
}

void listarMenorAlPromedio(eAlbum list[],int tam)
{
	 int i;
	    int acumulador = 0;
	    int contador = 0;
	    float promedio;

		if(list != NULL && tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				if(list[i].estado == OCUPADO)
				{
					acumulador+= list[i].importe;
					contador++;
				}
			}

		}

		if(contador != 0)
		{
			promedio = (float)acumulador/contador;

			for(i=0;i<tam;i++)
			{
				if(list[i].estado == OCUPADO && list[i].importe < promedio)
				{
					eAlbum_imprimirUno(list[i]);
				}
			}
		}
}

void listarAlbumesPorArtistas(eAlbum albumes[],int tam, eArtista artistas[], int lenArt)
{
	int i;
	int j;

	if(albumes != NULL && tam > 0 && artistas != NULL && lenArt > 0)
	{

		for(i=0; i<lenArt; i++)
		{
			printf("%s\n", artistas[i].nombreArtista);
			for(j=0;j<tam;j++)
			{
				if(artistas[i].codigoDeArtista==albumes[j].codigoDeArtista)
				{
					eAlbum_imprimirUno(albumes[j]);
				}
			}
		}
	}
}

void ordenarPorAnio(eAlbum albumes[], int tam)
{
	int i;
	int j;

   	eAlbum aux;

   	if(albumes != NULL && tam >0)
   	{
   		for(i=0;i<tam-1;i++)
   		{
   			for(j=i+1;j<tam;j++)
   			{
   				if(albumes[i].fechaDePublicacion.anio>albumes[j].fechaDePublicacion.anio)
   				{
   					aux = albumes[i];
   					albumes[i] = albumes[j];
   					albumes[j] = aux;
   				}

   			}
   		}
   	}

}

/*
void listarPorAnio(eAlbum albumes[], int tam)
{
	int i;


	if(albumes != NULL && tam >0)
	{
      for(i=0;i<tam;i++)
      {
          if()
      }
	}

}
*/

/*
 ============================================================================
 Name        : repaso.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

 void mostrarCantidadDePeliculasPorCadaGenero(ePelicula listaPeliculas[],int tam)
{
    int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idGenero)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }

    }

    if(flag)
    {
        printf("Genero...\n");
        printf("Accion : %d\nComedia : %d\nTerror : %d\nRomantica : %d\nOtro :%d\n",contador1,contador2,contador3,contador4,contador5);
    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }
}

void mostrarActoresMasSolicitados(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct)
{
     int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    int max;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idActor)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }
    }

    if(flag)
    {
        printf("Los actores que mas peliculas protagonizaron son :\n");
        max=contador1;

        if(max<contador2)
        {
            max=contador2;
        }
        if(max<contador3)
        {
            max=contador3;
        }
        if(max<contador4)
        {
            max=contador4;
        }
        if(max<contador5)
        {
            max=contador5;
        }

        if(contador1==max)
        {
            printf("%s\n",listaActores[0].nombre);
        }

        if(contador2==max)
        {
            printf("%s\n",listaActores[1].nombre);
        }

        if(contador3==max)
        {
            printf("%s\n",listaActores[2].nombre);
        }

        if(contador4==max)
        {
            printf("%s\n",listaActores[3].nombre);
        }

        if(contador5==max)
        {
            printf("%s\n",listaActores[4].nombre);
        }

        printf("\ny trabajaron en %d peliculas\n\n",max);

    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }

}

void mostrarGenerosConMenosPeliculas(ePelicula listaPeliculas[],int tam)
{
    int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;
    int min;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idGenero)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }
    }

    if(flag)
    {
        printf("Los generos con menos peliculas son :\n");
        min=contador1;

        if(min>contador2)
        {
            min=contador2;
        }
        if(min>contador3)
        {
            min=contador3;
        }
        if(min>contador4)
        {
            min=contador4;
        }
        if(min>contador5)
        {
            min=contador5;
        }

        if(contador1==min)
        {
            printf("%s\n",genero[0]);
        }

        if(contador2==min)
        {
            printf("%s\n",genero[1]);
        }

        if(contador3==min)
        {
            printf("%s\n",genero[2]);
        }

        if(contador4==min)
        {
            printf("%s\n",genero[3]);
        }

        if(contador5==min)
        {
            printf("%s\n",genero[4]);
        }

        printf("\nestos generos tienen %d peliculas\n\n",min);

    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }

}


void mostrarActoresQueNoTrbajaron(ePelicula listaPeliculas[],int tam,eActor listaActores[],int tamAct)
{
    int i;
    int flag=0;
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int contador4=0;
    int contador5=0;

    for(i=0;i<tam;i++)
    {

        if(listaPeliculas[i].cargado)
        {
            switch(listaPeliculas[i].idActor)
            {
                case 1:
                    contador1++;
                    break;
                case 2:
                    contador2++;
                    break;
                case 3:
                    contador3++;
                    break;
                case 4:
                    contador4++;
                    break;
                case 5:
                    contador5++;
                    break;
            }

            flag=1;
        }
    }

    if(flag && (contador1==0 || contador2==0 || contador3==0 || contador4==0 || contador5==0))
    {
        printf("Los actores que no trabajaron en ninguna pelicula :\n");


        if(contador1==0)
        {
            printf("%s\n",listaActores[0].nombre);
        }

        if(contador2==0)
        {
            printf("%s\n",listaActores[1].nombre);
        }

        if(contador3==0)
        {
            printf("%s\n",listaActores[2].nombre);
        }

        if(contador4==0)
        {
            printf("%s\n",listaActores[3].nombre);
        }

        if(contador5==0)
        {
            printf("%s\n",listaActores[4].nombre);
        }

    }
    else if(flag)
    {
        printf("\nTodos los Actores han trabajado en alguna peli\n\n");
    }
    else
    {
        printf("\nNo hay peliculas ingresadas\n\n");
    }

}

void masAlbumesArtista(eAlbum* list, int len, eArtista* listaArtistas, int lenArt)
{
	int i;

	int contador1 = 0;
	int contador2 = 0;
	int contador3 = 0;
	int contador4 = 0;
	int contador5 = 0;
	int maxArtista = -1;
	int flag = 0;

	//int codigoDeArtista[] = {100,101,102,103,104};
	//char nombreArtista[][51] = {"Camilo","Beatles","Camila Cabello","Coldplay","Dua Lipa"};


	for(i=0;i<len;i++)//recorro albumes
	{
		if(list[i].estado == OCUPADO)
		{
			switch(list[i].codigoDeArtista)
			{
				case 100://camilo
					contador1++;
					break;
				case 101://beatles
					contador2++;
					break;
				case 102://camila cabello
					contador3++;
					break;
				case 103://coldplay
					contador4++;
					break;
				case 104://Dua Lipa
					contador5++;
					break;
			}
         flag = 1;
		}
	}

	if(maxArtista<contador1)
	{
		maxArtista = contador1;
	}

	if(maxArtista<contador2)
	{
		maxArtista = contador2;
	}

	if(maxArtista<contador3)
	{
		maxArtista = contador3;
	}

	if(maxArtista<contador4)
	{
		maxArtista = contador4;
	}
	if(maxArtista<contador5)
	{
		maxArtista = contador5;
	}

	if(flag)
	{

		if(maxArtista == contador1)
		{
			printf("\n El artista con mas albumes: CAMILO");
			printf("\n %s",listaArtistas[0].nombreArtista);
		}
		if(maxArtista == contador2)
		{
			printf("\n El artista con mas albumes: BEATLES");
			printf("\n %s",listaArtistas[1].nombreArtista);
		}
		if(maxArtista == contador3)
		{
			printf("\n El artista con mas albumes: CAMILA CABELLO");
			printf("\n %s",listaArtistas[2].nombreArtista);
		}
		if(maxArtista == contador4)
		{
			printf("\n El artista con mas albumes: COLDPLAY");
			printf("\n %s",listaArtistas[3].nombreArtista);
		}
		if(maxArtista == contador5)
		{
			printf("\n El artista con mas albumes: DUA LIPA");
			printf("\n %s",listaArtistas[4].nombreArtista);
		}
		printf("\n ");
	}
	else
	{
		printf("\nNo hay albumes ingresados\n\n");
	}

}

void menosAlbumesArtista(eAlbum* list, int len, eArtista* listaArtistas, int lenArt)
{
	int i;

	int contador1 = 0;
	int contador2 = 0;
	int contador3 = 0;
	int contador4 = 0;
	int contador5 = 0;
	int minArtista;
	int flag = 0;

	//int codigoDeArtista[] = {100,101,102,103,104};
	//char nombreArtista[][51] = {"Camilo","Beatles","Camila Cabello","Coldplay","Dua Lipa"};


	for(i=0;i<len;i++)//recorro albumes
	{
		if(list[i].estado == OCUPADO)
		{
			switch(list[i].codigoDeArtista)
			{
				case 100://camilo
					contador1++;
					break;
				case 101://beatles
					contador2++;
					break;
				case 102://camila cabello
					contador3++;
					break;
				case 103://coldplay
					contador4++;
					break;
				case 104://Dua Lipa
					contador5++;
					break;
			}
         flag = 1;
		}
	}


     minArtista = contador1;

	if(minArtista>contador2)
	{
		minArtista = contador2;
	}

	if(minArtista>contador3)
	{
		minArtista = contador3;
	}

	if(minArtista>contador4)
	{
		minArtista = contador4;
	}
	if(minArtista>contador5)
	{
		minArtista = contador5;
	}

	if(flag)
	{

		if(maxArtista == contador1)
		{
			printf("\n El artista con mas albumes: CAMILO");
			printf("\n %s",listaArtistas[0].nombreArtista);
		}
		if(maxArtista == contador2)
		{
			printf("\n El artista con mas albumes: BEATLES");
			printf("\n %s",listaArtistas[1].nombreArtista);
		}
		if(maxArtista == contador3)
		{
			printf("\n El artista con mas albumes: CAMILA CABELLO");
			printf("\n %s",listaArtistas[2].nombreArtista);
		}
		if(maxArtista == contador4)
		{
			printf("\n El artista con mas albumes: COLDPLAY");
			printf("\n %s",listaArtistas[3].nombreArtista);
		}
		if(maxArtista == contador5)
		{
			printf("\n El artista con mas albumes: DUA LIPA");
			printf("\n %s",listaArtistas[4].nombreArtista);
		}
		printf("\n ");
	}
	else
	{
		printf("\nNo hay albumes ingresados\n\n");
	}

}

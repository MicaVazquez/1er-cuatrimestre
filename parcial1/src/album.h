/*
 * album.h
 *
 *  Created on: 30 abr. 2022
 *      Author: PC-INC
 */

#ifndef ALBUM_H_
#define ALBUM_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int codigoTipoArtista;//PK
	char descripcionTipoArtista[51];

}eTipoArtista;//(1, solista; 2, banda)

typedef struct
{
	int codigoDeArtista;//PK
	char nombreArtista[51];

}eArtista;

typedef struct
{
	int id;
	char descripcion[51];

}ePais;


typedef struct
{
	int codigoDeDiscografica;//PK
	char descripcionDiscografica[51];
}eDiscografica;

typedef struct
{
  int estado;
  int codigoTipoArtista;//FK
  int codigoDeArtista;//FK
  int codigoDeDiscografica;//FK
  int codigoDeAlbum;
  char titulo[51];
  eFecha fechaDePublicacion;
  int importe;

}eAlbum;

int eAlbum_inicializar(eAlbum* list, int len);
int eAlbum_alta(eAlbum list[], int len,eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,eArtista listaDeArtistas[], int limArt);
void eAlbum_imprimirUno(eAlbum unAlbum);
void eAlbum_imprimirTodos(eAlbum* list, int largo);
eFecha pedirFecha();
int buscarLibre(eAlbum* list, int len);
int eAlbum_encontrarPorCodigo(eAlbum* list, int len,int codigo);
eAlbum cargarUno(eTipoArtista listaDeTipoArtista[],int limTipoArtista,eDiscografica listaDeDiscograficas[],int limDisc,eArtista listaDeArtistas[], int limArt);
void eAlbum_modificar(eAlbum list[], int len, eTipoArtista listaDeTipoArtista[],int tamTipoArtista,eDiscografica listaDeDiscograficas[],int tamDisc,eArtista listaDeArtistas[], int tamArt);
int eAlbum_baja(eAlbum* list, int len);
void eAlbum_importeTotalPromedio(eAlbum lista[], int tam);
void eAlbum_hardcodearDatos(eAlbum lista[]);
void eAlbum_posterior(eAlbum list[], int len);
void eAlbum_informar(eAlbum list[], int len);
void eAlbum_listar(eAlbum list[], int tam,eTipoArtista listaTipoArtista[],int lenTipoArtista,eDiscografica listaDiscograficas[],int lenDisc,eArtista listaArtistas[],int lenArt);
/**
 * @brief inicializa tipo de artista con datos
 *
 * @param lista array
 * @param lim tama�o
 */
void hardcodearTipoArtista(eTipoArtista lista[], int lim);
/**
 * @brief inicializa discografias con datos
 *
 * @param lista array
 * @param lim tama�o
 */
void hardcodearDiscograficas(eDiscografica lista[], int lim);
/**
 * @brief inicializa artistas con datos
 *
 * @param lista array
 * @param lim  tama�o
 */
void hardcodearArtistas(eArtista lista[], int lim);
/**
 * @brief ordena por doble criterio: los albumes de forma descendente por importe y ascendente por titulo
 *
 * @param list array
 * @param len tama�o
 */
void ordenarAlbumes(eAlbum list[],int len);

/**
 * @brief la funcion lista todos los tipos de artistas
 *
 * @param albumes array album
 * @param len
 * @param listaDeTipoArtista
 * @param lenTipoArtista
 */
void listarTiposArtistas(eAlbum albumes[], int len, eTipoArtista listaDeTipoArtista[], int lenTipoArtista);
/**
 * @brief la funcion lista todos los artistas
 *
 * @param albumes
 * @param len
 * @param listaDeArtistas
 * @param lenArt
 */
void listarArtistas(eAlbum albumes[], int len, eArtista listaDeArtistas[], int lenArt);
/**
 * @brief la funcion lista todas las discograficas
 *
 * @param albumes
 * @param len
 * @param listaDeDiscograficas
 * @param lenDisc
 */
void listarDiscograficas(eAlbum albumes[], int len, eDiscografica listaDeDiscograficas[], int lenDisc);

/**
 * @brief lista los ambumes posteriores a 1999
 *
 * @param list array
 * @param len tama�o
 */
void listarPosteriores(eAlbum list[],int len);

/**
 * @brief lista albumes que no superan el rpomedio
 *
 * @param list array
 * @param tam  tama�o
 */
void listarMenorAlPromedio(eAlbum list[],int tam);

/**
 * @brief lista de albumes por cada artista
 *
 * @param albumes lista de albumes
 * @param tam  largo de la lista
 * @param artistas lista de artistas
 * @param lenArt  largo de la lista
 */
void listarAlbumesPorArtistas(eAlbum albumes[],int tam, eArtista artistas[], int lenArt);

/**
 * @brief ordenar el array de albumes por a�o
 *
 * @param albumes array
 * @param tam largo del array
 */
void ordenarPorAnio(eAlbum albumes[], int tam);
#endif /* ALBUM_H_ */

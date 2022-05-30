/*
 * alumnos.h
 *
 *  Created on: 18 abr. 2022
 *      Author: PC-INC
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_

typedef struct
{
	char nombre [20];
	int edad;
	int nota;
	int estado;

}eAlumno;
/**
 * @brief la funcion inicializa el vector en 0.
 *
 * @param listaAlumnos vector de la estructura.
 * @param tamanio cantidad de elementos del vector.
 */
void inicializarVector(eAlumno listaAlumnos [],int tamanio);

/**
 * @brief la funcion busca un espacio libre.
 *
 * @param listaAlumnos vector de la estructura.
 * @param tamanio cantidad de elementos del vector.
 * @return retorna la posicion. En caso de ser 0 hay un espacio libre, pero en caso de ser -1, no hay mas posiciones para cargar.
 */
int buscarLibre (eAlumno listaAlumnos [],int tamanio);

/**
 * @brief La funcion llama a la funcion "buscarLibre"
 * le pasa los dos parametros y segun lo que le retorne va a pedir datos u imprimira un mensaje de que no hay mas espacio.
 *
 * @param listaAlumnos vector de la estructura
 * @param tamanio cantidad de elementos del vector.
 */
void altaAlumnos(eAlumno listaAlumnos [],int tamanio);

/**
 * @brief La funcion muestra por consola la cantidad de elementos del vactor cargados.
 *
 * @param listaAlumnos vector de la estructura.
 * @param tamanio cantidad de elementos del vector.
 */
void imprimirAlumnos(eAlumno listaAlumnos [],int tamanio);
#endif /* ALUMNOS_H_ */

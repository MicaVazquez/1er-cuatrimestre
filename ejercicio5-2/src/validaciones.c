/*
 * validaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC-INC
 */
//CUERPO/DESARROLLO
#include <stdio.h>
#include <stdlib.h>
int pedirEnteroPositivo(char mensaje[],char error[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d", &numero);

    while(numero < 1)
    {
        printf("%s",error);
        scanf("%d", &numero);
    }

    return numero;
}
//FUNCION UTN GET NUMERO
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensaje != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d",&bufferInt);

            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }while(reintentos >= 0);
    }
    return retorno;
}


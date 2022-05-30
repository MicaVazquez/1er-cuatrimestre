/*
 ============================================================================
 Name        : ejercicioSabado1-3.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ejercicio 1-3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	char tipoCursada;
    int materias;
    char sexo;
    int notaPromedio;
    int edad;
    char respuesta;
    int mayorPromedio;
    int banderaMayorPromedio;
    int edadMasJoven;
    int banderaMasJoven;
    int contadorF;
    int contadorM;
    int contadorO;
    int acumuladorF;
    int acumuladorM;
    int acumuladorO;
    int promedioF;
    int promedioM;
    int promedioO;
    int legajo;
    int legajoMasJoven;
    int legajoMujerMejorP;
    int edadMasMaterias;
    int legajoMasMaterias;


    contadorF=0;
    contadorM=0;
    contadorO=0;
    acumuladorF=0;
    acumuladorM=0;
    acumuladorO=0;
    banderaMasJoven=0;
    banderaMayorPromedio=0;
	respuesta='s';
    do
    {
    	printf("Ingrese el legajo: ");
    	scanf("%d",&legajo);

    	while(legajo>0)
    	{
    		printf("Reingrese el legajo: ");
    		scanf("%d",&legajo);
    	}

    	printf("Tipo de cursada libre 'l', presencial 'p' o remota 'r' :");
    	fflush(stdin);
    	scanf("%c",&tipoCursada);

    	while(tipoCursada != 'l'&& tipoCursada !='p' && tipoCursada!='r')
    	{
    		printf("Reingrese tipo de cursada libre 'l', presencial 'p' o remota 'r' :");
    		fflush(stdin);
    		scanf("%c",&tipoCursada);
    	}

        printf("Cantidad de materias: ");
        scanf("%d",&materias);

        while(materias<0 || materias>8)
        {
        	printf("Cantidad de materias: ");
        	scanf("%d",&materias);
        }

        printf("ingrese sexo masculino 'm', femenino 'f' o no binario 'o' ");
        fflush(stdin);
        scanf("%c",&sexo);

        while(sexo!='m'&& sexo!='f'&& sexo!='o')
        {
        	printf("ingrese sexo masculino 'm', femenino 'f' o no binario 'o' ");
        	fflush(stdin);
        	scanf("%c",&sexo);
        }

        printf("Ingrese nota promedio : "); //0 a 10
        scanf("%d",&notaPromedio);

        while(notaPromedio<0 || notaPromedio>10)
        {
        	printf("Reingrese nota promedio : "); //0 a 10
        	scanf("%d",&notaPromedio);
        }

        printf("Ingrese edad : ");//mayor 18
        scanf("%d",&edad);

        while(edad<18)
        {
        	printf("Reingrese edad : ");//mayor 18
        	scanf("%d",&edad);
        }

        // La edad y legajo del que cursa más materias. (Sin importar su género)

        if(materias==8)
        {
        	edadMasMaterias=edad;
        	legajoMasMaterias=legajo;

        }

        switch(sexo)
        {
        case 'f':
        	if(notaPromedio>mayorPromedio || banderaMayorPromedio)
        	{
        		mayorPromedio = notaPromedio;   //legajo de la mjujer joven con mayor promedio;
                legajoMujerMejorP = legajo;
        		banderaMayorPromedio = 0;
        	}
        	acumuladorF+=notaPromedio;
        	contadorF++;
        	break;
        case 'm':
        	if(tipoCursada=='l')
        	{
        		if(edadMasJoven<edad||banderaMasJoven)
        		{
        			edadMasJoven=edad;  //legajo de el chico mas joven
        			legajoMasJoven = legajo;
        			banderaMasJoven=0;
        		}
        	}
        	acumuladorM+=notaPromedio;
        	contadorM++;
        	break;
        case 'o':
        	acumuladorO+=notaPromedio;
        	contadorO++;
        	break;

        }

    	printf("Desea continuar? s o n: ");
    	fflush(stdin);
    	scanf("%c",&respuesta);
    }while(respuesta=='s');

    promedioF=acumuladorF/contadorF;
    promedioM=acumuladorM/contadorM;
    promedioO=acumuladorO/contadorO;

    printf("a) El Legajo del mejor promedio femenino: %d", legajoMujerMejorP);
    printf("b) El legajo del más joven de los alumnos masculinos entre los que dan libre: %d",legajoMasJoven);
    printf("c) Promedio de edad por sexo: femenino %d , masculino %d , no binario %d ",promedioF,promedioM,promedioO);
    printf("d) El que cursa más materias: edad %d y legajo %d (Sin importar su género)",edadMasMaterias,legajoMasMaterias);

	return EXIT_SUCCESS;
}

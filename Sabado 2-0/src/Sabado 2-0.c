/*
 ============================================================================
  EJERCICIO 2-0
Crear una función que reciba como parámetro dos números enteros, que realice el promedio de los números y que retorne dicho valor.
Vazquez Micaela

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float calcularPromedio (int a, int b); //prototipo  tipoDevuelve nombreFuncion (tipo parametros)

int main(void)
{   int x=5;
	int y=10;
	float total;

	total=calcularPromedio(x,y);//parametros actuales: cambian
	printf("Promedio: %.2f", total);

	return EXIT_SUCCESS;
}
float calcularPromedio (int a, int b) //parametros formales
{
	float resultado;//variable local solo tiene visivilidad dentro de esa función.
	int suma;
	suma= a + b;
	resultado=(float)suma/2; //castear
	return resultado;
}


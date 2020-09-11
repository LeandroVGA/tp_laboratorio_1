/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Leandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);

	float numeroA;
	float numeroB;
	float resultado[6];
	int pOpcion;
	int respuesta;
	int banderaA = 0;
	int banderaB = 0;
	do {
		system("cls");
		printf(
				"\nTitulo\n"
				"***\n"
				"1.Ingresar 1er operando (A=x)\n"
				"2.Ingresar 2do operando (B=y)\n"
				"3.Calcular todas las operaciones\n"
				"4.Informar resultados\n"
				"5.Salir\n\n");
		if(banderaA != 0){

		printf("A= %.2f \n",numeroA);
		}
		if(banderaB != 0){

		printf("B= %.2f \n",numeroB);
		}

	getInt("Ingrese opcion: ", "\nOpcion invalida. Por favor ", &pOpcion, 5,5, 1);
	switch (pOpcion) {
	case 1:

		system("cls");
		printf("\nOpcion 1 \n"); //Ingrese operador A
		printf("\n***************\n");
		getFloat("Ingrese su primer numero \n","Tenes que ingresar un valor numerico Porfavor", &numeroA,2, 100, 0);
		printf("\n***************\n");
		banderaA = 1;

		break;

	case 2:

		system("cls");
		printf ("\nOpcion 2 \n");       //Ingrese operador B
		printf("\n***************\n");
		getFloat("Ingrese su segundo numero \n","Tenes que ingresar un valor numerico Porfavor", &numeroB,2, 100, 0);
		printf("\n***************\n");
		banderaB = 1;

		break;

	case 3:

		system("cls");
		printf ("\nOpcion 3 \n");       //Funciones de calculo

		Suma(numeroA, numeroB, &resultado[0]);

		Resta(numeroA, numeroB, &resultado[1]);

		respuesta = Division(numeroA, numeroB, &resultado[2]);

		if(respuesta != 0){

			printf ("\nLa Division ha fallado, NO SE PUEDE DIVIDIR CON 0 \n");
		}

		Multiplicacion(numeroA, numeroB, &resultado[3]);

		Factorial(numeroA,&resultado[4]);
		Factorial(numeroB,&resultado[5]);

		if(respuesta == 0){

			printf ("\nLos distintos calculos se realizaron Exitosamente!!\n");

		}

		printf("\n***************\n");
		system("cls");
		break;

	case 4:

		system("cls");
		printf ("\nOpcion 4 \n");       //Funcion de imprimir
		printf("\n***************\n");
		printf("\nEl resultado de la Suma es:  %.2f\n", resultado[0]);
		printf("\nEl resultado de la Resta es:  %.2f\n", resultado[1]);
		printf("\nEl resultado de la Multiplicacion es: %.2f\n", resultado[2]);
		printf("\nEl resultado de la Division es: %.2f\n", resultado[3]);
		printf("\nEl resultado de la Factorial del numero 1 es: %.2f\n", resultado[4]);
		printf("\nEl resultado de la Factorial del numero 2 es: %.2f\n", resultado[5]);
		printf("\n***************\n");

		system("pause");
		break;
			}
		}
	while (pOpcion != 5);




		}


#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int getFloat(char* mensaje, char* mensajeError, float* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush // __fpurge
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush // __fpurge
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Suma los valores que ingresa el usuario
 * \param float numeroA es le primer numero que ingreso la persona
 * \param float numeroB es le primer numero que ingreso la persona
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 *
 */
int Suma(float numeroA, float numeroB, float resultado[]) {

	*resultado = numeroA + numeroB;

	return 0;

}

/**
 * \brief Resta los valores que ingresa el usuario
 * \param float numeroA es le primer numero que ingreso la persona
 * \param float numeroB es le primer numero que ingreso la persona
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 *
 */
int Resta(float numeroA, float numeroB, float resultado[]) {

	*resultado = numeroA - numeroB;

	return 0;

}

/**
 * \brief Multiplicacion los valores que ingresa el usuario
 * \param float numeroA es le primer numero que ingreso la persona
 * \param float numeroB es le primer numero que ingreso la persona
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 *
 */
int Multiplicacion(float numeroA, float numeroB, float resultado[]) {

	*resultado = numeroA * numeroB;

	return 0;

}


/**
 * \brief Division los valores que ingresa el usuario
 * \param float numeroA es le primer numero que ingreso la persona
 * \param float numeroB es le primer numero que ingreso la persona
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 *
 */
int Division(float numeroA, float numeroB, float resultado[]) {

	int error = -1;

	if (numeroB != 0.0) {

		*resultado = numeroA / numeroB;

		error = 0;

	}

	return error;

}


/**
 * \brief Division los valores que ingresa el usuario
 * \param float numeroA es le primer numero que ingreso la persona
 * \param float numeroB es le primer numero que ingreso la persona
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 *
 */
int Factorial(float numero, float resultado[]) {

	int total = 1;
	int acumulador;
	for (int i=1; i<=numero; i++) {
		acumulador = total * i;
	}
	*resultado = acumulador;
	return 0;
}





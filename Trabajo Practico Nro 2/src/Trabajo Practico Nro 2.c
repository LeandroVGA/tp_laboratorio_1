/*
 *  Created on: 26 sep. 2020
 *  Author: Leandro varela gomez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "ArrayEmployee.h"
#include "utn.h"


int main(void) {
setbuf(stdout,NULL);
int opcion;

Employee employeeList[CANT_EMPLOYEE];
initEmployees(employeeList, CANT_EMPLOYEE);


  do
    {
      printf ("\n---------------"
	      "\n* MENU  *"
	      "\n*********"
	      "\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-Salir\n\n");


      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
	{
	  switch (opcion)
	    {
	    case 1:

	      if (flagLimite (employeeList, CANT_EMPLOYEE) != -1)
		{
		  if (utn_searchFree (employeeList, CANT_EMPLOYEE) == TRUE)
		    {
		      printf ("\n------------------------------------------------------");
		      printf ("\n------------------      ALTA    --------------------\n");
		      printf ("------------------------------------------------------\n");
		      if (AltaEmployee (employeeList, CANT_EMPLOYEE) != 0)
			{
			  printf ("\n-----------------------------\n");
			  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
			  printf ("\n-----------------------------\n");
			}
		    }
		}
	      else
		{
		  printf ("\n-------------------------------------------\n");
		  printf ("\nLA CANTIDAD DE EMPLEADOS LLEGO A SU LIMITE!\n");
		  printf ("\n-------------------------------------------\n");
		}

	      break;
	    case 2:
	      if (flagLimite (employeeList, CANT_EMPLOYEE) != 0)
		{
		  printf ("\n-----------------------------------------------------");
		  printf ("\n------------------    MODIFICAR    ------------------\n");
		 printf ("-----------------------------------------------------\n");
		  if (updateEmployee (employeeList, CANT_EMPLOYEE) != 0)
		    {
		      printf ("\n******\n");
		      printf ("\nERROR!\n");
		      printf ("\n******\n");
		    }
		}
	      else
		{
	      printf ("\n--------------------------------------------\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MODIFICAR!\n");
		  printf ("\n--------------------------------------------\n");

		}

	      break;
	    case 3:
	      if (flagLimite (employeeList, CANT_EMPLOYEE) != 0)
	      	{
		  printf ("\n-----------------------------------------------------\n");
		  printf ("\n--------------------     BAJA    ---------------------\n");
		  printf ("\n-----------------------------------------------------\n");
	      if(prepareForDelete(employeeList,CANT_EMPLOYEE)==-1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      	}
	      else
	      		{
		  printf ("\n----------------------------------------\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA ELIMINAR!\n");
		  printf ("\n----------------------------------------\n");
	      		}
	      break;
	    case 4:
	      if (flagLimite (employeeList, CANT_EMPLOYEE) != 0)
	        {
		 printf ("\n------------------------------------------------------");
		 printf ("\n------------------    INFORMAR    --------------------\n");
		 printf ("-----------------------------------------------------\n");
	      if(sortEmployees(employeeList, CANT_EMPLOYEE, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      cabeceraEmployee();
	      printEmployees(employeeList, CANT_EMPLOYEE);
	      printf ("\n------------------------------------------------------\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",sumaTotal(employeeList, CANT_EMPLOYEE));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",promedio(employeeList, CANT_EMPLOYEE));
      	      printf ("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",cantidadSuperiorAlPronedio(employeeList, CANT_EMPLOYEE));
	      printf ("\n------------------------------------------------------\n");
	     	}
	      else
			{
		  printf ("\n------------------------------------\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MOSTRAR!\n");
		  printf ("\n------------------------------------\n");
			}
	      break;
	    case 5:
	      printf("\nEL RPOGRAMA SE CERRO CON EXITO!\n");
	      system ("pause");
	      return EXIT_SUCCESS;
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  printf ("\n------------------------------------\n");
	  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
	  printf ("\n------------------------------------\n");

	  //return EXIT_SUCCESS;
	}
    }
  while (opcion != 5);

	return EXIT_SUCCESS;
}

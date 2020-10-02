/*
 *  Created on: 26 sep. 2020
 *  Author: Leandro varela gomez
 */

#include "ArrayEmployee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn.h"

/*
 * list | se le pasa la lista de tipo Employee
 * len | se le pasa la longitud de la lista
 *
 * Se encarga de inicializar todas las variables
 *
 * */
int initEmployees(Employee list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].id = 0;
		    strcpy(list[i].name, "");
		    strcpy(list[i].lastName,"");
		    list[i].salary = 0.00;
		    list[i].sector = 0;
		}
		retorno = 0;
	}
	return retorno;
}


//
/*
 * list | se le pasa la lista de tipo Employee
 * len | se le pasa la longitud de la lista
 *
 * Se encarga de imprimir lo que este dento de la lista
 *
 * */
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf(" %-6d %-12s %-13s %-12.2f %d \n"
				 //   ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].name
				    ,list[i].lastName
				    ,list[i].salary
				    ,list[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}


void cabeceraEmployee(void)
{
    printf("\n%*s%*s%*s%*s%*s",
	   -7, " ID",
	   -13," NOMBRE",
	   -14," APELLIDO",
	   -12," SALARIO",
	    0," SECTOR"
	   "\n-----------------------------------------------------\n");
}



int utn_searchFree (Employee *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (isEmpty(list, len, i) == 1)
	    {
	      retorno = TRUE;
	      break;
	    }
	}
    }
  return retorno;
}
//nose porque me tira warning el isEmpty que esta justo arriba, cuando la declaracion o prototipo es este!!
int isEmpty(Employee* list, int limit, int index)
{
  int retorno = FALSE;
    if (list != NULL && list > 0)
    {
      if (list[index].isEmpty == TRUE)
	{
	  retorno = TRUE;
	}
    }
  return retorno;
}

/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 * name     | se le pasa el nombre del empleado
 * lastName | se le pasa el apellido del empleado
 * salary   | se le pasa el salario del empleado
 * sector   | se le pasa el sector del empleado
 * Se encarga de agregar un empleado a la lista Employee
 *
 * */
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (isEmpty (list, len, i) == 1)
	    {
	      list[i].id = id;
	      strcpy (list[i].name, name);
	      strcpy (list[i].lastName, lastName);
	      list[i].salary = salary;
	      list[i].sector = sector;
	      list[i].isEmpty = FALSE;
	      return 0;
	    }
	}
    }
  return -1;
}


int idIncremental(void)
{
    static int id = 0;
    id++;
    return id;
}



/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 *
 * Se encarga de dar de alta un empleado
 *
 * */

int AltaEmployee (Employee *list, int len)
{
  Employee auxEmployee;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", auxEmployee.name, LONG_NAME_EMPLOYE, 5) != 0)
	{
	  return -1;
	}
     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", auxEmployee.lastName, LONG_NAME_EMPLOYE, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNumeroFloat (&auxEmployee.salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	{
	  return -1;
	}
      if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxEmployee.sector, 0, 100, 5)!= 0)
	{
	  return -1;
	}
      switch (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	{
	case -1:
	  return -1;
	  break;

	case 1:
	  auxEmployee.id = idIncremental ();
	  printf ("\n-----------------------------------------------------");
	  printf ("\n                    ALTA EXITOSA!                  \n");
	  printf ("-----------------------------------------------------\n\n");
	  if(addEmployee (list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector)!=0)
	    {
	      return -1;
	    }
	  return 0;
	  break;

	case 0:
	  return 0;
	  break;

	default:
	  break;
	}
    }
  return -1;
}



/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 *
 * se encarga de encontrar a un empleado a travez del id
 *
 * */
int findEmployeeById (Employee *list, int len, int id)
{
  int i;
  int retorno = -1;

  if (list != NULL && len > 0 && id != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      retorno = id;
	      break;
	    }
	}

    }
return retorno;
}
/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 *
 * Se encarga de imprimir toda la informacion de un empleado a travez del id
 *
 * */
int printForId  (Employee *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    cabeceraEmployee();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].sector != FALSE )
  			{
  				printf(" %-6d %-12s %-13s %-12.2f %d \n"
  				  //  ,list[i].isEmpty
  				    ,list[i].id
  				    ,list[i].name
  				    ,list[i].lastName
  				    ,list[i].salary
  				    ,list[i].sector);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}




int arrayToBuffer(Employee *list,Employee *listBuffer, int len, int id)
{
  int retorno = -1;
    int i;
    	if(list != NULL && len > 0)
    	{
    	      for( i=0;i<len;i++)
    		{
    			if(list[i].id == id)
    			{
    			*listBuffer=list[i];
    			}
    		}
    		retorno = 0;
    	}
return retorno;
}


int bufferToArray(Employee *list, Employee *listBuffer, int len, int id)
{
  int i;
  int retorno = -1;
  if (list != NULL && listBuffer != NULL && len > 0)
    {

	for (i = 0; i < len; i++)
	  {
	    if (list[i].id == id)
	      {
		list[i] = *listBuffer;
		retorno = 0;
	      }
	  }
    }
  return retorno;
}



/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 *
 * se encarga de modificar el valor de la informacion de un empleado en base a su id
 *
 * */
int updateEmployee (Employee *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Employee auxEmployee;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, CANT_EMPLOYEE, 5);
      if (findEmployeeById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  arrayToBuffer(list, &auxEmployee,  len,  bufferID);
	  do
	     {
	      printForId  (&auxEmployee,len,  bufferID);
	      printf ("\n1-Nombre-\n"
	    		  "2-Apellido-\n"
	      	      "3-Salario-\n"
	      	      "4-Sector-\n"
	      	      "5-Aceptar Cambios-\n"
	      	      "6-Salir-\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\nNOMBRE\n-----------\n");

	 	     if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", auxEmployee.name, LONG_NAME_EMPLOYE, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\nAPELLIDO\n-----------\n");
	 	     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", auxEmployee.lastName, LONG_NAME_EMPLOYE, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	    case 3:
	 	      printf ("\nSALARIO\n-----------\n");
	 	     if (utn_getNumeroFloat (&auxEmployee.salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	      break;
	 	    case 4:
	 	      printf ("\nSECTOR\n------------\n");
	 	     if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxEmployee.sector, 1, 100, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 5:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 		    bufferToArray (list, &auxEmployee,  len, bufferID);
	 		    printf ("\nLOS CAMBIOS SE GRABARON EXITOSAMENTE!\n");

	 		   }
	 	      break;
	 	    }
	 	}
	       else
	 	{
	 	  printf ("\nTE QUEDASTE SIN REINTENTOS\n");
	 	  system ("pause");
	 	  return EXIT_SUCCESS;
	 	}
	     }
	   while (opcion != 6);

	  if(opcion == 6)
	    {
	      return EXIT_SUCCESS;
	    }
	}//final del if findEmployeeById
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }//final de validacion de null
  return retorno;
}

/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * id       | se le pasa el id del empleado
 *
 * Se encarga de eliminar un empleado a la lista Employee
 *
 * */
int removeEmployee(Employee* list, int len, int id)
{
  int i;
  int retorno;

  if (list != NULL && len > 0 && id > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      list[i].isEmpty = TRUE;
	      retorno = 0;
	    }
	}
    }
 return retorno;
}


int prepareForDelete (Employee *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, CANT_EMPLOYEE, 5);
      if (findEmployeeById (list, len, bufferID) != -1)
	{
	  printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar empleado? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      removeEmployee (list, len, bufferID);
	      retorno = 1;
	      printf ("\n------------------------------------------------------");
	      printf ("\n             ELIMINACION EXITOSA!\n");
	      printf ("------------------------------------------------------\n\n");
	    }
	}
    }
  return retorno;
}


/*
 * list     | se le pasa la lista de tipo Employee
 * len      | se le pasa la longitud de la lista
 * order    | se le pasa el valor para ordenar menor a 0 o mayor a 0 (-1 o 1)
 * Se encarga de agregar un empleado a la lista Employee
 *
 * */
int sortEmployees(Employee* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Employee buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;

	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
	      if ((order == 0 && strcmp (list[i].lastName, list[i + 1].lastName) < 0)||
		  (order == 1 && strcmp (list[i].lastName, list[i + 1].lastName) > 0)||
		  (0==strcmp (list[i].lastName, list[i + 1].lastName) &&
		      (((list[i].sector > list[i + 1].sector)&&(order == 1))
			  ||((list[i].sector < list[i + 1].sector) &&(order == 0)))))
		{
		  flagSwap = 1;
		  buffer = list[i];
		  list[i] = list[i + 1];
		  list[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}



float sumaTotal (Employee *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].salary != FALSE)
	    {
	      aux = aux + list[i].salary;
	    }
	}
      retorno = aux;
    }
  return retorno;
}



float promedio(Employee* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].salary != FALSE)
	    {
	      contador++;
	    }
	}
      retorno = sumaTotal (list, len) / contador;
    }
  return retorno;
}


int cantidadSuperiorAlPronedio(Employee* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = promedio (list, len);
  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].salary > aux)
	    {
	      contador++;
	    }
	}
      retorno = contador;
    }
  return retorno;
}



int flagLimite(Employee* list, int len)
{
  int retorno = -1;
  int i;
  int contador = 0;

  for (i = 0; i < len; i++)
    {
      if (i <= len && list[i].isEmpty == FALSE)
	{
	  contador++;
	}
    }
  if (contador == 0)
    {
      retorno = 0;
    }
  else if (contador > 0 && contador != len)
    {
      retorno = contador;
    }
  return retorno;
}


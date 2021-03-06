/*
 *  Created on: 26 sep. 2020
 *  Author: Leandro varela gomez
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_EMPLOYE 51
#define CANT_EMPLOYEE 6
#define MAX_EMPLOYEE 100

struct
{
int id;
char name[LONG_NAME_EMPLOYE];
char lastName[LONG_NAME_EMPLOYE];
float salary;
int sector;
int isEmpty;
}typedef Employee;



int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
void cabeceraEmployee(void);
int idIncremental(void);
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int AltaEmployee (Employee* list, int len);
int utn_searchFree (Employee* list, int len);
int findEmployeeById (Employee *list, int len, int id);
int updateEmployee (Employee* list, int len);
int  bufferToArray (Employee* list, Employee *auxEmployee, int len, int id);
int printForId  (Employee *list, int len, int id);
int arrayToBuffer(Employee *list,Employee *listBuffer, int len, int id);
void printForId2  (Employee* auxEmployee);
int deleteEmployee (Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
float sumaTotal(Employee* list, int len);
float promedio(Employee* list, int len);
int cantidadSuperiorAlPronedio(Employee* list, int len);
int flagLimite(Employee* list, int len);




#endif /* ARRAYEMPLOYEE_H_ */

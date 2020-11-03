#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define NOMBRE_LEN 128
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

void employee_headerArray(void);

Employee* employee_new(void);
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newParametros(int id, char* nombre,int horasTrabajadasStr, int sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_setIdTexto(Employee* this,char* id);
int employee_getId(Employee* this,int* id);
int employee_getIdTexto(Employee* this,char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTexto(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getHorasTrabajadasTexto(Employee* this,char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTexto(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getSueldoTexto(Employee* this,char* sueldo);

int employee_imprimir(Employee* this);
int employee_ordenarNombre(void* EmpUno, void* EmpDos);
int employee_ordenarID(void* auxUno, void* auxDos);





#endif // employee_H_INCLUDED

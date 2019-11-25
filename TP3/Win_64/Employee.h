#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int verificarID(LinkedList* pArrayListEmployee,int id);
void mostraEmpleado(Employee* pEmployee);
int compararID(void* pElement,void* pElement2);
int compararNombre(void* pElement,void* pElement2);
int compararHorasTrabajadas(void* pElement,void* pElement2);
int compararSueldo(void* pElement,void* pElement2);

#endif // employee_H_INCLUDED

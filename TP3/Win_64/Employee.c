#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* e;
    e=(Employee*) malloc(sizeof(Employee));
    return e;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxEmployee=employee_new();
    if(auxEmployee!=NULL)
    {
        if(!employee_setId(auxEmployee,atoi(idStr)))
        {
            printf("Fallo al cargar ID\n");
        }
        if(!employee_setNombre(auxEmployee,nombreStr))
        {
            printf("Fallo al cargar Nombre\n");
        }
        if(!employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr)))
        {
            printf("Fallo al cargar horas trabajadas\n");
        }
        if(!employee_setSueldo(auxEmployee,atoi(sueldoStr)))
        {
            printf("Fallo al cargar sueldo\n");
        }

    }
    return auxEmployee;
}

int employee_setId(Employee* this,int id)
{
    int flag=0;
    if(this!=NULL)
    {
        this->id=id;
        flag=1;
    }
    return flag;
}

int employee_getId(Employee* this,int* id)
{
    int flag=0;
    if(this!=NULL)
    {
        id=&this->id;
        flag=1;
    }
    return flag;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int flag=0;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        flag=1;
    }
    return flag;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int flag=0;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        flag=1;
    }
    return flag;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int flag=0;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        flag=1;
    }
    return flag;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int flag=0;
    if(this!=NULL)
    {
        horasTrabajadas=&this->horasTrabajadas;
        flag=1;
    }
    return flag;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int flag=0;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        flag=1;
    }
    return flag;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int flag=0;
    if(this!=NULL)
    {
        sueldo=&this->sueldo;
        flag=1;
    }
    return flag;
}

void mostraEmpleado(Employee* pEmployee)
{
    printf("|%5d| |%15s| |%9d| |%9d|\n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
}

int verificarID(LinkedList* pArrayListEmployee,int id)
{
    int flag=-1;
    int i;
    Employee* auxNode=(Employee*) malloc(sizeof(Employee));
    if(pArrayListEmployee!=NULL && id>=0)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxNode=ll_get(pArrayListEmployee,i);

            if(auxNode->id==id)
            {
                flag=i;
                break;
            }
        }
    }
    return flag;
}

int compararID(void* pElement,void* pElement2)
{
    int flag=0;
    Employee* emp1=(Employee*)pElement;
    Employee* emp2=(Employee*)pElement2;
    if(emp1->id > emp2->id)
    {
        flag=1;
    }else
    {
        if(emp1->id < emp2->id)
        {
            flag=-1;
        }
    }
    return flag;
}


int compararNombre(void* pElement,void* pElement2)
{
    Employee* emp1=(Employee*)pElement;
    Employee* emp2=(Employee*)pElement2;
    return strcmp(emp1->nombre,emp2->nombre);
}

int compararHorasTrabajadas(void* pElement,void* pElement2)
{
    int flag=0;
    Employee* emp1=(Employee*)pElement;
    Employee* emp2=(Employee*)pElement2;
    if(emp1->horasTrabajadas > emp2->horasTrabajadas)
    {
        flag=1;
    }else
    {
        if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            flag=-1;
        }
    }
    return flag;
}


int compararSueldo(void* pElement,void* pElement2)
{
    int flag=0;
    Employee* emp1=(Employee*)pElement;
    Employee* emp2=(Employee*)pElement2;
    if(emp1->sueldo > emp2->sueldo)
    {
        flag=1;
    }else
    {
        if(emp1->sueldo < emp2->sueldo)
        {
            flag=-1;
        }
    }
    return flag;
}



#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "input.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int flag=0;
    FILE* fileTexto= fopen(path,"r");
    if(fileTexto!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromText(fileTexto,pArrayListEmployee)==1)
        {
            flag=1;
        }
    }
    fclose(fileTexto);
    return flag;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int flag=0;
    FILE* fileBinario=fopen(path,"rb");
    if(fileBinario!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromBinary(fileBinario,pArrayListEmployee))
        {
            flag=1;
        }
    }
    fclose(fileBinario);
    return flag;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int flag=0;
    Employee* auxEmployee=employee_new();
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        employee_setId(auxEmployee,generateID(pArrayListEmployee));
        verificarTexto(auxNombre,"Ingrese el nombre: ",1,128);
        if(!employee_setNombre(auxEmployee,auxNombre))
        {
            printf("Error al cargar el nombre\n");
        }
        verificarNumerico(&auxHorasTrabajadas,"Ingrese las horas trabajadas: ",1,100);
        if(!employee_setHorasTrabajadas(auxEmployee,auxHorasTrabajadas))
        {
            printf("Error al cargar las horas\n");
        }
        verificarNumerico(&auxSueldo,"Ingrese un sueldo: ",1,1000000);
        if(!employee_setSueldo(auxEmployee,auxSueldo))
        {
            printf("Error al cargar el sueldo\n");
        }
        ll_add(pArrayListEmployee,auxEmployee);
        flag=1;

    }
    return flag;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int flag=0;
    int id;
    int opcion;
    Employee* auxEmploye=(Employee*)malloc(sizeof(Employee));
    verificarNumerico(&id,"Ingrese un id :",0,ll_len(pArrayListEmployee));
    id=verificarID(pArrayListEmployee,id);
    if(id!=-1)
    {
        system("cls");
        auxEmploye=ll_get(pArrayListEmployee,id);
        printf("| ID  | |     Nombre    | |  Horas  | |  Sueldo |\n");
        mostraEmpleado(auxEmploye);
        do
        {
            printf("1- Modificar el nombre\n");
            printf("2- Modificar las horas Trabajadas\n");
            printf("3- Modificar el Sueldo\n");
            printf("4- Salir\n");
            verificarNumerico(&opcion,"Ingrese una opcion: ",1,4);
            switch(opcion)
            {
            case 1:
                system("cls");
                mostraEmpleado(auxEmploye);
                verificarTexto(auxEmploye->nombre,"Ingrese el Nombre: ",1,128);
                mostraEmpleado(auxEmploye);
                flag=1;
                break;
            case 2:
                system("cls");
                mostraEmpleado(auxEmploye);
                verificarNumerico(&auxEmploye->horasTrabajadas,"Ingrese las horas: ",1,90000);
                mostraEmpleado(auxEmploye);
                flag=1;
                break;
            case 3:
                system("cls");
                mostraEmpleado(auxEmploye);
                verificarNumerico(&auxEmploye->sueldo,"Ingrese el sueldo: ",1,90000);
                mostraEmpleado(auxEmploye);
                flag=1;
                break;
            }
        }while(opcion!=4);

    }else{
    printf("FALLO AL BUSCAR\n");
    }


    return flag;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     int flag=0;
    int id;
    verificarNumerico(&id,"Ingrese un id :",0,ll_len(pArrayListEmployee));
    id=verificarID(pArrayListEmployee,id);
    if(id!=-1)
    {
        ll_remove(pArrayListEmployee,id);
        flag=1;
    }else
    {
        printf("Fallo al buscar\n");
    }
    return flag;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int flag=0;
    Employee* auxEmploye=employee_new();
    if(pArrayListEmployee!=NULL)
    {
        printf("| ID  | |     Nombre    | |  Horas  | |  Sueldo |\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmploye=(Employee*)ll_get(pArrayListEmployee,i);
            mostraEmpleado(auxEmploye);
        }
        flag=1;
    }
    return flag;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int flag=0;
    int opcion;
    int order;
    do
    {
        printf("+++ORDENAR+++\n\n");
        printf("1 -Por ID\n");
        printf("2- Por Nombre\n");
        printf("3- Por Horas trabajadas\n");
        printf("4- Por Sueldo\n");
        printf("5- Salir\n");
        verificarNumerico(&opcion,"Ingrese una opcion: ",1,5);
        switch(opcion)
        {
        case 1:
            verificarNumerico(&order,"1-Ascendente\n0-Desendente\ningrese el orden: ",0,1);
            ll_sort(pArrayListEmployee,compararID,order);
            printf("Ordenado Correctamente\n");
            break;
        case 2:
            verificarNumerico(&order,"1-Ascendente\n0-Desendente\ningrese el orden: ",0,1);
            ll_sort(pArrayListEmployee,compararNombre,order);
            printf("Ordenado Correctamente\n");
            break;
        case 3:
            verificarNumerico(&order,"1-Ascendente\n0-Desendente\ningrese el orden: ",0,1);
            ll_sort(pArrayListEmployee,compararHorasTrabajadas,order);
            printf("Ordenado Correctamente\n");
            break;
        case 4:
            verificarNumerico(&order,"1-Ascendente\n0-Desendente\ningrese el orden: ",0,1);
            ll_sort(pArrayListEmployee,compararSueldo,order);
            printf("Ordenado Correctamente\n");
            break;
        case 5:
            printf("Hasta Luego\n");
            break;
        }
    }while(opcion!=5);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int flag=0;
    int i;
    FILE* file=NULL;
    Employee* auxEmployee=(Employee*)malloc(sizeof(Employee));
    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        file=fopen(path,"w");
        if(file!=NULL)
        {
            fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                auxEmployee=ll_get(pArrayListEmployee,i);
                fprintf(file,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
            }
        }else
        {
            return flag;
        }
        fclose(file);
        flag=1;

    }
    return flag;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int flag=0;
    int i=0;
    int tam=ll_len(pArrayListEmployee);
    FILE* fileB=NULL;
    if(pArrayListEmployee!=NULL && tam>0 && path!=NULL)
    {
        fileB=fopen(path,"wb");
        if(fileB==NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return flag;
        }
        for(i=0;i<tam;i++)
        {
            fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,fileB);
        }
        fclose(fileB);
        flag=1;
    }
    return flag;
}

int generateID(LinkedList* pArrayListEmployee)
{
    int id=0;
    int i=0;
    if(pArrayListEmployee!=NULL)
    {
        Employee* auxEmployee=employee_new();
        if(auxEmployee!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
                if(id<auxEmployee->id)
                {
                    id=auxEmployee->id;
                }
            }
        }
    }
    return id+1;
}

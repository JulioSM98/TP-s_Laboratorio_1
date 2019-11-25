#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int flag=0;
    char buffer[4][128];
    int cant=0;


    if(pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant<4)
            {
                break;
            }else
            {
                Employee* auxemployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,auxemployee);
            }
        }
        flag=1;
    }

    return flag;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int flag=0;
    int cant=0;
    if(pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            Employee* auxEmployee=employee_new();
            if(auxEmployee==NULL)
            {
                return flag;
                break;
            }
            cant=fread(auxEmployee,sizeof(Employee),1,pFile);
            if(cant<1)
            {
                break;
            }else
            {
                ll_add(pArrayListEmployee,auxEmployee);
            }
        }
        flag=1;
    }
    return flag;
}



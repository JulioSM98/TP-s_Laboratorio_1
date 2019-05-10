#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "utn.h"
#include "ArrayEmployess.h"

int main()
{
    eEmployee Employees[CANT];

    char auxName[51],auxLastName[51];
    float auxSalary,promedio;
    int auxSector,option=0,buscador,cont=0;

    initEmployees(Employees,CANT);




    while(option!=5){
            system("cls");
        printf("\nMENU\n");
        printf("1-ALTA\n");
        if(cont!=0){
            printf("2-MODIFICAR\n3-BAJA\n4-INFORMAR\n");
        }
        printf("5-SALIR\n");
        option=getValidInt("Ingrese una opcion: ","Ingrese solo numeros",1,5);
        switch(option){
        case 1:
            getValidString("Ingrese el Nombre: ","El nombre debe estar compuesto por letras\n",auxName);
            getValidString("Ingrese el Apellido: ","El Apellido debe estar compuesto por letras\n",auxLastName);
            auxSalary=getFloat("Ingrese el salario: ");
            auxSector=getValidInt("Ingrese el sector: ","El sector debe ser numerico\n",1,10);
            if(addEmployyes(Employees,CANT,auxName,auxLastName,auxSalary,auxSector)==0){
               printf("Empleado Agragado con exito!!\n");
               cont=cont+1;
               system("pause");
               break;
            }


            break;
        case 2:
            if(cont==0){
                printf("Opcion invalida!\n");
                system("pause");
                break;
            }
            buscador=findEmployeeById(Employees,CANT,getValidInt("Ingrese un ID: ","Ingrese solo numero",0,cont));
            if(buscador==-1){
                printf("ID Invalido\n");
                system("pause");
            }else{
                getValidString("\nIngrese Un Nombre: ","El nombre solo debe contener letras",auxName);
                getValidString("\nIngrese Un Apellido: ","El apellido solo debe contener Letras",auxLastName);
                Employees[buscador].salary=getFloat("\nIngrese Salario: ");
                Employees[buscador].sector=getValidInt("\nIngrese el Sector: ","El sector solo debe contener numero",1,10);
                strcpy(Employees[buscador].name,auxName);
                strcpy(Employees[buscador].lastName,auxLastName);
            }
            break;
        case 3:
            if(cont==0){
                printf("Opcion inavalida!\n");
                system("pause");
                break;
            }
            buscador=removeEmployee(Employees,CANT,getInt("Ingrese el ID: "));
            if(buscador==-1){
                printf("\nEl ID no Existe\n");
                system("pause");
                break;
            }
            cont=cont-1;
            break;
        case 4:
            if(cont==0){
                printf("Opcion invalida!\n");
                system("pause");
                break;
            }
            sortEmployees(Employees,CANT,1);
            printEmployees(Employees,CANT);
            printf("\nEl salario total es: %.1f\n",totalSalario(Employees,CANT));
            promedio=cont;
            promedio=totalSalario(Employees,CANT)/promedio;
            printf("El promedio de los salarios es de: %.2f\n",promedio);
            system("pause");
            break;
        }

    }
    return 0;
}


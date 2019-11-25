#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu(int verificador);

int main()
{
    int option = 0;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        option=menu(flag);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados) && flag==0)
                {
                    flag=1;
                    printf("Cargados correctamente!!\n");
                }else
                {
                    if(flag==1)
                    {
                       char auxOpcion;
                       printf("Se borrara la lista anterior\n");
                       do
                       {

                           auxOpcion=getChar("Esta seguro?(S/N): ");
                       }while(auxOpcion!='n' && auxOpcion!='N' && auxOpcion!='s' && auxOpcion!='S');
                        if(auxOpcion=='s'||auxOpcion=='S')
                        {
                            ll_deleteLinkedList(listaEmpleados);
                            listaEmpleados=ll_newLinkedList();
                            controller_loadFromText("data.csv",listaEmpleados);
                        }else
                        {
                            printf("Carga Cancelada\n");
                        }
                    }
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados)==1 && flag==0)
                {
                    flag=1;
                    printf("Cargados correctamente!!\n");
                }else
                {
                    if(flag==1)
                    {
                       char auxOpcion;
                       printf("Se borrara la lista anterior\n");
                       do
                       {

                           auxOpcion=getChar("Esta seguro?(S/N): ");
                       }while(auxOpcion!='n' && auxOpcion!='N' && auxOpcion!='s' && auxOpcion!='S');
                        if(auxOpcion=='s'||auxOpcion=='S')
                        {
                            ll_deleteLinkedList(listaEmpleados);
                            listaEmpleados=ll_newLinkedList();
                            controller_loadFromBinary("data.csv",listaEmpleados);
                        }else
                        {
                            printf("Carga Cancelada\n");
                        }
                    }
                }
                break;
            case 3:
                if(flag!=0)
                {
                    if(controller_addEmployee(listaEmpleados))
                    {
                    printf("Cargado con exito\n");
                    }else
                    {
                        printf("Error al cargar\n");
                    }
                }else
                {
                    printf("Error, Carge un archivo antes\n");
                }

                break;
            case 4:
                if(flag!=0)
                {
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("Modificacion con exito\n");
                    }else
                    {
                        printf("Error al modificar\n");
                    }
                }
                break;
            case 5:
                if(flag!=0)
                {
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Eliminado con exito\n");
                    }else
                    {
                        printf("Error al eliminar\n");
                    }
                }
                break;
            case 6:
                if(flag==0)
                {
                    printf("Error, Carge un archivo antes\n");
                }else
                {
                    if(!controller_ListEmployee(listaEmpleados))
                    {
                        printf("Error al listar\n");
                    }
                }
                break;
            case 7:
                if(flag==0)
                {
                    printf("Error, Carge un archivo antes\n");
                }else
                {
                    if(!controller_sortEmployee(listaEmpleados))
                    {
                        printf("Error al listar\n");
                    }
                }
                break;
            case 8:
                if(flag==0)
                {
                    printf("Error, Carge un archivo antes\n");
                }else
                {
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("error al guardar\n");
                    }else
                    {
                        printf("Guardado con exito en texto\n");
                    }
                }
                break;
            case 9:
                if(flag==0)
                {
                    printf("Error, Carge un archivo antes\n");
                }else
                {
                    if(controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("guardada con exito en binario\n");
                    }else
                    {
                        printf("error al guardar\n");
                    }

                }
                break;
            case 10:
                printf("Hasta pronto\n");
                break;
            default:
                printf("error\n");
        }
        system("pause");
    }while(option!=10);
    return 0;
}

int menu(int verificador)
{
    int option;
    printf("------------------MENU----------------------\n");
    printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    if(verificador!=0)
    {
        printf("3- Alta de empleado.\n");
        printf("4- Modificar datos de empleado.\n");
        printf("5- Baja de empleado.\n");
        printf("6- Listar empleados.\n");
        printf("7- Ordenar empleados.\n");
        printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9- Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    }
    printf("10- Salir.\n");
    verificarNumerico(&option,"Ingrese una opcion: ",1,10);
    return option;
}

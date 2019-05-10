#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployess.h"

#define TRUE 1
#define FALSE 0

int cont=0;

/** \brief Para indicar que todas las posiciones en la matriz esten vacías, esta función coloca el indicador (isEmpty) en TRUE en todas las posiciones de la matriz
 *
 * \param list eEmployee* Puntero a la matriz de empleados
 * \param length int tamaño de la matriz
 * \return int Return (-1) si es error [tamaño de matriz invalido o puntero nulo] - (0)si esta bien
 *
 */
int initEmployees(eEmployee* list,int length){
    int i;
    if(list==NULL|| length<=0){
        return -1;
    }else{
        for(i=0;i<length;i++){
            list[i].isEmpty=TRUE;
            }
        return 0;
        }
}


/** \brief Agregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
 *
 * \param list eEmployee*
 * \param length int
 * \param name[] char
 * \param lastname[] char
 * \param salary float
 * \param sector int
 * \return
 *
 */
int addEmployyes(eEmployee* list, int length, char name[],char lastName[],float salary,int sector){
    int i;
    char auxName[51],auxLastName[51];
    strcpy(auxName,name);
    strcpy(auxLastName,lastName);
    for(i=0;i<strlen(name);i++){
        auxName[i]=name[i];
        if(i==0){
            auxName[i]=toupper(name[i]);
        }
    }
    for(i=0;i<strlen(lastName);i++){
        auxLastName[i]=lastName[i];
        if(i==0){
            auxLastName[i]=toupper(lastName[i]);
        }
    }

    if(list!=NULL || length>0){
                list[cont].isEmpty=FALSE;
                list[cont].id=cont;
                strcpy(list[cont].name,auxName);
                strcpy(list[cont].lastName,auxLastName);
                list[cont].salary=salary;
                list[cont].sector=sector;
                cont=cont+1;
                return 0;
    }
    return -1;
}

/** \brief Buscar un Employee por el ID y retornar su posicion en el array
 *
 * \param list Employee*
 * \param length int
 * \param id int
 * \return devuelve la posicion del empleado o (-1) si [ el tamnano del array es invalido o el valor del puntero de empleados es nulo o si el empleado no se encuentra]
 *
 */
int findEmployeeById(eEmployee* list, int length,int id){
        int i;
        if(list!=NULL && length>0){
            for(i=0; i<length;i++){
                if(list[i].isEmpty!=TRUE && list[i].id==id){
                    return i;
                    break;
                }
            }
        }
        return -1;
}

/** \brief remueve un empleado por el ID (pone isEmpty en 1)
 *
 * \param list Employee*
 * \param length int
 * \param id int
 * \return devuelve un entero (-1) si falla [El tamnano del array es invalido o el valor del puntero de empleados es nulo o si el empleado no se encuentra] - (0) si esta bien
 *
 */
int removeEmployee(eEmployee* list, int len,int id){
    int i;
    if(list!=NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty!=TRUE && list[i].id==id){
                list[i].isEmpty=TRUE;
                cont=cont-1;
                return 0;
                break;
            }
        }
    }
    return -1;
}


/** \brief ordena los elementos in el array de empleados, el argumento del orden indica si es ascendente o descendente
 *
 * \param list Employee*
 * \param lenght int
 * \param order int [1] indica ascendente - [0]Indica descendente
 * \return retorna un entero (-1) if algo fallo y (0) si esta bien
 *
 */
int sortEmployees(eEmployee* list,int len, int order){
    int i,j,auxId,auxSector;
    float auxSalary;
    char auxName[51],auxLastName[51];
    if(list!=NULL && len>0){
        for(i=0;i<len-1;i++){
                if(list[i].isEmpty==TRUE){
                    continue;
                }
            for(j=i+1;j<len;j++){
                if(list[j].isEmpty==TRUE){
                    continue;
                }
                if(order==1 && strcmp(list[i].lastName,list[j].lastName)<0){
                        auxId=list[i].id;
                        list[i].id=list[j].id;
                        list[j].id=auxId;

                        strcpy(auxName,list[i].name);
                        strcpy(list[i].name,list[j].name);
                        strcpy(list[j].name,auxName);

                        strcpy(auxLastName,list[i].lastName);
                        strcpy(list[i].lastName,list[j].lastName);
                        strcpy(list[j].lastName,auxLastName);

                        auxSalary=list[i].salary;
                        list[i].salary=list[j].salary;
                        list[j].salary=auxSalary;

                        auxSector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=auxSector;
                }else if(order==1 && strcmp(list[i].lastName,list[j].lastName)==0){
                    if(list[i].sector<list[j].sector){
                        auxId=list[i].id;
                        list[i].id=list[j].id;
                        list[j].id=auxId;

                        strcpy(auxName,list[i].name);
                        strcpy(list[i].name,list[j].name);
                        strcpy(list[j].name,auxName);

                        strcpy(auxLastName,list[i].lastName);
                        strcpy(list[i].lastName,list[j].lastName);
                        strcpy(list[j].lastName,auxLastName);

                        auxSalary=list[i].salary;
                        list[i].salary=list[j].salary;
                        list[j].salary=auxSalary;

                        auxSector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=auxSector;
                    }
                }
                if(order==0 && strcmp(list[i].lastName,list[j].lastName)>0){
                        auxId=list[i].id;
                        list[i].id=list[j].id;
                        list[j].id=auxId;

                        strcpy(auxName,list[i].name);
                        strcpy(list[i].name,list[j].name);
                        strcpy(list[j].name,auxName);

                        strcpy(auxLastName,list[i].lastName);
                        strcpy(list[i].lastName,list[j].lastName);
                        strcpy(list[j].lastName,auxLastName);

                        auxSalary=list[i].salary;
                        list[i].salary=list[j].salary;
                        list[j].salary=auxSalary;

                        auxSector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=auxSector;
                }else if(order==0 && strcmp(list[i].lastName,list[j].lastName)==0){
                    if(list[i].sector>list[j].sector){
                        auxId=list[i].id;
                        list[i].id=list[j].id;
                        list[j].id=auxId;

                        strcpy(auxName,list[i].name);
                        strcpy(list[i].name,list[j].name);
                        strcpy(list[j].name,auxName);

                        strcpy(auxLastName,list[i].lastName);
                        strcpy(list[i].lastName,list[j].lastName);
                        strcpy(list[j].lastName,auxLastName);

                        auxSalary=list[i].salary;
                        list[i].salary=list[j].salary;
                        list[j].salary=auxSalary;

                        auxSector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=auxSector;
                    }
                }
            }
        }
    }
    return 0;
}

/** \brief imprime el contenido del array empleados
 *
 * \param list eEmployee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee* list, int length){
    int i;
    printf("\n   ID   |     Name     |    LastName    |  Salary  |  Sector");
    for(i=0;i<length;i++){
        if(!list[i].isEmpty){
            printf("\n %6i - %12s - %14s - %7.1f$ - %6d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}

/** \brief Calcula la suma total de los salarios
 *
 * \param list eEmployee*
 * \param lenght int
 * \return un flotante
 *
 */
float totalSalario(eEmployee* list,int length){
    int i;
    float total;
    for(i=0;i<length;i++){
            if(list[i].isEmpty==0){
                total=total+list[i].salary;
            }
    }
    return total;
}



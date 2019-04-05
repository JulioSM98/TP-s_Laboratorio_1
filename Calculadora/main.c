#include <stdio.h>
#include <stdlib.h>
//Biblioteca de Funciones
#include "operaciones.h"


int main()
{
    int x,y;
    int opcion=0;
    //Pide al usuario el  1 operando
    printf("Ingrese el 1er Operando (A=x): ");
    scanf("%d",&x);
    system("cls");
    //Pide al usuario el segundo operando
    printf("ingrese el 2do Operando (B=y): ");
    scanf("%d",&y);
    system("cls");
    //Bucle donde el usuario puede modificar los operandos, calcularlos y salir
   while(opcion!=4){
        printf("Por favor, elija una opción\n 1-Modificar 1er operando (A=%d)\n 2-Modificar 2do operando (B=%d)\n 3-Calcular las operaciones e informar resultados\n 4-salir\nSeleccionar: ",x,y);
        scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1:
                // El usuario modifica el 1 operando
                printf("Ingrese el 1er operando: ");
                scanf("%d",&x);
                system("cls");
                break;
            case 2:
                // El usuario modifica el 2 operando
                printf("Ingrese el 2do operando: ");
                scanf("%d",&y);
                system("cls");
                break;
            case 3:
                // El programa muestra por pantalla los resultados de sus respectivas operaciones
                Suma(x,y);
                Resta(x,y);
                Division(x,y);
                Multiplicacion(x,y);
                Factorial(x,y);
                printf("________________________________\n\n");
                break;
            case 4:
                //El usuario decide salir
                printf("Hasta luego...");
                break;
            default:
                // Mensaje en caso de que la opcion no exista
                printf("Esa opcion no existe\n");
                break;

        }


    }
}

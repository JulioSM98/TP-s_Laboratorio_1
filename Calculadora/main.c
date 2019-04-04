#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int main()
{
    int x,y;
    int opcion=0;
    printf("Ingrese el 1er Operando (A=x): ");
    scanf("%d",&x);
    system("cls");
    printf("ingrese el 2do Operando (B=y): ");
    scanf("%d",&y);
    system("cls");
   while(opcion!=4){
        printf("Por favor, elija una opción\n 1-Modificar 1er operando (A=%d)\n 2-Modificar 2do operando (B=%d)\n 3-Calcular las operaciones e informar resultados\n 4-salir\nSeleccionar: ",x,y);
        scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1:
                printf("Ingrese el 1er operando: ");
                scanf("%d",&x);
                system("cls");
                break;
            case 2:
                printf("Ingrese el 2do operando: ");
                scanf("%d",&y);
                system("cls");
                break;
            case 3:
                Suma(x,y);
                Resta(x,y);
                Division(x,y);
                Multiplicacion(x,y);
                Factorial(x,y);
                printf("________________________________\n\n");
                break;
            case 4:
                printf("Hasta luego...");
                break;
            default:
                printf("Esa opcion no existe\n");
                break;

        }


    }
}

#include <stdio.h>
#include <stdlib.h>

// Funcion Suma
int Suma(int a,int b){
    int total;
    total=a+b;
    return printf("El resultado de %d+%d: %d\n",a,b,total);
}
// Funcion Resta
int Resta(int a, int b){
    int total;
    total=a-b;
    return printf("El resultado de %d-%d es: %d\n",a,b,total);
}
//Funcion Multiplicacion
int Multiplicacion(int a, int b){
    int total;
    total=a+b;
    return printf("El resultado de %d*%d es: %d\n",a,b,total);
}
//Funcion Division
int Division(int a, int b){
    float total;
    float x=a, y=b;
    if(b==0){
        return printf("No es posible dividir por cero");
    }
    total=x/y;
    return printf("El resultado de %d/%d es :%.2f \n",a,b,total);
}
//funcion Factorial
int Factorial(int a, int b){
    int totalA=1;
    int totalB=1;
    int i;
    //Sacar factorial de A
    for(i=a;i>1;i--){
        totalA=totalA*i;
    }
    //Sacar factorial de B
    for(i=b;i>1;i--){
        totalB=totalB*i;
    }
    return printf("el Factorial de %d es :%d \nEl factorial de %d es: %d\n",a,totalA,b,totalB);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "input.h"

/**
 * \brief Solicita un numero al usuario y lo devuelve
 * \param mensaje, es el mensaje q mostrar como instruccion al usuario
 * \return El numero ingresado por el usuario
 * Devuelve un entero
 */
int getIn ( char mensaje[]) {
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
    }
/**
 * \brief Solicita un numero al usuario y lo devuelve
 * \param mensaje, es el mensaje q mostrar como instruccion al usuario
 * \return El numero ingresado por el usuario
 * devuelve un float
 */
float getFloat (char mensaje[]){
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}
/**
 * \brief Solicita un caracter al usuario y lo devuelve
 * \param mensaje, es el mensaje q mostrar como instruccion al usuario
 * \return El numero ingresado por el usuario
 * devuelve un char
 */
char getChar(char mensaje[]){
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
/** \brief Verifica si el valor es numerico;
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es numerico, 0 si no lo es.
 *
 */

int esNumerico (char str []){
    int i=0;
    while (str[i]!='\0'){
        if(str[i]<'0' || str[i]>'9'){
        return 0;
        }
        i++;
    }
    return 1;
}

/** \brief Es flotante
 *
 * \param Str recibe un array con la cadena que va analizar
 * \return 1 si es flotante, 0 si no lo es.
 *
 */
int esFlotante (char str []){
    int i=0;
    int flag=0;
    while (str[i]!='\0'){
            if(str[i]=='.'){
                flag++;
            }
        if((str[i]<'0' || str[i]>'9') && flag<1){
        printf("Ingrese Solo Numeros\n");
        return 0;
        }
        i++;
    }
    return 1;
}



/** \brief Verifica si el valor es Letras
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es letras, 0 si no lo es.
 *
 */

int esLetras (char str[]){
int i=0;
    while (str[i]!='\0'){
        if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        i++;
    }
    return 1;
}
/** \brief Verifica si es alfa numerico
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es alfa numerico, 0 si no lo es.
 *
 */

int esAlfaNumerico (char str[]) {
    int i=0;
    while (str[i]!='\0'){
        if((str[i]<'0' || str[i]>'9')&& (str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        i++;
    }
    return 1;
}
/** \brief Verifica si es un conjunto numerico telefonico
 *
 * \param str Recibe un array con la cadena q va a analizar.
 * \return 1 si es correcto, 0 si no lo es.
 * Permite un solo guion
 */
int esTelefono (char str[]){
    int i=0;
    int contGuion=0;
    while (str[i]!='\0'){
        if((str[i]<'0' || str[i]>'9')&& (str[i]!=' ') && (str[i]!='-')) // Chequea por la negativa para return 0
            {
        return 0;
        }
        if (str[i]=='-'){
            contGuion++;
        }
        i++;
    }
    if (contGuion==1)
        return 1;

    return 0;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    printf("Ingrese solo letras\n");
    return 0;
}
/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }

    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    printf("Ingrese Solo Numeros\n");
    return 0;
}

/** \brief chequea el largo del array.
 *
 * \param str es el array
 * \param i, recibe el largo q debe tener.
 * \return  1 si esta ok, 0 i esta excedido.
 *
 */

int checkLenght(char str[], int tamMax , int tamMin){
 if(strlen(str)<=tamMax && strlen(str)>=tamMin)
    {
    return 0;
    }
return 1;
}

int limitadorInt(float valor, int lowLimit, int highLimit){
if( valor < lowLimit || valor > highLimit )
    {
        printf("Error. No respeta los limites (limites: %d - %d)\n",lowLimit,highLimit);
        return 0;
    }
return 1;
}






//---------------------------------------------------------------------

/** \brief Verifica si es un numero y limita
 *
 * \param el int donde va a cargar si todo es correcto (&variable)
 * \param Char Mensaje: El mensaje que va a mostrar para cargar el numero
 * \param int valMin valor minimo
 * \param int valMax valor maximo
 *
 */

void verificarNumerico(int *input,char mensaje[],int valMin,int valMax)
{
    char auxNumero[256];
    float auxFloat;
    int flag=-1;

    do
    {
        if(getStringNumeros(mensaje,auxNumero)==0)
        {
        }else
        {
            auxFloat=atof(auxNumero);
            if(limitadorInt(auxFloat,valMin,valMax)==1)
            {
                *input=atoi(auxNumero);
                flag=1;
            }
        }
    }while(flag==-1);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void verificarFlotante(float *input,char mensaje[],int valMin,int valMax)
{
    char auxNumero[256];
    float auxFloat;
    int flag=-1;

    do
    {

        if(getStringNumerosFlotantes(mensaje,auxNumero)==0)
        {
        }else
        {
            auxFloat=atof(auxNumero);
            if(limitadorInt(auxFloat,valMin,valMax)==1)
            {
                *input=auxFloat;
                flag=1;
            }
        }
    }while(flag==-1);
}

/** \brief Verificar el tama�o y la oracion
 *
 * \param
 * \param
 * \return
 *
 */

void verificarTexto(char *input,char mensaje[],int tamMin,int tamMax)
{
    char auxTexto[256];
    int flag=-1;

    do
    {
        if(getStringLetras(mensaje,auxTexto)==0)
        {
        }else
        {
            if(checkLenght(auxTexto,tamMax,tamMin)==1)
            {
                printf("Verifique la cantidad de los caracteres (%d - %d)\n",tamMin,tamMax);
            }else
            {
                capitalizacion(auxTexto,256);
                strcpy(input,auxTexto);
                flag=1;
            }
        }
    }while(flag==-1);
}

void verificarAltaNumerico(char *input,char mensaje[],int tamMin,int tamMax)
{
    char auxTexto[256];
    int flag=-1;

    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(auxTexto);
        if(esAlfaNumerico(auxTexto)==0)
        {
        }else
        {
            if(checkLenght(auxTexto,tamMax,tamMin)==1)
            {
                printf("Verifique la cantidad de los caracteres (%d - %d)\n",tamMin,tamMax);
            }else
            {
                strcpy(input,auxTexto);
                flag=1;
            }
        }
    }while(flag==-1);
}


void capitalizacion(char palabras[],int len)
{
    int i;
    for(i=0;i<len;i++){
        if(i==0)
        {
            palabras[i]=toupper(palabras[i]);
        }else
        {
            if(palabras[i]==' ')
            {
                palabras[i+1]=toupper(palabras[i+1]);
            }
        }
    }
}


void verificarFecha(int *dia,int *mes,int *anio)
{
    verificarNumerico(dia,"Ingrese Dia: ",1,31);
    verificarNumerico(mes,"Ingrese un mes: ",1,12);
    verificarNumerico(anio,"Ingrese un anio: ",1990,2020);
}



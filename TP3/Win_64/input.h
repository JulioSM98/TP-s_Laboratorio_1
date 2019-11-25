//Getin Mensaje y devuelve la entrada

int getIn (char mensaje[]);

float getFloat (char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico (char str []);
int esFlotante (char str []);
int esLetras (char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str []);

int checkLenght(char str[], int tamMax , int tamMin);
int limitadorInt(float valor, int lowLimit, int highLimit);



void verificarNumerico(int *input,char mensaje[],int valMin,int valMax);
void verificarFlotante(float *input,char mensaje[],int valMin,int valMax);
void verificarTexto(char *input,char mensaje[],int tamMin,int tamMax);
void verificarAltaNumerico(char *input,char mensaje[],int tamMin,int tamMax);

void capitalizacion(char palabras[],int len);
void verificarFecha(int *dia,int *mes,int *anio);






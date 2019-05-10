#ifndef ARRAYEMPLOYESS_H_INCLUDED
#define ARRAYEMPLOYESS_H_INCLUDED
#define CANT 1000
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

int initEmployees(eEmployee* pEmployee,int len);

int addEmployyes(eEmployee* list, int len, char name[],char lastName[],float salary,int sector);

int findEmployeeById(eEmployee* list, int len,int id);

int removeEmployee(eEmployee* list,int len,int id);

int sortEmployees(eEmployee* list,int len,int order);

int printEmployees(eEmployee* list, int length);

float totalSalario(eEmployee* list,int length);
#endif // ARRAYEMPLOYESS_H_INCLUDED

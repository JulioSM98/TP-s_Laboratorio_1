# ABM Empleados
Sistema para administrar su nómina de empleados

### Datos
* `Employee`
    * **int** id
    * **char** name[51]
    * **char** lastname[51]
    * **float** salary
    * **int** isEmpty
### Menu
* **1-ALTA**: permite ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.
* **2-MODIFICAR**: Se ingresará el Número de Id, permitiendo modificar: Nombre o Apellido o Salario o Sector.
* **3-BAJA**: Se ingresará el Número de Id y se eliminará el empleado del sistema.
* **4-INFORMAR**: 
    * 1-  Listado de los empleados ordenados alfabéticamente por Apellido y Sector
    * 2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio. 

`NOTA: No se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algún empleado.`

## Funciones
### ArrayEmployees
 funciones que permiten trabajar con los datos almacenados en la estructura Employee, la cual representa los datos de un empleado de la empresa.
 
 #### initEmployes
 Para indicar que todas las posiciones en la matriz esten vacías, esta función coloca el indicador (isEmpty) en TRUE en todas las posiciones de la matriz
 
 ```C
 int initEmployees(Employee* list, int len)
{
 return 0;
}
 ```
 **Ejemplo**
 
 ```C
 r = initEmployees(arrayEmployees, ELEMENTS);
 ```
 
 #### addEmployees
 Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.

```C
int addEmployee(Employee* list, int len, int id, char  name[],char lastName[],float salary,int sector)
{
 return -1;
}
```

**Ejemplo**

```C
r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);
```

#### findEmployeesById
Busca un empleado recibiendo como parámetro de búsqueda su Id.

```C
int findEmployeeById(Employee* list, int len,int id)
{
 return NULL
}
```

**Ejemplo**

```C
int index = findEmployeeById(arrayEmployees, ELEMENTS,9);
```
#### removeEmployee
Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id

```C
int removeEmployee(Employee* list, int len, int id)
{
 return -1;
}
```

**Ejemplo**

```C
r = removeEmployee(arrayEmployees, ELEMENTS,20);
```
#### sortEmployees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.

```C
int sortEmployees(Employee* list, int len, int order)
{
 return 0;
}
```

**Ejemplo**

```C
r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
```
#### printEmployees
Imprime el array de empleados de forma encolumnada.
```C
int printEmployees(Employee* list, int length)
{
 return 0;
}
```

**Ejemplo**

```C
r = printEmployees(arrayEmployees, ELEMENTS);
```
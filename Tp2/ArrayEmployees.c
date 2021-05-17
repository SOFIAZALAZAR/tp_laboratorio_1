#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"


int initEmployees(Employee* list, int len)
{
    int todoOk= -1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 0;
    }

    return todoOk;
}

int freeSpace(Employee* list, int len)
{
    int indice = -1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                indice = i;
                break;
            }
        }

    }
    return indice;
}

int menu()
{
    int opcion;
    printf("\t\t***Menu Empleados***\n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMES\n");
    printf("5. SALIR\n");
    utn_getNumero(&opcion,"Ingrese Opcion: ","Opcion invalida, ",1,5,10);
    printf("\n\n");
    return opcion;
}


int findEmployeeById(Employee* list, int len,int id)
{
    int index = -1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                index = i;
            }

        }
    }
    return index;
}



int removeEmployee(Employee* list, int len, int id)
{
    int todoOk = -1;
    int i;
    if(list!=NULL && len>0)
    {
        i = findEmployeeById(list,len,id);
         if(i!=-1)
            {
                list[i].isEmpty = 1;
                todoOk = 0;
            }

    }

    return todoOk;
}

int sortEmployees(Employee* list, int len, int order)
{
    int todoOk = -1;
    Employee auxEmpleado;
    if(list!=NULL && len>0)
    {
        switch(order)
        {
        case 1:
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if((list[i].sector > list[j].sector)||(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName)>0))
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
            }
            break;
        case 0:
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if((list[i].sector < list[j].sector)||(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName)<0))
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
            }

            break;
        }
        todoOk = 0;
    }
    return todoOk;
}
void printEmployee(Employee oneEmployee)
{
    printf(" %d     %10s     %10s        %.2f      %10d    \n"
           ,oneEmployee.id
           ,oneEmployee.name
           ,oneEmployee.lastName
           ,oneEmployee.salary
           ,oneEmployee.sector
          );

}
int printEmployees(Employee* list, int length)
{
    int todoOk = -1;
    int sinEmpleados = 1;
    if(list!=NULL && length > 0)
    {
        printf("\n                     |   Lista de empleados   |   \n\n");
        printf("  ID          Nombre          Apellido         Sueldo          Sector\n\n");
        for(int i=0; i < length; i++)
        {
            if(!list[i].isEmpty)
            {
               printEmployee(list[i]);
               sinEmpleados = 0;
            }

        }
        if(sinEmpleados)
          {
            printf("No hay empleados que mostrar.");
          }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}

int menuModificar()
{
    int opcion;
    printf("  Modificar del Empleado\n\n");
    printf("1 Nombre\n");
    printf("2 Apellido\n");
    printf("3 Sueldo\n");
    printf("4 Sector\n");
    printf("5 Salir\n");
    utn_getNumero(&opcion,"Ingrese Opcion: ","ERROR, ",1,5,10);
    printf("\n\n");
    return opcion;

}

int modificarEmpleado(Employee lista[], int tam)
{
    int todoOk = 0;
    int i;
    int id;
    char confirmacion = 'n';
    char salir = 'n';
    Employee auxEmpleado;
    system("cls");
    printEmployees(lista,tam);
    utn_getNumero(&id,"Ingrese el ID del empleado que quiere modificar: ","ERROR, ",1000,2000,10);
    if(lista!= NULL && tam > 0 )
    {
        system("cls");
        i = findEmployeeById(lista,tam, id);
        if(i == -1)
        {
            printf("No se encontro el empleado con el ID: %d\n", id);
        }
        else
        {
            auxEmpleado = lista[i];
            do
            {
                printf("\n\n");
                printEmployee(auxEmpleado);
                printf("\n\n");
                switch(menuModificar())
                {
                case 1:
                    utn_getTexto(auxEmpleado.name,50,"Ingrese nombre: ","Invalido ",10);
                    break;
                case 2:
                    utn_getTexto(auxEmpleado.lastName,50,"Ingrese apellido: ","Invalido ",10);
                    break;
                case 3:
                    utn_getNumeroFlotante(&auxEmpleado.salary,"Ingrese sueldo: ","Invalido ",0,10000000,10);

                    break;
                case 4:
                    utn_getNumero(&auxEmpleado.sector,"Ingrese sector: ","Invalido ",500,504,10);
                    break;
                case 5:
                    printf("Confirma salida?: ");
                    fflush(stdin);
                    salir = getchar();
                    break;
                }
            }while(salir == 'n');
            system("cls");
            printf("\n\n");
            printEmployee(lista[i]);
            printf("\nEmpleado modificado: \n\n");
            printEmployee(auxEmpleado);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            confirmacion = getchar();
            if(confirmacion == 's')
            {
                lista[i] = auxEmpleado;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int totalSueldos(Employee list[],int tam, float* tot)
{
    int todoOk= -1;
    float total = 0;
    if(list!=NULL && tam>0)
    {
        for(int i=0; i<tam ; i++)
        {
            if(!list[i].isEmpty)
            {
                total += list[i].salary;
            }
        }
      *tot = total;
      todoOk = 0;
    }
   return todoOk;
}

int salarioPromedio(Employee list[], int tam, float* prom)
{
    int todoOk = -1;
    int contador = 0;
    float total;
    float promedio;
    if(list!=NULL && tam>0)
    {
        for(int i=0; i<tam ; i++)
        {
            if(!list[i].isEmpty)
            {
                contador++;
            }
        }
        totalSueldos(list,tam,&total);
        if(contador!=0)
        {
            promedio = total/contador;
            *prom = promedio;
            todoOk = 0;
        }
    }
    return todoOk;
}

int mayorAlPromedio(Employee list[],int tam)
{
    int todoOk = -1;
    int contador = 0;
    float promedio;
    if(list!=NULL && tam>0)
    {
       if(salarioPromedio(list,tam,&promedio)==0)
        {
            for(int i=0; i<tam ; i++)
            {
            if(!list[i].isEmpty && (list[i].salary > promedio))
            {
                printEmployee(list[i]);
                contador++;
            }
            }
            todoOk = 0;
            printf("\nEmpleados que superan el salario promedio: %d\n",contador);
        }
    }
    return todoOk;
}

int menuInformes()
{
    int opcion;
    printf("        *********INFORMAR********\n\n");
    printf("1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("3. Salir\n");
    utn_getNumero(&opcion,"Ingrese Opcion: ","ERROR, ",1,3,10);
    printf("\n\n");
    return opcion;
}

int ordenarEmpleados(Employee list[], int tam)
{
    int todoOk = -1;
    int opcion;
    do
    {
        system("cls");
        printf("\n        Ordenar Empleados\n\n");
        printf("0 Odeanamiento descendente\n");
        printf("1 Ordenamiento ascendente\n");
        utn_getNumero(&opcion,"Ingrese Opcion: ","Error.",0,1,3);
        todoOk = sortEmployees(list,tam,opcion);
        printEmployees(list,tam);
    }
    while(todoOk == -1);
    return todoOk;

}
int altaEmpleado(Employee lista[],int tam, int* pId, eSector sec[], int tamSec)
{
    int ok = 0;
    int id;
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int i;
    system("cls");
    printf("\t\t***Alta Empleado***\n\n");
    printf("Legajo: %d\n", *pId);
    if(lista!= NULL && tam > 0 && pId !=NULL)
    {
        i = freeSpace(lista,tam);
        if(i == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        id = *pId;
            utn_getTexto(nombre,50,"Ingrese el nombre: ","Error solo letras ",10);
            utn_getTexto(apellido,50,"Ingrese el apellido: ","Erro solo letras ",10);
            utn_getNumeroFlotante(&salario,"Ingrese el salario: ","Dato invalido ", 0,900000,10);
            mostrarSectores(sec,tamSec);
            utn_getNumero(&sector,"Ingrese el ID del sector (500 a 504): ","Error ",500,504,10);
            addEmployee(lista,tam,id,nombre,apellido,salario,sector);

        (*pId)++;
         ok = 1;
        }
    }
    return ok;
}




int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk = -1;
    int i;
    if(list!=NULL && len>0 && freeSpace(list,len)!=-1)
    {
        i = freeSpace(list,len);
        if(i == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else{
         list[i].id = id;
         strcpy(list[i].name,name);
         strcpy(list[i].lastName,lastName);
         list[i].salary = salary;
         list[i].sector = sector;
         list[i].isEmpty = 0;
         todoOk = 0;
        }

    }


    return todoOk;
}
int mostrarSectores(eSector sec[],int tam)
{
    int todoOk = -1;
    if(sec!=NULL && tam>0)
    {
        printf("\n           |  Sectores  | \n");
        printf("\n   ID           Sector\n\n");
        for(int i=0; i<tam ; i++){
        printf("    %d       %10s\n"
           ,sec[i].id
           ,sec[i].descripcion
          );
        }
        todoOk = 0;
    }
    return todoOk;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,int* pId)
{
    int todoOk=0;
    char buffer[4][100];
    int cant;
    int aux;
    Employee* auxEmpleado = NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL && pId!=NULL)
    {
    todoOk = 1;
     fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
     while(!feof(pFile))
    {
      cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
      if(cant ==4)
      {
        auxEmpleado = employee_newParametros( buffer[0], buffer[1], buffer[2], buffer[3]);
        if(auxEmpleado!=NULL)
        {
          ll_add(pArrayListEmployee,auxEmpleado);
          aux = atoi(buffer[0]);
        }else{
            ll_deleteLinkedList(pArrayListEmployee);
            aux = *pId;
            todoOk = 0;
            break;
        }
      }
    }
    *pId = aux + 1;

    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,int* pId)
{
int todoOk=0;
    int cant;
    int aux;
    Employee* auxEmpleado = NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL && pId!=NULL)
    {
       ll_clear(pArrayListEmployee);
        while(!feof(pFile))
        {
            auxEmpleado = employee_new();
            cant = fread(auxEmpleado,sizeof(Employee),1,pFile);
            if(cant<1)
            {
                break;
            }
            ll_add(pArrayListEmployee, auxEmpleado);
            aux = auxEmpleado->id;
            todoOk = 1;
        }
        *pId = aux + 1;
      }

    return todoOk;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id =0;
        strcpy(nuevoEmpleado->nombre," ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;

    }
    return nuevoEmpleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char*strSueldo)
{

       Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado,atoi(idStr))&&
                employee_setNombre(nuevoEmpleado,nombreStr)&&
             employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))&&
                employee_setSueldo(nuevoEmpleado,atoi(strSueldo)))
          )
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }

    }

 return nuevoEmpleado;

}
void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
     int todoOk = 0;
    if(this!=NULL && id>0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getId(Employee* this,int* id)
{

 int todoOk =0;

    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        todoOk = 1;

    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
  int todoOk = 0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }

    return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{

   int todoOk=0;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
     int todoOk =0;

    if(this!=NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;

    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
 {int todoOk = 0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
 }
int employee_getSueldo(Employee* this,int* sueldo)
{
     int todoOk =0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;

    }
    return todoOk;

}

int mostrarEmpleado(Employee* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    if(this!=NULL
            &&  employee_getId(this,&id)
            && employee_getNombre(this,nombre)
            && employee_getHorasTrabajadas(this, &horas)
            && employee_getSueldo(this,&sueldo)
      )
    {
        printf("%d  %10s  %d   %d \n"
               ,this->id
               ,this->nombre
               ,this->horasTrabajadas
               ,this->sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int compareId(Employee* this,Employee* this2)
{
    int ret = 0;
    if(this!=NULL && this2!=NULL)
    {
        if(this->id>this2->id)
        {
            ret= 1;
        }
        if(this->id<this2->id)
        {
            ret= -1;
        }
    }
return ret;
}


int employee_CmpId(void* a,void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->id > emp2->id)
        {
            retorno=1;
        }
        else if(emp1->id < emp2->id)
        {
            retorno= -1;
        }
    }
    return retorno;
}
int employee_CmpNombre(void* a,void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        retorno = strcmp(emp1->nombre,emp2->nombre);
    }
    return retorno;
}
int employee_CmpHorasTrabajdas(void* a,void* b)
{
   int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            retorno=1;
        }
        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            retorno= -1;
        }
    }
    return retorno;

}
int employee_CmpSueldo(void* a,void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->sueldo > emp2->sueldo)
        {
            retorno=1;
        }
        else if(emp1->sueldo < emp2->sueldo)
        {
            retorno= -1;
        }
    }
    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TAM 1000
#define TAMSEC 5


int main()
{
    int nextId = 1000;
    eSector sectores[TAMSEC]=
    {
        {500, "sistemas"},
        {501, "Legales"},
        {502, "RRHH"},
        {503, "Contable"},
        {504, "Ventas"}
    };
    Employee nomina[TAM];
    initEmployees(nomina,TAM);
    int id;
    char salir = 'n';
    float sueldosTotal;
    float promedioSueldos;

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(nomina,TAM,&nextId,sectores,TAMSEC);
            break;
        case 2:
            printf("2. MODIFICAR\n");
            if(modificarEmpleado(nomina,TAM))
            {
                printf("Modificacion Exitosa!!!\n");
            }else
            {
                printf("No se hicieron modificaciones.\n");
            }
            break;
        case 3:
            system("cls");
            printf("3. BAJA\n");
            printEmployees(nomina,TAM);
            utn_getNumero(&id,"Ingrese ID: ","ID invalido, ",1000,2000,10);
            removeEmployee(nomina,TAM,id);
            break;
        case 4:
            system("cls");
            printf("4. INFORMES\n");
            printEmployees(nomina,TAM);
            switch(menuInformes())
            {
            case 1:
                system("cls");
                ordenarEmpleados(nomina,TAM);
                break;
            case 2:
                system("cls");
                printEmployees(nomina,TAM);
                totalSueldos(nomina,TAM,&sueldosTotal);
                printf("\nTotal sueldos: %.2f\n",sueldosTotal);
                salarioPromedio(nomina,TAM,&promedioSueldos);
                printf("\nPromedio de sueldos: %.2f\n\n",promedioSueldos);
                mayorAlPromedio(nomina,TAM);
                break;
            default:
                break;
            }
            break;
        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            while(salir!= 'n' && salir!= 's')
            {
                printf("Confirma salida?: ");
                fflush(stdin);
                salir = getchar();
            }
            printf("\n\n");
            break;
        }
        system("pause");
        system("cls");

    }
    while(salir == 'n');


    return 0;
}







/*
 * utn.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Sofia
 */

#include <stdio.h>
#include <stdlib.h>


int menuCalculadora(int* flag1, int* flag2, int A, int B)
{
    int opcion;
    //system("cls");
    printf("*********MENU DE OPCIONES*******\n\n");
    if(*flag1){
        printf("1. 1er operando (A = %d)\n", A);
    }else{
    printf("1.Ingresar 1er operando (A=x)\n");
    }
    if(*flag2){
          printf("2. 2do operando (B = %d)\n", B);

    }else{
    printf("2.Ingresar 2do operando (B=y)\n");
    }
    printf("3.Calcular todas las operaciones\n");
    printf("4.Informar resultados\n");
    printf("5.Salir\n");
    printf("\nIngrese una opcion: \n");
    scanf("%d", &opcion);
    system("pause");
    return opcion;

}


int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

int dividir(int a, int b, float* div){

int posible = 0;
    if(b != 0)
    {
        *div = (float) a / b;
        posible = 1;
    }
    return posible;

}

int multiplicar(int a, int b){
return a * b;
}


int factorial(int n, int* fact){
    int ok = 0;
    if(n>= 0 && n<17)
    {
        *fact = 1;
        for(int i = 1; i <= n ; i++){
         *fact *= i;

        }
        ok = 1;
    }
    return ok;
}

/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	char salir = 'n';
    int numero1;
    int numero2;
    int banderaNumero1 = 0;
    int banderaNumero2 = 0;
    int banderaOperadores = 0;
    int rtdoSuma;
    int rtdoResta;
    float rtdoDivision;
    int okDivision;
    int rtdoMultiplicacion;
    int factorialUno;
    int factorialDos;
    int okFactorialUno;
    int okFactorialDos;


    do{
        switch(menuCalculadora(&banderaNumero1, &banderaNumero2, numero1, numero2))
        {
        case 1 :
            if(!banderaOperadores){
              printf("Ingrese el primer operador: \n");
            scanf("%d", &numero1);
            banderaNumero1 = 1;
            }else{
                printf("Ya realizó las operaciones, seleccione opción 4 o 5\n");
            }
            system("pause");

            break;
        case 2:
            if(!banderaOperadores && banderaNumero1){
                printf("Ingrese el segundo operador: \n");
                scanf("%d", &numero2);
                banderaNumero2 = 1;
            }else if (!banderaNumero1){
                printf("Debe ingresar primero el operador 1\n");
            }else{
                printf("Ya realizo las operaciones, seleccione opcion 4 o 5\n");
            }

            system("pause");

            break;
        case 3:
            if(banderaNumero1 && banderaNumero2)
            {
                printf("a)Calcular la suma (A+B)\n");
                printf("b)Calcular la resta (A-B)\n");
                printf("c)Calcular la division (A/B)\n");
                printf("d)Calcular la multiplicacion (A*B)\n");
                printf("e)Calcular el factorial (A!)\n");
                rtdoSuma = sumar(numero1,numero2);
                rtdoResta = restar(numero1,numero2);
                okDivision = dividir(numero1, numero2, &rtdoDivision);
                rtdoMultiplicacion = multiplicar(numero1,numero2);
                okFactorialUno = factorial(numero1, &factorialUno);
                okFactorialDos = factorial(numero2,&factorialDos);
                banderaOperadores = 1;
            }
            else
            {
                printf("Debe ingresar los operadores primero!\n");
            }
            system("pause");
            break;
        case 4:
            if(banderaOperadores)
            {
                printf("El resultado de A+B es: %d\n", rtdoSuma);
                printf("El resultado de A-B es: %d\n", rtdoResta);
                if(okDivision)
                {
                    printf("El resultado de A/B es: %.2f\n", rtdoDivision);
                }
                else
                {
                    printf("No es posible dividir por cero\n");
                }
                printf("El resultado de A*B es: %d\n", rtdoMultiplicacion);
                if(okFactorialUno && okFactorialDos){
                     printf("El factorial de A es: %d y El factorial de B es: %d\n", factorialUno, factorialDos);
                } else if(okFactorialUno){
                    printf("El factorial de A es: %d y El factorial de B no se pudo calcular\n", factorialUno);
                }else if (okFactorialDos){
                    printf("El factorial de A no se pudo calcular y El factorial de B es: %d \n", factorialDos);
                } else{
                    printf("No se pudo calcular el factorial de los operadores!\n");
                }
            }
            else
            {
                printf("Debe realizar las operaciones primero\n");
            }


            system("pause");
            break;
        case 5 :
            salir = 's';
            break;

        }

    }while(salir == 'n');

	return EXIT_SUCCESS;
}

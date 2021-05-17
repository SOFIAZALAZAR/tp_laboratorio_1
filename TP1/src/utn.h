/*
 * utn.h
 *
 *  Created on: 16 abr. 2021
 *      Author: Sofia
 */

#ifndef UTN_H_
#define UTN_H_


#endif /* UTN_H_ */

/** \brief Muestra el menu de opciones
 *
 * \return int devuelve la opcion seleccionada
 *
 */
int menuCalculadora(int* flag1, int* flag2, int A, int B);

/** \brief Realiza la suma entre dos operadores
 *
 * \param a int primer operador
 * \param b int segundo operador
 * \return int devulve el resultado de la suma a + b
 *
 */
int sumar(int a, int b);

/** \brief Realiza la resta entre dos operadores
 *
 * \param a int primer operador
 * \param b int segundo operador
 * \return int d devulve el resultado de la resta a - b
 *
 */
int restar(int a, int b);

/** \brief realiza la division entre dos enteros
 *
 * \param a int dividendo
 * \param b int divisor
 * \param div float* puntero al resultado de la division
 * \return int retorna 1 si se puedo realizar la division o 0 si no se pudo
 *
 */

int dividir(int a, int b, float* div);

/** \brief realiza la multiplicacion de dos enteros
 *
 * \param a int primer entero
 * \param b int segundo entero
 * \return int retorna el resultado de la multiplicacion entre los dos enteros
 *
 */
int multiplicar(int a, int b);


/** \brief Realiza el factorial de un entero
 *
 * \param n int numero entero
 * \param fact int* puntero con el resultado del factorial del entero
 * \return int devuelve 1 si se pudo hacer el facorial o 0 si no se puedo
 *
 */
int factorial(int n, int* fact);

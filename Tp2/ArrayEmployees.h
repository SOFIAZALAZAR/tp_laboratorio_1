#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;
typedef struct{
    int id;
    char descripcion[20];
}eSector;

#endif // ARRAYEMPLOYEES_H_INCLUDED
/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

/** \brief searches an existing list for the first free position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if there are no free positions or return the available position
 *
 */
int freeSpace(Employee* list, int len);
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* * \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);
/** \brief print the content of one employee
 *
 * \param oneEmployee Employee
 * \return void
 *
 */
void printEmployee(Employee oneEmployee);

/** \brief muestra las opciones del menu de empleados
 *
 * \return int retorna la opcion del menu
 *
 */
int menu();

/** \brief add in a existing list of employees the values received as parameters
*     in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief agrega un nuevo empleado en una lista existente de empleados
 *
 * \param lista[] Employee array de empleados
 * \param tam int tamaño del array
 * \param pId int* puntero al id
 * \return int retorna 0 si no se pudo cargar y 1 si e hizo de manera exitosa
 *
 */
/** \brief grega un nuevo empleado en una lista existente de empleados
 *
 * \param lista[] Employee array de empleados
 * \param tam int tamaño del array de empleados
 * \param pId int* puntero al id
 * \param sec[] eSector array de sectores
 * \param tamSec int tamaño del array de sectores
 * \return int retorna 0 si no se pudo cargar y 1 si se hizo de manera exitosa
 *
 */
int altaEmpleado(Employee lista[],int tam, int* pId, eSector sec[], int tamSec);
/** \brief muestra las opciones para modificar un empleado
 *
 * \return int retorna la opcion elegida por el usuario
 *
 */
int menuModificar();
/** \brief permite modificar un empleado existente
 *
 * \param lista[] Employee array de empleados
 * \param tam int tamaño del array
 * \return int retorna 0 si no se pudo modificar y 1 si se modifico de manera exitosa
 *
 */
int modificarEmpleado(Employee lista[], int tam);
/** \brief  calcula el total de sueldos de los empleados
 *
 * \param list[] Employee array de empleados
 * \param tam int tamaño del array
 * \param tot float* puntero al total
 * \return int retorna -1 si no se pudo calcular y 0 se pudo calcular de manera exitosa
 *
 */
int totalSueldos(Employee list[],int tam, float* tot);
/** \brief calcula el promedio de los sueldos
 *
 * \param list[] Employee array de empleados
 * \param tam int tamaño del array
 * \param prom float* puntero con el promedio
 * \return int retorna -1 si no se pudo calcular y 0 se pudo calcular de manera exitosa
 *
 */
int salarioPromedio(Employee list[], int tam, float* prom);
/** \brief muestra la cantidad de empleados con sueldos mayores al promedio
 *
 * \param list[] Employee array de empleados
 * \param tam int tamaño del array
 * \return int retorna -1 si no se pudo calcular y 0 se pudo calcular de manera exitosa
 *
 */
int mayorAlPromedio(Employee list[],int tam);
/** \brief muestra las opciones de informes
 *
 * \return int retorna la opcion elegida por el usuario
 *
 */
int menuInformes();
/** \brief ordena los empleados de manera ascendente o descendente
 *
 * \param list[] Employee array de empleados
 * \param tam int tamaño del array
 * \return int retorna 0 si se pudo ordenar y -1 si no se pudo ordenar
 *
 */
int ordenarEmpleados(Employee list[], int tam);


/** \brief muestra la lista de sectores
 *
 * \param sec[] eSector array de sectores
 * \param tam int tamaño de sectores
 * \return int retorna -1 si el array es nulo o el tamaño es menor a cero o 0 si esta todo ok
 *
 */
int mostrarSectores(eSector sec[],int tam);


#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

int utn_getNumero(int* pResultado, char*mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int getInt(int* pResultado);

int esNumerica(char* cadena);

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getTexto(char* texto, int tam, char* mensaje, char* mensajeError, int reintentos);

int getString(char* texto, int tam);

float getFloat(float* pResultado);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int esNumericaFlotante(char* cadena);

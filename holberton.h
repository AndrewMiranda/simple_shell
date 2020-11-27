#ifndef holberton_h
#define holberton_h

/* Librerias */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

/*Declarando cabeceras de funciones*/
void separaArgs(void); /*Esta func separa una cadena en palabras individuales*/
void listaDir(void); /*Esta función ejecuta el comando dir*/
void eco(void); /*Esta función ejecuta el comando echo*/
void comExterno(void); /*Func que ejecuta lo que se considere comandos externos*/

#endif

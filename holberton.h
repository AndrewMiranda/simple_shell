#ifndef holberton_h
#define holberton_h

/*Declaracion de librerias */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

/*Declarando cabeceras de funciones*/
void separaArgs(void); /*Func que separa la cadena ingresada por el usuario en palabras individuales*/
void listaDir(void); /*Esta func ejecuta el comando dir*/
void eco(void); /*Esta func ejecuta el comando echo*/
void comExterno(void); /*Esta func ejecuta lo que se considere comandos externos*/

#endif

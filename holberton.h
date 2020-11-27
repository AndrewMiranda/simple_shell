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
void separaArgs(void); /*Esta funcion separa la cadena ingresada por el usuario en palabras individuales, 
la 1° palabra sera considerada comando y el resto sus argumentos*/
void listaDir(void); /*Esta función ejecuta el comando dir*/
void eco(void); /*Esta función ejecuta el comando echo*/
void comExterno(void); /*Esta función ejecuta lo que se considere comandos externos*/

#endif

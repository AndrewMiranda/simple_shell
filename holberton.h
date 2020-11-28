#ifndef holberton_h
#define holberton_h

/*Declaracion de librerias */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_ARGS 13  /*Numero maximo de argumentos (-1) cuando se trate de un comando externo*/
#define MAX_I 105 /*Numero de caracteres maximo para comando las variables de ambiente*/

/*Declarando variables*/
char comando[MAX_I]; /*Esta var lee el comando que ingrese el usuario*/
char *args[MAX_ARGS]; /*en este arreglo se almacenan los argumentos del comando ingresado*/

/*Declarando variables de ambiente*/
char SHELL[MAX_I];
char PATH[MAX_I];
char HOME[MAX_I];
char PWD[MAX_I];

/*Declarando cabeceras de funciones*/
void separaArgs(void); /*Func que separa la cadena ingresada por el usuario en palabras individuales*/
void listaDir(void); /*Esta func ejecuta el comando dir*/
void eco(void); /*Esta func ejecuta el comando echo*/
void comExterno(void); /*Esta func ejecuta lo que se considere comandos externos*/

#endif

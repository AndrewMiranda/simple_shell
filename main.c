#include "holberton.h"
#include "shell.c"

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

main(void){
  int continuar = 1;
  /*Inicializando variables de ambiente*/
  getcwd(PWD, MAX_I); /*Obteniendo la ruta actual y cargando en PWD*/
  strcpy(PATH, getenv("PATH")); /*Obteniendo el directorio del path y cargando en PATH*/
  
  strcpy(HOME, PWD);
  strcpy(SHELL,  PWD);
  do{ /*Ciclo principal*/
    printf(" %s>", PWD); /*Imprimiendo el indicador del shell (directorio actual)*/
    __fpurge(stdin); /*Limpiando el buffer de entrada de teclado*/
    memset(comando,'\0', MAX_I); /*Borrando cualquier contenido previo de comando*/
    scanf("%[^\n]s", comando); /*Esperar hasta que el usuario ingrese algun comando*/
    if(strlen(comando)>0){ /*Actuar solo si comando contiene algo y solo un enter*/
      separaArgs(); /*Separar comando de sus argumentos*/
      if(strcmp(comando,"cd") == 0){ /*Si el comando es cd*/
        if(args[1]) /*Verificar que cuente con el argumento necesario*/
    if(chdir(args[1]) != 0) /*La func chdir hace el cambio de directorio si regresa un valor 
            diferente de cero la operacion no se pudo ejecutar con exito*/
     printf("Error! %s no existe o no se puede cambiar a este directorio\n",args[1]);
   else getcwd(PWD, MAX_I);/*En caso de cambio exitoso actualizar PWD*/
      }
      else if(strcmp(comando, "dir") == 0)
        listaDir(); /*Si el comando es el dir llamar a la func correspondiente*/
      else if(strcmp(comando, "clr") == 0)
        strcpy(comando,"clear"), comExterno(); /*Limpia la pantalla con la
         funcion de comando externo y se pasa como comando clear.*/
      else if(strcmp(comando, "env") == 0){
        printf(" Variables de ambiente:\n");/*Mostrar los valores de las var de ambiente*/
        printf("  HOME=%s\n  PWD=%s\n", HOME, PWD);
        printf("  SHELL=%s\n  PATH=%s\n", SHELL, PATH);
      }
      else if(strcmp(comando, "echo")==0){
        if(args[1]) eco(); /*Si hay al menos 1 argumento llamar la func que ejecuta echo*/
      }
      else if(strcmp(comando, "pwd")==0)
        printf("%s\n", PWD); /*Mostrar el contenido de PWD (Directorio actual)*/
      else if(strcmp(comando, "exit")==0)
        continuar = 0; /*Cambiar el valor de continuar para que termine*/
      else comExterno(); /*Cualquier otra entrada llamar a comExterno*/
    }
  }while(continuar); /*Volver a ejecutar mientras no ingresen exit*/
  return 0;
}

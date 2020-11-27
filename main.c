#include "holberton.h"
#include "shell.c"
#define MAX_ARGS 13
#define MAX_I 105

main(void) 
{
char comando[MAX_I];
char *args[MAX_ARGS];
char SHELL[MAX_I];
char PATH[MAX_I];
char HOME[MAX_I];
char PWD[MAX_I];
  
int continuar = 1;
getcwd(PWD, MAX_I);
strcpy(PATH, getenv("PATH"));
strcpy(HOME, PWD);
strcpy(SHELL,  PWD);
do 
{
printf(" %s > ", PWD);
__fpurge(stdin);
memset(comando, '\0', MAX_I);
scanf("%[^\n]s", comando);
if (strlen(comando) > 0) 
{
separaArgs();
if (strcmp(comando, "cd") == 0) 
{
if (args[1])
if (chdir(args[1]) != 0)
printf("Error! %s no existe o no se puede cambiar a este directorio\n", args[1]);
else getcwd(PWD, MAX_I);
}
else if (strcmp(comando, "dir") == 0)
listaDir();
else if (strcmp(comando, "clr") == 0)
strcpy(comando, "clear"), comExterno();
else if (strcmp(comando, "env") == 0) {
printf(" Variables de ambiente:\n");
printf(" HOME=%s\n  PWD=%s\n", HOME, PWD);
printf(" SHELL=%s\n  PATH=%s\n", SHELL, PATH);
}
else if (strcmp(comando, "echo") == 0) 
{
if (args[1]) eco();
}
else if (strcmp(comando, "pwd") == 0)
printf("%s\n", PWD);
else if (strcmp(comando, "exit") == 0)
continuar = 0;
else comExterno();
}
}
while (continuar); 
return (0); 
}

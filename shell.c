#include "holberton.h"

/**
 *
 *
**/

#define MAX_ARGS 13
#define MAX_I 105
char comando[MAX_I]; 
char *args[MAX_ARGS]; 
char SHELL[MAX_I];
char PATH[MAX_I];
char HOME[MAX_I];
char PWD[MAX_I];

void separaArgs(void){
int i;
for (i = 0; i < (MAX_ARGS-1); i++) args[i] = NULL; 
strtok(comando, " "), i = 0; 
args[i] = comando;
while ((args[++i] = strtok(NULL, " ")) != NULL && i < (MAX_ARGS-2));
}

void listaDir(void){
char ruta[MAX_I];
int archs;
int cnt = -1;
struct dirent **lista;
strcpy(ruta, PWD);
if (args[1]) strcat(ruta, "/"), strcat(ruta, args[1]); 
archs=scandir(ruta, &lista, 0, alphasort);
if (archs < 0)
printf("Error no existe o no se pudo leer [%s]\n", ruta);
else if (archs == 2){
printf(" El directorio [%s] esta vacio", ruta);
}
else 
{
printf(" Archivos y carpetas encontrados en: [%s]\n", ruta);
while (++cnt < archs)
if (strcmp(lista[cnt]->d_name, ".") != 0 && strcmp(lista[cnt]->d_name, "..") != 0)
printf(" %s\n", lista[cnt]->d_name);
}
}
void eco(void)
{
int i;
int j;
int k = 0;
char aux[6];
while (args[++k])
{
for (i = 0; i < strlen(args[k]); i++)
{ 
if (args[k][i] != '$') printf("%c",args[k][i]);
else 
{  
j = -1;
while (++j < 5 && (i + j + 1) < strlen(args[k]) && args[k][i + j + 1] != '\0')
aux[j] = args[k][i + j + 1];
aux[j]= '\0';
if (strcmp(aux, "SHELL") == 0)
printf("%s", SHELL), i += 5;
else if (strncmp(aux, "PATH" , 4) == 0)
printf("%s", PATH), i += 4;
else if (strncmp(aux, "PWD", 3) == 0)
printf("%s", PWD), i += 3;
else if (strncmp(aux, "HOME", 4) == 0)
printf("%s", HOME), i += 4;
else printf("$");
}
}
printf(" ");
}
printf("\n");
}

void comExterno()
{
int pid = 0;
int status;
pid = fork();
if (pid < 0) printf("Error! no se pudo crear un proceso hijo");
if (pid == 0)
{
status = execvp(comando, args);
if (status){
printf("¡Error! %s no se reconoce o no se pudo ejecutar\n", comando);
exit(1);
}
}
else
wait(NULL);
}

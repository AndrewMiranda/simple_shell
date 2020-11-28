#ifndef HEADER_H
#define HEADER_H
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <stdarg.h>
void _signal(int line);
void _split(char *buffer, char **av);
int _exec(int  ac, char *av[]);
int _strcmp(char *s1, char *s2);
int main(int ac, char **ar, char *envp[]);
int print_e(char **envp);
int _strlen(char *s);
extern char **environ;
#endif

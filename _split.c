#include "header.h"

/**
 * _split - function that separates string from stdin in tokens
 *@buffer: line of commands to be separated
 *@av: array where are saved
 */

void _split(char *buffer, char **av)
{
  char *token = NULL;
  int i = 0;

  token = strtok(buffer, "\t\n\a\r ");

  while (token != NULL)
    {

      av[i] = token;
      i++;
      token = strtok(NULL, " \t\n\r");
    }

  av[i] = NULL;

}

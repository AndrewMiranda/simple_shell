#include "header.h"
/**
 *main - get commands to execute
 *@ac: number of arguments unused
 *@ar: arguments unused
 *@envp: environment
 *Return: nothing
 */
int main(int ac, char *ar[], char **envp)
{
  char *buffer = NULL;
  char  *av[10];
  int pos = 0, g;
  size_t size = 0;
  (void)ac;
  (void)ar;

  do {
    signal(SIGINT, _signal);
    if (isatty(STDIN_FILENO))
      write(STDOUT_FILENO, "#cisfun$ ", 10);
    g = getline(&buffer, &size, stdin);
    if (!buffer)
      free(buffer);
    if (g == EOF)
      {
	if (isatty(STDIN_FILENO))
	  write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
      }
    if (_strcmp(buffer, "exit\n") == 0)
      {
	free(buffer);
	exit(2);
      }
    else if (_strcmp(buffer, "env\n") == 0)
      print_e(envp);
    _split(buffer, av);
    if ((*buffer != '\n') && av[0])
      _exec(pos, av);
    while (pos < 10)
      pos++;
  } while (1);
  free(buffer);
  free(av);
  free(envp);
  return (EXIT_SUCCESS);
}

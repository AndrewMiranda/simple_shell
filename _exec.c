#include "header.h"

/**
 *_exec-function thatexecutes commands from stdin
 * @av: array of arguments to execute
 * @ac: number of arguments
 * Return: 0
 */
int _exec(int  ac, char *av[])
{
  int pid = 0, status = 0;
  unsigned int i = 0;
  struct stat sb;
  (void) ac;

  if (av[0])
    {
      if ((stat(av[i], &sb) == -1) && (_strcmp(av[i], "env\n") != 0))
	{
	  write(STDOUT_FILENO, "./hsh:  not found\n", 20);
	  return (127);
	}
      else
	{
	  pid = fork();
	  if (pid == 0)
	    {
	      if (execve(av[0], av, NULL) == -1)
		{
		  if (_strcmp(av[i], "env\n") != 0)
		    {
		      perror("./shell");
		      exit(127);
		    }
		}
	    }
	  else
	    {
	      wait(&status);
	    }
	}
    }
  else
    {
      exit(127);
    }
  return (0);
}

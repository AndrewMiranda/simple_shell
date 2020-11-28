#include "header.h"

/**
 * print_e - printing environment
 * @arg: arguments to look for env
 * Return: nothing
 *
 */

int print_e(char **arg)

{

int i;

for (i = 0; arg[i] != NULL; i++)
{
write(STDOUT_FILENO, arg[i], _strlen(arg[i]));
write(STDOUT_FILENO, "\n", 1);

}
return (0);
}

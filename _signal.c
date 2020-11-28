#include "header.h"

/**
 *_signal-new line when detect de ^C call.
 * @line: no used argument
 * Return: 0
 */

void _signal(int line)

{
  (void) line;

  write(STDOUT_FILENO, "\n#cisfun$", 10);
}

#include "shell.h"

/**
 * our_clear - Clears screen.
 * @args: Array of the arguments.
 *
 * Return: 1, or 0 to exit.
*/
int our_clear(char **args)
{
	(void)args;
	our_puts("\033[2J\033[H");
	return (1);
}

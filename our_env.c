#include "shell.h"

/**
 * our_env - Prints all environment variables in shell.
 *
 * Return: void.
 */
int our_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		our_puts(environ[i]);
		our_putchar('\n');
	}

	return (0);
}

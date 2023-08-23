#include "shell.h"

/**
 * our_exit - Exits shell.
 * @args: Argument.
 *
 * Return: Nothing void.
 */
void our_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = our_atoi(args[1]);
	}
	free(args);
	remove_previous_input();
	exit(status);
}

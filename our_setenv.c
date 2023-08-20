#include "shell.h"

/**
 * our_setenv - setting value for environment variable.
 * @args: Arguments.
 *
 * Return: Nothing void.
 */
int our_setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		our_puterror("Usage: setenv variable value\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		our_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * our_unsetenv - Unsetting value for environment variable.
 * @args: Arguments.
 *
 * Return: Nothing void.
 */
int our_unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		our_puterror("Usage: unsetenv variable\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		our_puterror("unsetenv");
	}
	return (0);
}

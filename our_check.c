 #include "shell.h"

/**
 * our_check - checks if the command is built in or no.
 * @args: array of the arguments.
 *
 * Return: 1 when it is built in, 0 else.
 */
int our_check(char **args)
{
	if (!args[0])
		return (0);
	if (!our_strcmp(args[0], "exit"))
		our_exit(args);
	else if (!our_strcmp(args[0], "env"))
		our_env();
	else if (!our_strcmp(args[0], "setenv"))
		our_setenv(args);
	else if (!our_strcmp(args[0], "unsetenv"))
		our_unsetenv(args);
	else if (!our_strcmp(args[0], "help"))
		our_help();
	else if (!our_strcmp(args[0], "cd"))
		our_cd(args);
	else if (!our_strcmp(args[0], "clear"))
		our_clear(args);
	else
		return (0);
	return (1);
}

int our_execute(char *cmd, char **args)
{
    return 0;
}

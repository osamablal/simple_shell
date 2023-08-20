#include "shell.h"

/**
 * our_cd - changes working directory.
 * @args: Array of the arguments.
 */
void our_cd(char **args)
{
	char *dir = args[1];
	int ret;

	if (dir == NULL)
	{
		dir = _ourgetenv("Home");
		if (dir == NULL)
		{
			our_puts("cd: No Home directory is found\n");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}

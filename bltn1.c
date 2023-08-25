#include "shell.h"

/**
 * our_exit - exits the shell
 * @info: Structure having arguments.
 *  Return: Exits with an exit status.
 */
int our_exit(info_t *info)
{
	int excheck;

	if (info->argv[1])
	{
		excheck = our_err(info->argv[1]);
		if (excheck == -1)
		{
			info->status = 2;
			our_printerr(info, "Illegal num: ");
			our_eputs(info->argv[1]);
			our_eputchar('\n');
			return (1);
		}
		info->err_num = our_err(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * our_cd - Change current directory.
 * @info: Structure with args.
 *  Return: 0
 */
int our_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure <<\n");
	if (!info->argv[1])
	{
		dir = our_getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = our_getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (our_strcmp(info->argv[1], "-") == 0)
	{
		if (!our_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(our_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = our_getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		our_printerr(info, "Can Not cd ");
		our_eputs(info->argv[1]), our_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", our_getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * our_help - Show help information.
 * @info: Structure with args.
 *  Return: Always 0
 */
int our_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Function not yet working. \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

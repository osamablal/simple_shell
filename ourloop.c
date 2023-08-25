#include "shell.h"

/**
 * hsh - The main loop of shell.
 * @info: Return inf structure.
 * @vc: Vector.
 *
 * Return: 0 if success, 1 in eror.
 */
int hsh(info_t *info, char **vc)
{
	ssize_t r = 0;
	int builtn_rt = 0;

	while (r != -1 && builtn_rt != -2)
	{
		our_clearinf(info);
		if (intrctv(info))
			_puts("$ ");
		our_eputchar(BUF_FLUSH);
		r = our_getinput(info);
		if (r != -1)
		{
			our_setinf(info, vc);
			builtn_rt = ourfind_builtin(info);
			if (builtn_rt == -1)
				ourfind_cmd(info);
		}
		else if (intrctv(info))
			_putchar('\n');
		our_freeinf(info, 0);
	}
	ourwrithis(info);
	our_freeinf(info, 1);
	if (!intrctv(info) && info->status)
		exit(info->status);
	if (builtn_rt == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtn_rt);
}

/**
 * ourfind_builtin - Find BUILT-IN command.
 * @info: Return inf structure.
 *
 * Return: -1 if it's not found,
 *			0 if it's executed successfully,
 *			1 if it's found and not sucessful,
 *			-2 if it's signal exit.
 */
int ourfind_builtin(info_t *info)
{
	int i, builtn_rt = -1;
	builtin_table builtintbl[] = {
		{"exit", our_exit},
		{"env", our_env},
		{"help", our_help},
		{"history", our_history},
		{"setenv", our_setenv},
		{"unsetenv", our_unsetenv},
		{"cd", our_cd},
		{"alias", our_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (our_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			builtn_rt = builtintbl[i].func(info);
			break;
		}
	return (builtn_rt);
}

/**
 * ourfind_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void ourfind_cmd(info_t *info)
{
	char *path = NULL;
	int i, b;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, b = 0; info->arg[i]; i++)
		if (!isdlm(info->arg[i], " \t\n"))
			b++;
	if (!b)
		return;

	path = ourfind_path(info, our_getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		our_forkcmd(info);
	}
	else
	{
		if ((intrctv(info) || our_getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && ouris_cmd(info, info->argv[0]))
			our_forkcmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			our_printerr(info, "Not Found\n");
		}
	}
}

/**
 * our_forkcmd - fork threed to running cmd.
 * @info: Return inf Structure.
 *
 * Return: void
 */
void our_forkcmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			our_freeinf(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				our_printerr(info, "Permission Denied\n");
		}
	}
}


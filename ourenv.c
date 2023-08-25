#include "shell.h"

/**
 * our_env - Prints current envirnment.
 * @info: Structure with args.
 * Return: 0.
 */
int our_env(info_t *info)
{
	ourprint_list(info->env);
	return (0);
}

/**
 * our_getenv - Get value of environn.
 * @info: Structure with args.
 * @nm: Environ Name.
 *
 * Return: Value.
 */
char *our_getenv(info_t *info, const char *nm)
{
	list_t *nod = info->env;
	char *a;

	while (nod)
	{
		a = our_starts(nod->stg, nm);
		if (a && *a)
			return (a);
		nod = nod->next;
	}
	return (NULL);
}

/**
 * our_setenv - make new environment variable.
 * @info: Structure with args.
 *  Return: 0.
 */
int our_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		our_eputs("Incorrect num of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * our_unsetenv - Delete environment variable.
 * @info: Structure with args.
 *  Return: 0.
 */
int our_unsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		our_eputs("Few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * our_envlist - Populete environ linked list.
 * @info: Structure with args.
 * Return: 0.
 */
int our_envlist(info_t *info)
{
	list_t *nod = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ouradd_nodeend(&nod, environ[i], 0);
	info->env = nod;
	return (0);
}

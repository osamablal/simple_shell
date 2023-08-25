#include "shell.h"

/**
 * get_environ - Return string arrey copy of env.
 * @info: Structure.
 * Return: 0.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = ourlist_string(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Delete env variable.
 * @info: Structure.
 *  Return: 1, 0 otherwise
 * @var: String env var.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *nod = info->env;
	size_t i = 0;
	char *r;

	if (!nod || !var)
		return (0);

	while (nod)
	{
		r = our_starts(nod->stg, var);
		if (r && *r == '=')
		{
			info->env_changed = ourdelete_node(&(info->env), i);
			i = 0;
			nod = info->env;
			continue;
		}
		nod = nod->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialise new env variable.
 * @info: Structure.
 * @var: String env var.
 * @value: Var value.
 *  Return: 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *nod;
	char *r;

	if (!var || !value)
		return (0);

	buff = malloc(our_strlen(var) + our_strlen(value) + 2);
	if (!buff)
		return (1);
	our_strcpy(buff, var);
	our_strcat(buff, "=");
	our_strcat(buff, value);
	nod = info->env;
	while (nod)
	{
		r = our_starts(nod->stg, var);
		if (r && *r == '=')
		{
			free(nod->stg);
			nod->stg = buff;
			info->env_changed = 1;
			return (0);
		}
		nod = nod->next;
	}
	ouradd_nodeend(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}


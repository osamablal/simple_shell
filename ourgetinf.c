#include "shell.h"

/**
 * our_clearinf - Initialse info_t.
 * @info: structure address.
 */
void our_clearinf(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * our_setinf - Initialse info_t.
 * @info: Structure Address.
 * @arv: Arg vector.
 */
void our_setinf(info_t *info, char **arv)
{
	int i = 0;

	info->fname = arv[0];
	if (info->arg)
	{
		info->argv = ourstrtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = our_strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		ourreplace_alias(info);
		ourreplace_vars(info);
	}
}

/**
 * our_freeinf - Free info_t.
 * @info: Structuree address.
 * @alll: True if freeing all fields
 */
void our_freeinf(info_t *info, int alll)
{
	our_free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (alll)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			ourfree_list(&(info->env));
		if (info->history)
			ourfree_list(&(info->history));
		if (info->alias)
			ourfree_list(&(info->alias));
		our_free(info->environ);
			info->environ = NULL;
		our_bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

#include "shell.h"

/**
 * our_history - Shows history list.
 * @info: Structure with arguments.
 *  Return: Always 0
 */
int our_history(info_t *info)
{
	ourprint_list(info->history);
	return (0);
}

/**
 * ounset_alias - Puts alias to the string.
 * @info: Parameter Structure.
 * @stg: String Alias.
 *
 * Return: Always 0 , 1 if error.
 */
int ounset_alias(info_t *info, char *stg)
{
	char *a, b;
	int ret;

	a = our_strchr(stg, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	ret = ourdelete_node(&(info->alias),
		ourget_nodindx(info->alias, ournode_start(info->alias, stg, -1)));
	*a = b;
	return (ret);
}

/**
 * oset_alias - sets alias to string
 * @info: parameter struct
 * @stg: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int oset_alias(info_t *info, char *stg)
{
	char *a;

	a = our_strchr(stg, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (ounset_alias(info, stg));

	ounset_alias(info, stg);
	return (ouradd_nodeend(&(info->alias), stg, 0) == NULL);
}

/**
 * oprint_alias - prints an alias string
 * @nod: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int oprint_alias(list_t *nod)
{
	char *a = NULL, *s = NULL;

	if (nod)
	{
		a = our_strchr(nod->stg, '=');
		for (s = nod->stg; s <= a; s++)
			_putchar(*s);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * our_alias - Man alias.
 * @info: Structure with args.
 *  Return: 0.
 */
int our_alias(info_t *info)
{
	int i = 0;
	char *a = NULL;
	list_t *nod = NULL;

	if (info->argc == 1)
	{
		nod = info->alias;
		while (nod)
		{
			oprint_alias(nod);
			nod = nod->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		a = our_strchr(info->argv[i], '=');
		if (a)
			oset_alias(info, info->argv[i]);
		else
			oprint_alias(ournode_start(info->alias, info->argv[i], '='));
	}

	return (0);
}


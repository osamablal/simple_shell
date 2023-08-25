#include "shell.h"

/**
 * ourlist_len - Gets length of lnked list.
 * @g: First node Pointer.
 *
 * Return: List Siz.
 */
size_t ourlist_len(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		g = g->next;
		i++;
	}
	return (i);
}

/**
 * ourlist_string - Give array of strings.
 * @hd: First node Pointer.
 *
 * Return: array of strings.
 */
char **ourlist_string(list_t *hd)
{
	list_t *nod = hd;
	size_t i = list_len(hd), k;
	char **stgs;
	char *stg;

	if (!hd || !i)
		return (NULL);
	stgs = malloc(sizeof(char *) * (i + 1));
	if (!stgs)
		return (NULL);
	for (i = 0; nod; nod = nod->next, i++)
	{
		stg = malloc(our_strlen(nod->stg) + 1);
		if (!stg)
		{
			for (k = 0; k < i; k++)
				free(stgs[k]);
			free(stgs);
			return (NULL);
		}

		stg = our_strcpy(stg, nod->stg);
		stgs[i] = stg;
	}
	stgs[i] = NULL;
	return (stgs);
}


/**
 * ourprint_list - prints elements of list_t.
 * @hd: First node Pointer.
 *
 * Return: List Siz.
 */
size_t ourprint_list(const list_t *hd)
{
	size_t i = 0;

	while (hd)
	{
		_puts(convert_number(hd->nm, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hd->stg ? hd->stg : "(nil)");
		_puts("\n");
		hd = hd->next;
		i++;
	}
	return (i);
}

/**
 * ournode_start - returns node whose string starts with prefix
 * @nod: pointer to list head
 * @prefix: string to match
 * @chr: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *ournode_start(list_t *nod, char *prefix, char chr)
{
	char *x = NULL;

	while (nod)
	{
		x = starts_with(nod->stg, prefix);
		if (x && ((chr == -1) || (*x == chr)))
			return (nod);
		nod = nod->next;
	}
	return (NULL);
}

/**
 * ourget_nodindx - get the index of node.
 * @hd: List head Pointr.
 * @nod: Node Pointr.
 *
 * Return: index, -1.
 */
ssize_t ourget_nodindx(list_t *hd, list_t *nod)
{
	size_t i = 0;

	while (hd)
	{
		if (hd == nod)
			return (i);
		hd = hd->next;
		i++;
	}
	return (-1);
}

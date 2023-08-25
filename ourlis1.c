#include "shell.h"

/**
 * ouradd_node - adds a node to the start of the list
 * @hd: address of pointer to head node
 * @stg: str field of node
 * @nm: node index used by history
 *
 * Return: size of list
 */
list_t *ouradd_node(list_t **hd, const char *stg, int nm)
{
	list_t *new_hd;

	if (!hd)
		return (NULL);
	new_hd = malloc(sizeof(list_t));
	if (!new_hd)
		return (NULL);
	our_memset((void *)new_hd, 0, sizeof(list_t));
	new_hd->nm = nm;
	if (stg)
	{
		new_hd->stg = our_strdup(stg);
		if (!new_hd->stg)
		{
			free(new_hd);
			return (NULL);
		}
	}
	new_hd->next = *hd;
	*hd = new_hd;
	return (new_hd);
}

/**
 * ouradd_nodeend - adds a node to the end of the list
 * @hd: address of pointer to head node
 * @stg: str field of node
 * @nm: node index used by history
 *
 * Return: size of list
 */
list_t *ouradd_nodeend(list_t **hd, const char *stg, int nm)
{
	list_t *new_nod, *nod;

	if (!hd)
		return (NULL);

	nod = *hd;
	new_nod = malloc(sizeof(list_t));
	if (!new_nod)
		return (NULL);
	our_memset((void *)new_nod, 0, sizeof(list_t));
	new_nod->nm = nm;
	if (stg)
	{
		new_nod->stg = our_strdup(stg);
		if (!new_nod->stg)
		{
			free(new_nod);
			return (NULL);
		}
	}
	if (nod)
	{
		while (nod->next)
			nod = nod->next;
		nod->next = new_nod;
	}
	else
		*hd = new_nod;
	return (new_nod);
}

/**
 * ourprint_list - Print string element of list_t list.
 * @g: Pointer to the first node.
 *
 * Return: List Siz.
 */
size_t ourprint_list(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		_puts(g->stg ? g->stg : "(nil)");
		_puts("\n");
		g = g->next;
		i++;
	}
	return (i);
}

/**
 * ourdelete_node - Delete node.
 * @hd: Pointer of first node adress.
 * @index: Node index.
 *
 * Return: 1 , 0 in fail.
 */
int ourdelete_node(list_t **hd, unsigned int index)
{
	list_t *nod, *prev_nod;
	unsigned int i = 0;

	if (!hd || !*hd)
		return (0);

	if (!index)
	{
		nod = *hd;
		*hd = (*hd)->next;
		free(nod->stg);
		free(nod);
		return (1);
	}
	nod = *hd;
	while (nod)
	{
		if (i == index)
		{
			prev_nod->next = nod->next;
			free(nod->stg);
			free(nod);
			return (1);
		}
		i++;
		prev_nod = nod;
		nod = nod->next;
	}
	return (0);
}

/**
 * ourfree_list - free all the nodes.
 * @hd_pr: Pointer of head node adresss.
 *
 * Return: void
 */
void ourfree_list(list_t **hd_pr)
{
	list_t *nod, *next_nod, *hd;

	if (!hd_pr || !*hd_pr)
		return;
	hd = *hd_pr;
	nod = hd;
	while (nod)
	{
		next_nod = nod->next;
		free(nod->stg);
		free(nod);
		nod = next_nod;
	}
	*hd_pr = NULL;
}

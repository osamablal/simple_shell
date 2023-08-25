#include "shell.h"

/**
 **our_memset - fil memory with bytes.
 *@ss: Pointer to momory area.
 *@bs: Byte to fill *s with
 *@n: Num of bytes.
 *Return: Pointer to memory.
 */
char *our_memset(char *ss, char bs, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ss[i] = bs;
	return (ss);
}

/**
 * our_free - Free string of strings.
 * @ps: String of strings.
 */
void our_free(char **ps)
{
	char **x = ps;

	if (!ps)
		return;
	while (*ps)
		free(*ps++);
	free(x);
}

/**
 * our_realloc - reallocates a block of memory
 * @pntr: pointer to previous malloc'ated block
 * @old_siz: byte size of previous block
 * @new_siz: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *our_realloc(void *pntr, unsigned int old_siz, unsigned int new_siz)
{
	char *x;

	if (!pntr)
		return (malloc(new_siz));
	if (!new_siz)
		return (free(pntr), NULL);
	if (new_siz == old_siz)
		return (pntr);

	x = malloc(new_siz);
	if (!x)
		return (NULL);

	old_siz = old_siz < new_siz ? old_siz : new_siz;
	while (old_siz--)
		p[old_siz] = ((char *)pntr)[old_siz];
	free(pntr);
	return (x);
}

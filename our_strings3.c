#include "shell.h"

/**
 * our_atoi - Intgerize string.
 * @st: String.
 *
 * Return: Integer of string.
 */
int our_atoi(const char *st)
{
	int i, g;
	unsigned int h;

	i = 0;
	g = 1;
	h = 0;

	while (st[i] != '\0')
	{
		if (st[i] == '-')
			g *= -1;
		else if (st[i] >= '0' && st[i] <= '9')
			h = (h * 10) + (st[i] - '0');
		else
			break;
		i++;
	}
	return (h * g);
}

/**
 **our_memset - Fill memory by constant byte.
 *@a: A pointer to memory area.
 *@b: A byte to fill *s with it.
 *@c: Num of bytes being filled.
 *Return: a.
 */
char *our_memset(char *a, char b, unsigned int c)
{
	unsigned int i;

	for (i = 0; i < c; i++)
		a[i] = b;
	return (a);
}

/**
 * our_memcpy - Copy memory area.
 *
 * @z: Buffer to copy to.
 * @v: what is coppied.
 * @n: n bytes of v.
 *
 * Return: 0
*/

char *our_memcpy(char *z, char *v, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		z[i] = v[i];
	return (z);
}

/**
 * our_realloc - Reallocates block of memory.
 * @ptr: Pointer to old block.
 * @old_size: Byte size of old block.
 * @new_size: Byte size of new block.
 *
 * Return: pointer to old block.
 */
void *our_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * our_calloc - Allocates memory for array.
 *
 * @nmb: Size of array.
 * @siz: Size of element.
 *
 * Return: Pointer of new allocated memory
 *         or NULL.
*/

void *our_calloc(unsigned int nmb, unsigned int siz)
{
	char *q;

	if (nmb == 0 || siz == 0)
		return (NULL);

	q = malloc(nmb * siz);
	if (q == NULL)
		return (NULL);

	our_memset(q, 0, nmb * siz);

	return (q);
}

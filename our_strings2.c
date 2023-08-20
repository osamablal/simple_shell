#include "shell.h"

/**
 * our_strcpy - Copies strings.
 * @y: Destination.
 * @x: Source.
 *
 * Return: A pointer to the destination.
 */
char *our_strcpy(char *y, char *x)
{
	int i = 0;

	if (y == x || x == 0)
		return (y);
	while (x[i])
	{
		y[i] = x[i];
		i++;
	}
	y[i] = 0;
	return (y);
}

/**
 * our_strcat - Concatenates two strings.
 * @y: Destination buffer.
 * @x: Source buffer.
 *
 * Return: A pointer to the destination buffer.
 */
char *our_strcat(char *y, const char *x)
{
	char *rt = y;

	while (*y)
		y++;
	while (*x)
		*y++ = *x++;
	*y = *x;
	return (rt);
}

/**
 * our_strdup - Duplicate string.
 * @st: String.
 *
 * Return: A pointer to the duplicate string.
 */
char *our_strdup(const char *st)
{
	int length = 0;
	char *rt;

	if (st == NULL)
		return (NULL);
	while (*st++)
		length++;
	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
		return (NULL);
	for (length++; length--;)
		rt[length] = *--st;
	return (rt);
}

/**
 *our_putchar - write character v to stdout.
 * @v: Printed character.
 * Return: 1 For success.
 * -1 for Error.
 */
int our_putchar(char v)
{
	return (write(1, &v, 1));
}

/**
 * our_strspn - Gets the length of prefix.
 *
 * @j: A pointer to string input.
 * @p: A substring prefix.
 *
 * Return: num of bytes.
 */
unsigned int our_strspn(char *j, char *p)
{
	unsigned int f, d;

	for (f = 0; j[f]; f++)
	{
		for (d = 0; p[d]; d++)
		{
			if (j[f] == p[d])
				break;
		}
		if (!p[d])
			return (f);
	}

	return (f);
}

#include "shell.h"

/**
 * our_strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *our_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * our_strdup - Duplicate the streng.
 * @stg: String.
 *
 * Return: Pointer to the string.
 */
char *our_strdup(const char *stg)
{
	int length = 0;
	char *rt;

	if (stg == NULL)
		return (NULL);
	while (*stg++)
		length++;
	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
		return (NULL);
	for (length++; length--;)
		rt[length] = *--stg;
	return (rt);
}

/**
 *_puts - Print Input String.
 *@stg: String.
 *
 * Return: Nothing
 */
void _puts(char *stg)
{
	int i = 0;

	if (!stg)
		return;
	while (stg[i] != '\0')
	{
		_putchar(stg[i]);
		i++;
	}
}

/**
 * _putchar - Send character chr to the (STDOUT).
 * @chr: Character.
 *
 * Return: In success 1,-1 in error.
 */
int _putchar(char chr)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buff[i++] = chr;
	return (1);
}

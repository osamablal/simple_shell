#include "shell.h"

/**
 **our_strncpy - Copy string.
 *@dest: Destination.
 *@src: Source.
 *@n: Num of characters.
 *Return: String
 */
char *our_strncpy(char *dest, char *src, int n)
{
	int i, l;
	char *m = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		l = i;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (m);
}

/**
 **our_strncat - Conctnates two strings.
 *@dest: First String.
 *@src: Secnd String.
 *@n: Num of Bytes.
 *Return: String.
 */
char *our_strncat(char *dest, char *src, int n)
{
	int i, l;
	char *m = dest;

	i = 0;
	l = 0;
	while (dest[i] != '\0')
		i++;
	while (src[l] != '\0' && l < n)
	{
		dest[i] = src[l];
		i++;
		l++;
	}
	if (j < n)
		dest[i] = '\0';
	return (m);
}

/**
 **our_strchr - Get location of character in string.
 *@stg: String.
 *@chr: Character.
 *Return: Pointer to memory area.
 */
char *our_strchr(char *stg, char chr)
{
	do {
		if (*stg == chr)
			return (stg);
	} while (*stg++ != '\0');

	return (NULL);
}


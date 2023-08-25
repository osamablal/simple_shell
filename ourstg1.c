#include "shell.h"

/**
 * our_strlen - Return string length.
 * @stg: String.
 *
 * Return: Length.
 */
int our_strlen(char *stg)
{
	int i = 0;

	if (!stg)
		return (0);

	while (*stg++)
		i++;
	return (i);
}

/**
 * our_strcmp - Make comparison bt two strangs.
 * @stg1: First string.
 * @stg2: Second string.
 *
 * Return: positive if stg1 > stg2, negative if stg1 < stg2, zero if equal.
 */
int our_strcmp(char *stg1, char *stg2)
{
	while (*stg1 && *stg2)
	{
		if (*stg1 != *stg2)
			return (*stg1 - *stg2);
		stg1++;
		stg2++;
	}
	if (*stg1 == *stg2)
		return (0);
	else
		return (*stg1 < *stg2 ? -1 : 1);
}

/**
 * our_starts - checks if needle starts with haystack
 * @haystack: String we search for.
 * @needle: Substring to be found.
 *
 * Return: address of next char of haystack or NULL
 */
char *our_starts(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * our_strcat - concatinate two strings
 * @dest: Destination bufer.
 * @src: Source bufer.
 *
 * Return: A pointer to dest.
 */
char *our_strcat(char *dest, char *src)
{
	char *rt = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rt);
}

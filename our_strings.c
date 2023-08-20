#include "shell.h"

/**
 * our_strlen - Returns length of string.
 * @st: string.
 *
 * Return: The integer length.
 */
int our_strlen(const char *st)
{
	int z = 0;

	if (!st)
		return (0);

	while (*st++)
		z++;
	return (z);
}

/**
 * our_strcmp - Compare two strings.
 * @st1: First string.
 * @st2: Second string.
 * Return: 0 when st1 and st2 equal,
 *         negative when st1 is smaller than st2,
 *         positive value when st1 is bigger than st2.
 */
int our_strcmp(const char *st1, const char *st2)
{
	while (*st1 != '\0' && *st2 != '\0' && *st1 == *st2)
	{
		st1++;
		st2++;
	}

	return ((int) (*st1) - (*st2));
}

/**
 * our_strncmp - Compare between two strings.
 * @st1: First string.
 * @st2: Second string.
 * @m: Maximum num of characters.
 *
 * Return: 0 when they equal each other, negative when st1 smaller than st2
 *          positive when st1 bigger than st2.
 */
int our_strncmp(const char *st1, const char *st2, size_t m)
{
	unsigned char r, s;

	while (m-- > 0)
	{
		r = (unsigned char) *st1++;
		s = (unsigned char) *st2++;

		if (r != s)
			return (r - s);
		if (r == '\0')
			break;
	}

	return (0);
}

/**
 * our_strstr - Know if needle start in haystack.
 * @stg: String for search - haystack.
 * @sstg: Substring to be found - needle.
 *
 * Return: location of character or NULL.
 */
char *our_strstr(char *stg, char *sstg)
{
	int t;

	for (t = 0; stg[t] != '\0'; t++)
	{
		if (stg[t] == sstg[0])
		{
			int x;

			for (x = 0; sstg[x] != '\0'; x++)
			{
				if (stg[t + x] != sstg[x])
				{
					break;
				}
			}

			if (sstg[x] == '\0')
			{
				return (&stg[t]);
			}
		}
	}
	return (NULL);
}

/**
 * our_strchr - get the location of character in string.
 *
 * @k: pointer to the string input.
 * @h: character to be located.
 *
 * Return: the first location of character or NULL.
*/

char *our_strchr(char *k, char h)
{
	while (*k != '\0')
	{
		if (*k == h)
			return (k);
		k++;
	}
	if (*k == h)
		return (k);
	return (NULL);
}

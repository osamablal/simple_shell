#include "shell.h"

/**
 *our_eputs - Print input stg.
 * @stg: String
 *
 * Return: Nothing
 */
void our_eputs(char *stg)
{
	int i = 0;

	if (!stg)
		return;
	while (stg[i] != '\0')
	{
		our_eputchar(stg[i]);
		i++;
	}
}

/**
 * our_eputchar - Write character c to stder.
 * @chr: Character.
 *
 * Return: On success 1, If error, -1.
 */
int our_eputchar(char chr)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buff[i++] = chr;
	return (1);
}

/**
 * our_putfd - Write character to a given fd.
 * @chr: Character.
 * @flr: File scriptor.
 *
 * Return: On success 1, If error, -1.
 */
int our_putfd(char chr, int flr)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(flr, buff, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buff[i++] = chr;
	return (1);
}

/**
 *our_putsfd - Print input stg.
 * @stg: String.
 * @flr: File scriptor.
 *
 * Return: Num of characters.
 */
int our_putsfd(char *stg, int flr)
{
	int i = 0;

	if (!stg)
		return (0);
	while (*stg)
	{
		i += our_putfd(*stg++, flr);
	}
	return (i);
}

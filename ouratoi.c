#include "shell.h"

/**
 * intrctv - Return 1 as shell in interactive.
 * @info: Structure placing.
 *
 * Return: 1 in interactive, 0 else.
 */
int intrctv(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isdlm - Check character if delimeter.
 * @chr: Character.
 * @dlm: Delimeter.
 * Return: 1 in true, 0 in false.
 */
int isdlm(char chr, char *dlm)
{
	while (*dlm)
		if (*dlm++ == chr)
			return (1);
	return (0);
}

/**
 * islph - Checks if alphabetic.
 *@chr: Character.
 *Return: 1 if alphabetic, 0 else.
 */

int islph(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - Convert string to integr.
 *@stg: String.
 *Return: 0 , Number else.
 */

int _atoi(char *stg)
{
	int i, sn = 1, fg = 0, output;
	unsigned int rst = 0;

	for (i = 0;  stg[i] != '\0' && fg != 2; i++)
	{
		if (stg[i] == '-')
			sn *= -1;

		if (stg[i] >= '0' && stg[i] <= '9')
		{
			fg = 1;
			rst *= 10;
			rst += (stg[i] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (sn == -1)
		output = -rst;
	else
		output = rst;

	return (output);
}


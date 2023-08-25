#include "shell.h"

/**
 * our_err - Convert string to integer.
 * @stg: String.
 * Return: 0 , number.
 */
int our_err(char *stg)
{
	int i = 0;
	unsigned long int rslt = 0;

	if (*stg == '+')
		stg++;
	for (i = 0;  stg[i] != '\0'; i++)
	{
		if (stg[i] >= '0' && stg[i] <= '9')
		{
			rslt *= 10;
			rslt += (stg[i] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * our_printerr - Print error.
 * @info: Parameter, return structure.
 * @stg: String.
 * Return: 0 , number.
 */
void our_printerr(info_t *info, char *stg)
{
	our_eputs(info->fname);
	our_eputs(": ");
	our_printd(info->line_count, STDERR_FILENO);
	our_eputs(": ");
	our_eputs(info->argv[0]);
	our_eputs(": ");
	our_eputs(stg);
}

/**
 * our_printd - Print integer number.
 * @input: Input.
 * @flr: File scripter.
 *
 * Return: number of characters printed
 */
int our_printd(int input, int flr)
{
	int (*__putchar)(char) = _putchar;
	int i, cont = 0;
	unsigned int _abs_, current;

	if (flr == STDERR_FILENO)
		__putchar = our_eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		cont++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			cont++;
		}
		current %= i;
	}
	__putchar('0' + current);
	cont++;

	return (cont);
}

/**
 * ourconvert_num - Convert functions.
 * @nm: Number.
 * @bas: Base.
 * @flag: Arg flags.
 *
 * Return: String
 */
char *ourconvert_num(long int nm, int bas, int flag)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *pntr;
	unsigned long n = nm;

	if (!(flag & CONVERT_UNSIGNED) && nm < 0)
	{
		n = -nm;
		sign = '-';

	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buffer[49];
	*pntr = '\0';

	do	{
		*--pntr = array[n % bas];
		n /= bas;
	} while (n != 0);

	if (sign)
		*--pntr = sign;
	return (pntr);
}

/**
 * ourfree_comments - Replace instnce of # with '\0'.
 * @buff: String adress.
 *
 * Return: Always 0;
 */
void ourfree_comments(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
}

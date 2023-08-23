#include "shell.h"

/**
 * pro - print prompt to the stdin.
 *
 * Return: void.
 */
void pro(void)
{
	our_puts(PROMPT);
	fflush(stdout);
}

/**
 * inrctive - Returns 1 if it's interactive mode.
 * @inf: Structure placing.
 *
 * Return: 1 if it's interactive mode, 0 else.
 */
int inrctive(char *inf)
{
	return (isatty(STDIN_FILENO) & inf->ourget_input <= 2);
}

/**
 * isdlim - Check character if is delimeter.
 * @chr: the char to check
 * @dlm: the delimeter string
 * Return: 1 if true, 0 if false
 */
int isdlim(char chr, char *dlm)
{
	while (*dlm)
		if (*dlm++ == chr)
			return (1);
	return (0);
}

/**
 * islph - Checks about any alphabet.
 * @chr: Character.
 * Return: 1 if @chr alphabetic, 0 else.
 */

int islph(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}


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

#include "shell.h"

/**
 * interactive - return 1 if shell in interactive.
 * @info: structure place.
 *
 * Return: 1 if in interactive, 0 else.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


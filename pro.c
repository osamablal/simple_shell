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


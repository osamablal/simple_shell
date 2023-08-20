#include "shell.h"

/**
 * ourhandle_sigint - the signal handler for Ctrl+C.
 * @sg: the signal number.
 *
 * Return: void.
 */
void ourhandle_sigint(int sg)
{
	(void) sg;
	our_putchar('\n');
	pro();
}

/**
 * ourhandle_sigquit - the signal handler for Ctrl+\.
 * @sg: the signal number.
 *
 * Return: void.
 */
void ourhandle_sigquit(int sg)
{
	(void) sg;
	our_puterror("Quit\n");
	exit(EXIT_SUCCESS);
}

/**
 * ourhandle_sigstp - the signal handler for Ctrl+Z.
 * @sg: the signal number.
 *
 * Return: void.
 */
void ourhandle_sigstp(int sg)
{
	(void) sg;
	our_puts("\n");
	pro();
}


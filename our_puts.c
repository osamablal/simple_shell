#include "shell.h"

/**
 * our_puts - Prints a string to stdm.
 * @st: String.
 *
 * Return: Void.
 */
void our_puts(char *st)
{
	size_t ln;
	ssize_t num;

	ln = our_strlen(st);
	num = write(STDOUT_FILENO, st, ln);
	if (num == -1)
	{
		perror("write");
	}
}

/**
 * our_puterror - Prints error message to stdm.
 * @erro: Error message.
 *
 * Return: Void
 */
void our_puterror(char *erro)
{
	size_t ln;
	ssize_t num;

	ln = our_strlen(erro);
	num = write(STDERR_FILENO, erro, ln);
	if (num == -1)
	{
		perror("write");
	}
}


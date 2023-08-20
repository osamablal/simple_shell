#include "shell.h"

/**
 * main - Acts the simple shell.
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *input;
	char **args;
	int status;

	signal(SIGINT, ourhandle_sigint);
	signal(SIGQUIT, ourhandle_sigquit);
	signal(SIGTSTP, ourhandle_sigstp);

	do {
		input = ourget_input();
		if (!input || !*input)
			break;

		args = our_tokenise(input);
		if (!args || !*args)
		{
			free(input);
			remove_tokens(args);
			continue;
		}
		status = execute(args);
		free(input);
		remove_tokens(args);

		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}


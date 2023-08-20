#include "shell.h"

static char *previous_input;
/**
 * ourget_input - Read the input written from the user.
 *
 * Return: Pointer to buffer having the input of user.
*/
char *ourget_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

	do {
		pro();

		nread = getline(&input, &input_size, stdin);

		if (nread == -1)
		{
			free(input);
			our_puts("\n");
			return (NULL);
		}

		input[nread - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	previous_input = input;
	return (input);
}

/**
 * remove_previous_input - removes last input given from user.
 */
void remove_previous_input(void)
{
	free(previous_input);
	previous_input = NULL;
}


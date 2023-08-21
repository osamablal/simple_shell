#include "shell.h"

/**
 * remove_error - Removes pointers after sys error
 * @arg: Point to a pointer to array of characters
 * @argv: Point to a pointer to array of pointers
 *
 * Return: void.
 */
void remove_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * remove_tokens - removes memory in tokenize()
 * @ptr: pointer to the allocated memory
 *
 * Return: void.
 */
void remove_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}


/**
 * remove_path - Removes variable having Path environment
 *              value.
 *
 * Return: NULL.
 */
void remove_path(void)
{
	if (environ[i] != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (our_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}

#include "shell.h"

/**
 * tokenise - Parse input to arguments by splitting array
 *            string to tokens using delimiter.
 * @st: String.
 * @del: Delimiter to split the string.
 *
 * Return: Array of pointers to tokens, or NULL.
 */
char **tokenise(char *st, const char *del)
{
	char *token = NULL;
	char **rt = NULL;
	int i = 0;

	token = strtok(st, del);
	while (token)
	{
		rt = realloc(rt, sizeof(char *) * (i + 1));
		if (rt == NULL)
			return (NULL);

		rt[i] = malloc(our_strlen(token) + 1);
		if (!(rt[i]))
			return (NULL);

		our_strcpy(rt[i], token);
		token = strtok(NULL, del);
		i++;
	}
	rt = realloc(rt, (i + 1) * sizeof(char *));
	if (!rt)
		return (NULL);

	rt[i] = NULL;
	return (rt);
}

/**
 * our_tokenise - Split string input to tokens.
 * @input: User string input.
 *
 * Return: Array of pointers to tokens, or NULL.
 */
char **our_tokenise(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = our_strdup(input);
	if (tmp == NULL)
	{
		our_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenise(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}

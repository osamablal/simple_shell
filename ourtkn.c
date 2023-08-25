#include "shell.h"

/**
 * **ourstrtow - split the string to words.
 * @stg: String.
 * @dlm: Delimeter.
 * Return: Pointer to array of strings, or Null.
 */

char **ourstrtow(char *stg, char *dlm)
{
	int i, e, f, g, numwords = 0;
	char **h;

	if (stg == NULL || stg[0] == 0)
		return (NULL);
	if (!dlm)
		dlm = " ";
	for (i = 0; stg[i] != '\0'; i++)
		if (!isdlm(stg[i], dlm) && (isdlm(stg[i + 1], dlm) || !stg[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	h = malloc((1 + numwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (i = 0, e = 0; e < numwords; e++)
	{
		while (isdlm(stg[i], dlm))
			i++;
		f = 0;
		while (!isdlm(stg[i + f], dlm) && stg[i + f])
			k++;
		h[j] = malloc((f + 1) * sizeof(char));
		if (!h[e])
		{
			for (f = 0; f < e; f++)
				free(h[f]);
			free(h);
			return (NULL);
		}
		for (g = 0; g < f; g++)
			h[e][g] = stg[i++];
		h[e][g] = 0;
	}
	h[e] = NULL;
	return (h);
}

/**
 * **ourstrtow2 - Split string to words.
 * @stg: String.
 * @dlm: Delimeter.
 * Return: Pointer to array of strings, or NUL.
 */
char **ourstrtow2(char *stg, char dlm)
{
	int i, e, f, g, numwords = 0;
	char **h;

	if (stg == NULL || stg[0] == 0)
		return (NULL);
	for (i = 0; stg[i] != '\0'; i++)
		if ((stg[i] != dlm && stg[i + 1] == dlm) ||
		    (stg[i] != dlm && !stg[i + 1]) || stg[i + 1] == dlm)
			numwords++;
	if (numwords == 0)
		return (NULL);
	h = malloc((1 + numwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (i = 0, e = 0; e < numwords; e++)
	{
		while (stg[i] == dlm && stg[i] != dlm)
			i++;
		f = 0;
		while (stg[i + f] != dlm && stg[i + f] && stg[i + f] != dlm)
			f++;
		h[e] = malloc((f + 1) * sizeof(char));
		if (!h[e])
		{
			for (f = 0; f < e; f++)
				free(h[f]);
			free(h);
			return (NULL);
		}
		for (g = 0; g < f; g++)
			h[e][g] = stg[i++];
		h[e][g] = 0;
	}
	h[e] = NULL;
	return (h);
}


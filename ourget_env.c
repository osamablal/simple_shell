#include "shell.h"

/**
 * _ourgetenv - Getting the value of the environment variable.
 * @nam: Name of environment variable.
 *
 * Return: Value of environment variable, or NULL.
 */
char *_ourgetenv(const char *nam)
{
	char **env;
	size_t nam_len = our_strlen(nam);

	for (env = environ; *env != NULL; env++)
	{
		if (our_strncmp(*env, nam, nam_len) == 0 && (*env)[nam_len] == '=')
		{
			return (&(*env)[nam_len + 1]);
		}
	}

	return (NULL);
}


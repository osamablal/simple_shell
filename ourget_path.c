#include "shell.h"

/**
 * ourget_path - Returns value of Path environment variable.
 *
 * Return: Pointer to the value of $.
 */
char *ourget_path(void)
{
	return (_ourgetenv("PATH"));
}

/**
 * ourfind_path - search for command in each directory in Path
 *                environment variable.
 * @cmd: Pointer to command.
 *
 * Return: A pointer to string having the path if found,
 *         or NULL, if not found.
*/
char *ourfind_path(char *cmd)
{
	struct stat st;
	int stat_rt, i;
	char buf[PATH_MAX_LENGTH], *path, *rt, **dir;

	path = ourget_path();
	if (!path)
		return (NULL);
	dir = tokenise(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		our_memset(buf, 0, PATH_MAX_LENGTH);
		our_strcpy(buf, dir[i]);
		our_strcat(buf, "/");
		our_strcat(buf, cmd);
		stat_rt = stat(buf, &st);
		if (stat_rt == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			remove_tokens(dir);
			rt = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!rt)
				return (NULL);
			strcpy(rt, buf);
			return (rt);
		}
	}
	if (stat_rt == -1)
		remove_tokens(dir);
	return (NULL);
}


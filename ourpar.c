#include "shell.h"

/**
 * ouris_cmd - Knows if it's executable command.
 * @info: Info Structure.
 * @pat: Path.
 *
 * Return: 1, 0 else.
 */
int ouris_cmd(info_t *info, char *pat)
{
	struct stat st;

	(void)info;
	if (!pat || stat(pat, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * ourdup_chars - duplicate the charcter.
 * @pathstg: PATH String.
 * @start: Start Index.
 * @stop: Stop Index.
 *
 * Return: New buffer index.
 */
char *ourdup_chars(char *pathstg, int start, int stop)
{
	static char buff[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstg[i] != ':')
			buff[k++] = pathstg[i];
	buff[k] = 0;
	return (buff);
}

/**
 * ourfind_path - Find cmd in PATH String.
 * @info: Info structuree.
 * @pathstg: PATH String.
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *ourfind_path(info_t *info, char *pathstg, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstg)
		return (NULL);
	if ((our_strlen(cmd) > 2) && our_starts(cmd, "./"))
	{
		if (ouris_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstg[i] || pathstg[i] == ':')
		{
			path = ourdup_chars(pathstg, curr_pos, i);
			if (!*path)
				our_strcat(path, cmd);
			else
			{
				our_strcat(path, "/");
				our_strcat(path, cmd);
			}
			if (ouris_cmd(info, path))
				return (path);
			if (!pathstg[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * our_pfree - Free pointr.
 * @pntr: Pointer Adress.
 *
 * Return: 1 , else 0.
 */
int our_pfree(void **pntr)
{
	if (pntr && *pntr)
	{
		free(*pntr);
		*pntr = NULL;
		return (1);
	}
	return (0);
}

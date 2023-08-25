#include "shell.h"

/**
 * ourget_hisfile - Getting history file.
 * @info: Parameter Structure.
 *
 * Return: String.
 */

char *ourget_hisfile(info_t *info)
{
	char *buff, *dir;

	dir = our_getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buff = malloc(sizeof(char) * (our_strlen(dir) + our_strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	our_strcpy(buff, dir);
	our_strcat(buff, "/");
	our_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * ourwrithis - create file, append exist file.
 * @info: Parameter structuree.
 *
 * Return: 1, -1.
 */
int ourwrithis(info_t *info)
{
	ssize_t flr;
	char *filename = ourget_hisfile(info);
	list_t *nod = NULL;

	if (!filename)
		return (-1);

	flr = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (flr == -1)
		return (-1);
	for (nod = info->history; nod; nod = nod->next)
	{
		_putsfd(nod->stg, flr);
		_putfd('\n', flr);
	}
	_putfd(BUF_FLUSH, flr);
	close(flr);
	return (1);
}

/**
 * ourredhis - Reads history.
 * @info: Parameter Structuree.
 *
 * Return: history counting.
 */
int ourredhis(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t flr, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *filename = ourget_hisfile(info);

	if (!filename)
		return (0);

	flr = open(filename, O_RDONLY);
	free(filename);
	if (flr == -1)
		return (0);
	if (!fstat(flr, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdlen = read(flr, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);
	close(flr);
	for (i = 0; i < fsize; i++)
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			our_bldhislst(info, buff + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		our_bldhislst(info, buff + last, linecount++);
	free(buff);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		ourdelete_node(&(info->history), 0);
	our_numhis(info);
	return (info->histcount);
}

/**
 * our_bldhislst - Give entry to histry linked list.
 * @info: Structure with args.
 * @buff: Buffer.
 * @linecount: the histcount.
 *
 * Return: 0.
 */
int our_bldhislst(info_t *info, char *buff, int linecount)
{
	list_t *nod = NULL;

	if (info->history)
		nod = info->history;
	ouradd_nodeend(&nod, buff, linecount);

	if (!info->history)
		info->history = nod;
	return (0);
}

/**
 * our_numhis - Renumber the history linked list.
 * @info: Structure with args.
 *
 * Return: new hstcount.
 */
int our_numhis(info_t *info)
{
	list_t *nod = info->history;
	int i = 0;

	while (nod)
	{
		nod->num = i++;
		nod = nod->next;
	}
	return (info->histcount = i);
}

#include "shell.h"

/**
 * input_buff - buffer commands.
 * @info: parameter structuree.
 * @buff: Buffer addres.
 * @len: Addres of var.
 *
 * Return: Bytes.
 */
ssize_t input_buff(info_t *info, char **buff, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, oursign_Handler);
#if USE_GETLINE
		r = getline(buff, &len_p, stdin);
#else
		r = _getline(info, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			ourfree_comments(*buff);
			our_bldhislst(info, *buff, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buff;
			}
		}
	}
	return (r);
}

/**
 * our_getinput - Get a line.
 * @info: parmeter structuree.
 *
 * Return: Bytes.
 */
ssize_t our_getinput(info_t *info)
{
	static char *buff;
	static size_t i, k, len;
	ssize_t r = 0;
	char **buff_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buff(info, &buff, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		k = i;
		p = buff + i;

		ourcheck_chain(info, buff, &k, i, len);
		while (k < len)
		{
			if (ouris_chain(info, buff, &k))
				break;
			k++;
		}

		i = k + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_p = p;
		return (our_strlen(p));
	}

	*buff_p = buff;
	return (r);
}

/**
 * read_buf - Read Buffer.
 * @info: Parameter structuree.
 * @buff: Buffer.
 * @is: Size.
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buff, size_t *is)
{
	ssize_t r = 0;

	if (*is)
		return (0);
	r = read(info->readfd, buff, READ_BUF_SIZE);
	if (r >= 0)
		*is = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @leng: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *leng)
{
	static char buff[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && leng)
		s = *leng;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = our_strchr(buff + i, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : len;
	new_p = our_realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		our_strncat(new_p, buff + i, k - i);
	else
		our_strncpy(new_p, buff + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (leng)
		*leng = s;
	*ptr = p;
	return (s);
}

/**
 * oursign_Handler - Blocking ctrl C.
 * @sig_nm: Signal num.
 *
 * Return: void
 */
void oursign_Handler(__attribute__((unused))int sig_nm)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}


#include "shell.h"

/**
 * ouris_chain - Know if character is chain delimeter or no.
 * @info: Parameter Stracture.
 * @buff: Buffer.
 * @p: Position.
 *
 * Return: 1, 0 else.
 */
int ouris_chain(info_t *info, char *buff, size_t *p)
{
	size_t s = *p;

	if (buff[s] == '|' && buff[s + 1] == '|')
	{
		buff[s] = 0;
		s++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buff[s] == '&' && buff[s + 1] == '&')
	{
		buff[s] = 0;
		s++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buff[s] == ';')
	{
		buff[s] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = s;
	return (1);
}

/**
 * ourcheck_chain - Check Chaining.
 * @info: Parameter Struature.
 * @buff: Buffer.
 * @p: Position.
 * @r: Start pos.
 * @ln: Length of the buffer.
 *
 * Return: Void
 */
void ourcheck_chain(info_t *info, char *buff, size_t *p, size_t r, size_t ln)
{
	size_t s = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buff[r] = 0;
			s = ln;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[r] = 0;
			s = ln;
		}
	}

	*p = s;
}

/**
 * ourreplace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int ourreplace_alias(info_t *info)
{
	int i;
	list_t *nod;
	char *p;

	for (i = 0; i < 10; i++)
	{
		nod = ournode_start(info->alias, info->argv[0], '=');
		if (!nod)
			return (0);
		free(info->argv[0]);
		p = our_strchr(nod->stg, '=');
		if (!p)
			return (0);
		p = our_strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * ourreplace_vars - replace the vars in tokenised streng.
 * @info: Parameter Structure.
 *
 * Return: 1, 0 else.
 */
int ourreplace_vars(info_t *info)
{
	int i = 0;
	list_t *nod;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!our_strcmp(info->argv[i], "$?"))
		{
			ourreplace_string(&(info->argv[i]),
				our_strdup(ourconvert_num(info->status, 10, 0)));
			continue;
		}
		if (!our_strcmp(info->argv[i], "$$"))
		{
			ourreplace_string(&(info->argv[i]),
				our_strdup(ourconvert_num(getpid(), 10, 0)));
			continue;
		}
		nod = ournode_start(info->env, &info->argv[i][1], '=');
		if (nod)
		{
			ourreplace_string(&(info->argv[i]),
				our_strdup(our_strchr(nod->stg, '=') + 1));
			continue;
		}
		ourreplace_string(&info->argv[i], our_strdup(""));

	}
	return (0);
}

/**
 * ourreplace_string - Replace Strings.
 * @o: Old string.
 * @n: New string.
 *
 * Return: 1, 0 else.
 */
int ourreplace_string(char **o, char *n)
{
	free(*o);
	*o = n;
	return (1);
}


#include "shell.h"

/**
 * main - Point of Entry of Shell.
 * @c: Count.
 * @v: Vector.
 *
 * Return: 0 on success, 1 on error
 */
int main(int c, char **v)
{
	info_t info[] = { INFO_INIT };
	int flr = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (flr)
		: "r" (flr));

	if (c == 2)
	{
		flr = open(v[1], O_RDONLY);
		if (flr == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				our_eputs(v[0]);
				our_eputs(": 0: Can Not open ");
				our_eputs(v[1]);
				our_eputchar('\n');
				our_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = flr;
	}
	our_envlist(info);
	ourredhis(info);
	hsh(info, v);
	return (EXIT_SUCCESS);
}


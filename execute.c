#include "shell.h"

/**
 * execute - Execute commands comming with arguments.
 * @argv: Array of command and arguments.
 *
 * Return: Exit status.
 */
int execute(char **argv)
{
	pid_t id;
	int status = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (status);
	if (our_check(argv))
		return (status);

	id = fork();
	if (id < 0)
	{
		our_puterror("fork");
		return (1);
	}
	if (id == -1)
		perror(argv[0]), remove_tokens(argv), remove_previous_input();
	if (id == 0)
	{
		envp[0] = ourget_path();
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = ourfind_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]), remove_tokens(argv), remove_previous_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}


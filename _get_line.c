#include "shell.h"

/**
 * get_line - Read the input from standard input.
 *
 * Return: String givn from user.
*/
void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buff_pos, buff_size;
	char *input_str = NULL;
	char current_char;
	int input_len = 0;

	while (1)
	{
		if (buff_pos >= buff_size)
		{
			buff_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buff_pos = 0;
			if (buff_size == 0)
				return (input_str);
			else if (buff_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buff_pos];

		buff_pos++;

		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = current_char;
			input_len++;
		}
	}
}


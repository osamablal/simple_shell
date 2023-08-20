#include "shell.h"

/**
 * our_help - shows help information of builtins.
 */
void our_help(void)
{
	our_puts("\nShell Version 1.0.0\n\n");
	our_puts("Usage: ./hsh\n\n");
	our_puts("Shell builtin commands:\n\n");
	our_puts("help\t\tDisplay help information\n\n");
	our_puts("cd [dir]\tChange current working directory\n\n");
	our_puts("env\t\tDisplay environment variables\n\n");
	our_puts("setenv\t\tSet environment variable\n\n");
	our_puts("unsetenv\tUnset environment variable\n\n");
	our_puts("exit\t\tExit shell\n\n");
}

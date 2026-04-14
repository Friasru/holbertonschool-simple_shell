#include "shell.h"

/**
 * main - entry point for the simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *line;
	char **args;
	int count;

	count = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		prompt();

		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		count++;
		args = split_line(line);
		if (args && args[0])
			execute(args, argv[0], count);

			free(line);
			free_args(args);
	}
	return (0);
}

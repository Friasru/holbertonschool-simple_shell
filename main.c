#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *line;
	char *trimmed;
	char **args;
	pid_t pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		trimmed = trim(line);

		if (trimmed[0] == '\0')
		{
			free(line);
			continue;
		}

		args = split_line(trimmed);
		if (args == NULL || args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
				free(line);
				free(args);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}

		free(line);
		free(args);
	}

	return (0);
}

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
	char *args[2];
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

		if (line[0] == '\0')
		{
			free(line);
			continue;
		}

		args[0] = line;
		args[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execve(line, args, environ) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
				free(line);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}

		free(line);
	}

	return (0);
}
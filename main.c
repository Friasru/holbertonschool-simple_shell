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
	char *path;
	pid_t pid;
	int status;
	int count;

	count = 0;
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

		count++;
		args = split_line(trimmed);
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			free(line);
			continue;
		}

		path = find_path(args[0]);
		if (path == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], count, args[0]);
			free(args);
			free(line);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(path, args, environ) == -1)
			{
				fprintf(stderr, "%s: %d: %s: not found\n",
					argv[0], count, args[0]);
				if (path != args[0])
					free(path);
				free(args);
				free(line);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}

		if (path != args[0])
			free(path);
			free(args);
		free(line);
	}

	return (0);
}

#include "shell.h"

/**
 * print_error - Prints an error message to stderr
 * @argv0: Name of the shell program
 * @count: Command count
 * @cmd: The command that was not found
 */
void print_error(char *argv0, int count, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", argv0, count, cmd);
}

/**
 * execute - Forks and executes a command
 * @args: Array of arguments
 * @argv0: Name of the shell program
 * @count: Command count
 *
 * Return: 1 to continue, 0 to exit
 */
int execute(char **args, char *argv0, int count)
{
	pid_t pid;
	int status;
	char *path;

	if (strcmp(args[0], "exit") == 0)
		exit(0);

	path = find_path(args[0]);
	if (path == NULL)
	{
		print_error(argv0, count, args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			print_error(argv0, count, args[0]);
			free(path);
			exit(1);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}

	if (path != args[0])
		free(path);

	return (1);
}
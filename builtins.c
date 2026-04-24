#include "shell.h"

/**
 * handle_exit - Handles the exit builtin command
 * @args: Array of arguments
 * @line: The line to free before exiting
 * @path: The path to free before exiting
 *
 * Return: 1 if not exit command, no return if exit
 */
int handle_exit(char **args, char *line, char *path)
{
	if (strcmp(args[0], "exit") == 0)
	{
		if (path != NULL && path != args[0])
			free(path);
		free(args);
		free(line);
		exit(0);
	}
	return (1);
}

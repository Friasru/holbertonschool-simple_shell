#include "shell.h"

/**
 * find_path - Finds the full path of a command
 * @cmd: The command to find
 *
 * Return: Full path string or NULL if not found
 */
char *find_path(char *cmd)
{
	char *path_env;
	char *path_copy;
	char *token;
	char *full_path;
	struct stat st;
	int len;

	if (stat(cmd, &st) == 0)
		return (cmd);

	path_env = getenv("PATH");
	if (path_env == NULL || *path_env == '\0')
		return (NULL);

	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

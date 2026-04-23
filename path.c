#include "shell.h"

/**
 * get_env_value - Gets the value of an environment variable
 * @name: The name of the variable to find
 *
 * Return: The value string or NULL if not found
 */
char *get_env_value(const char *name)
{
	int i;
	int len;

	len = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 &&
			environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

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

	path_env = get_env_value("PATH");
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

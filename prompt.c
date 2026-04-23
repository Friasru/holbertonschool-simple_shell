#include "shell.h"

/**
 * prompt - prints the shell prompt
 */
void prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_line - reads a line from stdin
 *
 * Return: pointer the line read, or NULL onf EDF
 */
char *read_line(void)
{
	char *line;
	size_t len;
	ssize_t read;

	line = NULL;
	len = 0;
	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	line[read - 1] = '\0';
	return (line);
}

/**
 * free_args - Frees a null-terminated array of strings
 * @args: The array to be free
 */
void free_args(char **args)
{
	if (args)
	free(args);
}

/**
 * trim - Removes leading and trailing whitespace from a string
 * @str: The string to trim
 *
 * Return: Pointer to the trimmed string
 */
char *trim(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;

	*(end + 1) = '\0';

	return (str);
}

#include "shell.h"

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * split_line - splits a line into tokens
 * @line: the line to split
 *
 * Return: NULL-terminated array of tokens
 */
char **split_line(char *line)
{
	int bufsize;
	int i;
	char **tokens;
	char *token;

	bufsize = TOK_BUFSIZE;
	i = 0;

	tokens = malloc(bufsize * sizeof(char *));
	if (token == NULL)
		return (NULL);

	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			return (NULL);
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

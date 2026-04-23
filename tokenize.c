#include "shell.h"

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * split_line - Splits a line into tokens
 * @line: The line to split
 *
 * Return: Null-terminated array of tokens, or NULL on failure
 */
char **split_line(char *line)
{
	int bufsize;
	int i;
	char **tokens;
	char **tmp;
	char *token;

	bufsize = TOK_BUFSIZE;
	i = 0;
	token = NULL;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tmp = realloc(tokens, bufsize * sizeof(char *));
			if (tmp == NULL)
			{
				free(tokens);
				return (NULL);
			}
			tokens = tmp;
		}
		token = strtok(NULL, TOK_DELIM);
	}

	tokens[i] = NULL;
	return (tokens);
}

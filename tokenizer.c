#include "main.h"
/**
 * tokenizer -function tokenizes user input
 * @line: untokenized user input
 * @argv: array of args
 * @count: total number of iteration
 * Return: 0(success)
 */
int tokenizer(char *line, char **argv, int count)
{

	char *line_cpy, *delim = " \t\n", **tokens, *token;
	int tkn_len = 0, i = 0, value;

	line_cpy = strdup(line);
	token = strtok(line_cpy, delim);
	while (token)
	{
	tkn_len++;
	token = strtok(NULL, delim);
	}
	free(line_cpy);
	if (tkn_len == 0)
	return (0);
	tokens = malloc((tkn_len + 2) * sizeof(char *));
	token = strtok(line, delim);
	while (token)
	{
	tokens[i] = malloc(strlen(token) + 1);
	tokens[i] = strcpy(tokens[i], token);
	token = strtok(NULL, delim);
	i++;
	}
	tokens[i] = NULL;
	value = builtin(tokens, line, argv, count);
	if (value == 1)
	value = execute_command(tokens, argv, line, count);

	for (i = 0; tokens[i]; i++)
	free(tokens[i]);
	free(tokens);
	return (value);
}

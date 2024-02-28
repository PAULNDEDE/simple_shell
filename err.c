#include "main.h"
/**
 * err - writes error message to STDOUT
 * @tokens: tokenized user input
 * @argv: argument vector
 * @count: loop itteration number
 * Return: Nothing
 */
void err(char **tokens, char **argv, int count)
{
	int i = 0;

	write(STDOUT_FILENO, argv[0], strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	printer(count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens[0], strlen(tokens[0]));
	write(STDOUT_FILENO, ": not found", 11);
	write(STDOUT_FILENO, "\n", 1);
	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}

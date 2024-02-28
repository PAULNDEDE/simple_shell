#include "main.h"
/**
 * err1 - writes error message to STDOUT
 * @tokens: tokenized user input
 * @argv: argument vector
 * @count: loop itteration number
 * Return: Nothing
 */
void err1(char **tokens, char **argv, int count)
{
	write(STDOUT_FILENO, argv[0], strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	printer(count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens[0], strlen(tokens[0]));
	write(STDOUT_FILENO, ": not found", 11);
	write(STDOUT_FILENO, "\n", 1);
}

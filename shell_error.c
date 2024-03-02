#include "main.h"
/**
 * shell_error -function writes error message to STDOUT
 * @tkns: useer input (tokenized)
 * @argv: array of args
 * @count:total loop iteration
 * Return: Nothing
 */
void shell_error(char **tkns, char **argv, int count)
{
	write(STDOUT_FILENO, argv[0], strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	printer(count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tkns[0], strlen(tkns[0]));
	write(STDOUT_FILENO, ": not found", 11);
	write(STDOUT_FILENO, "\n", 1);
}

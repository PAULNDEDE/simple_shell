#include "main.h"
/**
 * exit_err - writes error message to STDOUT
 * @tokens: tokenized user input
 * @argv: argument vector
 * @count: input value
 * Return: Nothing
 */
void exit_err(char **tokens, char **argv, int count)
{
	write(STDOUT_FILENO, argv[0], strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	printer(count);
	write(STDOUT_FILENO, ":", 1);
	write(STDOUT_FILENO, tokens[0], strlen(tokens[0]));
	write(STDOUT_FILENO, ": illegal number: ", 18);
	write(STDOUT_FILENO, tokens[1], strlen(tokens[1]));
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * put_char - prints a character
 * @n: character to print
 * Return: 0 on success
 */
int put_char(char n)
{
	return (write(1, &n, 1));
}
/**
 * printer - prints a number
 * @value: number to print
 * Return: 0 on success
 */
int printer(int value)
{
	if (value < 0)
	{
		put_char('-');
		value = value * -1;
	}
	if (value > 9)
		printer(value / 10);
	put_char(value % 10 + '0');
	return (0);
}

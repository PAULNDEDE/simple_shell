#include "main.h"

/**
 * exit_error - prints an error message to STDOUT
 * @tokens: user input(tokenized)
 * @argv: array of args
 * @count:user input value
 * Return: Nothing
 */
void exit_error(char **tokens, char **argv, int count)
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
 * put_character - outputs a character
 * @ch: character to be printed
 * Return: 0 (success)
 */
int put_character(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * print_number -function  prints a number
 * @value: number to be printed
 * Return: 0(sucess)
 */
int print_number(int value)
{
	if (value < 0)
	{
		put_character('-');
		value = value * -1;
	}
	if (value > 9)
		print_number(value / 10);
	put_character(value % 10 + '0');
	return (0);
}

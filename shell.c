#include "main.h"

/**
 * main - Entry point of the Program
 * @argc: Arguments
 * @argv: Array of Arguments
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	int counter = 0;
	ssize_t index = 0;
	size_t size = 0;
	char *buffer = NULL;

	if (argc < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		counter++;
		buffer = NULL;
		signal(SIGINT, control_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		index = getline(&buffer, &size, stdin);
		if (index == -1)
		{
			free(buffer);
			exit(0);
		}
		if (buffer[0] != '\n')
		{
			if (buffer[0] != '#')
			{
				buffer = handle_hash(buffer);
				tokenizer(buffer, argv, counter);
			}
			free(buffer);
		}
		else
			free(buffer);
	}
	return (0);
}

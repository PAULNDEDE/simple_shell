#include "main.h"

/**
 * main -the entry point of the program
 * @argc: arguments count
 * @argv: an array of arguments
 * Return:ALways 0(success)
 *
 */
int main(int argc, char **argv)
{
	int command_count = 0;
	ssize_t line_length = 0;
	size_t buffer_size = 0;
	char *input_buffer = NULL;

	if (argc < 0)
	exit(EXIT_FAILURE);
	while (1)
	{
	command_count++;
	input_buffer = NULL;
	handle_signl(SIGINT);
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	line_length = getline(&input_buffer, &buffer_size, stdin);
	if (line_length == -1)
	{
	free(input_buffer);
	exit(0);
	}
	if (input_buffer[0] != '\n')
	{
	if (input_buffer[0] != '#')
	{
	input_buffer = hash_handler(input_buffer);
	tokenizer(input_buffer, argv, command_count);
	}
	free(input_buffer);
	}
	else
	free(input_buffer);
	}
	return (0);
}

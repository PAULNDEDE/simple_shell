#include "main.h"

/**
 * execute_command - function executes non-built-in commands using execve
 * @tokens: user input(tokenized)
 * @argv:array of  arguments
 * @input: user input(untokenized)
 * @count: total loop iteration
 * Return: 0 (success)
 */
int execute_command(char **tokens, char **argv, char *input, int count)
{
	pid_t pid;
	int value = 0, status;
	char *command;
	struct stat st;

	pid = fork();
	if (pid == -1)
	{
	perror("fork");
	return (127);
	}
	if (pid == 0)
	{
	if (stat(tokens[0], &st) == 0)
	{
	value = execve(tokens[0], tokens, environ);
	if (value == -1)
	perror("Execve");
	}
	else
	{
	command = search_executable(tokens[0]);
	if (command == NULL)
	{
	print_error(tokens, argv, count);
	free(input);
	exit(0);
	}
	else
	{
	value = execve(command, tokens, environ);
	if (value == -1)
	perror("Execve");
	}
	}
	}
	else
	wait(&status);
	return (0);
}

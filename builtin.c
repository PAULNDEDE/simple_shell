#include "main.h"
/**
 * builtin - handles custom shell builtins
 * @tks: tokenized user input
 * @tk: user input untokenized
 * @argv: argument vector
 * @count: loop iteration number
 * Return: 0 on builtin
 * -1 on non builtin
 */
int builtin(char **tks, char *tk, char **argv, int count)
{
	pid_t pid;
	int return_value = 1, value = 0;

	if (strcmp(tks[0], "cd") == 0)
	{
	return_value = cd(tks);
	if (return_value == -1)
	shell_error(tks, argv, count);
	}
	if (strcmp(tks[0], "env") == 0)
	{
	shell_environ();
	return_value = (0);
	}
	if (strcmp(tks[0], "exit") == 0)
	{
	if (tks[1] == NULL)
	{
	shell_exit(tks, tk);
	return_value = (0);
	}
	else
	{
	value = atoi(tks[1]);
	if (value == -1)
	exit_error(tks, argv, count);

	else
	shell_exit(tks, tk/*, argv, count*/);
	return_value = (0);
	}
	}

	/*a code to handle the echo command*/
	if (strcmp(tks[0], "echo") == 0 && strcmp(tks[1], "$$") == 0)
	{
	pid = getpid();
	printer(pid);
	write(STDOUT_FILENO, "\n", 1);
	return_value = 0;
	}
	return (return_value);
}

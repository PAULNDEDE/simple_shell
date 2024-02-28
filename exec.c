#include "main.h"
/**
 * exec_fxn - execve non builtins
 * @toks: tokenized user input
 * @argv: argument vector
 * @tk: untokenized user input
 * @count: loop iteration number
 * Return: 0 on success
 */
int exec_fxn(char **toks, char **argv, char *tk, int count)
{
	pid_t pid;
	int value = 0, status;
	char *cmd;
	struct stat st;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (127);
	}
	if (pid == 0)
	{
		if (stat(toks[0], &st) == 0)
		{
			value = execve(toks[0], toks, environ);
			if (value == -1)
				perror("Execve");
		}
		else
		{
			cmd = find_path(toks[0]);
			if (cmd == NULL)
			{
				err(toks, argv, count);
				free(tk);/*potential problem*/
				exit(0);
			}
			else
			{
				value = execve(cmd, toks, environ);
				if (value == -1)
					perror("Execve");
			}
		}
	}
	else
		wait(&status);
	return (0);
}

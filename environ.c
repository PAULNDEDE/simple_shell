#include "main.h"

/**
 * prnt_env - prints environmental variables
 * @envp: array of environmental variables
 * Return: Nothing
 */
void prnt_env(char **envp)
{
	int i = 0;

	while (envp[i] != NULL)
	{
	write(STDOUT_FILENO, envp[i], strlen(envp[i]));
	write(STDOUT_FILENO, "\n", 1);
	i++;
	}
}

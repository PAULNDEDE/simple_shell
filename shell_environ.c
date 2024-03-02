#include "main.h"
/**
 * shell_environ -function prints the shell environment variables
 * Return: Nothing
 */
void shell_environ(void)
{
	int a = 0;

	for (a = 0; environ[a]; a++)
	{
	write(STDOUT_FILENO, environ[a], strlen(environ[a]));
	write(STDOUT_FILENO, "\n", 1);
	}
}

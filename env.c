#include "main.h"
/**
 * env_fxn - prints environmental variables
 * Return: Nothing
 */
void env_fxn(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

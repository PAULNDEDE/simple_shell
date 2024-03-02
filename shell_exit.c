#include "main.h"
/**
 * shell_exit -function exits shell
 * @token: user input (tokenized)
 * @utk: untokenized user input
 * Return: Nothing
 */
void shell_exit(char **token, char *utk)
{
	int exit_value = 0, a = 0;

	if (token[1] != NULL)
		exit_value = atoi(token[1]);

	free(utk);
	for (a = 0; token[a]; a++)
		free(token[a]);
	free(token);
	exit(exit_value);
}

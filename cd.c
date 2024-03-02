#include "main.h"
/**
 * cd - changes directory
 * @tokens: tokenized user input
 * Return: 0 on suucees
 * -1 on err an errno set appropriately
 */
int cd(char **tokens)
{
	char *home = getenv("HOME");
	int return_value = 0;

	if (strcmp(tokens[1], ".") == 0)
		;
	else if (strcmp(tokens[1], "~") == 0 || (tokens[1] == NULL))
	{
		return_value = chdir(home);
		if (return_value == -1)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{
		return_value = chdir(tokens[1]);
		if (return_value == -1)
			return (-1);
	}
	return (return_value);
}


#include "main.h"
/**
 * cd_fxn - changes directory
 * @tokens: tokenized user input
 * Return: 0 on suucees
 * -1 on err an errno set appropriately
 */
int cd_fxn(char **tokens)
{
	char *home = getenv("HOME");
	int r_val = 0;

	if (strcmp(tokens[1], ".") == 0)
		;
	else if (strcmp(tokens[1], "~") == 0 || (tokens[1] == NULL))
	{
		r_val = chdir(home);
		if (r_val == -1)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{
		r_val = chdir(tokens[1]);
		if (r_val == -1)
			return (-1);
	}
	return (r_val);
}

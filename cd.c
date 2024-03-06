#include "main.h"

/**
 * cd - Function changes directory
 * @tokens: user input arguments
 * Return: Always 0 (success), else -1 on error
 */
int cd(char **tokens)
{
	char cwd[1024];
	char *home_dir = getenv("HOME");
	char *prev_dir = getenv("PWD");
	char *new_dir;
	int return_value = 0;

 
	if (tokens[1] == NULL || strcmp(tokens[1], "~") == 0)
	{
	new_dir = home_dir;
	}
	else if
	(strcmp(tokens[1], "-") == 0)
	{
	if (prev_dir == NULL)
	{
	fprintf(stderr, "cd: OLDPWD not set\n");
	return (-1);
	}
	new_dir = prev_dir;
	}
	else
	{
	new_dir = tokens[1];
	}


	(return_value = chdir(new_dir));
	if (return_value == -1)
	{
	perror("cd");
	return (-1);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
	perror("getcwd");
	return (-1);
	}
	if (setenv("PWD", cwd, 1) == -1)
	{
	perror("setenv");
	return (-1);
	}
	if (setenv("OLDPWD", prev_dir != NULL ? prev_dir : "", 1) == -1)
	{
	perror("setenv");
	return (-1);
	}

	return (0);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * cd - Function changes directory
 * @args: user input arguments
 * Return: Always 0 (success), else -1 on error
 */
	int cd(char **tokens)
	{
	char *home_dir = getenv("HOME");
	char *prev_dir = getenv("PWD");
	int return_value = 0;

	char cwd[1024];

	if (!tokens[1] || strcmp(tokens[1], "~") == 0)
	{
	(return_value = chdir(home_dir));
	}
	else if (strcmp(tokens[1], "-") == 0)
	{
	if (!prev_dir)
	{
	fprintf(stderr, "cd: OLDPWD not set\n");
	return (-1);
	}
	(return_value = chdir(prev_dir));
	}
	else
	{
	(return_value = chdir(tokens[1]));
	}

	if (return_value == -1)
	{
	perror("cd");
	return (-1);
	}


	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
	setenv("PWD", cwd, 1);
	}
	else
	{
	perror("getcwd() error");
	return (-1);
	}
	setenv("OLDPWD", prev_dir ? prev_dir : "", 1);
	return (0);
}

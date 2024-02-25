#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 2048
#define MAX_ARGS 64

/**
 * show_prompt -funnction displays a shell prompt
 */
void show_prompt(void)
{
	printf("$");
}

/**
 * execute_cmd - function executes a  command
 * @cmd: The command to be executed
 * @args: vector of arguments for the command
 *
 * Return: 0 on success,else return  -1 on failure
 */
int execute_cmd(char *cmd, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(cmd, args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}

/**
 * main - entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char cmd[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	char *token;
	int a;

	while (1)
	{
		show_prompt();

		if (fgets(cmd, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\nExiting shell. Please wait..\n");
				break;
			}
			else
			{
				perror("fgets");
				return (EXIT_FAILURE);
			}
		}

		token = strtok(cmd, " \n");
		a = 0;
		while (token != NULL)
		{
			args[a++] = token;
			token = strtok(NULL, " \n");
		}
		args[a] = NULL;

		if (execute_cmd(args[0], args) < 0)
		{
			return (EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}

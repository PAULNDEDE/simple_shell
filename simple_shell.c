#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 2048

/**
 * show_prompt - function displays the shell prompt
 */
void show_prompt(void)
{
	printf("$ ");
}

/**
 * execute_command -Function executes a given command provided by user.
 * @command: The command to execute
 * Return: 0 on success,otherwise return -1
 */
int execute_command(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{

		execlp(command, command, NULL);
		fprintf(stderr, "Error: Command '%s' not found\n", command);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}

	return (0);
}

/**
 * main - Entry point for thr program
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		show_prompt();


		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\nExiting shell...\n");
				break;
			}
			else
			{
				perror("fgets");
				return (EXIT_FAILURE);
			}
		}

		command[strcspn(command, "\n")] = '\0';

		if (execute_command(command) < 0)
		{
			return (EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}

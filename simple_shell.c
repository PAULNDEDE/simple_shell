#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 2048

void display_promt()
{
	printf(" $ ");
}

int execute_shell_command(char *command)
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

int main (void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_promt();
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

		if (execute_shell_command(command) < 0)
		{
			return (EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}

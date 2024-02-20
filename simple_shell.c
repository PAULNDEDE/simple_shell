#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 2048

void display_prompt()
{
	printf(" # ");
}

int execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
	printf("Exiting Shell.. Please Wait..\n");
	exit(EXIT_SUCCESS);
	}
	else if (strncmp(command, "cd ", 3) == 0)
	{
		char *dir = command + 3;

	if (chdir(dir) != 0)
	{
	perror("chdir");
	return (-1);
	}
	return (0);
	}


	else if (strcmp(command, "cd") == 0)
	{
		char *home_dir = getenv("HOME");

		if (home_dir == NULL)
		{
			fprintf(stderr, "Home Environment Not set\n");
			return (-1);
		}
		if (chdir(home_dir) != 0)
		{
			perror("chdir");
			return (-1);
		}
		return (0);
	}
	else if (strncmp(command, "emacs ", 6) == 0)
	{
		char *args[] = { "emacs", &command[6], NULL };

		execvp("emacs", args);
	}
	else
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
	}
	return (0);
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if  (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n Exiting Shell ...\n");
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

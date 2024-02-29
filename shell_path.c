#include "main.h"

/**
 * execute_command -the function executes a shell command
 * @command: The command to execute
 * @args: Array of command line arguments
 */
void execute_command(char *command, char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
	perror("Fork failed");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	execvp(command, args);
	printf("Command not found: %s\n", command);
	exit(EXIT_FAILURE);
	}
	else
	{
	waitpid(pid, &status, 0);
	}
}

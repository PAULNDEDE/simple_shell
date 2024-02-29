#include "main.h"

void shell(void)
{
	char input[100];
	char *command;
	char *args[10];

	while (1)
	{
	printf("$ ");
	fflush(stdout);

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
	printf("\n");
	break;
	}

	/*get user input*/
	command = strtok(input, " \n");
	int a = 0;

	while (command != NULL && a < 10)
	{
	args[a] = command;
	command = strtok(NULL, " \n");
	a++;
}
	args[a] = NULL;
	pid_t pid = fork();

	if (pid < 0)
	{
	perror("Fork failed");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	execvp(args[0], args);
	printf("Err: Command not found: %s\n", args[0]);
	exit(EXIT_FAILURE);
	}
	else
{
	waitpid(pid, NULL, 0);
	}
	}
}

/**
 * main: Entry of thee program
 *
 * Return:Always  0(success)
 *
 */

int main(void)
{
	shell();
	return (0);
}

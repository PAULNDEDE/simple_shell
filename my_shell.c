#include "main.h"

/**
 * shell - function to create a simple shell interpreter
 */
void shell(void)
{
	char command[100];
	pid_t pid;
	int status;

	while (1)
	{
	/* Display prompt*/
	printf("$ ");
	fflush(stdout);

	/*read command from user*/
	if (fgets(command, sizeof(command), stdin) == NULL)
	{
	printf("\n");
	break;
	}
	command[strcspn(command, "\n")] = '\0';
	pid = fork();

	if (pid < 0)
	{
	perror("Fork failed");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	execlp(command, command, NULL);
	printf("Command not found: %s\n", command);
	exit(EXIT_FAILURE);
	}
	else
	{
	waitpid(pid, &status, 0);
	}
	}
}

/**
 * parse_input - Parse input command line into command and arguments
 * @input: The input command line
 * @command: Pointer to store the command
 * @args: Pointer to store the arguments
 */
void parse_input(char *input, char **command, char **args) {
    *command = strtok(input, " \n");

    // Initialize args array
    for (int i = 0; i < 10; i++) {
        args[i] = NULL;
    }

    int a = 0;
    char *token;
    while ((token = strtok(NULL, " \n")) != NULL && a < 9)
    {
        args[a] = token;
        a++;
    }
    /*implement the built in commands*/

    if (command != NULL && strcmp(command, "env") == 0)
    {
            env_command(); // Call env_command if the input is "env"
        } else {
            // Execute external commands
            execute_command(command, args);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0(success)
 */
int main(void)
{
	shell();

	return (0);
}

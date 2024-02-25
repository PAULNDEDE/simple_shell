#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

/**
 * get_input - Read input from stdin
 *
 * Return: Pointer to the input string
 */
char *get_input(void);

/**
 * parse_input - Tokenize input string into array of arguments
 * @input: Input string to be tokenized
 *
 * Return: Array of strings containing the arguments
 */
char **parse_input(char *input);

/**
 * execute_command - Execute the command with provided arguments
 * @args: Array of strings containing the command and its arguments
 *
 * Return: 1 if the shell should continue, 0 if it should exit
 */
int execute_command(char **args);

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	while (1)
	{
		char *input = get_input();
		char **args = parse_input(input);
		int status = execute_command(args);

		free(input);
		free(args);

		if (status == 0)
		{
			break;
		}
	}

	return (EXIT_SUCCESS);
}

char *get_input(void)
{
	char *input = malloc(MAX_INPUT * sizeof(char));

	if (input == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	printf("$ ");
	fgets(input, MAX_INPUT, stdin);

	/* Remove trailing newline character */
	input[strcspn(input, "\n")] = '\0';

	return (input);
}

char **parse_input(char *input)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}

int execute_command(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	/* Check if the command exists in PATH*/
	char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not set\n");
		return (1);
	}

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char command_path[MAX_INPUT];

		snprintf(command_path, sizeof(command_path), "%s/%s", token, args[0]);

		if (access(command_path, X_OK) == 0)
		{
			/* Command found, execute it */
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				/* Child process */
				execv(command_path, args);
				/* If execv returns, an error occurred */
				perror("execv");
				exit(EXIT_FAILURE);
			}
			else
			{
				/* Parent process */
				int status;

				waitpid(pid, &status, 0);
				return (1);
			}
		}

		token = strtok(NULL, ":");
	}

	/* Command not found */
	printf("Command not found: %s\n", args[0]);
	return (1);
}

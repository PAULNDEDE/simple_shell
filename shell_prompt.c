#include "shell.h"
int main()
{
	void execute_command(char *args);
	char command[MAX_COMMAND_LENGTH];

	
	while (1)
	{
		int m = 0;

		printf("$");
	/*Get command from user*/
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nEXITING SHELL..\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
	/*fork to execute  a command*/
		pid_t pid = fork();
		if (pid < 0){
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} else if (m == 0){
			execute_command(command);
		}
		else if (pid == 0) {
			execlp(command, command, NULL);
			printf("ERROR: command '%s' not found.\n", command);
			exit(EXIT_FAILURE);
		}
		else {
			int status;
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

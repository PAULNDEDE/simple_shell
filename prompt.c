#include "shell.h"
int main()
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
	int m = 0;
        printf("Shell> ");
        
        // Read command from user
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\nExiting shell.\n");
            break;
        }

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Fork to execute command
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if(m == 0){
		execute_command(command)
	}	
	else if (pid == 0) {
            // Child process
            execlp(command, command, NULL);
            // If execlp returns, it means the command was not found
            printf("Error: Command '%s' not found.\n", command);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

#include "shell.h"

// Function definition for execute_command
void execute_command main(char *command_line)
{
    pid_t pid;
    int status;

    // Parse command and arguments
    char *command = strtok(command_line, " ");
    char *arguments[100];
    arguments[0] = command;

    // Parse arguments
    int i = 1;
    while ((arguments[i] = strtok(NULL, " ")) != NULL)
    {
        i++;
    }
    arguments[i] = NULL; // Mark end of arguments

    // Check if the command exists in PATH directories
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char command_path[1024];

    while (dir != NULL)
    {
        snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);
        if (access(command_path, X_OK) == 0)
            break;
        dir = strtok(NULL, ":");
    }

    free(path_copy);

    // If command not found, print error and return
    if (dir == NULL)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return;
    }

    // Fork and execute the command
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        execv(command_path, arguments);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process waiting for child to terminate
        waitpid(pid, &status, 0);
    }
}

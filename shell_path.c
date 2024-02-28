#include "shell.h"

/* Function prototype for the execute_shell function in shell_prompt.c*/
void execute_shell(void);

int main(int argc, char *argv[]) {
    // Call the execute_shell function from shell_prompt.c
    while(1)
    {
	    execute_shell();
	    return 0;
    }
}

void execute_shell(void) {
    /* Get the PATH environment variable*/
    char *path = getenv("PATH");
    if (path == NULL) {
        fprintf(stderr, "PATH environment variable not found\n");
        return;
    }

    /* Parse the PATH variable to search for the command*/
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char command_path[1024];

    /* Get the command entered by the user*/
    char command[BUFFER_SIZE];
    printf("Enter command: ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove newline character

    // Search for the command in the PATH directories
    while (dir != NULL) {
        snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);
        if (access(command_path, X_OK) == 0) {
            /* Command found, proceed with execution*/
            break;
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);

    /* If command not found, print error and return*/
    if (dir == NULL) {
        fprintf(stderr, "%s: command not found\n", command);
        return;
    }
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        execl(command_path, command, NULL);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

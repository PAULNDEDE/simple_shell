#include "main.h"

void env_command(void); // Declare env_command before usage

void parse_input(char *input, char **command, char **args) {
    int a; // Move variable declaration to the beginning of the block

    // Initialize args array
    for (a = 0; a < 10; a++) {
        args[a] = NULL;
    }

    char *token = strtok(input, " \n");
    if (token != NULL) {
        *command = token;
        int i = 0;
        while ((token = strtok(NULL, " \n")) != NULL && i < 9) {
            args[i] = token;
            i++;
        }
    } else {
        *command = NULL;
    }
}

void shell(void) {
    char input[100];
    char *command;
    char *args[10];

    while (1) {
        // Display prompt
        printf("$ ");
        fflush(stdout);

        // Read input from user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle EOF
            printf("\n");
            break;
        }

        // Parse input
        parse_input(input, &command, args);

        // Execute built-in commands
        if (command != NULL && strcmp(command, "env") == 0) {
            env_command(); // Call env_command if the input is "env"
        } else {
            // Execute external commands
void execute_command(char *command,char **args);
        }
    }
}

int main(void) {
    // Start the shell
    shell();
    return 0;
}

void env_command(void) {
    extern char **environ; // External variable containing the environment variables

    // Print each environment variable
    for (int a = 0; environ[a] != NULL; a++) {
        printf("%s\n", environ[a]);
    }
}

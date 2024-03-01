"#include "main.h"


void env_command(void);

void parse_input(char *input, char **command, char **args) {
    char *token;
    int i;

    for (i = 0; i < 10; i++) {
        args[i] = NULL;
    }

    token = strtok(input, " \n");
    if (token != NULL) {
        *command = token;
        i = 0;
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
    pid_t pid;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        /* Read input from user*/
        if (fgets(input, sizeof(input), stdin) == NULL) {
            /* Handle EOf*/
            printf("\n");
            break;
        }

        /* Parse input*/
        parse_input(input, &command, args);

        /* Execute builtin commands*/
        if (command != NULL && strcmp(command, "env") == 0) {
            env_command();
        } else {
            /* Execute external commands*/
            pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                execve(command, args, NULL);
                perror("execve");
                exit(EXIT_FAILURE);
            } else {
                wait(NULL);
            }
        }
    }
}

int main(void) {
  
    shell();
    return 0;
}

void env_command(void) {
    extern char **environ;
    int a;

    for (a = 0; environ[a] != NULL; a++) {
        printf("%s\n", environ[a]);
    }
}

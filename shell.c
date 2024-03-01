#include "main.h"

void exit_command(void)
{
	exit(EXIT_SUCCESS);
}



void env_command(void);

void shell(void) {
    char input[100];
    char *command;
    char *args[10];
    pid_t pid;

    while (1) {
        printf("$ ");
        fflush(stdout);

        
        if (fgets(input, sizeof(input), stdin) == NULL) {
           
            printf("\n");
            break;
        }

        
        parse_input(input, &command, args);

      
        if (command != NULL && strcmp(command, "env") == 0) {
            env_command();
        } else {
           
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

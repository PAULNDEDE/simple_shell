#include "main.h"

#define MAX_ARGS 10

void parse_input(char *input, char **command, char **args) {
    char *token;
    int i;
    int arg_index = 0;

    /* Initialize args array */
    for (i = 0; i < MAX_ARGS; i++) {
        args[i] = NULL;
    }

    token = strtok(input, " \n");
    if (token != NULL) {
        *command = token;
        while ((token = strtok(NULL, " \n")) != NULL && arg_index < MAX_ARGS - 1) {
            args[arg_index++] = token;
        }
        args[arg_index] = NULL;
    } else {
        *command = NULL;
    }
}

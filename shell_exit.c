#include "main.h"

/**
 * exit_program -function exits a shell program
 * @tokens: user input(tokenized)
 * @input:user input untokenized
 * Return: Nothing
 */
void exit_program(char **tokens, char *input)
{
    int exit_status = 0, i = 0;

    if (tokens[1] != NULL)
        exit_status = a_toi(tokens[1]);

    free(input);
    for (i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
    exit(exit_status);
}

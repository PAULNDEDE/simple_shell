#include "main.h"
#include <string.h>

/**
 * process_input -function processes user input
 * @input: user input(sstring)
 * Return: string up to the first occurrence of '#'
 */
char *process_input(char *input)
{
    char *token;

    token = strtok(input, "#");
    return token;
}

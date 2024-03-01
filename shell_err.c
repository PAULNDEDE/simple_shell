#include "main.h"

/**
 * print_error - prints an error message to STDOUT
 * @cmd: user input command
 * @argv:array of arguments
 * @count: total error iteration
 * Return: Nothing
 */
void print_error(char **cmd, char **argv, int count)
{
    write(STDOUT_FILENO, argv[0], strlen(argv[0]));
    write(STDOUT_FILENO, ": ", 2);
    printer(count);
    write(STDOUT_FILENO, ": ", 2);
    write(STDOUT_FILENO, cmd[0], strlen(cmd[0]));
    write(STDOUT_FILENO, ": not found", 11);
    write(STDOUT_FILENO, "\n", 1);
}

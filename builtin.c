#include "main.h"

/**
 * handle_builtin - handles custom shell builtins
 * @args: tokenized user input
 * @input: user input untokenized
 * @argv: argument vector
 * @count: loop iteration number
 * Return: 0 for  builtin function
 * else -1 for non builtin
 */
int handle_builtin(char **args, char *input, char **argv, int count)
{
    pid_t pid;
    int return_value = 1, value = 0;

    if (strcmp(args[0], "cd") == 0)
    {
        return_value = cd_function(args);
        if (return_value == -1)
            error_handler(args, argv, count);
    }
    if (strcmp(args[0], "env") == 0)
    {
        env_function();
        return_value = 0;
    }
    if (strcmp(args[0], "exit") == 0)
    {
        if (args[1] == NULL)
        {
            exit_function(args, input);
            return_value = 0;
        }
        else
        {
            value = string_to_integer(args[1]);
            if (value == -1)
                exit_error(args, argv, count);
            else
                exit_function(args, input);
            return_value = 0;
        }
    }
    if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "$$") == 0)
    {
        pid = getpid();
        print_pid(pid);
        write(STDOUT_FILENO, "\n", 1);
        return_value = 0;
    }
    return (return_value);
}

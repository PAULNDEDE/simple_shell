#include "main.h"

/**
 * change_directory -Function changes directory
 * @args: user input arguments
 * Return: Always 0 (success),else  -1 on error
 */
int change_dir(char **args)
{
    char *home_dir = getenv("HOME");
    int return_value = 0;

    if (strcmp(args[1], ".") == 0)
        ;
    else if (strcmp(args[1], "~") == 0 || (args[1] == NULL))
    {
        return_value = chdir(home_dir);
        if (return_value == -1)
        {
            perror("cd");
            return (-1);
        }
    }
    else
    {
        return_value = chdir(args[1]);
        if (return_value == -1)
            return (-1);
    }
    return (return_value);
}

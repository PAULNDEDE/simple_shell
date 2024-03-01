#include "main.h"

/**
 * search_executable -function  finds the first executable path
 * of the user's first input token
 * @token: first tokenized input
 * Return: pointer to the first executable path on success, NULL otherwise
 */
char *search_executable(char *token)
{
    int m = 0, n = 0;
    struct stat st;
    char *path = getenv("PATH");
    char *path_copy = NULL;
    char *path_token = NULL;
    char *executable_path = NULL;

    if (path == NULL || token == NULL)
        return NULL;

    path_copy = strdup(path);
    if (path_copy == NULL)
        return NULL;

    path_token = strtok(path_copy, ":");
    while (path_token)
    {
        executable_path = malloc(strlen(token) + strlen(path_token) + 2);
        if (executable_path == NULL)
        {
            free(path_copy);
            return NULL;
        }

        for (m = 0; path_token[m]; m++)
            executable_path[m] = path_token[m];
        executable_path[m++] = '/';
        for (n = 0; token[n]; n++)
            executable_path[m + n] = token[n];
        executable_path[m + n] = '\0';

        
        if (stat(executable_path, &st) == 0)
        {
            free(path_copy);
            return executable_path;
        }

       
        free(executable_path);

        path_token = strtok(NULL, ":");
    }

    
    free(path_copy);

    return NULL;
}

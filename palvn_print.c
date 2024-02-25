#include "shell.h"
/**
 *
 */
void leo_print(const char *string)
{
    write(STDOUT_FILENO, string, strlen(string));
}

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function prototypes*/
void parse_input(char *input, char **command, char **args);
void shell(void);
void env_command(void);
void exit_command(void);


#endif /* MAIN_H */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


void execute_command(char *command, char **args);
/*void env_command(void);*/
void parse_input(char *input, char **command, char **args);


/**
 * shell - A simple shell interpreter
 */
void shell(void);







#endif /* MAIN_H */

